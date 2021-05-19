#include <stdio.h>
#include <stdbool.h>


/* Incluimos el fichero de las cabezeras de los procedimientos */
#include "../include/headers.h"

#define N_PRUEBAS 11 // MODIFICAR PRUEBAS AQUI
#define N_PRUEBAS_IDEAL 11 // MODIFICAR PRUEBAS AQUI

void test_ordenacion(int vector[], int *n_columnas)
{
    // Largo del vector que se prueba, hay N_PRUEBAS
    int largo_tabla[] = {1, 10, 50, 100, 1000, 2500, 5000, 10000, 25000, 50000, 100000}; // MODIFICAR PRUEBAS AQUI Y EN N_PRUEBAS
    int intercambios[3][N_PRUEBAS]; // tabla donde se guarda los contadores de los sistemas de ordenacion
    int i = 0, j; // i para las filas, j para las columnas de intercambios[i][j]
    int veces_repetido[3][N_PRUEBAS];

    /* Realizamos las pruebas */
    while(i < 3)
    {
        j = 0;
        printf("  Prueba %d/3\n", i+1);
        while(j < N_PRUEBAS){
            *n_columnas = largo_tabla[j];
            vector_aleatorio(vector, n_columnas); // generamos vectores aleatorios de distinto largo de la tabla
            

            switch (i){
            case 0:
                intercambios[i][j] = orden_seleccion(vector, *n_columnas, &veces_repetido[i][j]); //guardamos resultados en la primera fila
                break;

            case 1:
                intercambios[i][j] = orden_burbuja(vector, *n_columnas, &veces_repetido[i][j]); //guardamos resultados en la segunda fila
                break;

            case 2:
                intercambios[i][j] = orden_insercion(vector, *n_columnas, &veces_repetido[i][j]); //guardamos resultados en la tercera fila
                break;
            }

            j++;
        }
        i++;
    }

    /* mostramos los resultados*/
    printf("\n Se han hecho las siguientes pruebas: \n\n");
    ver_vector(largo_tabla, N_PRUEBAS);

    printf("\n Ordenacion por seleccion: \n");
    printf("\t Intercambios realizados: \n");
    ver_vector(&intercambios[0][0], N_PRUEBAS); // mostramos la primera fila
    printf("\t Bucles realizados: \n");
    ver_vector(&veces_repetido[0][0], N_PRUEBAS); // mostramos la primera fila

    printf(" Ordenacion por burbuja: \n");
    printf("\t Intercambios realizados: \n");
    ver_vector(&intercambios[1][0], N_PRUEBAS); // mostramos la segunda fila
    printf("\t Bucles realizados: \n");
    ver_vector(&veces_repetido[1][0], N_PRUEBAS); // mostramos la primera fila

    printf(" Ordenacion por insercion: \n");
    printf("\t Intercambios realizados: \n");
    ver_vector(&intercambios[2][0], N_PRUEBAS); // mostramos la tercera fila
    printf("\t Bucles realizados: \n");
    ver_vector(&veces_repetido[2][0], N_PRUEBAS); // mostramos la primera fila

}

void test_caso_mejor(int vector[], int *n_columnas){
    // Largo del vector que se prueba, hay N_PRUEBAS_IDEAL
    int largo_tabla[] = {1, 10, 50, 100, 1000, 2500, 5000, 10000, 25000, 50000, 100000}; // MODIFICAR PRUEBAS AQUI Y EN N_PRUEBAS_IDEAL
    int intercambios[3][N_PRUEBAS_IDEAL], veces_repetido[3][N_PRUEBAS_IDEAL]; // tabla donde se guarda los contadores de los sistemas de ordenacion
    int j = 0; // j para las columnas de intercambios[i][j]

    /* Realizamos las pruebas */
    while(j < N_PRUEBAS_IDEAL) // Nos desplazamos al siguiente tamaño de la tabla
    {

        *n_columnas = largo_tabla[j];
        vector_ordenado(vector, n_columnas); // generamos vectores ordenados de distinto largo de la tabla

        intercambios[0][j] = orden_seleccion(vector, *n_columnas, &veces_repetido[0][j]); //guardamos resultados en la primera fila
        intercambios[1][j] = orden_burbuja(vector, *n_columnas, &veces_repetido[1][j]);   //guardamos resultados en la segunda fila
        intercambios[2][j] = orden_insercion(vector, *n_columnas, &veces_repetido[2][j]); //guardamos resultados en la tercera fila

        j++;
    }

    printf("\n Se han hecho las siguientes pruebas para los casos ideales: \n\n");
    ver_vector(largo_tabla, N_PRUEBAS_IDEAL);

    printf("\n Ordenacion por seleccion: \n\n");
    printf("\t Intercambios realizados: \n");
    ver_vector(&intercambios[0][0], N_PRUEBAS_IDEAL); // mostramos la primera fila
    printf("\t Bucles realizados: \n");
    ver_vector(&veces_repetido[0][0], N_PRUEBAS); // mostramos la primera fila

    printf("\n Ordenacion por burbuja: \n\n");
    printf("\t Intercambios realizados: \n");
    ver_vector(&intercambios[1][0], N_PRUEBAS_IDEAL); // mostramos la segunda fila
    printf("\t Bucles realizados: \n");
    ver_vector(&veces_repetido[1][0], N_PRUEBAS); // mostramos la primera fila

    printf("\n Ordenacion por insercion: \n\n");
    printf("\t Intercambios realizados: \n");
    ver_vector(&intercambios[2][0], N_PRUEBAS_IDEAL); // mostramos la tercera fila
    printf("\t Bucles realizados: \n");
    ver_vector(&veces_repetido[2][0], N_PRUEBAS); // mostramos la primera fila
}
