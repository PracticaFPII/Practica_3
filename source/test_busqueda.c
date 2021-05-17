#include <stdio.h> 
#include <stdbool.h> 

/* Incluimos el fichero de las cabezeras de los procedimientos */
#include "../include/headers.h"

#define N_PRUEBAS_BUSQ 7 // MODIFICAR PRUEBAS AQUI
#define VALORES_CONOCIDOS 3

void test_busqueda(int vector[], int *n_columnas)
{
    // Largo del vector que se prueba, hay N_PRUEBAS_BUSQ
    int largo_tabla[] = {10, 50, 100, 1000, 2500, 5000, 10000}; // MODIFICAR PRUEBAS AQUI Y EN N_PRUEBAS_BUSQ
    int conocido[][VALORES_CONOCIDOS] = {0, 2, 3};

    int intercambios[3][N_PRUEBAS_BUSQ]; // tabla donde se guarda las posiciones de los sistemas de ordenacion
    int i = 0, j; // i para las filas, j para las columnas de intercambios[i][j]

    /* Realizamos las pruebas */
    while(i < 3)
    {
        
    }

    /* mostramos los resultados*/
    printf(" Se han hecho las siguientes pruebas para la busqueda dicotomica: \n\n");
    ver_vector(largo_tabla, N_PRUEBAS_BUSQ);

    printf(" Ordenacion por seleccion: \n\n");
    ver_vector(intercambios, N_PRUEBAS_BUSQ); // mostramos la primera fila
    printf(" Ordenacion por burbuja: \n\n");
    ver_vector(&(intercambios[N_PRUEBAS_BUSQ]), N_PRUEBAS_BUSQ); // mostramos la segunda fila
    printf(" Ordenacion por insercion: \n\n");
    ver_vector(&(intercambios[N_PRUEBAS_BUSQ*2]), N_PRUEBAS_BUSQ); // mostramos la tercera fila

}

