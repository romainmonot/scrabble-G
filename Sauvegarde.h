#ifndef SCRABLE_PROJET_SAUVEGARDE_H
#define SCRABLE_PROJET_SAUVEGARDE_H

#include "Macros et include.h"
#include "Fonctions de base .h"

void sauvegarde(char**tChevalets,char tGrille[2][DIM_GRILLE][DIM_GRILLE],char**tJoueurs,int JDebute,int*tPoints,int tPioche[NB_CARAC][NB_COLONE],int totalPiece,int nbJoueurs,char*tMot);
char**rechargeJoueurs(char tGrille[2][DIM_GRILLE][DIM_GRILLE],char** tJoueurs,int*pJDebute,int tPioche[NB_CARAC][NB_COLONE],int*pTotalPiece,int*pNbJoueurs);
char**rechargeChevalets(char**tChevalets,char**tJoueurs,int nbJoueurs);
int*rechargePoints(int*tPoints,char**tJoueurs,char**tChevalets,int nbJoueurs);

#endif //SCRABLE_PROJET_SAUVEGARDE_H
