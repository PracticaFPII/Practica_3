#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Incluimos el fichero de las cabezeras de los procedimientos */
#include "../include/headers.h"

#define N_PRUEBAS_BUSQ 7 // MODIFICAR PRUEBAS AQUI
#define INDEX_CONOCIDOS 6 // MODIFICAR NUMERO DE INDICES
#define N_PRUEBAS_DESCONOCIDO 10 // Numeros que se buscan en la tabla

void test_busqueda(int vector[], int *n_columnas)
{
    // Largo del vector que se prueba, hay N_PRUEBAS_BUSQ
    int largo_tabla[] = {10, 50, 100, 1000, 2500, 5000, 10000}; // MODIFICAR PRUEBAS AQUI Y EN N_PRUEBAS_BUSQ
    int i = 0, j, buscado;  // i para las filas, j para las columnas de intercambios[i][j]
    int num_tests=0, num_tests_ok=0, contador=0;

    // tabla donde se guarda las posiciones
    int posiciones_conocido[N_PRUEBAS_BUSQ][INDEX_CONOCIDOS];
    int posiciones_desconocido[N_PRUEBAS_BUSQ][N_PRUEBAS_DESCONOCIDO];


    int conocido[N_PRUEBAS_BUSQ][INDEX_CONOCIDOS] = {
        { 0,  2,   3,   5,    7,    9},  // fila para 10
        { 1, 10,   7,  15,   33,   47},  // fila para 50
        { 2, 20,  25,  45,   56,   99},  // fila para 100
        { 3, 30,  35, 303,  500,  999},  // fila para 1000
        { 5, 40, 105, 300, 1000, 2499},  // fila para 2500
        {20, 50, 780, 900, 1005, 4999},  // fila para 5000
        {39, 60,  67,  70, 4000, 9999},  // fila para 10000
        };


    /* Realizamos las pruebas */
    while(i < N_PRUEBAS_BUSQ){
        *n_columnas = largo_tabla[i];
        vector_ordenado(vector, n_columnas); // Se crea un vector ordenado

        j = 0;
        while(j < INDEX_CONOCIDOS){
            buscado = vector[conocido[i][j]];   // Se guarda el valor del indice conocido
            posiciones_conocido[i][j] = busqueda_ite(vector, *n_columnas, buscado); // se pasa el numero a buscar

            if (conocido[i][j] == posiciones_conocido[i][j]){ // Si la posicion buscada coincide con la conocida aumenta test_ok
                num_tests_ok++;
                contador++;
            }
            num_tests++; // Aumenta el numero de pruebas hechas
            j++;
        }
        j = 0;
        while(j < N_PRUEBAS_DESCONOCIDO){
            buscado = rand();
            posiciones_desconocido[i][j] = busqueda_ite(vector, *n_columnas, buscado);

            if (posiciones_desconocido >= 0){
                contador++;
            }
        }

        i++;
    }



    /* mostramos los resultados*/
    printf(" Se han realizado %d pruebas correctamente de %d hechas \n\n", num_tests_ok, num_tests);
    printf(" Veces que se han encontrado numeros en el vector:");

}

