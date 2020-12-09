#include "Sauvegarde.h"

void sauvegarde(char**tChevalets,char tGrille[2][DIM_GRILLE][DIM_GRILLE],char**tJoueurs,int JDebute,int*tPoints,int tPioche[NB_CARAC][NB_COLONE],int totalPiece,int nbJoueurs,char*tMot){
    FILE* fecriture = NULL;
    fecriture=fopen("sauvegarde.txt","w");
    if(fecriture==NULL){
        printf("Erreur d'ouverture du fichier de sauvegarde");
        liberationChar(tJoueurs,nbJoueurs);
        liberationChar(tChevalets,nbJoueurs);
        free(tMot);
        free(tPoints);
        exit(1);}
    fprintf(fecriture, "%d\n", nbJoueurs);
    for(int k=0;k<nbJoueurs;k++) {
        for (int c=0;c<NB_PIECE_MAIN;c++){
            fprintf(fecriture, "%c", tChevalets[k][c]);
        }
        fprintf(fecriture, "\n");
    }
    for(int i=0;i<DIM_GRILLE;i++){
        for (int j=0;j<DIM_GRILLE;j++){
            fprintf(fecriture,"%c",tGrille[1][i][j]);
        }
    }
    for (int n=0; n<nbJoueurs;n++){
        fprintf(fecriture,"%s\n",tJoueurs[n]);
    }
    fprintf(fecriture,"%d\n",JDebute);

    for (int h=0;h<NB_CARAC;h++){
        fprintf(fecriture,"%d ",tPioche[h][0]);
    }
    fprintf(fecriture,"%d\n",totalPiece);
    for(int l=0;l<nbJoueurs;l++){
        fprintf(fecriture,"%d\n",tPoints[l]);
    }
    fclose(fecriture);
    fecriture = NULL;
}

char**rechargeJoueurs(char tGrille[2][DIM_GRILLE][DIM_GRILLE],char** tJoueurs,int*pJDebute,int tPioche[NB_CARAC][NB_COLONE],int*pTotalPiece,int*pNbJoueurs){
    FILE* flecture = NULL;
    flecture = fopen("sauvegarde.txt", "r");
    if(flecture==NULL){printf("Erreur d'ouverture du fichier de sauvegarde"); exit(2);}
    int nbJoueurs=0;
    fscanf(flecture, "%d",&nbJoueurs);
    *pNbJoueurs=nbJoueurs;
    fseek(flecture,17*sizeof(char),SEEK_CUR);
    for(int i=0;i<DIM_GRILLE;i++){
        for (int j=0;j<DIM_GRILLE;j++){
            fscanf(flecture,"%c",&tGrille[1][i][j]);
        }
    }
    tJoueurs=(char**)malloc(nbJoueurs*sizeof(char)*LONGEUR_PSEUDO);
    for (int i=0; i<nbJoueurs; i++){
        tJoueurs[i]=(char*)malloc(LONGEUR_PSEUDO*sizeof(char));
    }
    for (int n=0; n<nbJoueurs;n++){
        fscanf(flecture,"%s",tJoueurs[n]);
        tJoueurs[n]=realloc(tJoueurs[n],sizeof(char)*strlen(tJoueurs[n]));
    }
    fscanf(flecture,"%d",pJDebute);
    for (int h=0;h<NB_CARAC;h++){
        fscanf(flecture,"%d",&tPioche[h][0]);
    }
    fscanf(flecture,"%d",pTotalPiece);
    fclose(flecture);
    flecture=NULL;
    return tJoueurs;
}

char**rechargeChevalets(char**tChevalets,char**tJoueurs,int nbJoueurs){
    FILE* flecture = NULL;
    flecture = fopen("sauvegarde.txt", "r");
    if(flecture==NULL){
        printf("Erreur d'ouverture du fichier de sauvegarde");
        liberationChar(tJoueurs,nbJoueurs);
        exit(2);
    }
    fscanf(flecture, "%d",&nbJoueurs);
    tChevalets=allocDynamique2D(nbJoueurs,NB_PIECE_MAIN);
    for(int k=0;k<nbJoueurs;k++) {
        fscanf(flecture, "%s", tChevalets[k]);
    }
    fclose(flecture);
    flecture=NULL;
    return tChevalets;
}
int*rechargePoints(int*tPoints,char**tJoueurs,char**tChevalets,int nbJoueurs){
    int useless=0;
    FILE* flecture = NULL;
    flecture = fopen("sauvegarde.txt", "r");
    if(flecture==NULL){
        printf("Erreur d'ouverture du fichier de sauvegarde");
        liberationChar(tJoueurs,nbJoueurs);
        liberationChar(tChevalets,nbJoueurs);
        exit(2);
    }
    fscanf(flecture, "%d",&nbJoueurs);
    fseek(flecture,(17+DIM_GRILLE*DIM_GRILLE)*sizeof(char),SEEK_CUR);
    char tJoueur[nbJoueurs][LONGEUR_PSEUDO];
    for (int n=0; n<nbJoueurs;n++){
        fscanf(flecture,"%s",tJoueurs[n]);
    }
    for (int i = 0; i <NB_CARAC+2 ;i++) {
        fscanf(flecture,"%d",&useless);
    }
    tPoints=(int*)calloc(nbJoueurs,sizeof(int));
    for(int l=0;l<nbJoueurs;l++){
        fscanf(flecture,"%d",&tPoints[l]);
    }
    fclose(flecture);
    flecture=NULL;
    return tPoints;
}