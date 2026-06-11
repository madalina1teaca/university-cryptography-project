#include "CryptoGF.h"
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

// pozițiile valide sunt de la 1 la 26
const string ALPHABET = " ABCDEFGHIJKLMNOPQRSTUVXYWZ";

/*
=== Cheia personalizată ===
prenume:    MADALINA-ELENA 
nume:       TEACA
a1 = M = 13
a2 = A = 1
b1 = T = 20
b2 = E = 5
*/ 
const int A1_EXP = 13;
const int A2_EXP = 1;
const int B1_EXP = 20;
const int B2_EXP = 5;

/*
=== Tabele pentru conversii ===
exponent -> polinom
polinom -> exponent
*/
map<int, tuple<int, int, int>> expToPoly;
map<tuple<int, int, int>, int> polyToExp;

// înlocuiește toate aparițiile unui șir cu alt șir
// funcție folosită pentru normalizarea diacriticelor
void replaceAll(string& text, const string& from, const string& to)
{
    size_t startPos = 0;

    while((startPos = text.find(from, startPos)) != string::npos)
    {
        text.replace(startPos, from.length(), to);
        startPos += to.length();
    }
}

/*
=== normalizarea ===
- înlocuirea diacriticelor cu echivalente din alfabetul dat
- păstrează spațiile și caracterel speciale pentru a aplicare mai largă a programului
- convertește literele în majuscule
obs. -> diacriticele ro în UTF-8 ocupă mai mult de un byte => tratate ca șir de caractere
*/  
string normalizeText(string text)
{
    replaceAll(text, "ă", "a"); replaceAll(text, "Ă", "A");
    replaceAll(text, "â", "a"); replaceAll(text, "Â", "A");
    replaceAll(text, "î", "i"); replaceAll(text, "Î", "I");
    replaceAll(text, "ș", "s"); replaceAll(text, "Ș", "S");
    replaceAll(text, "ț", "t"); replaceAll(text, "Ț", "T");


    transform(text.begin(), text.end(), text.begin(),
              [](unsigned char c) { return toupper(c); });

    return text;
}

// poziția unei litere în alfabet
int getLetterIndex(char c) {
   
    size_t pos = ALPHABET.find(c);

    if(pos == string::npos) return -1;

    return static_cast<int>(pos);

}

// litera corespunzătoare unui index
char getLetterFromIndex (int index) {

    if(index >= 1 && index <= 26) return ALPHABET[index];

    return ' '; // spațiul pentru elementul 0 sau erori
}

// transformă un polinom de forma (a,b,c) -> fn = a*9 + b*3 + c
int polynomialToFn(tuple<int, int, int> p) {

    return get<0>(p) * 9 + get<1>(p) * 3 + get<2>(p);

}

// transformă o val fn -> polinom
tuple<int, int, int> fnToPolynomial(int fn)
{
    int a = fn / 9;
    int b = (fn % 9) / 3;
    int c = fn % 3;

    return make_tuple(a, b, c);
}

// polinom în forma compactă
string polynomialToString(tuple<int, int, int> p)
{
    return to_string(get<0>(p)) + to_string(get<1>(p)) + to_string(get<2>(p));
}

// construiește GF(3^3) = GF(27)
// se folosește polinomul primitiv t^3 + 2t + 1 = 0 => t^3 = t + 2 in modulo 3.
void buildGF27()
{
    expToPoly.clear();
    polyToExp.clear();

    tuple<int, int, int> current = make_tuple(0, 1, 0); // t^1 = 010

    for(int exp = 1; exp <= 26; exp++)
    {
        expToPoly[exp] = current;
        polyToExp[current] = exp;

        int c0 = get<0>(current);
        int c1 = get<1>(current);
        int c2 = get<2>(current);

        current = make_tuple(
            c1 % 3,
            (c0 + c2) % 3,
            (2 * c0) % 3
        );
    }

    expToPoly[0] = make_tuple(0, 0, 0);
    polyToExp[make_tuple(0, 0, 0)] = 0;
} 

// == ADUNAREA == în GF(27) - adunarea coeficienților modulo 3
tuple<int, int, int> gfAdd(tuple<int, int, int> a, tuple<int, int, int> b)
{
    return make_tuple(
        (get<0>(a) + get<0>(b)) % 3,
        (get<1>(a) + get<1>(b)) % 3,
        (get<2>(a) + get<2>(b)) % 3
    );
}

// == SCĂDEREA == în GF (27) - componentă cu componentă modulo 3
tuple<int, int, int> gfSub(tuple<int, int, int> a, tuple<int, int, int> b)
{
    return make_tuple(
        (get<0>(a) - get<0>(b) + 3) % 3,
        (get<1>(a) - get<1>(b) + 3) % 3,
        (get<2>(a) - get<2>(b) + 3) % 3
    );
}

// == ÎNMULȚIREA == în GF(27) folosind exponenți - t^a * t^b = t^(a+b mod 26)
int gfMultiplyExp(int expA, int expB)
{
    if(expA == 0 || expB == 0) return 0;

    int result = (expA + expB) % 26;

    if(result == 0) result = 26;

    return result;
}

// == INVERS MULTIPLICATIV == în GF(27) - pt t^a inversul este t^(26-a)
int gfInverseExp(int exp)
{
    if(exp == 0) return 0;

    int result = (26 - exp) % 26;

    if(result == 0) result = 26;

    return result;
}

// generează secvențe pe dimensiuni mai mari
vector<int> generateASequence()
{
    vector<int> aExp(100, 0); 
    vector<tuple<int, int, int>> aPoly(100);

    aExp[1] = A1_EXP;
    aExp[2] = A2_EXP;

    aPoly[1] = expToPoly[A1_EXP];
    aPoly[2] = expToPoly[A2_EXP];

    for(int i = 3; i < 100; i++)
    {
        aPoly[i] = gfAdd(aPoly[i - 1], aPoly[i - 2]);
        aExp[i] = polyToExp[aPoly[i]];
    }

    return aExp;
}

// generează secvența b_i -> b(i+2) = b(i+1) * b(i)
// în exponenți, înmulțirea devine adunare modulo
vector<int> generateBSequence()
{
    vector<int> bExp(100, 0);

    bExp[1] = B1_EXP;
    bExp[2] = B2_EXP;

    for(int i = 3; i < 100; i++)
    {
        int result = (bExp[i - 1] + bExp[i - 2]) % 26;

        if(result == 0) result = 26;

        bExp[i] = result;
    }

    return bExp;
}

/*
=== CRIPTAREA ===
- formula: y_i = a_i * x_i + b_i
- caracterele care nu aparțin alfabetului sunt păstrate așa cum sunt
*/
string encryptGF(string text)
{
   // inițializează corpul GF(27)
    buildGF27();

    // normalizarea textului
    text = normalizeText(text);

    // generarea secvențelor de chei
    vector<int> aExp = generateASequence();
    vector<int> bExp = generateBSequence();

    string encrypted;
    int pos_text = 1; // contorizează a câta literă validă este procesată

    cout << "\n===== CRIPTAREA =====\n";

    for(char ch : text)
    {
        int i = getLetterIndex(ch);

        // păstrează caracterului neschimbat dacă acesta nu aparține alfabetului
        if(i < 1 || i > 26)
        {
            encrypted += ch;
            continue;
        }

        // --- ETAPA DE CALCUL MATEMATIC --- // 
        
        // xFn -> valoarea numerică a literei din text
        int xFn = i; 
        tuple<int, int, int> xPoly = fnToPolynomial(xFn);
        int xExp = polyToExp[xPoly];

        // extrage 'a_i' și 'b_i' pe baza poziției din text
        int aiExp = aExp[pos_text];
        tuple<int, int, int> aiPoly = expToPoly[aiExp];

        int biExp = bExp[pos_text];
        tuple<int, int, int> biPoly = expToPoly[biExp];

        // înmulțirea în GF(27): a_i * x (adunarea exponenților modulo 26)
        int axExp = gfMultiplyExp(aiExp, xExp);
        tuple<int, int, int> axPoly = expToPoly[axExp];

        // adunarea în GF(27): (a_i * x) + b_i (adunarea polinoamelor modulo 3)
        tuple<int, int, int> yPoly = gfAdd(axPoly, biPoly);
        
        // convertește rezultatul în exponent și în indice numeric pentru alfabet (yFn)
        int yExp = polyToExp[yPoly];
        int yFn = polynomialToFn(yPoly);

        // convertește indicele numeric în caracterul criptat final
        char encryptedChar = getLetterFromIndex(yFn);
        encrypted += encryptedChar;

        // afișarea pas cu pas
        cout << "\n‣ Litera: " << ch << " (Poziția în text: " << pos_text << ")" << endl;
        cout << "‣ nr.crt / fn: " << xFn << endl;
        cout << "‣ x-pol: " << polynomialToString(xPoly) << endl;
        cout << "‣ x-exp: t^" << xExp << endl;
        cout << "‣ a_i exp: t^" << aiExp << endl;
        cout << "‣ a_i pol: " << polynomialToString(aiPoly) << endl;
        cout << "‣ b_i exp: t^" << biExp << endl;
        cout << "‣ b_i pol: " << polynomialToString(biPoly) << endl;
        cout << "‣ a_i * x_i exp: t^" << axExp << endl;
        cout << "‣ a_i * x_i pol: " << polynomialToString(axPoly) << endl;
        cout << "‣ a_i * x_i + b_i pol: " << polynomialToString(yPoly) << endl;
        cout << "‣ rezultat exp: t^" << yExp << endl;
        cout << "‣ rezultat fn: " << yFn << endl;
        cout << "‣ litera criptată: " << encryptedChar << endl;

        pos_text++; // intrementează poziția curentă din fluxul de chei
    }

    return encrypted;
}

/*
=== DECRPTAREA ===
- se reconstruiește invers tabelul de substituție
- caracterele care nu aparțin alfabetului sunt păstrate așa cum sunt
*/
string decryptGF(string text)
{
    // reinițializarea structurii GF(27)
    buildGF27();
    text = normalizeText(text);

    // generarea aceleiași secvențe de chei
    vector<int> aExp = generateASequence();
    vector<int> bExp = generateBSequence();

    string decrypted;
    int pos_text = 1; // contorizează poziția curentă a literei în text

    cout << "\n===== DECRIPTAREA PAS CU PAS =====\n";

    for(char ch : text)
    {
        // indicele numeric al caracterului criptat (yFn)
        int yFn = getLetterIndex(ch);

        // dacă caracterul nu aparține alfabetului -> rămâne neschimbat
        if(yFn < 1 || yFn > 26)
        {
            decrypted += ch;
            continue;
        }

        // recuperează cheile specifice acestei poziții din text
        int aiExp = aExp[pos_text];
        int biExp = bExp[pos_text];
        
        tuple<int, int, int> biPoly = expToPoly[biExp];
        tuple<int, int, int> yPoly = fnToPolynomial(yFn);

        // y - b_i (scădere polinomială modulo 3)
        tuple<int, int, int> diffPoly = gfSub(yPoly, biPoly);
        int diffExp = polyToExp[diffPoly];

        // află inversul multiplicativ al lui a_i
        int aiInvExp = gfInverseExp(aiExp);

        // calculează x recuperat: x = a_i^(-1) * (y - b_i)
        int xRecoveredExp = gfMultiplyExp(aiInvExp, diffExp);
        tuple<int, int, int> xRecoveredPoly = expToPoly[xRecoveredExp];

        // trece de la polinomul recuperat la valoarea numerică fn (care este chiar xFn-ul inițial)
        int xFn = polynomialToFn(xRecoveredPoly);

        // obține caracterul din indexul determinat
        char clearChar = getLetterFromIndex(xFn);
        decrypted += clearChar;

        // afișarea pas cu pas
        cout << "\n‣ Litera criptata: " << ch << " (Pozitie text: " << pos_text << ")" << endl;
        cout << "‣ litera clara gasita: " << clearChar << endl;
        cout << "‣ nr.crt / fn (recuperat): " << xFn << endl;
        cout << "‣ y-pol: " << polynomialToString(yPoly) << endl;
        cout << "‣ b_i pol: " << polynomialToString(biPoly) << endl;
        cout << "‣ y - b_i pol: " << polynomialToString(diffPoly) << endl;
        cout << "‣ a_i^(-1) exp: t^" << aiInvExp << endl;
        cout << "‣ x recuperat exp: t^" << xRecoveredExp << endl;
        cout << "‣ x recuperat pol: " << polynomialToString(xRecoveredPoly) << endl;

        pos_text++; // trece la următoarea cheie din flux
    }

    return decrypted;
}

// === AFIȘAREA TABELULUI GF (27)
void printGFTable()
{
    buildGF27();

    cout << "\n===== TABEL GF(27) =====\n";
    // Am împărțit coloana GF în 3 sub-coloane pentru polinoame (c2, c1, c0)
    cout << "Exp\t[  GF  ]\tfn\tLitera\n";
    cout << "\tc2 c1 c0\n";
    cout << "--------------------------------------\n";

    for(int exp = 1; exp <= 26; exp++)
    {
        tuple<int, int, int> p = expToPoly[exp];
        int fn = polynomialToFn(p);
        
        // Extragere coeficienți separat pentru cele 3 coloane din Excel
        int c2 = get<0>(p);
        int c1 = get<1>(p);
        int c0 = get<2>(p);

        // Preluăm caracterul direct ('A', 'B', 'C'...) în loc de codul numeric ASCII
        char litera = getLetterFromIndex(fn);

        cout << "t^" << exp << "\t"
             << c2 << "  " << c1 << "  " << c0 << "\t"
             << "\t" << fn //<< "\t"
             << "\t" << litera << endl;
    }
}

// === AFIȘAREA SECV a_i ȘI b_i ====
void printKeySequence()
{
    buildGF27();

    vector<int> aExp = generateASequence();
    vector<int> bExp = generateBSequence();

    cout << "\n===== SECVENȚA CHEII =====\n";
    cout << "i\tLitera\ta_i\tb_i\n";

    for(int i = 1; i <= 26; i++)
    {
        cout << i << "\t"
             << getLetterFromIndex(i) << "\t"
             << "t^" << aExp[i] << "\t"
             << "t^" << bExp[i] << endl;
    }
}