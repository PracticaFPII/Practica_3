#include <stdio.h> 
#include <stdbool.h> 

/* Incluimos el fichero de las cabezeras de los procedimientos */
#include "../include/headers.h"

/** BUSQUEDA DICOTOMICA **/
void busqueda_dicotomica (int vector[], int n_columnas) {
    int num_buscado,posicion;

    printf(" Introduzca el numero a buscar: ");
    scanf("%d", &num_buscado);

    posicion = busqueda_ite (vector, n_columnas);
}

int busqueda_ite (int vector[], int n_columnas) {
    int i;

    while (i < n_columnas) {

        i = (n_columnas-1)/2; // Buscar el medio


    }
    
}