#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "functions.h"

char **init_tab() 
{
    char **tab = malloc(taille * sizeof(char *));
    if (!tab) exit(EXIT_FAILURE);  // Si l'allocation échoue met fin au programme

    for (int i = 0; i < taille; i++) 
    {
        tab[i] = malloc(taille * sizeof(char));
        if (!tab[i]) exit(EXIT_FAILURE); 

        for (int j = 0; j < taille; j++) 
        {
            if (i == 0 || i == taille - 1 || j == 0 || j == taille - 1)
                tab[i][j] = '#';     // murs
            else
                tab[i][j] = ' ';     // zone jouable
        }
    }
    return tab;
}