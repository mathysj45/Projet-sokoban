#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

void print_tab(char **tab) 
{
    for (int i = 0; i < taille; i++) 
    {
        for (int j = 0; j < taille; j++)
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