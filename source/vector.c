#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Incluimos el fichero de las cabezeras de los procedimientos */
#include "../include/headers.h"

#define MAX_MOSTRAR 100
#define INTERVAL 10

/*
Un procediment que creï un vector d’enters de mida N i contingut aleatori. Per simplicitat, es
recomana que utilitzeu vectors estàtics, amb una mida màxima de 100000 elements. Agafem
aquest valor perquè farem proves amb vectors petits i grans.
*/

/* CREAR VECTOR */
void crear_vector(unsigned long long vector[], int *n_columnas) {

    do{
        printf(" Indica el largo de la tabla (tiene que ser entre 1 y 100000): ");
        scanf("%d", n_columnas);
    } while(*n_columnas <= 0 || *n_columnas > MAX_TABLA);

    vector_aleatorio(vector, n_columnas);
}


void vector_aleatorio(unsigned long long vector[], int *n_columnas){

    for (int i = 0; i < *n_columnas; i++) {
		vector[i] = rand();
    }
}

void vector_ordenado(unsigned long long vector[], int *n_columnas){
    unsigned long long veces_repetido;

    vector_aleatorio(vector, n_columnas);
    orden_seleccion(vector, *n_columnas, &veces_repetido);
}


/* Mostrar el vector */
void ver_vector(unsigned long long vector[], int n_columnas) {
    int i = 0;

    if (n_columnas < MAX_MOSTRAR) {
        while (i < n_columnas) {
            printf(" [%d] - %llu\n", i, vector[i]);
            i++;
        }
        printf("\n");
    }
}

/*
void histograma(unsigned long long vector[], int n_columnas) {

    int i = 0, max = 0, div, contador_histograma;

    printf("Cuantos intervalos quieres generar?");
    scanf(" %d", div);

    contador_histograma = (int*)malloc(div*sizeof(int));

    div = max/div;

    while (vector[i] < n_columnas) {



        i++;
    }

    free (contador_histograma);
}
*/
