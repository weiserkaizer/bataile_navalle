#ifndef FONCTION_GRAPH_H_INCLUDED
#define FONCTION_GRAPH_H_INCLUDED

#include "donnees.h"

EtatCase creeVarEtat(char ch[20],char ch1[20],char ch2[20],char ch3[20]);

//graphe
int egalA(char ch1[],char ch2[]);
void afficher(EtatCase **,EtatCase **);
cellule creeCellule(EtatCase T);




#endif // FONCTION_GRAPH_H_INCLUDED
