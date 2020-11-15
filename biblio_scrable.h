//
// Created by Romain on 09/10/2020.
//

#ifndef SCRABLE_PROJET_BIBLIO_SCRABLE_H
#define SCRABLE_PROJET_BIBLIO_SCRABLE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<fcntl.h>

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
void afficheMots(char**tab,int numJoueur);
void initialiseGrille(char tGrille[2][DIM_GRILLE][DIM_GRILLE]);
int estDansLaGrille(char tGrille[2][DIM_GRILLE][DIM_GRILLE],int tCase[3],char*tMot);
void affichageTour(char tGrille[2][DIM_GRILLE][DIM_GRILLE],char**tJoueurs,char**tChevalets,int tCase[3],int tPioche[NB_CARAC][NB_COLONE],int numJoueur,char*tMot,int*pTotalPiece);
void ecrireDansLaGrille(char tGrille[2][DIM_GRILLE][DIM_GRILLE],int tCase[3],char*tMot);
int finDePartie(int totalPiece,char**tChevalets,int nbJouers);
int motvalide(char mot[26]);
#endif //SCRABLE_PROJET_BIBLIO_SCRABLE_H
