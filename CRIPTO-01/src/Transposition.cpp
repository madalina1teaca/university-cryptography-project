#include "Transposition.h"
#include <cctype>

/*
=== Descriere ===
- criptează un text folosind transpoziția
- păstrează literele originale, dar le amestecă 
- textul este scris într-o matrice cu un număr dat de coloane
- este citit coloană cu coloană
 */
std::string transpositionEncrypt(std::string text, int columns)
{
    std::string cleanText;
    std::string result;

    // curățarea și standardizarea - păstrarea doar a literelor și tranfosrmarea lor în majuscule
    for(char c : text)
    {
        if(isalpha(c))
            cleanText += toupper(c);
    }

    int length = cleanText.length();

    // citirea pe coloane a matricei 
    for(int col = 0; col < columns; col++)
    {
        for(int i = col; i < length; i += columns)
        {
            result += cleanText[i];
        }
    }

    return result;
}


/*
=== Descriere ===
- decriptează textul prin reconstrucția matricei 
- calculează numărul de linii în funcție de lungime lextului și numărul de coloane
- restabilește ordinea inițial a caracterelor după liniile rezultate 
*/
std::string transpositionDecrypt(std::string text, int columns)
{
    int length = text.length();
    // determinarea numărului de rânduri prin rotunjire superioară
    int rows = (length + columns - 1) / columns;

    std::string result(length, ' ');
    int index = 0;

    for(int col = 0; col < columns; col++)
    {
        for(int row = 0; row < rows; row++)
        {
            int position = row * columns + col;

            if(position < length)
            {
                result[position] = text[index];
                index++;
            }
        }
    }

    return result;
}