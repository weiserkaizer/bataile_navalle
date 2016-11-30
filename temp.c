/*
 * temp.c
 *
 *  Created on: 25 nov. 2016
 *      Author: Nicolas
 */

#include <time.h>

int chrono()
{
	time_t temps;
	time(&temps);

	return temps;
}

int diffTemps(int init, int final)
{
	return (difftime(final, init));
}
