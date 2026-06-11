#ifndef CRYPTOGF_H
#define CRYPTOGF_H

#include <string>
#include <vector>
#include <tuple>

// === normalizare text ===
std::string normalizeText(std::string text);

// construiește și inițializează Corpul Galois GF(27)
void buildGF27();

// === criptarea și decriptarea ====
// formulă criptare: y_i = a_i * x_i + b_i
std::string encryptGF(std::string text);
// formulă decriptare: x_i = a_i^(-1) * (y_i - b_i)
std::string decryptGF(std::string text);

// === printarea ===
// afișează tabela cu operațiile prntru GF(27)
void printGFTable();
// afișează secvența de chei generată sau utilizată în procesul curent
void printKeySequence();

#endif // CRYPTOGF_H