#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include "fonction_graph.h"

int main()
{

    EtatCase Tj[10][10],To[10][10];
    int i,j;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            Tj[i][j]=creeVarEtat("celVide","1","n","u");
            To[i][j]=creeVarEtat("celVide","1","n","u");
        }
    }



    afficher(Tj,To);


    int J;
    scanf(&J);








    printf("Hello world!\n");
    return 0;
}
