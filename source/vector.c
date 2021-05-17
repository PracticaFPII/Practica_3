#include <stdio.h> 
#include <stdbool.h> 
#include <time.h>

/* Incluimos el fichero de las cabezeras de los procedimientos */
#include "../include/headers.h"

#define //MIN 
#define //MAX 
#define MAX_MOSTRAR 100

/*
Un procediment que creï un vector d’enters de mida N i contingut aleatori. Per simplicitat, es
recomana que utilitzeu vectors estàtics, amb una mida màxima de 100000 elements. Agafem
aquest valor perquè farem proves amb vectors petits i grans. 
*/

/* CREAMOS EL VECTOR */
int aleatorio_entre (int min, int max) /* Es una función que escoge un numero aleatorio de entre un minimo y maximo*/
{
    return (min + (rand()%(max-min+1))); 
}

void crear_vector(int vector[], int *n_columnas) {

    do{
        printf(" Indica el largo de la tabla (tiene que ser entre 1 y 100000): ");
        scanf("%d", n_columnas);
    } while(n_columnas <= 0 && n_columnas > MAX_TABLA);
    
    vector_aleatorio(vector, n_columnas);
}

void vector_aleatorio(int vector[], int *n_columnas){
    srand((unsigned int)time(NULL));

    for (int i = 0; i < n_columnas; i++) {
		vector[i] = aleatorio_entre(MIN, MAX);
    }
}


/* Mostrar el vector */
void ver_vector(int vector[], int n_columnas) {
    int cont, i = 0;
    
    if (n_columnas < MAX_MOSTRAR) {
        while (i < n_columnas) {
            printf(" [%d] - %d\n", i, vector[i]);
            i++;
        }
    }
}