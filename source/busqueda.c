#include <stdio.h> 
#include <stdbool.h> 

/* Incluimos el fichero de las cabezeras de los procedimientos */
#include "../include/headers.h"

/** BUSQUEDA DICOTOMICA **/
void busqueda_dicotomica (int vector[], int n_columnas) {
    int num_buscado,posicion;

    printf(" Introduzca el numero a buscar: ");
    scanf("%d", &num_buscado);

    posicion = busqueda_ite (vector, n_columnas,num_buscado);
}

int busqueda_ite (int vector[], int n_columnas, int num_buscado) {
    int i;
    int pos_inicial = 0;
    int pos_final = -1;
    int posicion;

    i = (n_columnas-1)/2; // Buscar el medio

    while ((pos_inicial < pos_final) && (vector[i] != num_buscado)) {
        
        if (vector[i] < num_buscado) {
            pos_inicial = i+1;
        } else {
            pos_final = i-1;
        }

        i = (pos_inicial + pos_final)/2;
    }
    
}