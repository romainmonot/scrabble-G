#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include<fcntl.h>
#include "biblio_scrable.h"

#define LONGEUR 50

//Pour les  tests
void afficheTab2D2(char**tab, int numLongeur, int larg){
    for (int j = 0; j < larg-1; j++) {
        printf("%c,",tab[numLongeur][j]);
    }
    printf("%c\n",tab[numLongeur][larg-1]);
}

int main() {
    //Initialisation
    srand(time(NULL));
    printf("1");
    int debut = afficheMenu();
    if(debut==0){
        return 0;
    }
    int tPioche[NB_CARAC][NB_COLONE];
    initialiseTab(tPioche);
    int totalPiece=TOTAL_PIECE,nbJoueurs=0,JDebute=0;
    int*pTotalPiece=&totalPiece;
    printf("Combien de joueurs y'a t-il ?\n");
    do {
        scanf("%d",&nbJoueurs);
    }while (nbJoueurs<2 && nbJoueurs>4);
    printf("\n");
    JDebute=rand()%nbJoueurs;
    char tGrille[2][DIM_GRILLE][DIM_GRILLE];
    initialiseGrille(tGrille);
    int tCase[3]={0,0,0};
    char**tJoueurs=allocJoueur(nbJoueurs);
    char**tChevalet=initialiseChevalets(tPioche,pTotalPiece,JDebute,nbJoueurs);
    char*tMot=(char*)malloc(DIM_GRILLE*sizeof(char));
    printf("%s commence",tJoueurs[JDebute])
    while (fin!=1) {
        affichageTour(tGrille,tJoueurs,tChevalet,tCase,tPioche,JDebute,tMot,pTotalPiece);
        JDebute=(JDebute+1)%nbJoueurs;
    }
    liberationChar(tJoueurs,nbJoueurs);
    liberationChar(tChevalet,nbJoueurs);
    free(tMot);
    return 0;
}

//ajouter le score et estDans la Grille dans affichageTour