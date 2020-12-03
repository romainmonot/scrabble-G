#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include "biblio_scrable.h"

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
    initialiseTab(tPioche);
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
        tJoueurs=recharge(tGrille,tJoueurs,&JDebute,tPioche,pTotalPiece,pNbJoueurs);
        tChevalets=recharge2(tChevalets,tJoueurs,nbJoueurs);
        tPoints=recharge3(tPoints,tJoueurs,tChevalets,nbJoueurs);
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

//Utiisation du joker => faire en sorte que une lettre lui soit attribuer => minuscule
//Integrer le syts de points aux fonctions
//depiocher si mot n'existe pas => scinder en deux mot valide
//Cas de connexion sans lettre en commun
//Verifier que les connexions n'engendre pas de mot bizarre

//liste de mot & victoire non testé