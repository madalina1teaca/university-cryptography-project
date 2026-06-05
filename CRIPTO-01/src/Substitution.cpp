#include "Substitution.h"
#include <cctype>

const std::string ALPHABET =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

const std::string SUBSTITUTE =
        "TEABCDFGHIJKLMNOPQRSUVWXYZ";

/*
 * Criptare prin substitutie monoalfabetica.
 */
std::string substitutionEncrypt(std::string text)
{
    std::string result;

    for(char c : text)
    {
        if(isalpha(c))
        {
            c = toupper(c);

            int pos = ALPHABET.find(c);

            result += SUBSTITUTE[pos];
        }
        else
        {
            result += c;
        }
    }

    return result;
}

/*
 * Decriptare prin substitutia inversa.
 */
std::string substitutionDecrypt(std::string text)
{
    std::string result;

    for(char c : text)
    {
        if(isalpha(c))
        {
            c = toupper(c);

            int pos = SUBSTITUTE.find(c);

            result += ALPHABET[pos];
        }
        else
        {
            result += c;
        }
    }

    return result;
}