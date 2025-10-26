#include <stdio.h>
#include "functions.h"

int deplacement(char **tab, int *xJ, int *yJ, char direction)
{
    int newX = *xJ;
    int newY = *yJ;
    
    // Calcul de la nouvelle position selon la direction
    switch(direction) 
    {
        case 'z': newY--; break;  // Haut
        case 's': newY++; break;  // Bas
        case 'q': newX--; break;  // Gauche
        case 'd': newX++; break;  // Droite
        default: return 0;         // Direction invalide
    }
    
    // Vérification des murs
    if (tab[newY][newX] == '#') return 0;
    
    // Case vide : déplacement simple
    if (tab[newY][newX] == ' ' || tab[newY][newX] == emplacement) 
    {
        tab[*yJ][*xJ] = ' ';  // Ancienne position devient vide
        tab[newY][newX] = joueur;  // Nouvelle position
        *xJ = newX;
        *yJ = newY;
        return 1;
    }
    
    // Caisse à pousser
    if (tab[newY][newX] == caisse) 
    {
        int pushX = newX + (newX - *xJ);
        int pushY = newY + (newY - *yJ);
        
        // Vérifier si on peut pousser la caisse
        if (tab[pushY][pushX] == ' ' || tab[pushY][pushX] == emplacement) 
        {
            tab[*yJ][*xJ] = ' ';        // Ancienne position du joueur devient vide
            tab[newY][newX] = joueur;   // Joueur prend la place de la caisse
            tab[pushY][pushX] = caisse; // Caisse est poussée
            *xJ = newX;
            *yJ = newY;
            return 1;
        }
    }
    
    return 0;  // Déplacement impossible
}