#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "functions.h"


int main()
{
    srand(time(NULL));

    char **tab = init_tab();
    int xJ, yJ; // Joueur
    int xB, yB; // Boîte
    int xE, yE; // Emplacement

    randomizer(tab, joueur, &xJ, &yJ);
    randomizer(tab, caisse, &xB, &yB);
    randomizer(tab, emplacement, &xE, &yE);

    printf("\nCoordonnées :\n");
    printf("Joueur       : (%d, %d)\n", xJ, yJ);
    printf("Boîte        : (%d, %d)\n", xB, yB);
    printf("Emplacement  : (%d, %d)\n", xE, yE);

    print_tab(tab);
    liberer_tab(tab);
    exit(0);
}