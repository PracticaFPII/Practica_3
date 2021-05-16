#include <stdio.h> 
#include <stdbool.h> 

/* Incluimos el fichero de las cabezeras de los procedimientos */
#include "../include/headers.h"

/**  Función que intercambia dos posiciones de la tabla **/
void intercambio(int *a, int *b){
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

/** Funcion que inserta un numero del vector en una posicion menor del vector y desplaza el resto **/
void insertar(int vector[], int index_insertado, int index_a_desplazar)
{
    int n = index_insertado; 
    int aux = vector[index_insertado];
    
    while (n > index_a_desplazar)
    {
        intercambio(vector[n], vector[n-1]);
        n--;
    }
}



/* PROCEDIMIENTO PARA ORDENAR POR SELECCIÓN */
int orden_seleccion(int vector[], int n_columnas)
{
    int i, contador = 0;

    if(n_columnas > 1) //
    {

    }

}



/* PROCEDIMIENTO PARA ORDENAR POR BURBUJA */
int orden_burbuja(int vector[], int n_columnas)
{
    int i, contador = 0;

    while(n_columnas > 1){ // Mientras la tabla no ordenada tenga mas de un elemento

        /* Realizamos una iteracion para ordenar*/
        i = 0;
        while (i < n_columnas){
            if(vector[i] > vector[i+1]){ // Realizamos el intercambio si no estan ordenados los dos contiguos
                intercambio(vector[i], vector[i+1]); 
                contador++;
            }
            i++; 
        }

        n_columnas--; // Disminuimos las columnas a ordenar
    }
    return contador;
}



/* PROCEDIMIENTO PARA ORDENAR POR INSERCIÓN */
int orden_insercion(int vector[], int n_columnas)
{
    int i = 1, n, contador = 0;

    if (n_columnas > 1) // Si solo hay uno ya esta ordenado
    {
        
        while (i < n_columnas){ // Hacemos un recorrido comparando para saber donde insertarlo

            n = 1;
            while (n <= i) 
            {
                // Comparamos el numero a insertar con las posiciones anteriores
                if( (i == n && vector[i] < vector [0]) || (vector[i] < vector[i-n] && vector[i] > vector[i-n-1]) ) 
                { 
                    insertar(vector, i, i-n);
                    contador++;
                }
                n++;
            }
            i++;

        }
    }
    return contador;
}

