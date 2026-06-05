#ifndef CRYPTOGF_H
#define CRYPTOGF_H

#include <string>

/*
Funcția realizează criptarea unui text folosind formula:
E(x) = ( a * x + b ) mod 26
*/

std::string encrypt(std::string text);

/*
Funcția realizează decriptarea unui text folosind funcția inversă:
D(y) = ( y - b ) mod 26
*/

std::string decrypt(std::string text);

#endif // CRYPTOGF_H