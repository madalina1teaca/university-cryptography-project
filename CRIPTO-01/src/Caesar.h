#ifndef CAESAR_H
#define CAESAR_H

#include <string>

// declararea funcțiilor utilizate pentru criptare și decriptare folosind algoritmul Caesar.

// criptarea textului folosind o cheie dată
std::string caesarEncrypt(std::string text, int key);
// decriptarea textului folosind aceeași cheie
std::string caesarDecrypt(std::string text, int key);

#endif // CAESAR_H