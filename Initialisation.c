#include "Initialisation.h"

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
    return 0;
}

void initialisePioche(int tPioche[NB_CARAC][NB_COLONE]){
    tPioche[0][0]=9;
    tPioche[0][1]=1;
    tPioche[1][0]=2;
    tPioche[1][1]=3;
    tPioche[2][0]=2;
    tPioche[2][1]=3;
    tPioche[3][0]=3;
    tPioche[3][1]=2;
    tPioche[4][0]=15;
    tPioche[4][1]=1;
    tPioche[5][0]=2;
    tPioche[5][1]=4;
    tPioche[6][0]=2;
    tPioche[6][1]=2;
    tPioche[7][0]=2;
    tPioche[7][1]=4;
    tPioche[8][0]=8;
    tPioche[8][1]=1;
    tPioche[9][0]=1;
    tPioche[9][1]=8;
    tPioche[10][0]=1;
    tPioche[10][1]=10;
    tPioche[11][0]=5;
    tPioche[11][1]=1;
    tPioche[12][0]=3;
    tPioche[12][1]=2;
    tPioche[13][0]=6;
    tPioche[13][1]=1;
    tPioche[14][0]=6;
    tPioche[14][1]=1;
    tPioche[15][0]=2;
    tPioche[15][1]=3;
    tPioche[16][0]=1;
    tPioche[16][1]=8;
    tPioche[17][0]=6;
    tPioche[17][1]=1;
    tPioche[18][0]=6;
    tPioche[18][1]=1;
    tPioche[19][0]=6;
    tPioche[19][1]=1;
    tPioche[20][0]=6;
    tPioche[20][1]=1;
    tPioche[21][0]=2;
    tPioche[21][1]=4;
    tPioche[22][0]=1;
    tPioche[22][1]=10;
    tPioche[23][0]=1;
    tPioche[23][1]=10;
    tPioche[24][0]=1;
    tPioche[24][1]=10;
    tPioche[25][0]=1;
    tPioche[25][1]=10;
    tPioche[26][0]=2;
    tPioche[26][1]=0;
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

char** allocJoueur(int nbJoueurs){
    char**tTab=(char**)malloc(nbJoueurs*sizeof(char)*LONGEUR_PSEUDO);
    char tTab2[LONGEUR_PSEUDO];
    printf("Saisissez les pseudos des %d joueurs\n",nbJoueurs);
    for (int i=0; i<nbJoueurs; i++){
        tTab[i]=(char*)malloc(LONGEUR_PSEUDO*sizeof(char));
        scanf("%s",tTab2);
        strcpy(tTab[i],tTab2);
        tTab[i]=realloc(tTab[i],sizeof(char)*strlen(tTab[i]));
    }
    return tTab;
}

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