#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

void print_tab(char **tab) 
{
    for (int i = 0; i < taille; i++) // Parcours des lignes
    {
        for (int j = 0; j < taille; j++) // Parcours des colonnes
            printf("%c", tab[i][j]);
        printf("\n");
    }
}
void liberer_tab(char **tab) 
{
    for (int i = 0; i < taille; i++)
        free(tab[i]);
    free(tab);
}