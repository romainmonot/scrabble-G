#ifndef SCRABLE_PROJET_FONCTIONS_DE_BASE_H
#define SCRABLE_PROJET_FONCTIONS_DE_BASE_H

#include "Macros et include.h"

char** allocDynamique2D(int longeur,int larg);
void liberationChar(char** tTab, int longeur);
char lettrage(int numLettre);
int chiffrage(char lettreNum);
char pioche(int tPioche[NB_CARAC][NB_COLONE],int*pTotalPiece);
void ecrireDansLaGrille(char tGrille[2][DIM_GRILLE][DIM_GRILLE],int tCase[3],char*tMot);
void affichageGrille(char tGrille[2][DIM_GRILLE][DIM_GRILLE]);
int scoreMot(char*tMot, char tGrille[2][DIM_GRILLE][DIM_GRILLE], int tPioche[NB_CARAC][NB_COLONE],int tCase[3],int*listPosMot);
char*joker(char*tMot);
void changerNPiece(char**tChevalet,int tPioche[NB_CARAC][NB_COLONE],int*pTotalPiece,int numJoueur);
int repioche (int* listepositions,int tPioche[NB_CARAC][NB_COLONE],int* pTotalPiece,char* tChevaletJoueur);

#endif //SCRABLE_PROJET_FONCTIONS_DE_BASE_H
