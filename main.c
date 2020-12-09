#include <time.h>
#include "Macros et include.h"
#include "Sauvegarde.h"
#include "Fin de partie .h"
#include "Synthese.h"
#include "Initialisation.h"
#include "Fonctions de base .h"

int main() {
    // Initialisation
    srand(time(NULL));
    int debut=afficheMenu();
    if(debut==0){
        return 0;
    }
    int tPioche[NB_CARAC][NB_COLONE];
    int totalPiece=TOTAL_PIECE,nbJoueurs=0,JDebute=0,fin=0;
    int*pTotalPiece=&totalPiece;
    int*pNbJoueurs=&nbJoueurs;
    char tGrille[2][DIM_GRILLE][DIM_GRILLE];
    int*tPoints;
    char**tJoueurs;
    char**tChevalets;
    initialiseGrille(tGrille);
    initialisePioche(tPioche);
    if(debut==1){
        printf("Combien de joueurs y'a t-il ?\n");
        do{
            scanf("%d",&nbJoueurs);
        }while(nbJoueurs<2 && nbJoueurs>4);
        printf("\n");
        JDebute=rand()%nbJoueurs;
        tJoueurs=allocJoueur(nbJoueurs);
        tChevalets=initialiseChevalets(tPioche,pTotalPiece,JDebute,nbJoueurs);
        tPoints=(int*)calloc(nbJoueurs,sizeof(int));
    }
    else{
        tJoueurs=rechargeJoueurs(tGrille,tJoueurs,&JDebute,tPioche,pTotalPiece,pNbJoueurs);
        tChevalets=rechargeChevalets(tChevalets,tJoueurs,nbJoueurs);
        tPoints=rechargePoints(tPoints,tJoueurs,tChevalets,nbJoueurs);
        }
    char*tMot=(char*)malloc(DIM_GRILLE*sizeof(char));
    int tCase[3]={7,7,0};
    tCase[2]=chiffrage('H');
    // Partie
    printf("%s commence\n",tJoueurs[JDebute]);
    while(fin==0){
        affichageTour(tGrille,tJoueurs,tChevalets,tCase,tPioche,JDebute,tMot,pTotalPiece,tPoints,nbJoueurs);
        JDebute=(JDebute+1)%nbJoueurs;
        fin=finDePartie(totalPiece,tChevalets,nbJoueurs,tPoints,tPioche);
    }
    victoire(tPoints,tJoueurs,nbJoueurs);
    // Liberation
    liberationChar(tJoueurs,nbJoueurs);
    liberationChar(tChevalets,nbJoueurs);
    free(tMot);
    free(tPoints);
    return 0;
}