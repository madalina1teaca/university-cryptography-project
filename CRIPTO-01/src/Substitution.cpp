#include "Substitution.h"
#include <cctype>

// alfabetul standard utilizat pentru maparea indexului (0-25)
const std::string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// alfabetul de substituție definit prin permutarea generată de cuvântul cheie
const std::string SUBSTITUTE = "TEABCDFGHIJKLMNOPQRSUVWXYZ";

/*
=== Descriere ===
- criptează un text prin folosiea substituției monoalfabetice simple
- se elimină ralația de ordine nativă
- fiecare literă este înlocuită cu litera ce se află pe același index în alfabetul 'SUBSTITUTE' 
*/
std::string substitutionEncrypt(std::string text)
{
    std::string result;

    for(char c : text)
    {
        if(isalpha(c))
        {
            c = toupper(c);
            int pos = ALPHABET.find(c); // găsește poziția nativă 
            result += SUBSTITUTE[pos];  // înlocuiește cu litera de pe aceeași poziție din noul alfabet
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
- decpritează textul criptat folosind substituția inversă
- inversează maparea căutând caracterul în alfabetul 'SUBSTITUTE' și recuperând caracterul din alfabetul standard
*/
std::string substitutionDecrypt(std::string text)
{
    std::string result;

    for(char c : text)
    {
        if(isalpha(c))
        {
            c = toupper(c);
            int pos = SUBSTITUTE.find(c); // identifică indexul în alfabetul criptat
            result += ALPHABET[pos];      // recuperează caracterul original
        }
        else
        {
            result += c;
        }
    }

    return result;
}