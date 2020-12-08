#include "Fin de partie .h"

int finDePartie(int totalPiece,char**tChevalets,int nbJoueurs,int*tPoints,int tPioche[NB_CARAC][NB_COLONE]){
    if(totalPiece==0){
        int a=0,i=0,j=0,k=0;
        for(i=0;i<nbJoueurs;i++){
            if(strcmp(tChevalets[i],"0000000")==0){
                //Modif des Scores
                for(j=0;j<nbJoueurs;j++){
                    if(j!=i){
                        for(k=0;k<NB_PIECE_MAIN;k++){
                            if(tChevalets[j][k]!='0'){
                                a=tPioche[chiffrage(tChevalets[j][k])][1];
                                tPoints[j]-=a;
                                tPoints[i]+=a;
                            }
                        }
                        if(tPoints[j]<0){
                            tPoints[j]=0;
                        }
                    }
                }
                return 1;
            }
        }
    }
    return 0;
}

void victoire(int*tPoints,char**tJoueurs,int nbJoueurs){
    int pointMax=0,numMax=0,compteur=0,i=0,j=0,k=0,l=0;
    int id[4]={7,7,7,7};
    for(i=0;i<nbJoueurs;i++){
        if(tPoints[i]>pointMax){
            pointMax=tPoints[i];
            numMax=i;
        }
    }
    for(j=0;j<nbJoueurs;j++){
        if(tPoints[i]==pointMax){
            id[compteur]=j;
            compteur+=1;
        }
    }
    if(compteur>1){
        printf("Égalité de ");
        for(k=0;k<compteur-1;k++){//Cette boucleest en cas de triple égalité (voir plus)
            printf("%s, ",tJoueurs[id[k]]);
        }
        printf("‰s et ‰s !\n\n",tJoueurs[id[compteur-2]],tJoueurs[id[compteur-1]]);
    }
    else{
        printf("Le vainqueur est %s !\n\n",tJoueurs[numMax]);
    }
    printf("Les scores étaient de :\n");
    for(l=0;l<nbJoueurs;l++){
        printf("%s : %d points\n",tJoueurs[l],tPoints[l]);
    }
}