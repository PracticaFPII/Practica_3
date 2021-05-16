/********************************************************************************
*                PRACTICA 3 - ORDENACIÓN, BUSQUEDA Y COSTE                      *
* POR CRISTIAN FERNANDEZ LOPEZ, DANIEL CLAVERO LAHERA, MASSIN LAAOUAJ MADROUNI  *
*                                    FPII                                       *
********************************************************************************/

#include <stdio.h>
#include <stdbool.h>

#define MAX_TABLA 100000 // el tamaño maximo es de 100 000

/** =========================    FUNCIONES   ================================ **/
int aleatorio_entre (int min, int max); // genera numeros aleatorios entre un minimo y maximo
void crear_vector(int vector[], int *n_columnas); // CREAR VECTOR
void ver_vector(int vector[], int n_columnas); // parte 1


void intercambio(int *a, int *b); // Usada para intercambiar el contenido de dos variables (o posicion en vector) de enteros
void insertar(int vector[], int index_insertado, int index_a_desplazar); // Inserta un numero del vector en una posicion menor del vector y desplaza el resto

int orden_seleccion(int vector[], int n_columnas); //parte 1
int orden_burbuja(int vector[], int n_columnas); // parte 1
int orden_insercion(int vector[], int n_columnas); // parte 1



void busqueda_dicotomica(int vector[], int n_columnas); // parte 2
