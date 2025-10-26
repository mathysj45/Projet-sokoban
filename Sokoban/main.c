#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "functions.h"


int main()
{
    srand(time(NULL));

    char **tab = init_tab();
    int xJ, yJ; // coordonnées Joueur
    int xB, yB; // coordonnées Boîte
    int xE, yE; // coordonnées Emplacement
    char direction; // direction de déplacement
    int coups = 0; // nombre de coups
    int resultat = -1;  // -1 = abandon, 0 = défaite, 1 = victoire

    randomizer(tab, joueur, &xJ, &yJ);
    randomizer(tab, caisse, &xB, &yB);
    randomizer(tab, emplacement, &xE, &yE);

    printf("Bienvenue dans Sokoban ! Le but ? Déplacer la boite (X) jusqu'à l'emplacement choisi (.) ! Bonne chance !\n");
    printf("Attention ! Si une boîte est coincée contre un mur (#), vous perdez la partie !\n");
    sleep(5);

    while (1)
    {
        system("clear");
        printf("\nCoordonnées :\n");
        printf("Joueur       : (%d, %d)\n", xJ, yJ);
        printf("Boîte        : (%d, %d)\n", xB, yB);
        printf("Emplacement  : (%d, %d)\n", xE, yE);
        printf("\n");
        print_tab(tab);

        if (verifier_victoire(tab))
            {
                printf("Félicitations ! Vous avez triomphez du Sokoban en %d coups !\n", coups);
                resultat = 1;
                break;
            }

        if (verifier_defaite(tab))
            {
                printf("Dommage ! Le Sokoban vous a terrassé !\n");
                resultat = 0;
                break;
            }

        printf("Pour vous déplacer, utilisez les touches 'z' (haut), 's' (bas), 'q' (gauche), 'd' (droite), pour quitter appuyer sur 'x' : \n");
        scanf("%c", &direction);

        if (direction == 'x')
        {
            printf("Partie abandonnée. Dommage !\n");
            resultat = -1;
            break;
        }

        if (deplacement(tab, &xJ, &yJ, direction))
        {
            coups++;
        }
        else
        {
            printf("Déplacement impossible. Essayez une autre direction.\n");
        }
    }
    save_game(tab, coups, resultat);
    liberer_tab(tab);
    exit(0);
}