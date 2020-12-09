#include "Verifications.h"

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

int motexiste(char tMot[NB_CARAC]) {
    int valide=0,mots =0,rep =0,vers = 1;
    char motsdico[nb_mots][NB_CARAC] ={{0}};
    char * buffer = malloc(sizeof(char) * 1);
    int fd = open("Mots.txt", O_RDONLY);
    if (fd == -1){printf ("error0\n");return 0;}
    while (vers !=0 && vers != -1){
        vers = read (fd, buffer, 1);
        if (rep >NB_CARAC){ printf ("error1\n");return 0;}
        if (vers != 0 && vers != -1 && buffer[0]!=' ' && buffer[0]!= '\n' && buffer[0]!='\r'){
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
        if ( strcmp (motsdico[n], tMot) == 0) {valide = 1;}
    }
    return valide;
}

int*lettredansmot(char c,char tChevaletJoueur[NB_PIECE_MAIN],int tListPosChev[NB_PIECE_MAIN],int*pK,char tGrille[2][DIM_GRILLE][DIM_GRILLE],int tCase[3],int*pKbis){
    int a=0;
    if(c=='0'){
        return tListPosChev;
    }
    if(tCase[2]==chiffrage('H')){
        if(tGrille[1][tCase[0]][tCase[1]+ *pK]==c){
            *pK+=1;
            *pKbis+=1;
            return tListPosChev;
        }
        if(tGrille[1][tCase[0]][tCase[1]+ *pK]!=' '){
            return tListPosChev;
        }
    }
    else{
        if(tGrille[1][tCase[0]+ *pK][tCase[1]]==c){
            *pK+=1;
            *pKbis+=1;
            return tListPosChev;
        }
        if(tGrille[1][tCase[0]+ *pK][tCase[1]]!=' '){
            return tListPosChev;
        }
    }
    if(c<123 && c>96){
        for(int i=0;i<NB_PIECE_MAIN;++i) {
            if('?'==tChevaletJoueur[i]){
                a=0;
                for(int j=0;j<NB_PIECE_MAIN;j++) {
                    if(i==tListPosChev[j]) {
                        a+=1;
                    }
                }
                if(a==0){
                    for(int h=0;h<NB_PIECE_MAIN;h++) {
                        if(tListPosChev[h]==NB_PIECE_MAIN){
                            tListPosChev[h]=i;
                            *pK+=1;
                            return tListPosChev;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<NB_PIECE_MAIN;++i) {
        if(c==tChevaletJoueur[i]) {
            a=0;
            for(int j=0;j<NB_PIECE_MAIN;j++) {
                if(i==tListPosChev[j]) {
                    a+=1;
                }
            }
            if(a==0){
                for(int h=0;h<NB_PIECE_MAIN;h++) {
                    if(tListPosChev[h]==NB_PIECE_MAIN){
                        tListPosChev[h]=i;
                        *pK+=1;
                        return tListPosChev;
                    }
                }
            }
        }
    }
    return tListPosChev;
}

int*motvalide(char tMot[DIM_GRILLE],char tChevaletJoueur[NB_PIECE_MAIN],char tGrille[2][DIM_GRILLE][DIM_GRILLE],int tCase[3],int*pValide) {
    *pValide = 0;
    int compteur=0,compteurbis=0,a=0;
    int*pK=&compteur;
    int*pKbis=&compteurbis;
    int*tListPosChev=calloc(NB_PIECE_MAIN,sizeof(int));
    int*tListPosMot=calloc(NB_PIECE_MAIN,sizeof(int));
    for(int j=0;j<NB_PIECE_MAIN;j++) {
        tListPosChev[j]=NB_PIECE_MAIN;
        tListPosMot[j]=NB_PIECE_MAIN;
    }
    for (int i = 0; i < strlen(tMot); i++) {
        tListPosChev=lettredansmot(tMot[i],tChevaletJoueur,tListPosChev,pK,tGrille,tCase,pKbis);
        if(compteurbis==a){
            tListPosMot[i-a]=i;
        }
        else{
            a=compteurbis;
        }
    }
    if (*pK>=strlen(tMot)){
        if(compteurbis>0 || (tCase[0]==7 && tCase[1]==chiffrage('H'))){
            *pValide=1;
        }
        else{
            *pValide=2;
        }
    }
    else{
        printf("Erreur: Vous n'avez pas les pièces nécessaires\n");
    }
    free(tListPosChev);
    return tListPosMot;
}

int*listPosChev(char tMot[DIM_GRILLE],char tChevaletJoueur[NB_PIECE_MAIN],char tGrille[2][DIM_GRILLE][DIM_GRILLE],int tCase[3]) {
    int compteur=0,compteurbis=0;
    int*pK=&compteur;
    int*pKbis=&compteurbis;
    int*tListPosChev=calloc(NB_PIECE_MAIN,sizeof(int));
    for(int j=0;j<NB_PIECE_MAIN;j++) {
        tListPosChev[j]=NB_PIECE_MAIN;
    }
    for (int i = 0; i < strlen(tMot); i++) {
        tListPosChev=lettredansmot(tMot[i],tChevaletJoueur,tListPosChev,pK,tGrille,tCase,pKbis);
    }
    return tListPosChev;
}

void minuscule(char tMot[DIM_GRILLE]){
    for (int i=0;i<strlen(tMot);i++){
        tMot[i]=tolower(tMot[i]);
    }
}

char**listeDeMots(char tGrille[2][DIM_GRILLE][DIM_GRILLE],int tCase[3],int*tListPosMot,char*tMot,int*pLenList){
    char**tListeDeMots;
    char tMotBis[DIM_GRILLE+3]="\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    int i=0,j=0,k=0,lenListPos=0,premPosMot=0,b=0,c=0;
    while(tListPosMot[lenListPos]!=NB_PIECE_MAIN && lenListPos!=NB_PIECE_MAIN-1){
        lenListPos+=1;
    }
    tListeDeMots=(char**)malloc(8);
    for(i=0;i<lenListPos;i++){
        if(tCase[2]==chiffrage('H')){
            premPosMot=tCase[0];
            while(tGrille[1][premPosMot-1][tCase[1]+tListPosMot[i]]!=' ' && premPosMot!=0){
                premPosMot-=1;
            }
            b=premPosMot;
            while(tGrille[1][b][tCase[1]+tListPosMot[i]]!=' ' || b==tCase[0]){
                if(b==tCase[0]){
                    tMotBis[b-premPosMot]=tMot[tListPosMot[i]];
                }
                else{
                    tMotBis[b-premPosMot]=tGrille[1][b][tCase[1]+tListPosMot[i]];
                }
                b+=1;
            }
            if(b-premPosMot==1){
                c+=1;
            }
            else{
                tListeDeMots=realloc(tListeDeMots,sizeof(tListeDeMots)+sizeof(char)*(DIM_GRILLE+3));
                tListeDeMots[i-c]=(char*)malloc((DIM_GRILLE+3)*sizeof(char));
                strcpy(tListeDeMots[i-c],tMotBis);
                tListeDeMots[i-c][strlen(tListeDeMots[i-c])+1]=lettrage(tListPosMot[i]);
                tListeDeMots[i-c][strlen(tListeDeMots[i-c])+2]=lettrage(tCase[0]-premPosMot);
                for(k=0;k<DIM_GRILLE+3;k++){
                    tMotBis[k]='\0';
                }
            }
        }
        else{
            premPosMot=tCase[1];
            while(tGrille[1][tCase[0]+tListPosMot[i]][premPosMot-1]!=' ' && premPosMot!=0){
                premPosMot-=1;
            }
            b=premPosMot;
            while(tGrille[1][tCase[0]+tListPosMot[i]][b]!=' ' || b==tCase[1]){
                if(b==tCase[1]){
                    tMotBis[b-premPosMot]=tMot[tListPosMot[i]];
                }
                else{
                    tMotBis[b-premPosMot]=tGrille[1][tCase[0]+tListPosMot[i]][b];
                }
                b+=1;
            }
            if(b-premPosMot==1){
                c+=1;
            }
            else{
                tListeDeMots=realloc(tListeDeMots,sizeof(tListeDeMots)+sizeof(char)*(DIM_GRILLE+3));
                tListeDeMots[i-c]=(char*)malloc((DIM_GRILLE+3)*sizeof(char));
                strcpy(tListeDeMots[i-c],tMotBis);
                tListeDeMots[i-c][strlen(tListeDeMots[i-c])+1]=lettrage(tListPosMot[i]);
                tListeDeMots[i-c][strlen(tListeDeMots[i-c])+2]=lettrage(tCase[1]-premPosMot);
                for(k=0;k<DIM_GRILLE+3;k++){
                    tMotBis[k]='\0';
                }
            }
        }
    }
    if(c==lenListPos){
        free(tListeDeMots);
        tListeDeMots=NULL;
        printf("\nLe mot écrit est :\n%s\n",tMot);
    }
    else{
        *pLenList=lenListPos-c;
        printf("\nLes mots écrit sont :\n%s\n",tMot);
        for (int k = 0; k <*pLenList ; k++) {
            printf("%s\n",tListeDeMots[k]);
        }
    }
    return tListeDeMots;
}

int* testValidite(char*tMot,char*tChevalet,char tGrille[2][DIM_GRILLE][DIM_GRILLE],int tCase[3],int*pRes,int*pPoint,int tPioche[NB_CARAC][NB_COLONE]) {
    *pPoint = 0;
    char tMotBis[DIM_GRILLE];
    strcpy(tMotBis, tMot);
    minuscule(tMotBis);
    int tCaseBis[3]={tCase[0],tCase[1],tCase[2]};
    int tListPosMotBis[NB_PIECE_MAIN]={0,NB_PIECE_MAIN};
    int me = motexiste(tMotBis), i = 0, compteur = 1, listPos = 0, lenList = 0;
    int mv = 0;
    int *tListPosMot = motvalide(tMot, tChevalet, tGrille, tCase, &mv);
    *pPoint+=scoreMot(tMot,tGrille,tPioche,tCase,tListPosMot);
    int *tListPosChev = listPosChev(tMot, tChevalet, tGrille, tCase);
    char **tListeDeMots;
    if (mv != 0) {
        tListeDeMots = listeDeMots(tGrille, tCase, tListPosMot, tMot, &lenList);
        if (tListeDeMots != NULL) {
            mv = 1;
            for (i = 0; i < lenList; i++) {
                if (strcmp(tListeDeMots[i], "") != 0) {
                    strcpy(tMotBis, tListeDeMots[i]);
                    minuscule(tMotBis);
                    me += motexiste(tMotBis);
                    compteur += 1;
                    if(tCase[2]==chiffrage(('H'))){
                        tCaseBis[0]=tCase[0];
                        tCaseBis[1]=chiffrage(tListeDeMots[i][strlen(tListeDeMots[i])+1])+tCase[1];
                        tCaseBis[0]-=chiffrage(tListeDeMots[i][strlen(tListeDeMots[i])+2]);
                        tCaseBis[2]=chiffrage('V');
                    }
                    else{
                        tCaseBis[1]=tCase[1];
                        tCaseBis[0]=chiffrage(tListeDeMots[i][strlen(tListeDeMots[i])+1])+tCase[0];
                        tCaseBis[1]-=chiffrage(tListeDeMots[i][strlen(tListeDeMots[i])+2]);
                        tCaseBis[2]=chiffrage('H');
                    }
                    tListPosMotBis[0]=chiffrage(tListeDeMots[i][strlen(tListeDeMots[i])+2]);
                    *pPoint+=scoreMot(tListeDeMots[i],tGrille,tPioche,tCaseBis,tListPosMotBis);
                }
            }
            liberationChar(tListeDeMots, lenList);
        }
    }
    if (mv == 2) {
        printf("Erreur: Vous n'avez pas connecté votre mot aux autres\n");
        mv = 0;
    }
    me /= compteur;
    *pRes = me + 2 * mv;
    return tListPosChev;
}

int litige(int numJoueur,int numAccusateur,int*tPoints,int res,char**tJoueurs){
    if(res%2!=1){
        printf("Le mot n'existe pas\n");
        return 0;
    }
    else{
        printf("Le mot existe, -10 points pour %s\n",tJoueurs[numAccusateur]);
        if(tPoints[numAccusateur]>10){
            tPoints[numAccusateur]-=10;
        }
        else{
            tPoints[numAccusateur]=0;
        }
    }
    return 9;
}