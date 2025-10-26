#include <stdlib.h>
#include <stdio.h>
#include "functions.h"


int verifier_victoire(char **tab)
{
    for (int i = 0; i < taille; i++) 
    {
        for (int j = 0; j < taille; j++) 
        {
            if (tab[i][j] == emplacement) 
            {
                return 0;  // Il reste des emplacements vide
            }
        }
    }
    return 1;  // Toutes les caisses sont sur les emplacements
}

int verifier_defaite(char **tab)
{
    for (int i = 0; i < taille; i++) 
    {
        for (int j = 0; j < taille; j++) 
        {
            if (tab[i][j] == caisse) 
            {
                // Vérifier si la caisse est adjacente à un mur
                if (tab[i-1][j] == '#' || tab[i+1][j] == '#' || tab[i][j-1] == '#' || tab[i][j+1] == '#') 
                {
                    return 1;  // Défaite : caisse contre un mur
                }
            }
        }
    }
    return 0;  // Pas de défaite
}