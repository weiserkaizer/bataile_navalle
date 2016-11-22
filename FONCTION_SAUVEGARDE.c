#include "FONCTION_SAUVEGARDE.h"

/*EtatCase creeVarEtat(char ch[20],char ch1[20],char ch2[20],char ch3[20])
{
    EtatCase T;
    strcpy(T.cel,ch);
    strcpy(T.position,ch1);
    strcpy(T.etat,ch2);
    strcpy(T.orientation,ch3);



    return(T);
}*/


int sauverReplay(int taille,char saisie[taille] )
{
    FILE * saveReplay = NULL;
    saveReplay = fopen("replay/saveReplay.txt","a");
    if(saveReplay != NULL)
    {
        fputs(saisie,saveReplay);
        fprintf(saveReplay,"\n");
    }
    else
    {
        printf("le fichier n'est pas ouvert lel");
        return 0;
    }
    fclose(saveReplay);
    return 1;

}


int sauverReplay2(int taille,char saisieJ[taille][taille], char saisieM[taille] )
{
    int i = 0;
    int j = 0;
    char  saisiePrecJ[taille][taille];
    char saisiePrecM[taille][taille];
    FILE * saveReplayJ = NULL;

    FILE * saveReplayM = NULL;
    saveReplayJ = fopen("replay/saveReplayJ.txt","a");
    saveReplayM = fopen("replay/saveReplayM.txt", "a");

    if(saveReplayJ != NULL && saveReplayM != NULL)
    {
        if(saisieJ != saisiePrecJ )
        {
            fputs(saisieJ,saveReplayJ);
            fprintf(saveReplayJ,"\n");
            for(i=0; i<taille; i++)
            {
                for(j=0; j<taille; j++)

                {
                    strcpy(saisieJ[i][j],saisiePrecJ[i][j]);
                }
            }

        }
        if(saisieM != saisiePrecM)
        {
            fputs(saisieM,saveReplayM);
            fprintf(saveReplayM,"\n");
            for(i=0; i<taille; i++)
            {
                strcpy(saisieM[i],saisiePrecM[i]);
            }
        }

    }


}


sauverPartie(int taille,EtatCase tabJ[taille][taille],EtatCase tabM[taille][taille])
{
    //renvoie 1 si la sauvegarde a march�, renvoie 0 sinon ;
    int i =0;
    int j =0;
    FILE * sauvegardeJ = NULL ;
    FILE * sauvegardeM = NULL ;
    sauvegardeJ = fopen("sauvegarde/saveJ.txt","r+");
    sauvegardeM = fopen("sauvegarde/saveM.txt","r+");
    if(sauvegardeJ != NULL && sauvegardeM != NULL )
    {
        for(i=0; i<taille; i++)
        {
            for(j=0; j<taille; j++)
            {


                //fputs(tabJ,sauvegardeJ);
                //fputs(tabM,sauvegardeM);
                fprintf(sauvegardeJ,"%s \n",tabJ[i][j].cel);
                fprintf(sauvegardeJ,"%s \n",tabJ[i][j].position);
                fprintf(sauvegardeJ,"%s \n",tabJ[i][j].etat);
                fprintf(sauvegardeJ,"%s \n",tabJ[i][j].orientation);
                fprintf(sauvegardeJ,"\n");

                //printf("%s \n",tabJ);
                //printf("%s\n",tabM);
            }

        }

    }
    else
    {
        printf("Le fichier n'est pas ouvert ");
        return 0;

    }

    fclose(sauvegardeJ);
    fclose(sauvegardeM);
    return 1;

}

int sauvegardeReplay();

EtatCase * reload(int taille, EtatCase  tabJ[taille][taille])
{
    int i,j;
    FILE * reloadJ = NULL;
    //FILE * reloadM = NULL;
    reloadJ = fopen("sauvegarde/saveJ.txt","r");
    //reloadM = fopen("sauvegarde/saveM.txt","r");
    i=0;
    j=0;
    char sld[20];
    rewind(reloadJ);
    if(reloadJ != NULL /*&& reloadM != NULL*/ )
    {
        for(i=0; i<taille; i++)
        {
            for(j=0; j<taille; j++)
            {
                fgets(tabJ[i][j].cel,30,reloadJ);
                fgets(tabJ[i][j].position,30,reloadJ);
                fgets(tabJ[i][j].etat,30,reloadJ);
                fgets(tabJ[i][j].orientation,30,reloadJ);
                fgets(sld,20,reloadJ);
                printf(" la cellule a le statut  et la celulle X du tableau est %s \n", tabJ[i][j].cel);


            }


        }
    }
    else
    {
        printf("Il y a eu une erreur ,d�sol� ");
        //return ;
    }
    fclose(reloadJ);
    return tabJ;
}
