#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__
#define taille 10
#define joueur 'o'
#define caisse 'X'
#define emplacement '.'
#define vide ' '
void print_tab(char **tab);
void liberer_tab(char **tab);
char **init_tab();
void randomizer(char **tab, char symbole, int *x, int *y);
int deplacement(char **tab, int *xJ, int *yJ, char direction);
int verifier_victoire(char **tab);
int verifier_defaite(char **tab);
#endif