#include "Caesar.h"
#include <cctype>

/*
====CRIPTAREA====
se realizează. prin deplasarea fiecărei litere din alfabet
cu un număr fix de poziții - cheia.
*/ 
std::string caesarEncrypt(std::string text, int key) {  

    std::string result;

    for(char c : text)
    {
        if(isalpha(c))
        {
            c = toupper(c);

            int x = c - 'A';
            int y = (x + key) % 26;

            result  += char(y + 'A');
        }
        else
        {
            result += c;
        }
    }

    return result;
}

/*
====DECRIPTAREA====
se realizează prin deplasarea inversă cu aceeași cheie
*/
std::string caesarDecrypt(std::string text, int key) {  

    std::string result;

    for(char c : text)
    {
        if(isalpha(c))
        {
            c = toupper(c);
            
            int y = c - 'A';
            int x = (y - key + 26) % 26;

            result  += char(x + 'A');
    
        }
        else
        {
            result += c;
        }
    }

    return result;

}