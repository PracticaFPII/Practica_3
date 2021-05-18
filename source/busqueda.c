#include <stdio.h>
#include <stdbool.h>

/* Incluimos el fichero de las cabezeras de los procedimientos */
#include "../include/headers.h"

#define NO_ENCONTRADO -1

/** BUSQUEDA DICOTOMICA **/
void busqueda_dicotomica (int vector[], int n_columnas) {
    int num_buscado, posicion;
    bool salir;

    do { // Bucle para volver a buscar
        printf(" Introduzca el numero a buscar: ");
        scanf(" %d", &num_buscado);

        posicion = busqueda_ite (vector, n_columnas, num_buscado); //Guardamos la posicion, en caso de encontrar el numero introducido, en caso contrario retorna un "-1"

        if (posicion == NO_ENCONTRADO) { // En caso de no poder encontrar el numero
            printf("\n No se ha podido encontrar el numero %d\n", num_buscado);

        } else { // En caso de encontrar el numero
            printf("\n El numero %d se encuentra en la posicion [%d] del vector\n", num_buscado, posicion);
        }

        do{
        printf(" Desea volver a buscar? [0]No / [1]Si: ");
        scanf(" %d", &num_buscado);
        }while(num_buscado<0 || num_buscado>1);

        if (num_buscado == 0) { // El usuario desea salir
            salir = true;
        }
    } while (!salir);
}


/* busqueda_ite: Función para realizar la busqueda dicotomica */
int busqueda_ite (int vector[], int n_columnas, int num_buscado) {
    int i; // [][i][]
    int pos_inicial = 0; // [X][i][]
    int pos_final = n_columnas-1; // [][i][X]
    int posicion = NO_ENCONTRADO; // En caso de no encontrar el numero, retorna -1
    bool salir;

    i = (n_columnas-1)/2; // Buscar el medio

    while ((pos_inicial < pos_final) && (!salir)) { // Bucle para recorrer en busca del numero pasado por parametro

        if (num_buscado == vector[i]) { // En caso de encontrar

            posicion = i;

            salir = true;
        } else if (num_buscado != vector[i]) {

            if (vector[i] < num_buscado) { // En caso de ser menor
                pos_inicial = i+1;
            } else { // En caso de ser superior
                pos_final = i-1;
            }

            i = (pos_inicial + pos_final)/2; // Calcular el medio
        }
    }

    return posicion;
}
