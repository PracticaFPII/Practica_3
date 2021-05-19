#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Incluimos el fichero de las cabezeras de los procedimientos */
#include "../include/headers.h"

#define N_PRUEBAS_BUSQ 7 // MODIFICAR PRUEBAS AQUI
#define N_PRUEBAS_CONOCIDO 6 // MODIFICAR NUMERO DE INDICES
#define N_PRUEBAS_DESCONOCIDO 10 // Numeros que se buscan en la tabla

void test_busqueda(int vector[], int *n_columnas)
{
    // Largo del vector que se prueba, hay N_PRUEBAS_BUSQ
    int largo_tabla[] = {10, 50, 100, 1000, 2500, 5000, 10000}; // MODIFICAR PRUEBAS AQUI Y EN N_PRUEBAS_BUSQ
    int i = 0, j, buscado;  // i para las filas, j para las columnas de intercambios[i][j]
    int num_tests=0, num_tests_ok=0, contador_ok=0, contador_tot=0;
    int cont_conocidos[N_PRUEBAS_BUSQ] = {0}, cont_desconocidos[N_PRUEBAS_BUSQ] = {0};

    // tabla donde se guarda las posiciones
    int posiciones_conocido;
    int posiciones_desconocido;


    int conocido[N_PRUEBAS_BUSQ][N_PRUEBAS_CONOCIDO] = { // Se selecciona los indices de los valores que se conoceran
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
        while(j < N_PRUEBAS_CONOCIDO){
            buscado = vector[conocido[i][j]];   // Se guarda el valor del indice conocido
            posiciones_conocido = busqueda_ite(vector, *n_columnas, buscado); // Se pasa el numero a buscar

            if (conocido[i][j] == posiciones_conocido){ // Si la posicion buscada coincide con la conocida aumenta test_ok
                num_tests_ok++;
                cont_conocidos[i]++; // sumamos las veces de cada largo de la tabla
            }
            num_tests++; // Aumenta el numero de pruebas hechas
            j++;
        }
        j = 0;
        while(j < N_PRUEBAS_DESCONOCIDO){
            buscado = rand();
            posiciones_desconocido = busqueda_ite(vector, *n_columnas, buscado);

            if (posiciones_desconocido >= 0){
                contador_ok++;
                cont_desconocidos[i]++;
            }
            contador_tot++;
            j++;
        }

        i++;
    }

    /* Mostramos los resultados*/
    printf(" Las diferentes longitudes del vector que se han probado son: \n");
    ver_vector(largo_tabla, N_PRUEBAS_BUSQ);

    printf("\n Se han realizado %d pruebas correctamente de %d hechas\n de los valores que se conoce que estan en el vector\n\n", num_tests_ok, num_tests);
    printf(" Se han realizado %d pruebas correctamente de %d hechas\n de los valores que se desconoce si estan en el vector\n\n", contador_ok, contador_tot);

    printf("\n Se han realizado %d pruebas (valores conocidos) para cada largo de la tabla\n", N_PRUEBAS_CONOCIDO);
    printf(" Las pruebas correctamente hechas fueron:\n");
    ver_vector(cont_conocidos, N_PRUEBAS_BUSQ);

    printf("\n Se han realizado %d pruebas (valores desconocidos) para cada largo de la tabla\n", N_PRUEBAS_DESCONOCIDO);
    printf(" Las pruebas que se han encontrado en el vector:\n");
    ver_vector(cont_desconocidos, N_PRUEBAS_BUSQ);

}

