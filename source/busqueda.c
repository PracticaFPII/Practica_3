#include <stdio.h> 
#include <stdbool.h> 

/* Incluimos el fichero de las cabezeras de los procedimientos */
#include "../include/headers.h"

/** BUSQUEDA DICOTOMICA **/
void busqueda_dicotomica (int vector[], int n_columnas) {
    int num_buscado, posicion;
    bool salir;

    do { // Bucle en caso de no encontrar el numero
        printf(" Introduzca el numero a buscar: ");
        scanf(" %d", &num_buscado);
        
        posicion = busqueda_ite (vector, n_columnas, num_buscado); //Guardamos la posicion, en caso de encontrar el numero introducido, en caso contrario retorna un "-1"

        if (posicion == -1) { // En caso de no poder encontrar el numero 
            printf("\n No se ha podido encontrar el numero %d\n", num_buscado);
            printf(" Desea volver a buscar? [0]No / [1]Si");
            scanf(" %d", &num_buscado);

            if (num_buscado == 0) { // El usuario desea salir
                salir = true;
            }
        } else { // En caso de encontrar el numero
            printf("\n El numero %d se encuentra en la posicion [%d]\n", num_buscado, posicion);
            salir = true;
        }

    } while (!salir);
}


/* busqueda_ite: Función para realizar la busqueda dicotomica */
int busqueda_ite (int vector[], int n_columnas, int num_buscado) {
    int i; // [][i][]
    int pos_inicial = 0; // [X][i][]
    int pos_final = n_columnas-1; // [][i][X]
    int posicion;

    i = (n_columnas-1)/2; // Buscar el medio
    
    if (num_buscado != vector[i]) { // En caso de que el numero de la mitad no sea el buscado

        while ((pos_inicial < pos_final) && (vector[i] != num_buscado)) { // Bucle para recorrer en busca del numero pasado por parametro

            if (vector[i] < num_buscado) {
                pos_inicial = i+1;
            } else {
                pos_final = i-1;
            }

            i = (pos_inicial + pos_final)/2;
        }
    }

    if (num_buscado == vector[i]) {
        posicion = i;
    } else { // En caso de no encontrar el numero retorna "-1"
        posicion = -1;
    } 

    return posicion;
}