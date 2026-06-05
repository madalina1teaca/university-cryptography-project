#include "Vigenere.h"
#include <cctype>

/*
=== Descriere ===
- criptează un text folosind 'Algoritmul Vigenere'
- utilizează o cheie text
- fiecare literă din cheie determină deplasarea caracterului corespunzător din mesaj
- formula: c_j = (m_j + k_(j mod n)) mod 26
*/
std::string vigenereEncrypt(std::string text, std::string key)
{
    std::string result;
    int keyIndex = 0; // contorizează poziția din cheie, avansând doar la caractere valide

    for(char c : text)
    {
        if(isalpha(c))
        {
            c = toupper(c);
            int x = c - 'A';

            // determinarea caracterului corespunzător din cheie și a deplasării 
            char k = toupper(key[keyIndex % key.length()]);
            int shift = k - 'A';

            // criptarea 
            int y = (x + shift) % 26;
            result += char(y + 'A');

            keyIndex++; // indexul cheii avansează doar dacă a fost criptată o literă
        }
        else
        {
            result += c;
        }
    }

    return result;
}

/*
=== Descriere ===
- decrptează textul inversând deplasarea adusă de cheie
- formula: m_j = (c_j - k_(j mod n) + 26) mod 26
*/
std::string vigenereDecrypt(std::string text, std::string key)
{
    std::string result;
    int keyIndex = 0;

    for(char c : text)
    {
        if(isalpha(c))
        {
            c = toupper(c);
            int y = c - 'A';

            char k = toupper(key[keyIndex % key.length()]);
            int shift = k - 'A';

            int x = (y - shift + 26) % 26;
            result += char(x + 'A');

            keyIndex++;
        }
        else
        {
            result += c;
        }
    }

    return result;
}