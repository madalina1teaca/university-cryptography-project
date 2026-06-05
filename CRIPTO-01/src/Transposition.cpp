#include "Transposition.h"
#include <cctype>

/*
 * Metoda transpozitiei nu schimba literele,
 * ci doar pozitia acestora in mesaj.
 *
 * Textul este scris pe linii, intr-un tabel
 * cu un numar fix de coloane, apoi este citit
 * pe coloane.
 */
std::string transpositionEncrypt(std::string text, int columns)
{
    std::string cleanText;
    std::string result;

    for(char c : text)
    {
        if(isalpha(c))
            cleanText += toupper(c);
    }

    int length = cleanText.length();

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
 * Decriptarea reface ordinea initiala a literelor,
 * reconstruind tabelul folosit la criptare.
 */
std::string transpositionDecrypt(std::string text, int columns)
{
    int length = text.length();
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