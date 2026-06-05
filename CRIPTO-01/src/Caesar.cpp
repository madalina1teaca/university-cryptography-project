#include "Caesar.h"
#include <cctype>

/*
=== Descriere ===
- criptează un text folosind 'Cifrul lui Caesar'
- algoritmul asociază fiecare literă cu poziția ei din alfabet - indexul (0-25)
- înlocuiște caracterle cu cele aflate la o distanță fixă - cheia
- formula matematică folosită: E(x): (x + k) mod 26
=== Parametrii și detalii tehnice ===
- text: textul introdus de utlizator
- key: numărul de poziții pentru deplasare ( valoare >= 0 și <= 25)
- return: std::string -> textul criptat format exclusiv din majuscule
*/

std::string caesarEncrypt(std::string text, int key) {  
    std::string result;

    for(char c : text)
    {
        if(isalpha(c)) // procesează doar caracterele alfabetice
        {
            c = toupper(c); // standardizare la majuscule

            int x = c - 'A';          // conversia caracter -> index 
            int y = (x + key) % 26;   // aplicarea formulei de criptare

            result += char(y + 'A');  // conversie index -> caracter
        }
        else
        {
            result += c; // păstrarea intactă a caracterelor speciale și a spațiilor
        }
    }

    return result;
}

/*
=== Descriere ===
- decriptarea unui text criptat cu 'Cifrul lui Caesar'
- se aplică formula inversă: D(y) = (y - k + 26) mod 26
=== Obs ===
- adunarea cu 26 previne obținerea unui rezultat negativ înainte de modulo
*/
std::string caesarDecrypt(std::string text, int key) {  
    std::string result;

    for(char c : text)
    {
        if(isalpha(c))
        {
            c = toupper(c);
            
            int y = c - 'A';
            int x = (y - key + 26) % 26; // reface indexul original

            result += char(x + 'A');
        }
        else
        {
            result += c;
        }
    }

    return result;
}