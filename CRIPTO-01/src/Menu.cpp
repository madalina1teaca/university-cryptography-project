#include <iostream>
#include <limits>
#include "Menu.h"
#include "Caesar.h"
#include "Vigenere.h"
#include "Substitution.h"
#include "Transposition.h"
#include "Mixed.h"

using namespace std;

// funcție ajutătoare - curăță starea de eroare a fluxului std::cin 
// și previne buclele infinte în cazul introducerii unor tipuri greșite valori
void fixInvalidInput() {
    if (cin.fail()) {
        cin.clear(); // resetează flag-ul de eroare al stream-ului
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // șterge tot buffer-ul până la o linie nouă
    }
}

void showMenu()
{
    int option;

    do
    {
        cout << "\n===== CRIPTO-R1 =====\n";
        cout << "1. Caesar\n";
        cout << "2. Vigenere\n";
        cout << "3. Substituție\n";
        cout << "4. Transpoziție\n";
        cout << "5. Sistem mixt\n";
        cout << "0. Ieșire\n";

        cout << "\nOpțiune: ";
        if (!(cin >> option)) { // dacă citirea eșuează (utilizatorul a introdus caractere non-numerice)
            cout << "Eroare: Trebuie sa introdus un număr!\n";
            fixInvalidInput();
            option = -1; // setează o opțiune invalidă pentru a reafișa meniul
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // curăță corect buffer-ul după citire

        switch(option)
        {
            case 1:
                runCaesar();
                break;

            case 2:
                runVigenere();
                break;

            case 3:
                runSubstitution();
                break;

            case 4:
                runTransposition();
                break;

            case 5:
                runMixed();
                break;

            case 0:
                cout << "Program închis.\n";
                break;

            default:
                cout << "Opțiune invalidă! Selectează o valoare din meniu.\n";
        }

    } while(option != 0);
}

void runCaesar() {
    string text;
    int key;

    cout << "\nTextul pentru criptare:\n";
    getline(cin, text);

    while (true) {
        cout << "\nCheia pentru criptare (0-25):\n";
        if (cin >> key && key >= 0 && key <= 25) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break; // Input valid
        }
        cout << "Cheie invalidă! Introdu un număr întreg între 0 și 25.\n";
        fixInvalidInput();
    }

    string encryptedText = caesarEncrypt(text, key);
    string decryptedText = caesarDecrypt(encryptedText, key);

    cout << "\nTextul criptat:\n" << encryptedText << "\n";
    cout << "Textul decriptat:\n" << decryptedText << "\n\n";
}

void runVigenere() {
    string text;
    string key;

    cout << "\nTextul pentru criptare:\n";
    getline(cin, text);

    while (true) {
        cout << "\nCheia pentru criptare (text):\n";
        getline(cin, key);
        
        // validarea string-ulului cheii - nu poate fi gol
        if (!key.empty()) break;
        cout << "Cheia nu poate fi vidă!\n";
    }

    string encryptedText = vigenereEncrypt(text, key);
    string decryptedText = vigenereDecrypt(encryptedText, key); 

    cout << "\nTextul criptat:\n"<< encryptedText << "\n";
    cout << "Textul decriptat: " << decryptedText << "\n\n";
}

void runSubstitution()
{
    string text;

    cout << "\nTextul pentru criptare:\n";
    getline(cin, text);

    string encrypted = substitutionEncrypt(text);
    string decrypted = substitutionDecrypt(encrypted);

    cout << "\nTextul criptat:\n" << encrypted << endl;
    cout << "\nTextul decriptat:\n" << decrypted << endl;
}

void runTransposition()
{
    string text;
    int columns;

    cout << "\nTextul pentru criptare:\n";
    getline(cin, text);

    while (true) {
        cout << "Numărul de coloane (minim 1): ";
        if (cin >> columns && columns > 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        cout << "Număr de coloane invalid! Trebuie să fie mai mare decât 0.\n";
        fixInvalidInput();
    }

    string encrypted = transpositionEncrypt(text, columns);
    string decrypted = transpositionDecrypt(encrypted, columns);

    cout << "\nTextul criptat:\n" << encrypted << endl;
    cout << "\nTextul decriptat:\n" << decrypted << endl;
}

void runMixed()
{
    string text;
    int columns;

    cout << "\nTextul pentru criptare:\n";
    getline(cin, text);

    while (true) {
        cout << "Numărul de coloane pentru transpoziție (minim 1): ";
        if (cin >> columns && columns > 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        cout << "Număr de coloane invalid! Trebuie să fie mai mare decât 0.\n";
        fixInvalidInput();
    }

    string encrypted = mixedEncrypt(text, columns);
    string decrypted = mixedDecrypt(encrypted, columns);

    cout << "\nTextul criptat:\n" << encrypted << endl;
    cout << "\nTextul decriptat:\n" << decrypted << endl;
}