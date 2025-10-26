#include <stdlib.h>
#include <time.h>
#include "functions.h"

void randomizer(char **tab, char symbole, int *x, int *y)
{
    if (symbole == caisse)  // pour les caisses, éviter les positions adjacentes aux murs
    {
        *x = (rand() % (taille - 4)) + 2;   
        *y = (rand() % (taille - 4)) + 2;   
    }
    else
    {
        *x = (rand() % (taille - 2)) + 1;   // entre 1 et taille-2
        *y = (rand() % (taille - 2)) + 1;   // évite les bords
    }
    
    while (tab[*x][*y] != vide);    // doit être une case vide

    tab[*x][*y] = symbole;
}