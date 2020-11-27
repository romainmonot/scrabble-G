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
    int*tPoints;
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
        tPoints=(int*)calloc(nbJoueurs,sizeof(int));
    }
    else{
        tJoueurs=recharge(tGrille,tJoueurs,&JDebute,0,tPioche,pTotalPiece);
        tChevalet=recharge2(tChevalet);
        tPoints=recharge3(tPoints);
    }
    char*tMot=(char*)malloc(DIM_GRILLE*sizeof(char));
    int tCase[3]={7,7,0};
    tCase[2]=chiffrage('H');
    /*Tests
    affichageTour(tGrille,tJoueurs,tChevalet,tCase,tPioche,1,tMot,pTotalPiece,tPoints);
    affichageTour(tGrille,tJoueurs,tChevalet,tCase,tPioche,0,tMot,pTotalPiece,tPoints);
*/
    // Partie
    printf("%s commence",tJoueurs[JDebute]);
    while(fin!=1){
        affichageTour(tGrille,tJoueurs,tChevalet,tCase,tPioche,JDebute,tMot,pTotalPiece);
        JDebute=(JDebute+1)%nbJoueurs;
        fin=finDePartie(totalPiece,tChevalet,nbJoueurs);
    }
    //QUI A  Gagné?
    liberationChar(tJoueurs,nbJoueurs);
    liberationChar(tChevalet,nbJoueurs);
    free(tMot);
    free(tPoints);
    return 0;
}


//ajouter estDansGrille dans affichageTour
//mot valide tiend en compte la grille
//free si erreur de charge/sauvegarde