#include <stdio.h>
#include <string.h>
#include "citation.h"

#define MAX_WIDTH_DEFAULT 40
#define BORDER_CHAR '-'
#define VERTICAL_CHAR '|'
#define SPACE_CHAR ' '

void affiche_bordure(int width) {

    for (int i = 0; i < width + 4; i++) {
        putchar(BORDER_CHAR);
    }
    putchar('\n');
}

void affiche_citation(char* quote) {

    // Déterminer la longueur de la bulle de texte et le nombre de lignes
    int len = strlen(quote);
    int width = len < MAX_WIDTH_DEFAULT ? len : MAX_WIDTH_DEFAULT;
    int lineCount = (len / width) + 1;
    int indexInQuote = 0;

    // Imprimer le haut de la bulle de texte
    affiche_bordure(width);

    // Imprimer le corps de la citation
    for (int i = 0; i < lineCount; i++) {

        putchar(VERTICAL_CHAR);
        putchar(SPACE_CHAR);

        for (int j = 0; j < width; j++) {
            indexInQuote = i * width + j;
            if (indexInQuote < len) {
                putchar(quote[indexInQuote]);
            } else {
                putchar(SPACE_CHAR);
            }
        }

        putchar(SPACE_CHAR);
        putchar(VERTICAL_CHAR);
        putchar('\n');
    }

    // Imprimer le bas de la bulle de texte
    affiche_bordure(width);
}