#include <stdio.h>
#include <stdbool.h>

/* Incluimos el fichero de las cabezeras de los procedimientos */
#include "../include/headers.h"

/**  Función que intercambia dos posiciones de la tabla **/
void intercambio(unsigned long long *a, unsigned long long *b){
    unsigned long long aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

/** Funcion que inserta un numero del vector en una posicion menor del vector y desplaza el resto **/
unsigned long long insertar(unsigned long long vector[], int index_insertado, int index_a_desplazar)
{
    unsigned long long contador_cambios = 0;
    int n = index_insertado;

    while (n > index_a_desplazar)
    {
        intercambio(&vector[n], &vector[n-1]);
        contador_cambios++;
        n--;
    }
    return contador_cambios;
}



/* PROCEDIMIENTO PARA ORDENAR POR SELECCIÓN */
unsigned long long orden_seleccion(unsigned long long vector[], int n_columnas, unsigned long long *contador_veces)
{
    unsigned long long contador_cambios = 0;
    int i, j=0, index_min;
    *contador_veces = 0;

    while(j < n_columnas-1) /* Se va avanzando en la tabla ya ordenada */
    {
        i = j;
        index_min = i;
        while (i < n_columnas) /* Se va avanzando en la tabla NO ordenada */
        {
            if (vector[i] < vector[index_min]) /* Comprueba que valor es mas pequeño */
            {
                index_min = i; /* Guarda la posicion del nuevo valor mas pequeño */
            }
            i++;
            (*contador_veces)++;
        }
        intercambio( &vector[index_min], &vector[j]); /* Intercambia el valor mas pequeño por el siguiente no ordenado */
        contador_cambios++;
        j++;
    }
    return contador_cambios;
}



/* PROCEDIMIENTO PARA ORDENAR POR BURBUJA */
unsigned long long orden_burbuja(unsigned long long vector[], int n_columnas, unsigned long long *contador_veces)
{
    unsigned long long contador_cambios = 0;
    int i, n_ordenado;
    bool ordenado = false;
    *contador_veces = 0;

    while(n_columnas > 1 && !ordenado){ // Mientras la tabla no ordenada tenga mas de un elemento

        /* Realizamos una iteracion para ordenar*/
        i = 0;
        n_ordenado=0;
        while (i < n_columnas-1){
            if(vector[i] > vector[i+1]){ // Realizamos el intercambio si no estan ordenados los dos contiguos
                intercambio( &vector[i], &vector[i+1]);
                contador_cambios++;
            }
            else{n_ordenado++;}
            i++;
            (*contador_veces)++;
        }
        if (n_ordenado == n_columnas-1){
            ordenado = true;
        }

        n_columnas--; // Disminuimos las columnas a ordenar
    }
    return contador_cambios;
}



/* PROCEDIMIENTO PARA ORDENAR POR INSERCIÓN */
unsigned long long orden_insercion(unsigned long long vector[], int n_columnas, unsigned long long *contador_veces)
{
    unsigned long long contador_cambios = 0;
    int i = 1, n;
    *contador_veces = 0;

    while (i < n_columnas){ // Hacemos un recorrido comparando para saber donde insertarlo

        n = 1;
        while (n <= i)
        {
            // Comparamos el numero a insertar con las posiciones anteriores
            if( (i == n && vector[i] < vector [0]) || (vector[i] < vector[i-n] && vector[i] > vector[i-n-1]) )
            {
                contador_cambios += insertar(vector, i, i-n);
            }
            n++;
            (*contador_veces)++;
        }
        i++;

    }
    return contador_cambios;
}

