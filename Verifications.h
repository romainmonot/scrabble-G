#ifndef SCRABLE_PROJET_VERIFICATIONS_H
#define SCRABLE_PROJET_VERIFICATIONS_H

#include "Fonctions de base .h"
#include "Macros et include.h"

int estDansLaGrille(char tGrille[2][DIM_GRILLE][DIM_GRILLE],int tCase[3],char*tMot);
int motexiste(char tMot[NB_CARAC]);
int*lettredansmot(char c,char tChevaletJoueur[NB_PIECE_MAIN],int tListPosChev[NB_PIECE_MAIN],int*pK,char tGrille[2][DIM_GRILLE][DIM_GRILLE],int tCase[3],int*pKbis);
int*motvalide(char tMot[DIM_GRILLE],char tChevaletJoueur[NB_PIECE_MAIN],char tGrille[2][DIM_GRILLE][DIM_GRILLE],int tCase[3],int*pValide) ;
int*listPosChev(char tMot[DIM_GRILLE],char tChevaletJoueur[NB_PIECE_MAIN],char tGrille[2][DIM_GRILLE][DIM_GRILLE],int tCase[3]);
void minuscule(char tMot[DIM_GRILLE]);
char**listeDeMots(char tGrille[2][DIM_GRILLE][DIM_GRILLE],int tCase[3],int*tListPosMot,char*tMot,int*pLenList);
int* testValidite(char*tMot,char*tChevalet,char tGrille[2][DIM_GRILLE][DIM_GRILLE],int tCase[3],int*pRes,int*pPoint,int tPioche[NB_CARAC][NB_COLONE]);
int litige(int numJoueur,int numAccusateur,int*tPoints,int res,char**tJoueurs);

#endif //SCRABLE_PROJET_VERIFICATIONS_H
