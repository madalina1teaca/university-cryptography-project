#include <iostream>
#include "CryptoGF.h"

using namespace std;

/*
=== Programul Principal ===
Include:
- criptarea unui text
- decriptarea unui text
- afișarea tebelului GF(27)
- afișarea secvenței cheii
*/

int main () {

    int option;
    string text;

    do {

        cout << "\n\n=============================\n";
        cout << "===== CRIPTARE GF(27) ====\n";
        cout << "Student: Teacă Mădălina-Elena\n";
        cout << "=============================\n\n";

        cout << " Meniul aplicație:\n";
        cout << "1. Criptare\n";
        cout << "2. Decriptare\n";
        cout << "3. Criptare + decriptare\n";
        cout << "4. Afișarea tabelului GF(27)\n";
        cout << "5. Afișare secvenței cheii\n";
        cout << "0. Ieșire\n";

        cout << "\nAlegeți opțiunea dorită: ";
        cin >> option;
        cin.ignore();

        switch (option) {

            case 1:
            {
                cout << "\nIntroduceți textul pentru criptare: ";
                getline(cin, text);

                string encrypted = encryptGF(text);

                cout << "\nText normalizat: " << normalizeText(text);
                cout << "\nText criptat: " << encrypted << endl;

                break;
            }

            case 2:
            {
                cout << "\nIntroduceți textul criptat: ";
                getline(cin, text);

                string decrypted = decryptGF(text);

                cout << "\nText criptat normalizat: " << normalizeText(text);
                cout << "\nText decriptat: " << decrypted << endl;

                break;
            }

            case 3:
           {
                cout << "\nIntroduceți textul pentru criptare: ";
                getline(cin, text);

                string encrypted = encryptGF(text);
                string decrypted = decryptGF(encrypted);

                cout << "\n===== REZULTAT =====\n";
                cout << "Text normalizat: " << normalizeText(text) << endl;
                cout << "Text criptat: " << encrypted << endl;
                cout << "Text decriptat: " << decrypted << endl;

                break;
           } 

           case 4:
                printGFTable();
                break;

            case 5:
                printKeySequence();
                break;

            case 0:
                cout << "\nProgram închis.\n";
                break;

            default:
                cout << "\nOpțiune invalidă.\n";
        } 
    
    } while (option != 0);

}