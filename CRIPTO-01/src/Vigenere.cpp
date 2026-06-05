#include "Vigenere.h"
#include <cctype>

/*
 * Algoritmul Vigenere utilizeaza o cheie text.
 * Fiecare litera din cheie determina deplasarea
 * aplicata caracterului corespunzator din mesaj.
 */

std::string vigenereEncrypt(std::string text, std::string key)
{
    std::string result;
    int keyIndex = 0;

    for(char c : text)
    {
        if(isalpha(c))
        {
            c = toupper(c);

            int x = c - 'A';

            char k = toupper(key[keyIndex % key.length()]);
            int shift = k - 'A';

            int y = (x + shift) % 26;

            result += char(y + 'A');

            keyIndex++;
        }
        else
        {
            result += c;
        }
    }

    return result;
}

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