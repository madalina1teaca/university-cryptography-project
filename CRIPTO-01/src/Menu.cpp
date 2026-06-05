#include <iostream>
#include "Menu.h"
#include "Caesar.h"
#include "Vigenere.h"
#include "Substitution.h"
#include "Transposition.h"
#include "Mixed.h"

using namespace std;

void showMenu()
{
    int option;

    do
    {
        cout << "\n===== CRIPTO-R1 =====\n";
        cout << "1. Caesar\n";
        cout << "2. Vigenere\n";
        cout << "3. Substitutie\n";
        cout << "4. Transpozitie\n";
        cout << "5. Sistem mixt\n";
        cout << "0. Iesire\n";

        cout << "\nOptiune: ";
        cin >> option;
        cin.ignore();

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
                cout << "Program inchis.\n";
                break;

            default:
                cout << "Optiune invalida!\n";
        }

    } while(option != 0);
}

void runCaesar() {

    string text;
    int key;

    cout << "\nTextul pentru criptare:\n";
    getline(cin, text);

    cout << "\nCheia pentru criptare (0-25):\n";
    cin >> key;
    cin.ignore();

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

    cout << "\nCheia pentru criptare:\n";
    getline(cin, key);

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

    cout << "\nTextul criptat:\n";
    cout << encrypted << endl;

    cout << "\nTextul decriptat:\n";
    cout << decrypted << endl;
}

void runTransposition()
{
    string text;
    int columns;

    cout << "\nTextul pentru criptare:\n";
    getline(cin, text);

    cout << "Numarul de coloane: ";
    cin >> columns;
    cin.ignore();

    string encrypted = transpositionEncrypt(text, columns);
    string decrypted = transpositionDecrypt(encrypted, columns);

    cout << "\nTextul criptat:\n";
    cout << encrypted << endl;

    cout << "\nTextul decriptat:\n";
    cout << decrypted << endl;
}

void runMixed()
{
    string text;
    int columns;

    cout << "\nTextul pentru criptare:\n";
    getline(cin, text);

    cout << "Numarul de coloane pentru transpozitie: ";
    cin >> columns;
    cin.ignore();

    string encrypted = mixedEncrypt(text, columns);
    string decrypted = mixedDecrypt(encrypted, columns);

    cout << "\nTextul criptat:\n";
    cout << encrypted << endl;

    cout << "\nTextul decriptat:\n";
    cout << decrypted << endl;
}