#include "Mixed.h"
#include "Substitution.h"
#include "Transposition.h"

/*
 * Sistem mixt de criptare.
 *
 * Se aplica doua metode succesiv:
 * 1. substitutia monoalfabetica;
 * 2. transpozitia.
 */
std::string mixedEncrypt(std::string text, int columns)
{
    std::string substituted = substitutionEncrypt(text);
    std::string encrypted = transpositionEncrypt(substituted, columns);

    return encrypted;
}

/*
 * Decriptarea se face in ordine inversa:
 * 1. se inverseaza transpozitia;
 * 2. se inverseaza substitutia.
 */
std::string mixedDecrypt(std::string text, int columns)
{
    std::string transposedBack = transpositionDecrypt(text, columns);
    std::string decrypted = substitutionDecrypt(transposedBack);

    return decrypted;
}