#include "Mixed.h"
#include "Substitution.h"
#include "Transposition.h"

/*
=== Descriere ===
- combină două tehnici suuccesive: confuzia și difuzia 
- 1. substutuția
- 2. transpoziția
*/
std::string mixedEncrypt(std::string text, int columns)
{
    // aplică transformarea de substituție a caracterelor
    std::string substituted = substitutionEncrypt(text);
    // execută rearanjarea geometrică a pozițiilor
    std::string encrypted = transpositionEncrypt(substituted, columns);

    return encrypted;
}

/*
=== Descriere ===
- decriptarea se face în ordinea inversă criptării
- 1. transpoziția
- 2. substituția
*/
std::string mixedDecrypt(std::string text, int columns)
{
    std::string transposedBack = transpositionDecrypt(text, columns);
    std::string decrypted = substitutionDecrypt(transposedBack);

    return decrypted;
}