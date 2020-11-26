#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include "biblio_scrable.h"

int main() {
    //Initialisation
    srand(time(NULL));
    int debut=afficheMenu();
    if(debut==0){
        return 0;
    }
    int tPioche[NB_CARAC][NB_COLONE];
    int totalPiece=TOTAL_PIECE,nbJoueurs=0,JDebute=0,fin=0;
    int*pTotalPiece=&totalPiece;
    char tGrille[2][DIM_GRILLE][DIM_GRILLE];
    char**tJoueurs;
    char**tChevalet;
    initialiseGrille(tGrille);
    initialiseTab(tPioche);
    if(debut==1){
        printf("Combien de joueurs y'a t-il ?\n");
        do{
            scanf("%d",&nbJoueurs);
        }while(nbJoueurs<2 && nbJoueurs>4);
        printf("\n");
        JDebute=rand()%nbJoueurs;
        tJoueurs=allocJoueur(nbJoueurs);
        tChevalet=initialiseChevalets(tPioche,pTotalPiece,JDebute,nbJoueurs);
    }
    else{
        tJoueurs=recharge(tGrille,tJoueurs,&JDebute,0,tPioche,pTotalPiece);
        tChevalet=recharge2(tChevalet);
    }
    char*tMot=(char*)malloc(DIM_GRILLE*sizeof(char));
    int tCase[3]={7,7,chiffrage('H')};
    //Partie :
    printf("%s commence",tJoueurs[JDebute])
    while(fin!=1){//fin pas encore codé
        affichageTour(tGrille,tJoueurs,tChevalet,tCase,tPioche,JDebute,tMot,pTotalPiece);
        JDebute=(JDebute+1)%nbJoueurs;
        fin=finDePartie(totalPiece,tChevalets,nbJoueurs);
    }
    //QUI A  Gagné?
    //Libérations :
    liberationChar(tJoueurs,nbJoueurs);
    liberationChar(tChevalet,nbJoueurs);
    free(tMot);
    return 0;
}

//ajouter le score et estDans la Grille dans affichageTour