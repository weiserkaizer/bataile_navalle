/*
 * main.c
 *
 *  Created on: 22 oct. 2016
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonctions.h"
#include "fonction_graph.h"
#include "donnees.h"
#include "temps.h"

int main()
{
	srand(time(NULL)); //Initialisation de la seed avec le temps machine pour la génération de nombre pseudo-aléatoire
	system("color 1F");
    system("CLS");

    runIntro();

	system("pause");


	return 0;
}
