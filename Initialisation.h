#ifndef SCRABLE_PROJET_INITIALISATION_H
#define SCRABLE_PROJET_INITIALISATION_H

#include "Macros et include.h"
#include "Fonctions de base .h"

int afficheMenu();
void initialisePioche(int tPioche[NB_CARAC][NB_COLONE]);
char**initialiseChevalets(int tPioche[NB_CARAC][NB_COLONE],int*pTotalPiece,int JDebute,int nbJoueurs);
char** allocJoueur(int nbJoueurs);
void initialiseGrille(char tGrille[2][DIM_GRILLE][DIM_GRILLE]);

#endif //SCRABLE_PROJET_INITIALISATION_H
