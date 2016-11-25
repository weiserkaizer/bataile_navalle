#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include "donnees.h"
#include "fonction_graph.h"





//compare deux chaine de caratere

int egalA (char ch1[],char ch2[])
{
    int i=0,egal=0;
    if(strlen(ch1)==strlen(ch2))
    {
        for(i=0; (ch1[i]!='\0') && ch2[i]!='\0' ; i++)
        {
            if (ch1[i]==ch2[i])
            {
                egal = 1;

            }
            else
            {
                egal = 0;

                break;
            }
        }
    }

    return(egal);

}


//cree une structure contenant les information relative a l'affichage

EtatCase creeVarEtat(char ch[20],char ch1[20],char ch2[20],char ch3[20])
{
    EtatCase T;
    strcpy(T.cel,ch);
    strcpy(T.position,ch1);
    strcpy(T.etat,ch2);
    strcpy(T.orientation,ch3);



    return(T);
};

//Afficher l'intro

void intro()
{
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t       BATAILLE NAVALE\n\n");
    printf("Bienvenue Joueur\n\nEntrez 1 pour commencer une nouvelle partie\n\nEntrez 2 pour charger la derniere partie jouee\n\nEntrez 3 pour revoir la derniere partie jouee\n\n");
}




//cr�ation d'un tableau contenant les information d'affichage de toute les cellule

void afficher(EtatCase **Tj,EtatCase **To)
{
    system("CLS");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t       BATAILLE NAVALE\n\n");
    EtatCase T[11][23];

    //mise en place des cases constante

    T[0][0]=creeVarEtat("celVide","1","n","u");
    T[0][1]=creeVarEtat("A","1","n","u");
    T[0][2]=creeVarEtat("B","1","n","u");
    T[0][3]=creeVarEtat("C","1","n","u");
    T[0][4]=creeVarEtat("D","1","n","u");
    T[0][5]=creeVarEtat("E","1","n","u");
    T[0][6]=creeVarEtat("F","1","n","u");
    T[0][7]=creeVarEtat("G","1","n","u");
    T[0][8]=creeVarEtat("H","1","n","u");
    T[0][9]=creeVarEtat("I","1","n","u");
    T[0][10]=creeVarEtat("J","1","n","u");

    T[0][11]=creeVarEtat("sep","1","n","u");
    T[1][11]=creeVarEtat("sep","1","n","u");
    T[2][11]=creeVarEtat("sep","1","n","u");
    T[3][11]=creeVarEtat("sep","1","n","u");
    T[4][11]=creeVarEtat("sep","1","n","u");
    T[5][11]=creeVarEtat("sep","1","n","u");
    T[6][11]=creeVarEtat("sep","1","n","u");
    T[7][11]=creeVarEtat("sep","1","n","u");
    T[8][11]=creeVarEtat("sep","1","n","u");
    T[9][11]=creeVarEtat("sep","1","n","u");
    T[10][11]=creeVarEtat("sep","1","n","u");

    T[0][12]=creeVarEtat("celVide","1","n","u");
    T[0][13]=creeVarEtat("A","1","n","u");
    T[0][14]=creeVarEtat("B","1","n","u");
    T[0][15]=creeVarEtat("C","1","n","u");
    T[0][16]=creeVarEtat("D","1","n","u");
    T[0][17]=creeVarEtat("E","1","n","u");
    T[0][18]=creeVarEtat("F","1","n","u");
    T[0][19]=creeVarEtat("G","1","n","u");
    T[0][20]=creeVarEtat("H","1","n","u");
    T[0][21]=creeVarEtat("I","1","n","u");
    T[0][22]=creeVarEtat("J","1","n","u");

    T[1][0]=creeVarEtat("1","1","n","u");
    T[2][0]=creeVarEtat("2","1","n","u");
    T[3][0]=creeVarEtat("3","1","n","u");
    T[4][0]=creeVarEtat("4","1","n","u");
    T[5][0]=creeVarEtat("5","1","n","u");
    T[6][0]=creeVarEtat("6","1","n","u");
    T[7][0]=creeVarEtat("7","1","n","u");
    T[8][0]=creeVarEtat("8","1","n","u");
    T[9][0]=creeVarEtat("9","1","n","u");
    T[10][0]=creeVarEtat("10","1","n","u");

    T[1][12]=creeVarEtat("1","1","n","u");
    T[2][12]=creeVarEtat("2","1","n","u");
    T[3][12]=creeVarEtat("3","1","n","u");
    T[4][12]=creeVarEtat("4","1","n","u");
    T[5][12]=creeVarEtat("5","1","n","u");
    T[6][12]=creeVarEtat("6","1","n","u");
    T[7][12]=creeVarEtat("7","1","n","u");
    T[8][12]=creeVarEtat("8","1","n","u");
    T[9][12]=creeVarEtat("9","1","n","u");
    T[10][12]=creeVarEtat("10","1","n","u");

    //remplissage du reste du tableau � partir des tableau Tj et To

    int i,j;
    for(i=0; i<TAILLEPLATEAU; i++)
    {
        for(j=0; j<TAILLEPLATEAU; j++)
        {
            T[i+1][j+1]=Tj[i][j];
            T[i+1][j+13]=To[i][j];
        }
    }


    //affichage



    int l;
    j=0;
    i=0;
    for(i=0; i<11; i++)
    {
        for(l=1; l<6; l++)
        {
            for(j=0; j<23; j++)
            {
                cellule cel = creeCellule(T[i][j]);
                switch(l)
                {


                case 1 :
                    printf("%s",cel.ligne1);
                    break;
                case 2 :
                    printf("%s",cel.ligne2);
                    break;
                case 3 :
                    printf("%s",cel.ligne3);
                    break;
                case 4 :
                    printf("%s",cel.ligne4);
                    break;
                case 5 :
                    printf("%s",cel.ligne5);
                    break;
                default : break;

                }
            }
            printf("\n");
        }
    }
}



//cr�ation cellules

cellule creeCellule(EtatCase T)
{

    cellule cel;

    if(egalA(T.cel,"ba")==1)
    {
        if(egalA(T.etat,"n")==1)
        {
            strcpy(cel.ligne1,"|---------|");
            strcpy(cel.ligne2,"|#########|");
            strcpy(cel.ligne3,"|#########|");
            strcpy(cel.ligne4,"|#########|");
            strcpy(cel.ligne5,"|---------|");
        }
        else if(egalA(T.etat,"t")==1)
        {
            strcpy(cel.ligne1,"|---------|");
            strcpy(cel.ligne2,"|#~#~#~#~#|");
            strcpy(cel.ligne3,"|#~#~#~#~#|");
            strcpy(cel.ligne4,"|#~#~#~#~#|");
            strcpy(cel.ligne5,"|---------|");
        }
        else if(egalA(T.etat,"c")==1)
        {
            strcpy(cel.ligne1,"|---------|");
            strcpy(cel.ligne2,"|~~#~~#~~#|");
            strcpy(cel.ligne3,"|~~#~~#~~#|");
            strcpy(cel.ligne4,"|~~#~~#~~#|");
            strcpy(cel.ligne5,"|---------|");
        }

    }

    //création d'une cellule vide

    else if(egalA(T.cel,"celVide")==1)
    {
        if(egalA(T.etat,"n")==1)
        {
            strcpy(cel.ligne1,"|---------|");
            strcpy(cel.ligne2,"|         |");
            strcpy(cel.ligne3,"|         |");
            strcpy(cel.ligne4,"|         |");
            strcpy(cel.ligne5,"|---------|");
        }
        else
        {
            strcpy(cel.ligne1,"|---------|");
            strcpy(cel.ligne2,"|~ ~ ~ ~ ~|");
            strcpy(cel.ligne3,"|~ ~ ~ ~ ~|");
            strcpy(cel.ligne4,"|~ ~ ~ ~ ~|");
            strcpy(cel.ligne5,"|---------|");
        }
    }

    //création cellules lettre

    else if(egalA(T.cel,"A")==1)
    {
        strcpy(cel.ligne1,"|---------|");
        strcpy(cel.ligne2,"|         |");
        strcpy(cel.ligne3,"|    A    |");
        strcpy(cel.ligne4,"|         |");
        strcpy(cel.ligne5,"|---------|");
    }
    else if(egalA(T.cel,"B")==1)
    {
        strcpy(cel.ligne1,"|---------|");
        strcpy(cel.ligne2,"|         |");
        strcpy(cel.ligne3,"|    B    |");
        strcpy(cel.ligne4,"|         |");
        strcpy(cel.ligne5,"|---------|");
    }
    else if(egalA(T.cel,"C")==1)
    {
        strcpy(cel.ligne1,"|---------|");
        strcpy(cel.ligne2,"|         |");
        strcpy(cel.ligne3,"|    C    |");
        strcpy(cel.ligne4,"|         |");
        strcpy(cel.ligne5,"|---------|");
    }
    else if(egalA(T.cel,"D")==1)
    {
        strcpy(cel.ligne1,"|---------|");
        strcpy(cel.ligne2,"|         |");
        strcpy(cel.ligne3,"|    D    |");
        strcpy(cel.ligne4,"|         |");
        strcpy(cel.ligne5,"|---------|");
    }
    else if(egalA(T.cel,"E")==1)
    {
        strcpy(cel.ligne1,"|---------|");
        strcpy(cel.ligne2,"|         |");
        strcpy(cel.ligne3,"|    E    |");
        strcpy(cel.ligne4,"|         |");
        strcpy(cel.ligne5,"|---------|");
    }
    else if(egalA(T.cel,"F")==1)
    {
        strcpy(cel.ligne1,"|---------|");
        strcpy(cel.ligne2,"|         |");
        strcpy(cel.ligne3,"|    F    |");
        strcpy(cel.ligne4,"|         |");
        strcpy(cel.ligne5,"|---------|");
    }
    else if(egalA(T.cel,"G")==1)
    {
        strcpy(cel.ligne1,"|---------|");
        strcpy(cel.ligne2,"|         |");
        strcpy(cel.ligne3,"|    G    |");
        strcpy(cel.ligne4,"|         |");
        strcpy(cel.ligne5,"|---------|");
    }
    else if(egalA(T.cel,"H")==1)
    {
        strcpy(cel.ligne1,"|---------|");
        strcpy(cel.ligne2,"|         |");
        strcpy(cel.ligne3,"|    H    |");
        strcpy(cel.ligne4,"|         |");
        strcpy(cel.ligne5,"|---------|");
    }
    else if(egalA(T.cel,"I")==1)
    {
        strcpy(cel.ligne1,"|---------|");
        strcpy(cel.ligne2,"|         |");
        strcpy(cel.ligne3,"|    I    |");
        strcpy(cel.ligne4,"|         |");
        strcpy(cel.ligne5,"|---------|");
    }
    else if(egalA(T.cel,"J")==1)
    {
        strcpy(cel.ligne1,"|---------|");
        strcpy(cel.ligne2,"|         |");
        strcpy(cel.ligne3,"|    J    |");
        strcpy(cel.ligne4,"|         |");
        strcpy(cel.ligne5,"|---------|");
    }

    //création des cellules nombre

    else if(egalA(T.cel,"1")==1)
    {
        strcpy(cel.ligne1,"|---------|");
        strcpy(cel.ligne2,"|         |");
        strcpy(cel.ligne3,"|    1    |");
        strcpy(cel.ligne4,"|         |");
        strcpy(cel.ligne5,"|---------|");
    }
    else if(egalA(T.cel,"2")==1)
    {
        strcpy(cel.ligne1,"|---------|");
        strcpy(cel.ligne2,"|         |");
        strcpy(cel.ligne3,"|    2    |");
        strcpy(cel.ligne4,"|         |");
        strcpy(cel.ligne5,"|---------|");
    }
    else if(egalA(T.cel,"3")==1)
    {
        strcpy(cel.ligne1,"|---------|");
        strcpy(cel.ligne2,"|         |");
        strcpy(cel.ligne3,"|    3    |");
        strcpy(cel.ligne4,"|         |");
        strcpy(cel.ligne5,"|---------|");
    }
    else if(egalA(T.cel,"4")==1)
    {
        strcpy(cel.ligne1,"|---------|");
        strcpy(cel.ligne2,"|         |");
        strcpy(cel.ligne3,"|    4    |");
        strcpy(cel.ligne4,"|         |");
        strcpy(cel.ligne5,"|---------|");
    }
    else if(egalA(T.cel,"5")==1)
    {
        strcpy(cel.ligne1,"|---------|");
        strcpy(cel.ligne2,"|         |");
        strcpy(cel.ligne3,"|    5    |");
        strcpy(cel.ligne4,"|         |");
        strcpy(cel.ligne5,"|---------|");
    }
    else if(egalA(T.cel,"6")==1)
    {
        strcpy(cel.ligne1,"|---------|");
        strcpy(cel.ligne2,"|         |");
        strcpy(cel.ligne3,"|    6    |");
        strcpy(cel.ligne4,"|         |");
        strcpy(cel.ligne5,"|---------|");
    }
    else if(egalA(T.cel,"7")==1)
    {
        strcpy(cel.ligne1,"|---------|");
        strcpy(cel.ligne2,"|         |");
        strcpy(cel.ligne3,"|    7    |");
        strcpy(cel.ligne4,"|         |");
        strcpy(cel.ligne5,"|---------|");
    }
    else if(egalA(T.cel,"8")==1)
    {
        strcpy(cel.ligne1,"|---------|");
        strcpy(cel.ligne2,"|         |");
        strcpy(cel.ligne3,"|    8    |");
        strcpy(cel.ligne4,"|         |");
        strcpy(cel.ligne5,"|---------|");
    }
    else if(egalA(T.cel,"9")==1)
    {
        strcpy(cel.ligne1,"|---------|");
        strcpy(cel.ligne2,"|         |");
        strcpy(cel.ligne3,"|    9    |");
        strcpy(cel.ligne4,"|         |");
        strcpy(cel.ligne5,"|---------|");
    }
    else if(egalA(T.cel,"10")==1)
    {
        strcpy(cel.ligne1,"|---------|");
        strcpy(cel.ligne2,"|         |");
        strcpy(cel.ligne3,"|   10    |");
        strcpy(cel.ligne4,"|         |");
        strcpy(cel.ligne5,"|---------|");
    }

    //cellues de séparation

    else if(egalA(T.cel,"sep")==1)
    {
        strcpy(cel.ligne1,"   |||||   ");
        strcpy(cel.ligne2,"   |||||   ");
        strcpy(cel.ligne3,"   |||||   ");
        strcpy(cel.ligne4,"   |||||   ");
        strcpy(cel.ligne5,"   |||||   ");
    }

    //cellules porte avion

    else if(egalA(T.cel,"PA")==1)
    {
        if(egalA(T.position,"1")==1)
        {
            if(egalA(T.etat,"n")==1)
            {

                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|        #|");
                    strcpy(cel.ligne3,"|  #######|");
                    strcpy(cel.ligne4,"|   ######|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#        |");
                    strcpy(cel.ligne3,"|#######  |");
                    strcpy(cel.ligne4,"|#####    |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|   ###   |");
                    strcpy(cel.ligne3,"|   ####  |");
                    strcpy(cel.ligne4,"|  #####  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #####  |");
                    strcpy(cel.ligne3,"|   ####  |");
                    strcpy(cel.ligne4,"|   ###   |");
                    strcpy(cel.ligne5,"|---------|");
                }

            }
            else if(egalA(T.etat,"t")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|        #|");
                    strcpy(cel.ligne3,"|  ##~#~##|");
                    strcpy(cel.ligne4,"|   #~##~#|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#        |");
                    strcpy(cel.ligne3,"|##~#~##  |");
                    strcpy(cel.ligne4,"|#~#~#    |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|   ###   |");
                    strcpy(cel.ligne3,"|   ##~#  |");
                    strcpy(cel.ligne4,"|  #~##~  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #~##~  |");
                    strcpy(cel.ligne3,"|   #~##  |");
                    strcpy(cel.ligne4,"|   ###   |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
            else if(egalA(T.etat,"c")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|        #|");
                    strcpy(cel.ligne3,"|  #~~~#~~|");
                    strcpy(cel.ligne4,"|   #~~~##|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#        |");
                    strcpy(cel.ligne3,"|#~~~#~#  |");
                    strcpy(cel.ligne4,"|##~~~#   |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|   ###   |");
                    strcpy(cel.ligne3,"|   #~~#  |");
                    strcpy(cel.ligne4,"|  #~~#~  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #~#~~#  |");
                    strcpy(cel.ligne3,"|   #~~#  |");
                    strcpy(cel.ligne4,"|   ###   |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
        }
        else if(egalA(T.position,"2")==1)
        {
            if(egalA(T.etat,"n")==1)
            {

                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#########|");
                    strcpy(cel.ligne3,"|&&&&&&&&&|");
                    strcpy(cel.ligne4,"|#########|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#########|");
                    strcpy(cel.ligne3,"|&&&&&&&&&|");
                    strcpy(cel.ligne4,"|#########|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| #&&&&&&#|");
                    strcpy(cel.ligne3,"| #&&&&&&#|");
                    strcpy(cel.ligne4,"| #&&&&&&#|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| #&&&&&&#|");
                    strcpy(cel.ligne3,"| #&&&&&&#|");
                    strcpy(cel.ligne4,"| #&&&&&&#|");
                    strcpy(cel.ligne5,"|---------|");
                }

            }
            else if(egalA(T.etat,"t")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#~#~##~##|");
                    strcpy(cel.ligne3,"|&&~&&~&&&|");
                    strcpy(cel.ligne4,"|###~###~#|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#~#~##~##|");
                    strcpy(cel.ligne3,"|&&~&&~&&&|");
                    strcpy(cel.ligne4,"|###~###~#|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| #~&&~&&~|");
                    strcpy(cel.ligne3,"| ~&&&~&&#|");
                    strcpy(cel.ligne4,"| #&~&&~&#|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| #~&&~&&~|");
                    strcpy(cel.ligne3,"| ~&&&~&&#|");
                    strcpy(cel.ligne4,"| #&~&&~&#|");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
            else if(egalA(T.etat,"c")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#~#~#~#~#|");
                    strcpy(cel.ligne3,"|&~&~&~&~&|");
                    strcpy(cel.ligne4,"|#~#~#~#~#|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#~#~#~#~#|");
                    strcpy(cel.ligne3,"|&~&~&~&~&|");
                    strcpy(cel.ligne4,"|#~#~#~#~#|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| #~&~&~&~|");
                    strcpy(cel.ligne3,"| ~&~&~&~#|");
                    strcpy(cel.ligne4,"| ~&~&&~&~|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| #~&~&~&~|");
                    strcpy(cel.ligne3,"| ~&~&~&~#|");
                    strcpy(cel.ligne4,"| ~&~&~&~&|");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
        }
        else if(egalA(T.position,"3")==1)
        {
            if(egalA(T.etat,"n")==1)
            {

                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#########|");
                    strcpy(cel.ligne3,"|&&&&&&&&&|");
                    strcpy(cel.ligne4,"|#########|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#########|");
                    strcpy(cel.ligne3,"|&&&&&&&&&|");
                    strcpy(cel.ligne4,"|#########|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| #&&&&&# |");
                    strcpy(cel.ligne3,"| #&&&&&# |");
                    strcpy(cel.ligne4,"| #&&&&&# |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| #&&&&&# |");
                    strcpy(cel.ligne3,"| #&&&&&# |");
                    strcpy(cel.ligne4,"| #&&&&&# |");
                    strcpy(cel.ligne5,"|---------|");
                }

            }
            else if(egalA(T.etat,"t")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#~##~##~#|");
                    strcpy(cel.ligne3,"|&&~&&~&&~|");
                    strcpy(cel.ligne4,"|#~##~##~#|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#~##~##~#|");
                    strcpy(cel.ligne3,"|&&~&&~&&~|");
                    strcpy(cel.ligne4,"|#~##~##~#|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| #&~&&~# |");
                    strcpy(cel.ligne3,"| #~&&~&# |");
                    strcpy(cel.ligne4,"| #&~&&~# |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| #&~&&~# |");
                    strcpy(cel.ligne3,"| #~&&~&# |");
                    strcpy(cel.ligne4,"| #&~&&~# |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
            else if(egalA(T.etat,"c")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#~#~#~#~#|");
                    strcpy(cel.ligne3,"|~&~&~&~&~|");
                    strcpy(cel.ligne4,"|#~#~#~#~#|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#~#~#~#~#|");
                    strcpy(cel.ligne3,"|~&~&~&~&~|");
                    strcpy(cel.ligne4,"|#~#~#~#~#|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| ~&~&~&~ |");
                    strcpy(cel.ligne3,"| ~&~&~&~ |");
                    strcpy(cel.ligne4,"| ~&~&~&~ |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| ~&~&~&~ |");
                    strcpy(cel.ligne3,"| ~&~&~&~ |");
                    strcpy(cel.ligne4,"| ~&~&~&~ |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
        }
        else if(egalA(T.position,"4")==1)
        {
            if(egalA(T.etat,"n")==1)
            {

                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#########|");
                    strcpy(cel.ligne3,"|&&&&&&###|");
                    strcpy(cel.ligne4,"|#########|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#########|");
                    strcpy(cel.ligne3,"|###&&&&&&|");
                    strcpy(cel.ligne4,"|#########|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| #&&&&#  |");
                    strcpy(cel.ligne3,"| #&&&&&# |");
                    strcpy(cel.ligne4,"| #&&&&#  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| #&&&&#  |");
                    strcpy(cel.ligne3,"| #&&&&&# |");
                    strcpy(cel.ligne4,"| #&&&&#  |");
                    strcpy(cel.ligne5,"|---------|");
                }

            }
            else if(egalA(T.etat,"t")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#~##~##~#|");
                    strcpy(cel.ligne3,"|&&~&&~##~|");
                    strcpy(cel.ligne4,"|#~##~##~#|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#~##~##~#|");
                    strcpy(cel.ligne3,"|&&~&&~##~|");
                    strcpy(cel.ligne4,"|#~##~##~#|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| #~&&~#  |");
                    strcpy(cel.ligne3,"| #&~&&~# |");
                    strcpy(cel.ligne4,"| #~&&~#  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| #~&&~#  |");
                    strcpy(cel.ligne3,"| #&~&&~# |");
                    strcpy(cel.ligne4,"| #~&&~#  |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
            else if(egalA(T.etat,"c")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#~#~#~#~#|");
                    strcpy(cel.ligne3,"|~&~&~#~#~|");
                    strcpy(cel.ligne4,"|#~#~#~#~#|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#~#~#~#~#|");
                    strcpy(cel.ligne3,"|~&~&~#~#~|");
                    strcpy(cel.ligne4,"|#~#~#~#~#|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| #~&~&~  |");
                    strcpy(cel.ligne3,"| ~&~&~&~ |");
                    strcpy(cel.ligne4,"| ~&~&~#  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #~&~&~ |");
                    strcpy(cel.ligne3,"| #~&~&~& |");
                    strcpy(cel.ligne4,"|  ~&~&~# |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
        }
        else if(egalA(T.position,"5")==1)
        {
            if(egalA(T.etat,"n")==1)
            {

                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#######  |");
                    strcpy(cel.ligne3,"|###&&&#  |");
                    strcpy(cel.ligne4,"|   ###   |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #######|");
                    strcpy(cel.ligne3,"|  ###&&&#|");
                    strcpy(cel.ligne4,"|   ###   |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| #&&&&#  |");
                    strcpy(cel.ligne3,"| #&&&&&# |");
                    strcpy(cel.ligne4,"|   ###   |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|   ###   |");
                    strcpy(cel.ligne3,"| #&&&&&# |");
                    strcpy(cel.ligne4,"| #&&&&#  |");
                    strcpy(cel.ligne5,"|---------|");
                }

            }
            else if(egalA(T.etat,"t")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#~##~##  |");
                    strcpy(cel.ligne3,"|##~&&~#  |");
                    strcpy(cel.ligne4,"|   #~#   |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  ##~##~#|");
                    strcpy(cel.ligne3,"|  #~&&~##|");
                    strcpy(cel.ligne4,"|   #~#   |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| #&~&&~  |");
                    strcpy(cel.ligne3,"| #~&&~&# |");
                    strcpy(cel.ligne4,"|   #~#   |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|   #~#   |");
                    strcpy(cel.ligne3,"| #&~&&~# |");
                    strcpy(cel.ligne4,"| #~&&~#  |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
            else if(egalA(T.etat,"c")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#~#~#~#  |");
                    strcpy(cel.ligne3,"|~#~&~&~  |");
                    strcpy(cel.ligne4,"|   ~#~   |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #~#~#~#|");
                    strcpy(cel.ligne3,"|  #~&~#~#|");
                    strcpy(cel.ligne4,"|   ~#~   |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| #~&~&~  |");
                    strcpy(cel.ligne3,"| #~&~&~# |");
                    strcpy(cel.ligne4,"|   ~#~   |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|   ~#~   |");
                    strcpy(cel.ligne3,"| ~&~&~&~ |");
                    strcpy(cel.ligne4,"| ~&~&~#  |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
        }
    }

    //cellules croiseur

    else if(egalA(T.cel,"CR")==1)
    {
        if(egalA(T.position,"1")==1)
        {
            if(egalA(T.etat,"n")==1)
            {

                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|        #|");
                    strcpy(cel.ligne3,"| #######&|");
                    strcpy(cel.ligne4,"|        #|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#        |");
                    strcpy(cel.ligne3,"|&####### |");
                    strcpy(cel.ligne4,"|#        |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|    #    |");
                    strcpy(cel.ligne3,"|    #    |");
                    strcpy(cel.ligne4,"|   #&#   |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|   #&#   |");
                    strcpy(cel.ligne3,"|    #    |");
                    strcpy(cel.ligne4,"|    #    |");
                    strcpy(cel.ligne5,"|---------|");
                }

            }
            else if(egalA(T.etat,"t")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|        #|");
                    strcpy(cel.ligne3,"| ##~##~#&|");
                    strcpy(cel.ligne4,"|        #|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#        |");
                    strcpy(cel.ligne3,"|&#~##~## |");
                    strcpy(cel.ligne4,"|#        |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|    #    |");
                    strcpy(cel.ligne3,"|    ~    |");
                    strcpy(cel.ligne4,"|   #&#   |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|   #&#   |");
                    strcpy(cel.ligne3,"|    ~    |");
                    strcpy(cel.ligne4,"|    #    |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
            else if(egalA(T.etat,"c")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|        ~|");
                    strcpy(cel.ligne3,"| ~#~#~#~&|");
                    strcpy(cel.ligne4,"|        ~|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|~        |");
                    strcpy(cel.ligne3,"|&~#~#~#~ |");
                    strcpy(cel.ligne4,"|~        |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|    #    |");
                    strcpy(cel.ligne3,"|    ~    |");
                    strcpy(cel.ligne4,"|   ~&~   |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|   ~&~   |");
                    strcpy(cel.ligne3,"|    ~    |");
                    strcpy(cel.ligne4,"|    #    |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
        }
        else if(egalA(T.position,"2")==1)
        {
            if(egalA(T.etat,"n")==1)
            {

                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#########|");
                    strcpy(cel.ligne3,"|&&&&&&&&&|");
                    strcpy(cel.ligne4,"|#########|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#########|");
                    strcpy(cel.ligne3,"|&&&&&&&&&|");
                    strcpy(cel.ligne4,"|#########|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #&&&#  |");
                    strcpy(cel.ligne3,"|  #&&&#  |");
                    strcpy(cel.ligne4,"|  #&&&#  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #&&&#  |");
                    strcpy(cel.ligne3,"|  #&&&#  |");
                    strcpy(cel.ligne4,"|  #&&&#  |");
                    strcpy(cel.ligne5,"|---------|");
                }

            }
            else if(egalA(T.etat,"t")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|##~##~##~|");
                    strcpy(cel.ligne3,"|&~&&~&&~&|");
                    strcpy(cel.ligne4,"|##~##~##~|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|##~##~##~|");
                    strcpy(cel.ligne3,"|&~&&~&&~&|");
                    strcpy(cel.ligne4,"|##~##~##~|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #&~&#  |");
                    strcpy(cel.ligne3,"|  #~&&~  |");
                    strcpy(cel.ligne4,"|  ~&&~#  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #&~&#  |");
                    strcpy(cel.ligne3,"|  #~&&~  |");
                    strcpy(cel.ligne4,"|  ~&&~#  |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
            else if(egalA(T.etat,"c")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|~#~#~#~#~|");
                    strcpy(cel.ligne3,"|&~&~&~&~&|");
                    strcpy(cel.ligne4,"|#~#~#~#~#|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|~#~#~#~#~|");
                    strcpy(cel.ligne3,"|&~&~&~&~&|");
                    strcpy(cel.ligne4,"|#~#~#~#~#|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  ~&~&~  |");
                    strcpy(cel.ligne3,"|  #~&~&  |");
                    strcpy(cel.ligne4,"|  &~&~#  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  ~&~&~  |");
                    strcpy(cel.ligne3,"|  #~&~&  |");
                    strcpy(cel.ligne4,"|  &~&~#  |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
        }
        else if(egalA(T.position,"3")==1)
        {
            if(egalA(T.etat,"n")==1)
            {

                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#########|");
                    strcpy(cel.ligne3,"|&&&&&&&&&|");
                    strcpy(cel.ligne4,"|#########|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#########|");
                    strcpy(cel.ligne3,"|&&&&&&&&&|");
                    strcpy(cel.ligne4,"|#########|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #&&&&# |");
                    strcpy(cel.ligne3,"|  #&&&&# |");
                    strcpy(cel.ligne4,"|  #&&&&# |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #&&&&# |");
                    strcpy(cel.ligne3,"|  #&&&&# |");
                    strcpy(cel.ligne4,"|  #&&&&# |");
                    strcpy(cel.ligne5,"|---------|");
                }

            }
            else if(egalA(T.etat,"t")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|##~##~##~|");
                    strcpy(cel.ligne3,"|&~&&~&&~&|");
                    strcpy(cel.ligne4,"|##~##~##~|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|##~##~##~|");
                    strcpy(cel.ligne3,"|&~&&~&&~&|");
                    strcpy(cel.ligne4,"|##~##~##~|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #&~&&~ |");
                    strcpy(cel.ligne3,"|  #~&&~# |");
                    strcpy(cel.ligne4,"|  ~&&~&# |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #&~&&~ |");
                    strcpy(cel.ligne3,"|  #~&&~# |");
                    strcpy(cel.ligne4,"|  ~&&~&# |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
            else if(egalA(T.etat,"c")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|##~##~##~|");
                    strcpy(cel.ligne3,"|&~&&~&&~&|");
                    strcpy(cel.ligne4,"|##~##~##~|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|##~##~##~|");
                    strcpy(cel.ligne3,"|&~&&~&&~&|");
                    strcpy(cel.ligne4,"|##~##~##~|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #&~&&~ |");
                    strcpy(cel.ligne3,"|  #~&&~# |");
                    strcpy(cel.ligne4,"|  ~&&~&# |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #~&~&~ |");
                    strcpy(cel.ligne3,"|  #~&~&~ |");
                    strcpy(cel.ligne4,"|  ~&~&~# |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
        }
        else if(egalA(T.position,"4")==1)
        {
            if(egalA(T.etat,"n")==1)
            {

                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|###      |");
                    strcpy(cel.ligne3,"|&&&####  |");
                    strcpy(cel.ligne4,"|###      |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|      ###|");
                    strcpy(cel.ligne3,"|  ####&&&|");
                    strcpy(cel.ligne4,"|      ###|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #&&&&# |");
                    strcpy(cel.ligne3,"|   #&&#  |");
                    strcpy(cel.ligne4,"     ##   |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|    ##   |");
                    strcpy(cel.ligne3,"|   #&&#  |");
                    strcpy(cel.ligne4,"|  #&&&&# |");
                    strcpy(cel.ligne5,"|---------|");
                }

            }
            else if(egalA(T.etat,"t")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|##~      |");
                    strcpy(cel.ligne3,"|&~&#~##  |");
                    strcpy(cel.ligne4,"|~##      |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|      ~##|");
                    strcpy(cel.ligne3,"|  ##~#&~&|");
                    strcpy(cel.ligne4,"|      ##~|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #&~&&~ |");
                    strcpy(cel.ligne3,"|   #~&#  |");
                    strcpy(cel.ligne4,"     ##   |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|    ##   |");
                    strcpy(cel.ligne3,"|   #&~#  |");
                    strcpy(cel.ligne4,"|  #&~&&~ |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
            else if(egalA(T.etat,"c")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|~#~      |");
                    strcpy(cel.ligne3,"|&~&~#~#  |");
                    strcpy(cel.ligne4,"|#~#      |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|      #~#|");
                    strcpy(cel.ligne3,"|  ~#~#~&~|");
                    strcpy(cel.ligne4,"|      ###|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #~&~&~ |");
                    strcpy(cel.ligne3,"|   #~&~  |");
                    strcpy(cel.ligne4,"     ~#   |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|    #~   |");
                    strcpy(cel.ligne3,"|   #~&~  |");
                    strcpy(cel.ligne4,"|  #~&~&~ |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
        }
    }

    //cellules contre torpilleur

    else if(egalA(T.cel,"CT")==1)
    {
        if(egalA(T.position,"1")==1)
        {
            if(egalA(T.etat,"n")==1)
            {

                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|    #####|");
                    strcpy(cel.ligne3,"|#####&&&&|");
                    strcpy(cel.ligne4,"|    #####|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#####    |");
                    strcpy(cel.ligne3,"|&&&&#####|");
                    strcpy(cel.ligne4,"|#####    |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|   ##    |");
                    strcpy(cel.ligne3,"|  #&&#   |");
                    strcpy(cel.ligne4,"|  #&&&#  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #&&&#  |");
                    strcpy(cel.ligne3,"|  #&&#   |");
                    strcpy(cel.ligne4,"|   ##    |");
                    strcpy(cel.ligne5,"|---------|");
                }

            }
            else if(egalA(T.etat,"t")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|    ##~##|");
                    strcpy(cel.ligne3,"|##~##~&&~|");
                    strcpy(cel.ligne4,"|    #####|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|##~##    |");
                    strcpy(cel.ligne3,"|&&~&#~#~#|");
                    strcpy(cel.ligne4,"|##~##    |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|   ##    |");
                    strcpy(cel.ligne3,"|  #~&#   |");
                    strcpy(cel.ligne4,"|  #&~&#  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #&~&#  |");
                    strcpy(cel.ligne3,"|  #&~#   |");
                    strcpy(cel.ligne4,"|   ##    |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
            else if(egalA(T.etat,"c")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|    ~#~#~|");
                    strcpy(cel.ligne3,"|#~#~#~&~&|");
                    strcpy(cel.ligne4,"|    ~#~#~|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|~#~#~    |");
                    strcpy(cel.ligne3,"|&~&~&~#~#|");
                    strcpy(cel.ligne4,"|#~#~#    |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|   ~#    |");
                    strcpy(cel.ligne3,"|  #~&~   |");
                    strcpy(cel.ligne4,"|  ~&~&~  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  ~&~&~  |");
                    strcpy(cel.ligne3,"|  ~&~#   |");
                    strcpy(cel.ligne4,"|   ~#    |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
        }
        else if(egalA(T.position,"2")==1)
        {
            if(egalA(T.etat,"n")==1)
            {

                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#########|");
                    strcpy(cel.ligne3,"|&&&&&&&&&|");
                    strcpy(cel.ligne4,"|#########|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#########|");
                    strcpy(cel.ligne3,"|&&&&&&&&&|");
                    strcpy(cel.ligne4,"|#########|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#&&&&&&&#|");
                    strcpy(cel.ligne3,"|#&&&&&&&#|");
                    strcpy(cel.ligne4,"|#&&&&&&&#|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#&&&&&&&#|");
                    strcpy(cel.ligne3,"|#&&&&&&&#|");
                    strcpy(cel.ligne4,"|#&&&&&&&#|");
                    strcpy(cel.ligne5,"|---------|");
                }

            }
            else if(egalA(T.etat,"t")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|##~##~##~|");
                    strcpy(cel.ligne3,"|&~&&~&&~&|");
                    strcpy(cel.ligne4,"|~##~##~##|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|##~##~##~|");
                    strcpy(cel.ligne3,"|&~&&~&&~&|");
                    strcpy(cel.ligne4,"|~##~##~##|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#&~&&~&&~|");
                    strcpy(cel.ligne3,"|#~&&~&&~#|");
                    strcpy(cel.ligne4,"|~&&~&&~&#|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#&~&&~&&~|");
                    strcpy(cel.ligne3,"|#~&&~&&~#|");
                    strcpy(cel.ligne4,"|~&&~&&~&#|");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
            else if(egalA(T.etat,"c")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|##~##~##~|");
                    strcpy(cel.ligne3,"|&~&&~&&~&|");
                    strcpy(cel.ligne4,"|~##~##~##|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|##~##~##~|");
                    strcpy(cel.ligne3,"|&~&&~&&~&|");
                    strcpy(cel.ligne4,"|~##~##~##|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#&~&&~&&~|");
                    strcpy(cel.ligne3,"|#~&&~&&~#|");
                    strcpy(cel.ligne4,"|~&&~&&~&#|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#&~&&~&&~|");
                    strcpy(cel.ligne3,"|#~&&~&&~#|");
                    strcpy(cel.ligne4,"|~&&~&&~&#|");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
        }


        else if(egalA(T.position,"3")==1)
        {
            if(egalA(T.etat,"n")==1)
            {

                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#######  |");
                    strcpy(cel.ligne3,"|&&&&&&###|");
                    strcpy(cel.ligne4,"|#######  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #######|");
                    strcpy(cel.ligne3,"|###&&&&&&|");
                    strcpy(cel.ligne4,"|  #######|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #&&&#  |");
                    strcpy(cel.ligne3,"|  ##&##  |");
                    strcpy(cel.ligne4,"|   ###   |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|   ###   |");
                    strcpy(cel.ligne3,"|  ##&##  |");
                    strcpy(cel.ligne4,"|  #&&&#  |");
                    strcpy(cel.ligne5,"|---------|");
                }

            }
            else if(egalA(T.etat,"t")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|##~##~#  |");
                    strcpy(cel.ligne3,"|&~&&~&#~#|");
                    strcpy(cel.ligne4,"|~##~##~  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  ##~##~#|");
                    strcpy(cel.ligne3,"|##~&&~&&~|");
                    strcpy(cel.ligne4,"|  #~##~##|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #&~&#  |");
                    strcpy(cel.ligne3,"|  #~&#~  |");
                    strcpy(cel.ligne4,"|   ~##   |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|   #~#   |");
                    strcpy(cel.ligne3,"|  ~#&~#  |");
                    strcpy(cel.ligne4,"|  #~&&~  |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
            else if(egalA(T.etat,"c")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|~#~#~#~  |");
                    strcpy(cel.ligne3,"|&~&~&~&~#|");
                    strcpy(cel.ligne4,"|~#~#~#~  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #~#~#~#|");
                    strcpy(cel.ligne3,"|~&~&~&~&~|");
                    strcpy(cel.ligne4,"|  #~#~#~#|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  ~&~&~  |");
                    strcpy(cel.ligne3,"|  ~&~&~  |");
                    strcpy(cel.ligne4,"|   ~#~   |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|   ~#~   |");
                    strcpy(cel.ligne3,"|  ~#~&~  |");
                    strcpy(cel.ligne4,"|  ~&~&~  |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
        }
    }

    //cellules sous marin

    else if(egalA(T.cel,"SM")==1)
    {
        if(egalA(T.position,"1")==1)
        {
            if(egalA(T.etat,"n")==1)
            {

                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|    #####|");
                    strcpy(cel.ligne3,"|#####&&&&|");
                    strcpy(cel.ligne4,"|    #####|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#####    |");
                    strcpy(cel.ligne3,"|&&&&#####|");
                    strcpy(cel.ligne4,"|#####    |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|   ###   |");
                    strcpy(cel.ligne3,"| ###&### |");
                    strcpy(cel.ligne4,"|  #&&&#  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #&&&#  |");
                    strcpy(cel.ligne3,"| ###&### |");
                    strcpy(cel.ligne4,"|   ###   |");
                    strcpy(cel.ligne5,"|---------|");
                }

            }
            else if(egalA(T.etat,"t")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|    ##~##|");
                    strcpy(cel.ligne3,"|#~##~&&~&|");
                    strcpy(cel.ligne4,"|    #~##~|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|##~##    |");
                    strcpy(cel.ligne3,"|&~&&~##~#|");
                    strcpy(cel.ligne4,"|~##~#    |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|   #~#   |");
                    strcpy(cel.ligne3,"| #~#&~## |");
                    strcpy(cel.ligne4,"|  #~&&~  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #~&&~  |");
                    strcpy(cel.ligne3,"| #~#&~## |");
                    strcpy(cel.ligne4,"|   #~#   |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
            else if(egalA(T.etat,"c")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|    ~#~#~|");
                    strcpy(cel.ligne3,"|#~#~&~&~&|");
                    strcpy(cel.ligne4,"|    ~#~#~|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#~#~#    |");
                    strcpy(cel.ligne3,"|&~&~&~#~#|");
                    strcpy(cel.ligne4,"|~#~#~    |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|   #~#   |");
                    strcpy(cel.ligne3,"| #~#~&~# |");
                    strcpy(cel.ligne4,"|  #~&~#  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  ~&~&~  |");
                    strcpy(cel.ligne3,"| ~#~&~#~ |");
                    strcpy(cel.ligne4,"|   #~#   |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
        }
        else if(egalA(T.position,"2")==1)
        {
            if(egalA(T.etat,"n")==1)
            {

                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#########|");
                    strcpy(cel.ligne3,"|&&&&&&&&&|");
                    strcpy(cel.ligne4,"|#########|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#########|");
                    strcpy(cel.ligne3,"|&&&&&&&&&|");
                    strcpy(cel.ligne4,"|#########|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #&&&#  |");
                    strcpy(cel.ligne3,"|  #&&&#  |");
                    strcpy(cel.ligne4,"|  #&&&#  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #&&&#  |");
                    strcpy(cel.ligne3,"|  #&&&#  |");
                    strcpy(cel.ligne4,"|  #&&&#  |");
                    strcpy(cel.ligne5,"|---------|");
                }

            }
            else if(egalA(T.etat,"t")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|##~##~##~|");
                    strcpy(cel.ligne3,"|&~&&~&&~&|");
                    strcpy(cel.ligne4,"|~##~##~##|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|##~##~##~|");
                    strcpy(cel.ligne3,"|&~&&~&&~&|");
                    strcpy(cel.ligne4,"|~##~##~##|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #&~&#  |");
                    strcpy(cel.ligne3,"|  #~&&~  |");
                    strcpy(cel.ligne4,"|  ~&&~#  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #&~&#  |");
                    strcpy(cel.ligne3,"|  #~&&~  |");
                    strcpy(cel.ligne4,"|  ~&&~#  |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
            else if(egalA(T.etat,"c")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|~#~#~#~#~|");
                    strcpy(cel.ligne3,"|&~&~&~&~&|");
                    strcpy(cel.ligne4,"|~#~#~#~#~|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|~#~#~#~#~|");
                    strcpy(cel.ligne3,"|&~&~&~&~&|");
                    strcpy(cel.ligne4,"|~#~#~#~#~|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  ~&~&~  |");
                    strcpy(cel.ligne3,"|  ~&~&~  |");
                    strcpy(cel.ligne4,"|  ~&~&~  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  ~&~&~  |");
                    strcpy(cel.ligne3,"|  ~&~&~  |");
                    strcpy(cel.ligne4,"|  ~&~&~  |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
        }
        else if(egalA(T.position,"3")==1)
        {
            if(egalA(T.etat,"n")==1)
            {

                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|###  ### |");
                    strcpy(cel.ligne3,"|&&####&# |");
                    strcpy(cel.ligne4,"|###  ### |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| ###  ###|");
                    strcpy(cel.ligne3,"| #&####&&|");
                    strcpy(cel.ligne4,"| ###  ###|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  ##&##  |");
                    strcpy(cel.ligne3,"|   ###   |");
                    strcpy(cel.ligne4,"|    #    |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|    #    |");
                    strcpy(cel.ligne3,"|   ###   |");
                    strcpy(cel.ligne4,"|  ##&##  |");
                    strcpy(cel.ligne5,"|---------|");
                }

            }
            else if(egalA(T.etat,"t")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#~#  ##~ |");
                    strcpy(cel.ligne3,"|~&#~##~# |");
                    strcpy(cel.ligne4,"|##~  ~## |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| #~#  ~##|");
                    strcpy(cel.ligne3,"| ~&#~##~&|");
                    strcpy(cel.ligne4,"| ##~  ##~|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  ##~##  |");
                    strcpy(cel.ligne3,"|   ~##   |");
                    strcpy(cel.ligne4,"|    #    |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|    #    |");
                    strcpy(cel.ligne3,"|   ##~   |");
                    strcpy(cel.ligne4,"|  ##~##  |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
            else if(egalA(T.etat,"c")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#~#  ~#~ |");
                    strcpy(cel.ligne3,"|~&~#~#~# |");
                    strcpy(cel.ligne4,"|~#~  ~#~ |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| #~#  ~#~|");
                    strcpy(cel.ligne3,"| ~#~#~#~&|");
                    strcpy(cel.ligne4,"| ~#~  ~#~|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  ~#~#~  |");
                    strcpy(cel.ligne3,"|   ~#~   |");
                    strcpy(cel.ligne4,"|    ~    |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|    ~    |");
                    strcpy(cel.ligne3,"|   ~#~   |");
                    strcpy(cel.ligne4,"|  ~#~#~  |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
        }
    }

    //cellules torpilleur

    else if(egalA(T.cel,"TO")==1)
    {
        if(egalA(T.position,"1")==1)
        {
            if(egalA(T.etat,"n")==1)
            {

                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|     ####|");
                    strcpy(cel.ligne3,"|######&&&|");
                    strcpy(cel.ligne4,"|     ####|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|####     |");
                    strcpy(cel.ligne3,"|&&&######|");
                    strcpy(cel.ligne4,"|####     |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|   ###   |");
                    strcpy(cel.ligne3,"|  ##&##  |");
                    strcpy(cel.ligne4,"|  #&&&#  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #&&&#  |");
                    strcpy(cel.ligne3,"|  ##&##  |");
                    strcpy(cel.ligne4,"|   ###   |");
                    strcpy(cel.ligne5,"|---------|");
                }

            }
            else if(egalA(T.etat,"t")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|     ##~#|");
                    strcpy(cel.ligne3,"|##~##~&&~|");
                    strcpy(cel.ligne4,"|     #~##|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|##~#     |");
                    strcpy(cel.ligne3,"|&~&#~##~#|");
                    strcpy(cel.ligne4,"|~##~     |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|   #~#   |");
                    strcpy(cel.ligne3,"|  #~&#~  |");
                    strcpy(cel.ligne4,"|  ~&&~#  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  ~&&~#  |");
                    strcpy(cel.ligne3,"|  #~&#~  |");
                    strcpy(cel.ligne4,"|   #~#   |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
            else if(egalA(T.etat,"c")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|     ~#~#|");
                    strcpy(cel.ligne3,"|~#~#~&~&~|");
                    strcpy(cel.ligne4,"|     #~#~|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|#~#~     |");
                    strcpy(cel.ligne3,"|&~&~#~#~#|");
                    strcpy(cel.ligne4,"|#~#~     |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|   #~#   |");
                    strcpy(cel.ligne3,"|  ~&~#~  |");
                    strcpy(cel.ligne4,"|  ~&~&~  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  ~&~&~  |");
                    strcpy(cel.ligne3,"|  ~&~#~  |");
                    strcpy(cel.ligne4,"|   #~#   |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
        }
        else if(egalA(T.position,"2")==1)
        {
            if(egalA(T.etat,"n")==1)
            {

                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|######## |");
                    strcpy(cel.ligne3,"|&&&&&&&##|");
                    strcpy(cel.ligne4,"|######## |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| ########|");
                    strcpy(cel.ligne3,"|##&&&&&&&|");
                    strcpy(cel.ligne4,"| ########|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| ##&&&## |");
                    strcpy(cel.ligne3,"|  #&&&#  |");
                    strcpy(cel.ligne4,"|  #####  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #####  |");
                    strcpy(cel.ligne3,"|  #&&&#  |");
                    strcpy(cel.ligne4,"| ##&&&## |");
                    strcpy(cel.ligne5,"|---------|");
                }

            }
            else if(egalA(T.etat,"t")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|##~##~## |");
                    strcpy(cel.ligne3,"|~&&~&&~##|");
                    strcpy(cel.ligne4,"|#~##~##~ |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| ##~##~##|");
                    strcpy(cel.ligne3,"|#~&&~&&~&|");
                    strcpy(cel.ligne4,"| #~##~##~|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| ##~&&~# |");
                    strcpy(cel.ligne3,"|  #&~&#  |");
                    strcpy(cel.ligne4,"|  #~##~  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  ##~##  |");
                    strcpy(cel.ligne3,"|  #~&&~  |");
                    strcpy(cel.ligne4,"| #~&&~## |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
            else if(egalA(T.etat,"c")==1)
            {
                if(egalA(T.orientation,"l")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|~#~#~#~# |");
                    strcpy(cel.ligne3,"|&~&~&~#~#|");
                    strcpy(cel.ligne4,"|#~#~#~#~ |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"r")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| #~#~#~#~|");
                    strcpy(cel.ligne3,"|#~&~&~&~&|");
                    strcpy(cel.ligne4,"| #~#~#~#~|");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"u")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"| #~#~&~# |");
                    strcpy(cel.ligne3,"|  ~&~&~  |");
                    strcpy(cel.ligne4,"|  ~#~#~  |");
                    strcpy(cel.ligne5,"|---------|");
                }
                else if(egalA(T.orientation,"d")==1)
                {
                    strcpy(cel.ligne1,"|---------|");
                    strcpy(cel.ligne2,"|  #~#~#  |");
                    strcpy(cel.ligne3,"|  ~&~&~  |");
                    strcpy(cel.ligne4,"| ~&~&~#~ |");
                    strcpy(cel.ligne5,"|---------|");
                }
            }
        }

    }


    return(cel);
}
