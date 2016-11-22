#ifndef FONCTION_SAUVEGARDE_H_INCLUDED
#define FONCTION_SAUVEGARDE_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
//#include donnees.h
struct EtatCase // a mettre en commentaire si on fait le include des donnees
{
    char cel[20];
    char position[20];
    char etat[20];
    char orientation[20];
};

typedef struct EtatCase EtatCase;

int sauverPartie(int taille,EtatCase tabJ[taille][taille],EtatCase tabM[taille][taille]);

int sauverReplay(int , char*);
EtatCase creeVarEtat(char ch[20],char ch1[20],char ch2[20],char ch3[20]);
EtatCase * reload(int taille, EtatCase tabJ[taille][taille]);

#endif // FONCTION_SAUVEGARDE_H_INCLUDED
