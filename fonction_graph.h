#ifndef FONCTION_GRAPH_H_INCLUDED
#define FONCTION_GRAPH_H_INCLUDED

typedef struct EtatCase EtatCase;
struct EtatCase
{
    char cel[20];
    char position[20];
    char etat[20];
    char orientation[20];
};

EtatCase creeVarEtat(char ch[20],char ch1[20],char ch2[20],char ch3[20]);



//graphe
int egalA(char ch1[],char ch2[]);

typedef struct cellule cellule;
struct cellule
{
    char ligne1[20],ligne2[20],ligne3[20],ligne4[20],ligne5[20];
};

typedef struct GrilleCellule GrilleCellule;
struct GrilleCellule
{
    EtatCase grilleCellule[11][23];
};

void afficher(EtatCase Tj[10][10],EtatCase To[10][10]);
cellule creeCellule(EtatCase T);




#endif // FONCTION_GRAPH_H_INCLUDED
