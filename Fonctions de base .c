#include "Fonctions de base .h"

char** allocDynamique2D(int longeur,int larg){
    char** tTab=(char**)malloc(longeur*larg*sizeof(char));
    for (int i=0; i<longeur; i++){
        tTab[i]=(char*)malloc(larg*sizeof(char));
    }
    return tTab;
}

void liberationChar(char** tTab, int longeur){
    for (int i=0; i<longeur; i++){
        free(tTab[i]);
    }
    free(tTab);
}

char lettrage(int numLettre){//Permet de passer de l'indice d'une lette (A=0) à la dite lettre
    if(numLettre==26){
        return '?';
    }
    return numLettre+65;
}

int chiffrage(char lettreNum){//Permet de passer d'une lette à son indice (A=0)
    if(lettreNum=='?'){
        return 26;
    }
    return lettreNum-65;
}

char pioche(int tPioche[NB_CARAC][NB_COLONE],int*pTotalPiece){
    if(*pTotalPiece==0){
        return '0';
    }
    int numPiece=0,numLettre=0,totLoc=0;
    numPiece=rand()%*pTotalPiece;//Tire un numéro de pièce (pas de lettre) aléatiore
    do {//Cette boucle détermine la lettre correspondante au numéro de pièce tiré
        totLoc+=tPioche[numLettre][0];
        numLettre+=1;
    } while(totLoc<numPiece);
    numLettre-=1;
    tPioche[numLettre][0]-=1;
    *pTotalPiece-=1;
    return lettrage(numLettre);
}

void ecrireDansLaGrille(char tGrille[2][DIM_GRILLE][DIM_GRILLE],int tCase[3],char*tMot){
    int i=0;
    if(tCase[2]==chiffrage('H')){
        for(i=0;i<strlen(tMot);i++){
            tGrille[1][tCase[0]][tCase[1]+i]=tMot[i];
        }
    }
    else{
        for(i=0;i<strlen(tMot);i++){
            tGrille[1][tCase[0]+i][tCase[1]]=tMot[i];
        }
    }
}

void affichageGrille(char tGrille[2][DIM_GRILLE][DIM_GRILLE]){
    int i=0,j=0;
    printf("\n   A  B  C  D  E  F  G  H  I  J  K  L  M  N  O\n");
    for(i=0;i<10;i++){
        printf("%d |",i);
        for(j=0;j<DIM_GRILLE;j++){
            printf("%c%c|",tGrille[0][i][j],tGrille[1][i][j]);
        }
        printf("\n");
    }
    for(i=10;i<DIM_GRILLE;i++){
        printf("%d|",i);
        for(j=0;j<DIM_GRILLE;j++){
            printf("%c%c|",tGrille[0][i][j],tGrille[1][i][j]);
        }
        printf("\n");
    }
}

int scoreMot(char*tMot, char tGrille[2][DIM_GRILLE][DIM_GRILLE], int tPioche[NB_CARAC][NB_COLONE],int tCase[3],int*listPosMot) {
    int score = 0, i = 0, n = 0, lettre = 0,compteur=0;
    if (tCase[2] == chiffrage('H')) {
        for (i = 0; i < strlen(tMot); i++) {
            if (tMot[i] > 96 && tMot[i] < 123) {
                n = 26;
            } else {
                n = chiffrage(tMot[i]);
            }
            if (i == listPosMot[compteur]){
                compteur+=1;
                if (tGrille[0][tCase[0]][tCase[1] + i] == '&') {
                    lettre = tPioche[n][1] * 2;
                } else if (tGrille[1][tCase[0]][tCase[1] + i] == '%') {
                    lettre = tPioche[n][1] * 3;
                } else {
                    lettre = tPioche[n][1];
                }
            } else {
                lettre = tPioche[n][1];
            }
            score += lettre;
        }
    } else {
        for (i = 0; i < strlen(tMot); i++) {
            if (tMot[i] > 96 && tMot[i] < 123) {
                n = 26;
            } else {
                n = chiffrage(tMot[i]);
            }
            if (i == listPosMot[compteur]) {
                compteur += 1;
                if (tGrille[0][tCase[0] + i][tCase[1]] == '&') {
                    lettre = tPioche[n][1] * 2;
                } else if (tGrille[0][tCase[0] + i][tCase[1]] == '%') {
                    lettre = tPioche[n][1] * 3;
                } else {
                    lettre = tPioche[n][1];
                }
            }else {
                lettre = tPioche[n][1];
            }
            score += lettre;
        }
    }
    compteur=0;
    if (tCase[2] == chiffrage('H')) {
        for (i = 0; i < strlen(tMot); i++) {
            if (i == listPosMot[compteur]) {
                compteur += 1;
                if (tGrille[0][tCase[0]][tCase[1] + i] == '@') {
                    score *= 2;
                } else if (tGrille[1][tCase[0]][tCase[1] + i] == '$') {
                    score *= 3;
                }
            }
        }
    } else {
        for (i = 0; i < strlen(tMot); i++) {
            if (i == listPosMot[compteur]) {
                compteur += 1;
                if (tGrille[0][tCase[0] + i][tCase[1]] == '@') {
                    score *= 2;
                } else if (tGrille[0][tCase[0] + i][tCase[1]] == '$') {
                    score *= 3;
                }
            }
        }
    }
    return score;
}

char*joker(char*tMot){
    int entier=0, indice=0,compteur=0;
    char lettre='0';
    char tab[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for(entier=0;entier<strlen(tMot);entier++){
        if(tMot[entier]=='?'){
            do{
                printf("Quelle lettre voulez-vous attribuer a votre joker ? (ecrire en minuscule)\n");
                scanf(" %c", &lettre);
                for(indice=0; indice<26; indice++){
                    if (lettre==tab[indice]){
                        compteur+=1;
                    }
                }
                if(compteur!=1) {
                    printf("Cette lettre n'est pas valide. Recommencez !\n");
                }
            }while(compteur!=1);
            tMot[entier]=lettre;
        }
    }
    return tMot;
}

void changerNPiece(char**tChevalet,int tPioche[NB_CARAC][NB_COLONE],int*pTotalPiece,int numJoueur){
    int i =0,j=0,nbPiece=0,numPiece=0;
    char lettre='R';
    printf("Combien de pièce voulez vous changer ?\n");
    do{scanf("%d",&nbPiece);}while(nbPiece>NB_PIECE_MAIN);
    int tNumPiece[nbPiece];
    for(i=0;i<nbPiece;i++) {
        numPiece=0;
        printf("Saisisez la pièce à changer #%d\n",i+1);
        scanf("%c",&lettre);
        do{
            numPiece+=1;
            if (numPiece==NB_PIECE_MAIN+1){
                scanf("%c",&lettre);
                numPiece=1;
            }
        }while(lettre!=tChevalet[numJoueur][numPiece-1]);
        tNumPiece[i]=numPiece-1;
        *pTotalPiece+=1;
        tPioche[chiffrage(lettre)][0]+=1;
        tChevalet[numJoueur][numPiece-1]='0';
    }
    printf("Vous avez pioché : ");
    for(j=0;j<nbPiece;j++) {
        tChevalet[numJoueur][tNumPiece[j]]=pioche(tPioche,pTotalPiece);
        printf("%c ",tChevalet[numJoueur][tNumPiece[j]]);
    }
    printf("\n");
}

int repioche (int* tListPosChev,int tPioche[NB_CARAC][NB_COLONE],int* pTotalPiece,char* tChevaletJoueur){
    int lenListPos=0;
    while(tListPosChev[lenListPos]!=NB_PIECE_MAIN &&lenListPos!=NB_PIECE_MAIN-1){
        lenListPos+=1;
    }
    for (int j=0; j<lenListPos;j++){
        tChevaletJoueur[tListPosChev[j]]=pioche(tPioche,pTotalPiece);
    }
    if (lenListPos==NB_PIECE_MAIN){
        return 50;
    }
    return 0;
}