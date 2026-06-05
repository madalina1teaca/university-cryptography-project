#include "CryptoGF.h"
#include <cctype>

/*
Parametrii calculați pentru cerință:
PRENUME:    Mădălina-Elena
NUME:       Teacă
=> a = 1    b = 9
*/

const int a = 1;
const int b = 9;

/*
Funcția de criptare:
fiecare literă este transformată într-un număr între 0 și 25 după care se aplică formula
*/
std::string encrypt(std::string text)
{
    std::string result;

    for(char c : text)
    {
        if(isalpha(c))
        {
            // transformarea în litere mari
            c = toupper(c);

            // conversia literă -> poziția din alfabet (index)
            int x = c - 'A';

            // aplicarea funcției de criptare
            int y = (a * x + b) % 26;

            // conversia index -> literă
            result += char(y + 'A');
        }
        else
        {
            // păstrarea caracterelor speciale
            result += c;
        }
    }

    return result;
}


/*
Funcția de decriptare:
se aplică funcția inversă pentru a obține textul original
*/
std::string decrypt(std::string text)
{
    std::string result;

    for(char c : text)
    {
        if(isalpha(c))
        {
            // conversia literă criptată -> index
            int y = c - 'A';

            // aplicarea funcției inverse
            int x = (y - b + 26) % 26;

            // conversia index -> literă
            result += char(x + 'A');
        }
        else
        {
            // păstrarea caracterelor speciale
            result += c;
        }
    }
    return result;
}