#include "Synthese.h"

void affichageTour(char tGrille[2][DIM_GRILLE][DIM_GRILLE],char**tJoueurs,char**tChevalets,int tCase[3],int tPioche[NB_CARAC][NB_COLONE],int numJoueur,char*tMot,int*pTotalPiece,int*tPoints,int nbJoueurs){
    int k=0,l=0,ligne=0,rep=1,in=1,val=2,ecriture=0,point=0;
    int*tListePosition=NULL;
    char sens='R',colone='R';
    tMot=realloc(tMot,sizeof(char)*DIM_GRILLE);
    affichageGrille(tGrille);
    printf("\n%s : Score %d\n\t",tJoueurs[numJoueur],tPoints[numJoueur]);
    for(k=0;k<NB_PIECE_MAIN;k++){
        if(tChevalets[numJoueur][k]!='0') {
            printf("%c:%d pt(s)  ", tChevalets[numJoueur][k], tPioche[chiffrage(tChevalets[numJoueur][k])][1]);
        }
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
            sauvegarde(tChevalets,tGrille,tJoueurs,numJoueur,tPoints,tPioche,*pTotalPiece,nbJoueurs,tMot);
        }
        liberationChar(tJoueurs,nbJoueurs);
        liberationChar(tChevalets,nbJoueurs);
        free(tMot);
        free(tPoints);
        printf("À plus tard ;)");
        exit(0);
    }
    else{
        do {
            in=1;
            val=2;
            ecriture=0;
            printf("Voulez vous saisir un mot ? (1) oui, (0)non\n");
            do{
                scanf("%d",&rep);
            }while(rep!=0 && rep!=1);
            if(rep==0) {
                printf("Voulez vous changer vos lettres ? (1) oui, (0)non\n");
                do{
                    scanf("%d",&rep);
                }while(rep!=0 && rep!=1);
                if(rep==1){
                    changerNPiece(tChevalets,tPioche,pTotalPiece,numJoueur);
                }
            } else {
                ecriture=1;
                printf("Mot à saisir : ");
                do {
                    scanf("%s", tMot);
                }while(strlen(tMot)==1);
                printf("Entrez ses coodonées :\n Lettre de colone : ");
                scanf(" %c", &colone);
                tCase[1] = chiffrage(colone);
                printf(" Numéro de ligne : ");
                scanf("%d", &ligne);
                tCase[0] = ligne;
                printf(" Sens : ");
                scanf(" %c", &sens);
                tCase[2] = chiffrage(sens);
                tMot=joker(tMot);
                tListePosition=testValidite(tMot,tChevalets[numJoueur],tGrille,tCase,&val,&point,tPioche);
                in=estDansLaGrille(tGrille,tCase,tMot);
                if(in!=1){
                    printf("Erreur: Mot hors de la Grille\n");
                }
            }
        }while(in!=1 || val/2==0);
        if(ecriture==1){
            printf("Quelqu'un souhaite contester ?\nPersonne (9)\n");
            for(l=0;l<nbJoueurs;l++){
                if(l!=numJoueur){
                    printf("%s (%d)\n", tJoueurs[l], l);
                }
            }
            do{
                scanf("%d",&rep);
            }while(rep!=9 && rep>=nbJoueurs && rep<0);
            if(rep!=9){
                rep=litige(numJoueur,rep,tPoints,val,tJoueurs);
            }
            if(rep==9){
                ecrireDansLaGrille(tGrille,tCase,tMot);
                tPoints[numJoueur]+=point;
                tPoints[numJoueur]+=repioche(tListePosition,tPioche,pTotalPiece,tChevalets[numJoueur]);
            }
            if(tListePosition!=NULL){
                free(tListePosition);
            }
        }
    }
}