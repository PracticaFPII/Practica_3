/********************************************************************************
*                PRACTICA 3 - ORDENACIÓN, BUSQUEDA Y COSTE                      *
* POR CRISTIAN FERNANDEZ LOPEZ, DANIEL CLAVERO LAHERA, MASSIN LAAOUAJ MADROUNI  *
*                                    FPII                                       *
********************************************************************************/

#include <stdio.h>
#include <stdbool.h>

#define MAX_TABLA 100000 // el tamaño maximo es de 100 000

/** =========================    FUNCIONES   ================================ **/

void crear_vector(int vector[], int *n_columnas); // CREAR VECTOR
void vector_aleatorio(int vector[], int *n_columnas); // parte 1
void vector_ordenado(int vector[], int *n_columnas); // parte 2 (adicional)


void intercambio(int *a, int *b); // Usada para intercambiar el contenido de dos variables (o posicion en vector) de enteros

int orden_seleccion(int vector[], int n_columnas); //parte 1
int orden_burbuja(int vector[], int n_columnas); // parte 1
int orden_insercion(int vector[], int n_columnas); // parte 1

void ver_vector(int vector[], int n_columnas); // parte 1

void busqueda_dicotomica(int vector[], int n_columnas); // parte 2
