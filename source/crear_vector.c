#include <stdio.h> 
#include <stdbool.h> 
#include <time.h>

/* Incluimos el fichero de las cabezeras de los procedimientos */
#include "../include/headers.h"

#define //MIN 
#define //MAX 

/*
Un procediment que creï un vector d’enters de mida N i contingut aleatori. Per simplicitat, es
recomana que utilitzeu vectors estàtics, amb una mida màxima de 100000 elements. Agafem
aquest valor perquè farem proves amb vectors petits i grans. 
*/

int aleatorio_entre (int min, int max) /* Es una función que escoge un numero aleatorio de entre un minimo y maximo*/
{
    return (min + (rand()%(max-min+1))); 
}

void crear_vector(int vector[], int *n_columnas) {

    srand((unsigned int)time(NULL));
    
    for (int i = 0; i < MAX_TABLA; i++) {
		vector[i] =  aleatorio_entre(MIN, MAX);
    }

}