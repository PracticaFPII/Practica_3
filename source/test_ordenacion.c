#include <stdio.h> 
#include <stdbool.h> 

/* Incluimos el fichero de las cabezeras de los procedimientos */
#include "../include/headers.h"

#define N_PRUEBAS 11 // MODIFICAR PRUEBAS AQUI

void test_ordenacion(int vector[], int *n_columnas)
{
    // Largo del vector que se prueba, hay N_PRUEBAS
    int largo_tabla[] = {1, 10, 50, 100, 1000, 2500, 5000, 10000, 25000, 50000, 100000}; // MODIFICAR PRUEBAS AQUI Y EN N_PRUEBAS
    int intercambios[3][N_PRUEBAS]; // tabla donde se guarda los contadores de los sistemas de ordenacion
    int i = 0, j; // i para las filas, j para las columnas de intercambios[i][j]

    /* Realizamos las pruebas */
    while(i < 3)
    {
        j = 0;
        while(j < N_PRUEBAS){
            *n_columnas = largo_tabla[j];
            vector_aleatorio(vector, n_columnas); // generamos vectores aleatorios de distinto largo de la tabla

            switch (i){
            case 0:
                intercambios[i][j] = orden_seleccion(vector, n_columnas); //guardamos resultados en la primera fila
                break;
            
            case 1:
                intercambios[i][j] = orden_burbuja(vector, n_columnas); //guardamos resultados en la segunda fila
                break;

            case 2:
                intercambios[i][j] = orden_insercion(vector, n_columnas); //guardamos resultados en la tercera fila
                break;
            }

            j++;
        }
        i++;
    }

    /* mostramos los resultados*/
    printf(" Se han hecho las siguientes pruebas para los 3 sistemas de ordenacion: \n\n");
    ver_vector(largo_tabla, N_PRUEBAS);

    printf(" Ordenacion por seleccion: \n\n");
    ver_vector(intercambios, N_PRUEBAS); // mostramos la primera fila
    printf(" Ordenacion por burbuja: \n\n");
    ver_vector(&(intercambios[N_PRUEBAS]), N_PRUEBAS); // mostramos la segunda fila
    printf(" Ordenacion por insercion: \n\n");
    ver_vector(&(intercambios[N_PRUEBAS*2]), N_PRUEBAS); // mostramos la tercera fila

}

void test_caso_mejor(int vector[], int *n_columnas){
    ...
}