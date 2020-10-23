#include <stdio.h>
#include<fcntl.h>
#include <stdlib.h>
#include <string.h>
#define nb_mots 22740

void libererTableau2D(char** tableau2D, int nbLignes, int nbColonnes) {
    int i = 0;
    if (nbColonnes > 0) {
        for (i = 0; i < nbLignes; i++) {
            free(tableau2D[i]);
        }
    }
    if(nbLignes > 0) {
        free(tableau2D);
    }
}

int motvalide(char mot[26]) {

    int valide=0;
    int mots =0;
    int rep =0;
    int vers = 1;

    char** motsdico;
    motsdico = calloc(nb_mots,sizeof(char*));
    for (int k=0; k<= nb_mots; k++){
        motsdico[k]= calloc(26,sizeof(char));
    }


    char * buffer = malloc(sizeof(char) * 1);
    int fd = open("D:\\DEVOIRS ECE\\Informatique\\Scrable\\Mots.txt", O_RDONLY); //insérer l'emplacement du fichier
    if (fd == -1){printf ("error");return 0;}


    while (vers !=0 && vers != -1){
        vers = read (fd, buffer, 1);
        if (rep >26){ printf ("error");return 0;}
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
    if (vers == -1) {printf ("error");return 0;}
    close (fd);

    for (int n=0; n<=nb_mots;n++){

        if ( strcmp (motsdico[n], mot) == 0) {valide = 1;}
    }

    for (int k=0;k<=nb_mots;k++){
    }
    libererTableau2D(motsdico,nb_mots,26);
    return valide;

}

int main(){
    char motbis[25]="salut";
    printf("%d",motvalide(motbis));

}
