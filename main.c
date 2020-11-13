#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include "biblio_scrable.h"

int main() {
    //Initialisation
    srand(time(NULL));
    int debut = afficheMenu();
    if(debut==0){
        return 0;
    }
    int tPioche[NB_CARAC][NB_COLONE];
    int totalPiece=TOTAL_PIECE,nbJoueurs=0,JDebute=0;
    int*pTotalPiece=&totalPiece;
    char tGrille[2][DIM_GRILLE][DIM_GRILLE];
    char**tJoueurs;
    char**tChevalet;
    if(debut==1){
        initialiseTab(tPioche);
        printf("Combien de joueurs y'a t-il ?\n");
        do {
            scanf("%d",&nbJoueurs);
        }while (nbJoueurs<2 && nbJoueurs>4);
        printf("\n");
        JDebute=rand()%nbJoueurs;
        initialiseGrille(tGrille);
        tJoueurs=allocJoueur(nbJoueurs);
        tChevalet=initialiseChevalets(tPioche,pTotalPiece,JDebute,nbJoueurs);
    }
    else if(debut==2){
        //Fonction charger la partie
    }
    char*tMot=(char*)malloc(DIM_GRILLE*sizeof(char));
    int tCase[3]={0,0,0};
    //Partie :
    printf("%s commence",tJoueurs[JDebute])
    while (fin!=1) {//fin pas encore codé
        affichageTour(tGrille,tJoueurs,tChevalet,tCase,tPioche,JDebute,tMot,pTotalPiece);
        JDebute=(JDebute+1)%nbJoueurs;
    }
    //Libérations :
    liberationChar(tJoueurs,nbJoueurs);
    liberationChar(tChevalet,nbJoueurs);
    free(tMot);
    return 0;
}

//ajouter le score et estDans la Grille dans affichageTour