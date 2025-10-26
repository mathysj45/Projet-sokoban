#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void save_game(char **tab, int coups, int victoire)
{
    FILE *fichier = fopen("end.txt", "w");
    
    if (fichier == NULL) {
        printf("Erreur : impossible de créer le fichier end.txt\n");
        return;
    }
    
    // Écrire le résultat de la partie
    if (victoire == 1) {
        fprintf(fichier, "=== VICTOIRE ===\n");
        fprintf(fichier, "Nombre de coups : %d\n\n", coups);
    } else if (victoire == 0) {
        fprintf(fichier, "=== DEFAITE ===\n");
        fprintf(fichier, "Nombre de coups : %d\n\n", coups);
    } else {
        fprintf(fichier, "=== PARTIE ABANDONNEE ===\n");
        fprintf(fichier, "Nombre de coups : %d\n\n", coups);
    }
    
    // Écrire l'état du plateau
    fprintf(fichier, "Etat final du plateau :\n\n");
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            fprintf(fichier, "%c", tab[i][j]);
        }
        fprintf(fichier, "\n");
    }
    
    fclose(fichier);
    printf("Partie sauvegardée dans end.txt\n");
}