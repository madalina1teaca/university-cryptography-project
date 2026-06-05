#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>

// criptarea folosind algortimul Vigenre
std::string vigenereEncrypt(std::string text, std::string key);
// decriptarea folosind algoritmul Vigenere
std::string vigenereDecrypt(std::string text, std::string key);

#endif // VIGENERE_H    