//
// Created by Romain on 09/10/2020.
//

#include "biblio_scrable.h"
char** allocDynamique2D(int longeur,int larg){
    char** tTab=(char**)calloc(longeur,larg*sizeof(char));
    for (int i=0; i<longeur; i++){
        tTab[i]=(char*)calloc(larg,sizeof(char));
    }
    return tTab;
}

void initialiseTab(int tTab[NB_CARAC][NB_COLONE]){
    tTab[0][0]=9;
    tTab[0][1]=1;
    tTab[1][0]=2;
    tTab[1][1]=3;
    tTab[2][0]=2;
    tTab[2][1]=3;
    tTab[3][0]=3;
    tTab[3][1]=2;
    tTab[4][0]=15;
    tTab[4][1]=1;
    tTab[5][0]=2;
    tTab[5][1]=4;
    tTab[6][0]=2;
    tTab[6][1]=2;
    tTab[7][0]=2;
    tTab[7][1]=4;
    tTab[8][0]=8;
    tTab[8][1]=1;
    tTab[9][0]=1;
    tTab[9][1]=8;
    tTab[10][0]=1;
    tTab[10][1]=10;
    tTab[11][0]=5;
    tTab[11][1]=1;
    tTab[12][0]=3;
    tTab[12][1]=2;
    tTab[13][0]=6;
    tTab[13][1]=1;
    tTab[14][0]=6;
    tTab[14][1]=1;
    tTab[15][0]=2;
    tTab[15][1]=3;
    tTab[16][0]=1;
    tTab[16][1]=8;
    tTab[17][0]=6;
    tTab[17][1]=1;
    tTab[18][0]=6;
    tTab[18][1]=1;
    tTab[19][0]=6;
    tTab[19][1]=1;
    tTab[20][0]=6;
    tTab[20][1]=1;
    tTab[21][0]=2;
    tTab[21][1]=4;
    tTab[22][0]=1;
    tTab[22][1]=10;
    tTab[23][0]=1;
    tTab[23][1]=10;
    tTab[24][0]=1;
    tTab[24][1]=10;
    tTab[25][0]=1;
    tTab[25][1]=10;
    tTab[26][0]=2;
    tTab[26][1]=0;
}

//Permet de passer de l'indice d'une lette (A=0) à la dite lettre
char lettrage(int numLettre){
    if(numLettre==26){
        return '?';
    }
    return numLettre+65;
}

//Permet de passer d'une lette à son indice (A=0)
int chiffrage(char lettreNum){
    if(lettreNum=='?'){
        return 26;
    }
    return lettreNum-65;
}

char pioche(int tTab[NB_CARAC][NB_COLONE],int*pTotalPiece){
    if(*pTotalPiece==0){
        return '0';
    }
    int numPiece=0,numLettre=0,totLoc=0;
    numPiece=rand()%*pTotalPiece;//Tire un numéro de pièce (pas de lettre) aléatiore
    do {//Cette boucle détermine la lettre correspondante au numéro de pièce tiré
        totLoc+=tTab[numLettre][0];
        numLettre+=1;
    } while(totLoc<numPiece);
    numLettre-=1;
    tTab[numLettre][0]-=1;
    *pTotalPiece-=1;
    return lettrage(numLettre);
}

char**initialiseChevalets(int tPioche[NB_CARAC][NB_COLONE],int*pTotalPiece,int JDebute,int nbJoueurs){
    int i=0,j=0;
    char**tChevalet=allocDynamique2D(nbJoueurs,NB_PIECE_MAIN);
    for(i=0;i<nbJoueurs;i++){
        for(j=0;j<NB_PIECE_MAIN;j++){
            tChevalet[(JDebute+i)%nbJoueurs][j]=pioche(tPioche,pTotalPiece);
            //Le "(Jdebute+i)%nbJoueurs" permet de faire piocher en premier le joueur qui commence
        }
    }
    return tChevalet;
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

void liberationChar(char** tTab, int longeur){
    for (int i=0; i<longeur; i++){
        free(tTab[i]);
    }
    free(tTab);
}
int afficheMenu() {
    int commencer = 3;
    do {
        printf("Pour charger la dernière partie taper (2)\nPour commencer une nouvelle partie taper (1).\nPour quitter taper (0). \n");
        scanf("%d", &commencer);
        if (commencer == 1) {
            printf("Let's GO !\n\n");
            return 1;
        } else if (commencer == 0) {
            printf("A bientot !\n");
            return 0;
        } else if (commencer == 2) {
            printf("C'est reparti !\n");
            return 2;
        }else {
            printf("Recommencer.\n");
        }
    }while (commencer != 2 && commencer != 1 && commencer != 0);
}



char** allocJoueur(int nbJoueurs){
    char**tTab=(char**)malloc(nbJoueurs*sizeof(char)*LONGEUR_PSEUDO);
    char tTab2[50];
    printf("Saisissez les pseudos des %d joueurs\n",nbJoueurs);
    for (int i=0; i<nbJoueurs; i++){
        tTab[i]=(char*)malloc(LONGEUR_PSEUDO*sizeof(char));
        scanf("%s",tTab2);
        strcpy(tTab[i],tTab2);
        tTab[i]=realloc(tTab[i],sizeof(char)*strlen(tTab[i]));
    }
    return tTab;
}

void afficheMots(char**tTab,int numJoueur){
    int i=0;
    printf("%s\n",tTab[numJoueur]);
}

/*
Légende Grille
# : point de départ
& : lettre double
% : lettre triple
@ : mot double
$ : mot triple
*/
void initialiseGrille(char tGrille[2][DIM_GRILLE][DIM_GRILLE]){
    int i=0,j=0,k=0;
    for(i=0;i<2;i++) {
        for(j=0;j<DIM_GRILLE;j++) {
            for(k=0;k<DIM_GRILLE;k++) {
                tGrille[i][j][k]=' ';
            }
        }
    }
    tGrille[0][0][0]='$';
    tGrille[0][0][3]='&';
    tGrille[0][0][7]='$';
    tGrille[0][0][11]='&';
    tGrille[0][0][14]='$';
    tGrille[0][1][1]='@';
    tGrille[0][1][5]='%';
    tGrille[0][1][9]='%';
    tGrille[0][1][13]='@';
    tGrille[0][2][2]='@';
    tGrille[0][2][6]='&';
    tGrille[0][2][8]='&';
    tGrille[0][2][12]='@';
    tGrille[0][3][0]='&';
    tGrille[0][3][3]='@';
    tGrille[0][3][7]='&';
    tGrille[0][3][11]='@';
    tGrille[0][3][14]='&';//Pi
    tGrille[0][4][4]='@';
    tGrille[0][4][10]='@';
    tGrille[0][5][1]='%';
    tGrille[0][5][5]='%';
    tGrille[0][5][9]='%';
    tGrille[0][5][13]='%';
    tGrille[0][6][2]='&';
    tGrille[0][6][6]='&';
    tGrille[0][6][8]='&';
    tGrille[0][6][12]='&';
    tGrille[0][7][0]='$';
    tGrille[0][7][3]='&';
    tGrille[0][7][7]='#';
    tGrille[0][7][11]='&';
    tGrille[0][7][14]='$';
    tGrille[0][8][2]='&';
    tGrille[0][8][6]='&';
    tGrille[0][8][8]='&';
    tGrille[0][8][12]='&';
    tGrille[0][9][1]='%';
    tGrille[0][9][5]='%';
    tGrille[0][9][9]='%';
    tGrille[0][9][13]='%';
    tGrille[0][10][4]='@';
    tGrille[0][10][10]='@';
    tGrille[0][11][0]='&';
    tGrille[0][11][3]='@';
    tGrille[0][11][7]='&';
    tGrille[0][11][11]='@';
    tGrille[0][11][14]='&';
    tGrille[0][12][2]='@';
    tGrille[0][12][6]='&';
    tGrille[0][12][8]='&';
    tGrille[0][12][12]='@';
    tGrille[0][13][1]='@';
    tGrille[0][13][5]='%';
    tGrille[0][13][9]='%';
    tGrille[0][13][13]='@';
    tGrille[0][14][0]='$';
    tGrille[0][14][3]='&';
    tGrille[0][14][7]='$';
    tGrille[0][14][11]='&';
    tGrille[0][14][14]='$';
}

int estDansLaGrille(char tGrille[2][DIM_GRILLE][DIM_GRILLE],int tCase[3],char*tMot){
    int len=strlen(tMot);
    if(lettrage(tCase[2])=='H'){
        if(len-1+tCase[1]<DIM_GRILLE && tCase[0]<DIM_GRILLE){
            return 1;
        }
    }
    else{
        if(len-1+tCase[0]<DIM_GRILLE && tCase[1]<DIM_GRILLE){
            return 1;
        }
    }
    return 0;
}

void affichageTour(char tGrille[2][DIM_GRILLE][DIM_GRILLE],char**tJoueurs,char**tChevalets,int tCase[3],int tPioche[NB_CARAC][NB_COLONE],int numJoueur,char*tMot,int*pTotalPiece,int*tPoints){
    int i=0,j=0,k=0,ligne=0,rep=1;
    char sens='R',colone='R';
    tMot=realloc(tMot,sizeof(char)*DIM_GRILLE);
    printf("   A  B  C  D  E  F  G  H  I  J  K  L  M  N  O\n");
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
    printf("\n%s : Score %d\n\t",tJoueurs[numJoueur],tPoints[numJoueur]);
    for(k=0;k<NB_PIECE_MAIN;k++){
        printf("%c:%d pt(s)  ",tChevalets[numJoueur][k],tPioche[chiffrage(tChevalets[numJoueur][k])][1]);
    }
    printf("\nLégende :\n# : point de départ\n& : lettre double\n%c : lettre triple\n@ : mot double\n$ : mot triple\n\n",'%');
    printf("Voulez vous continuer à jouer ? (1) oui, (0)non\n");
    do{
        scanf("%d",&rep);
    }while(rep!=0 && rep!=1);
    if(rep==0){
        printf("Voulez vous sauvegarder la partie en cour ? (1) oui, (0)non\n");
        do{
            scanf("%d",&rep);
        }while(rep!=0 && rep!=1);
        if(rep==1){
            sauvegarde(tChevalets,tGrille,tJoueurs,numJoueur,tPoints,tPioche,*pTotalPiece);
        }
        liberationChar(tJoueurs,strlen(tJoueurs));
        liberationChar(tChevalets,strlen(tChevalets));
        free(tMot);
        free(tPoints);
        printf("À plus tard ;)");
        exit(0);
    }
    else{
        printf("Voulez vous saisir un mot ? (1) oui, (0)non\n");
        do{
            scanf("%d",&rep);
        }while(rep!=0 && rep!=1);
        if(rep==0){
            printf("Voulez vous changer vos lettres ? (1) oui, (0)non\n");
            do{
                scanf("%d",&rep);
            }while(rep!=0 && rep!=1);
            if(rep==1){
                changerNPiece(tChevalets, tPioche, pTotalPiece, numJoueur);
            }
        }
        else{
            printf("Mot à saisir : ");
            scanf("%s",tMot);
            printf("Entrez ses coodonées :\n Lettre de colone : ");
            scanf(" %c",&colone);
            tCase[1]=chiffrage(colone);
            printf(" Numéro de ligne : ");
            scanf("%d",&ligne);
            tCase[0]=ligne;
            printf(" Sens : ");
            scanf(" %c",&sens);
            tCase[2]=chiffrage(sens);
            //Se charger de la validité
            ecrireDansLaGrille(tGrille,tCase,tMot);
        }
    }
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

int finDePartie(int totalPiece,char**tChevalets,int nbJoueurs){
    if(totalPiece==0){
        int gagnant=0,i=0;
        for(i=0;i<nbJoueurs;i++){
            if(tChevalets[i]=="0000000"){
                //Modif des Scores
                return 1;
            }
        }
    }
    return 0;
}

char**recharge(char tGrille[2][DIM_GRILLE][DIM_GRILLE],char** tJoueurs,int*pJDebute,int points,int tPioche[NB_CARAC][NB_COLONE],int*pTotalPiece){
    FILE* flecture = NULL;
    flecture = fopen("sauvegarde.txt", "r");
    if(flecture==NULL){printf("Erreur d'ouverture du fichier de sauvegarde"); exit(2);}
    int nbJoueurs=0;
    fscanf(flecture, "%d",&nbJoueurs);
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
        fscanf(flecture,"%d",&tPioche[0][h]);
    }
    fscanf(flecture,"%d",pTotalPiece);
    fclose(flecture);
    flecture=NULL;
    return tJoueurs;
}

char**recharge2(char**tChevalets){
    FILE* flecture = NULL;
    flecture = fopen("sauvegarde.txt", "r");
    if(flecture==NULL){printf("Erreur d'ouverture du fichier de sauvegarde"); exit(2);}
    int nbJoueurs=0;
    fscanf(flecture, "%d",&nbJoueurs);
    tChevalets=allocDynamique2D(nbJoueurs,NB_PIECE_MAIN);
    for(int k=0;k<nbJoueurs;k++) {
        fscanf(flecture, "%s", tChevalets[k]);
    }
    fclose(flecture);
    flecture=NULL;
    return tChevalets;
}
int*recharge3(int*tPoints){
    int useless=0;
    FILE* flecture = NULL;
    flecture = fopen("sauvegarde.txt", "r");
    if(flecture==NULL){printf("Erreur d'ouverture du fichier de sauvegarde"); exit(2);}
    int nbJoueurs=0;
    fscanf(flecture, "%d",&nbJoueurs);
    fseek(flecture,(17+DIM_GRILLE*DIM_GRILLE)*sizeof(char),SEEK_CUR);
    char tJoueurs[nbJoueurs][LONGEUR_PSEUDO];
    for (int n=0; n<nbJoueurs;n++){
        fscanf(flecture,"%s",tJoueurs[n]);
    }
    fseek(flecture,(2+NB_CARAC*2)*sizeof(char),SEEK_CUR);
    fscanf(flecture,"%s",&useless);
    tPoints=(int*)calloc(nbJoueurs,sizeof(int));
    for(int l=0;l<nbJoueurs;l++){
        fscanf(flecture,"%d",tPoints[l]);
    }
    fclose(flecture);
    flecture=NULL;
    return tPoints;
}

void sauvegarde( char**tChevalets,char tGrille[2][DIM_GRILLE][DIM_GRILLE],char** tJoueurs,int JDebute,int*tPoints,int tPioche[NB_CARAC][NB_COLONE],int totalPiece){
    int nbJoueurs=strlen(tJoueurs);
    FILE* fecriture = NULL;
    fecriture=fopen("sauvegarde.txt","w");
    if(fecriture==NULL){printf("Erreur d'ouverture du fichier de sauvegarde"); exit(1);}
    fprintf(fecriture, "%d\n", nbJoueurs);
    for(int k=0;k<nbJoueurs;k++) {
        fprintf(fecriture, "%s\n", tChevalets[k]);
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
        fprintf(fecriture,"%d ",tPioche[0][h]);
    }
    fprintf(fecriture,"%d\n",totalPiece);
    for(int l=0;l<nbJoueurs;l++){
        fprintf(fecriture,"%d\n",tPoints[l]);
    }
    fclose(fecriture);
    fecriture = NULL;
}

int motexiste(char mot[27]) {
    int valide=0,mots =0,rep =0,vers = 1;
    char motsdico[nb_mots][27] ={{0}};
    char * buffer = malloc(sizeof(char) * 1);
    int fd = open("Mots.txt", O_RDONLY);
    if (fd == -1){printf ("error0");return 0;}
    while (vers !=0 && vers != -1){
        vers = read (fd, buffer, 1);
        if (rep >27){ printf ("error1");return 0;}
        if (vers != 0 && vers != -1 && buffer[0]!=' ' && buffer[0]!= '\n'){
            motsdico[mots][rep]=buffer[0];
            rep++;
        }
        else if (vers !=0 && vers != -1 && buffer[0]=='\n'){
            motsdico[mots][rep]='\0';
            rep =0;
            mots++;
        }
    }
    if (vers == -1) {printf ("error2");return 0;}
    close (fd);
    for (int n=0; n<=nb_mots;n++){
        if ( strcmp (motsdico[n], mot) == 0) {valide = 1;}
    }
    return valide;
}

void lettredansmot(char c,char listedelettre[7],int listedespositions[7],int*k){
    int a=0;
    for(int i=0;i<7;++i) {
        if(c==listedelettre[i]) {
            a=0;
            for(int j=0;j<7;j++) {
                if(i==listedespositions[j]) {
                    a+=1;
                }
            }
            if(a==0){
                for(int h=0;h<7;h++) {
                    if(listedespositions[h]==7){
                        listedespositions[h]=i;
                        *k+=1;
                        return;
                    }
                }
            }
        }
    }
}

int motvalide(char mot[15],char listedelettres[7]) {
    int valide = 0;
    int compteur=0;
    int*k=&compteur;
    int listepositions[7];
    for(int j=0;j<7;j++) {
        listepositions[j]=7;
    }
    for (int i = 0; i < strlen(mot); i++) {
        lettredansmot(mot[i],listedelettres,listepositions,k);
    }
    if (*k>=strlen(mot)){
        valide = 1;
        for (int j=0; j<strlen(mot);j++){
            listedelettres[listepositions[j]]='0';
        }
    }
    return valide;
}

void minuscule(char mot[15]){
    for (int i=0;i<strlen(mot);i++){
        mot[i]=tolower(mot[i]);
    }
}

int testValidite(char*tMot,char*tChevalet){
    minuscule(tMot);
    int me=motexiste(tMot);
    int mv=motvalide(tMot,tChevalet);

    if (me==1 && mv==1){//mot existe => option (tour)
        printf("Le mot \'%s\' est valide\n",tMot);
    }
    else (printf("Le mot \'%s\' n'est pas valide\n",tMot));
    return me+2*mv;
}