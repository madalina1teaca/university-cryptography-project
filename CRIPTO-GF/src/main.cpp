#include <iostream>
#include "CryptoGF.h"

using namespace std;

int main()
{
    string text;

    cout << "=====================================\n";
    cout << " REFERAT CRIPTOGRAFIE GF\n";
    cout << "STUDENT: Teacă Mădălina-Elena\n";
    cout << "=====================================\n";

    cout << "\n PARAMETRII UTILIZAȚI: \n";
    cout << "a = 1\n";
    cout << "b = 9\n";
    cout << "cuvânt_cheie = TEA\n";

    // citirea textului de la tastatură
    cout << "\nTEXT PENTRU CRIPTARE:\n";
    getline(cin, text);

    // criptarea textului
    string encryptedText = encrypt(text);

    // decriptarea textului
    string decryptedText = decrypt(encryptedText);

    // afișarea textului criptat și decriptat
    cout << "\nTEXT CRIPTAT:\n";
    cout << encryptedText << "\n";
    cout << "\nTEXT DECRIPTAT:\n";
    cout << decryptedText << "\n";

    return 0;
}