#include <stdlib.h>
#include <time.h>
#include "functions.h"

void randomizer(char **tab, char symbole, int *x, int *y)
{
    do
    {
        *x = (rand() % (taille - 2)) + 1;   // entre 1 et taille-2
        *y = (rand() % (taille - 2)) + 1;   // évite les bords
    }
    while (tab[*x][*y] != vide);    // doit être une case vide

    tab[*x][*y] = symbole;
}