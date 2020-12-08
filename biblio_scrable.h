//
// Created by Romain on 09/10/2020.
//

#ifndef SCRABLE_PROJET_BIBLIO_SCRABLE_H
#define SCRABLE_PROJET_BIBLIO_SCRABLE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<fcntl.h>
#include <ctype.h>
#include <unistd.h>

#define NB_CARAC 27
#define NB_COLONE 2
#define TOTAL_PIECE 102
#define NB_PIECE_MAIN 7
#define DIM_GRILLE 15
#define LONGEUR_PSEUDO 50
#define nb_mots 22740

char** allocDynamique2D(int longeur,int larg);
void initialiseTab(int tTab[NB_CARAC][NB_COLONE]);
char lettrage(int numLettre);
int chiffrage(char lettreNum);
char pioche(int tTab[NB_CARAC][NB_COLONE],int*pTotalPiece);
char**initialiseChevalets(int tPioche[NB_CARAC][NB_COLONE],int*pTotalPiece,int JDebute,int nbJoueurs);
void changerNPiece(char**tChevalet,int tPioche[NB_CARAC][NB_COLONE],int*pTotalPiece,int numJoueur);
void liberationChar(char** tTab, int longeur);
int afficheMenu();
char** allocJoueur(int nbJoueurs);
void initialiseGrille(char tGrille[2][DIM_GRILLE][DIM_GRILLE]);
int estDansLaGrille(char tGrille[2][DIM_GRILLE][DIM_GRILLE],int tCase[3],char*tMot);
void ecrireDansLaGrille(char tGrille[2][DIM_GRILLE][DIM_GRILLE],int tCase[3],char*tMot);
int finDePartie(int totalPiece,char**tChevalets,int nbJoueurs,int*tPoints,int tPioche[NB_CARAC][NB_COLONE]);
void sauvegarde( char**tChevalets,char tGrille[2][DIM_GRILLE][DIM_GRILLE],char** tJoueurs,int JDebute,int*tPoints,int tPioche[NB_CARAC][NB_COLONE],int totalPiece,int nbJoueurs,char*tMot);
char**recharge(char tGrille[2][DIM_GRILLE][DIM_GRILLE],char** tJoueurs,int*pJDebute,int tPioche[NB_CARAC][NB_COLONE],int*pTotalPiece,int*pNbJoueurs);
char**recharge2(char**tChevalets,char**tJoueurs,int nbJoueurs);
int*recharge3(int*tPoints,char**tJoueurs,char**tChevalets,int nbJoueurs);
int motexiste(char mot[27]);
int*lettredansmot(char c,char listedelettre[7],int listedespositions[7],int*k,char tGrille[2][DIM_GRILLE][DIM_GRILLE],int tCase[3],int*kbis);
int*motvalide(char mot[15],char listedelettres[7],char tGrille[2][DIM_GRILLE][DIM_GRILLE],int tCase[3],int*valide);
int*motvalide2(char mot[15],char listedelettres[7],char tGrille[2][DIM_GRILLE][DIM_GRILLE],int tCase[3]);
void minuscule(char mot[15]);
int litige(int numJoueur,int numAccusateur,int*tPoints,int res,char**tJoueurs);
void victoire(int*tPoints,char**tJoueurs,int nbJoueurs);
int repioche (int* listepositions,int tPioche[NB_CARAC][NB_COLONE],int* pTotalPiece,char* listedelettres);
char*joker(char*tMot);
int scoreMot(char*mot, char tGrille[2][DIM_GRILLE][DIM_GRILLE], int tTab[NB_CARAC][NB_COLONE],int tCase[3],int*listPosMot);
char**listeDeMots(char tGrille[2][DIM_GRILLE][DIM_GRILLE],int tCase[3],int*listedespositions,char*tMot,int*pLenList);
int* testValidite(char*tMot,char*tChevalet,char tGrille[2][DIM_GRILLE][DIM_GRILLE],int tCase[3],int*pRes,int*point,int tPioche[NB_CARAC][NB_COLONE]);
void affichageTour(char tGrille[2][DIM_GRILLE][DIM_GRILLE],char**tJoueurs,char**tChevalets,int tCase[3],int tPioche[NB_CARAC][NB_COLONE],int numJoueur,char*tMot,int*pTotalPiece,int*tPoints,int nbJoueurs);
#endif //SCRABLE_PROJET_BIBLIO_SCRABLE_H