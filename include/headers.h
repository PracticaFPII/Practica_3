/********************************************************************************
*                PRACTICA 3 - ORDENACIÓN, BUSQUEDA Y COSTE                      *
* POR CRISTIAN FERNANDEZ LOPEZ, DANIEL CLAVERO LAHERA, MASSIN LAAOUAJ MADROUNI  *
*                                    FPII                                       *
********************************************************************************/

#include <stdio.h>
#include <stdbool.h>

#define MAX_TABLA 100000 // el tamaño maximo es de 100 000

/** =========================    FUNCIONES   ================================ **/
void crear_vector(unsigned long long  vector[], int *n_columnas); // CREAR VECTOR
void ver_vector(unsigned long long  vector[], int n_columnas); // parte 1
void vector_aleatorio(unsigned long long  vector[], int *n_columnas);
void vector_ordenado(unsigned long long  vector[], int *n_columnas);


void intercambio(unsigned long long *a, unsigned long long *b); // Usada para intercambiar el contenido de dos variables (o posicion en vector) de enteros
unsigned long long insertar(unsigned long long vector[], int index_insertado, int index_a_desplazar); // Inserta un numero del vector en una posicion menor del vector y desplaza el resto

unsigned long long orden_seleccion(unsigned long long vector[], int n_columnas, unsigned long long *contador_veces); //parte 1
unsigned long long orden_burbuja(unsigned long long vector[], int n_columnas, unsigned long long *contador_veces); // parte 1
unsigned long long orden_insercion(unsigned long long vector[], int n_columnas, unsigned long long *contador_veces); // parte 1


void test_ordenacion(unsigned long long vector[], int *n_columnas); // Mostramos el coste algoritmico en funcion del tamaño del vector aleatorio
void test_caso_mejor(unsigned long long vector[], int *n_columnas); // Mostramos el coste algoritmico en funcion del tamaño del vector ordenado
void test_busqueda(unsigned long long vector[], int *n_columnas); // Mostramos los experimentos realizados a test_busqueda


void busqueda_dicotomica(unsigned long long vector[], int n_columnas); // parte 2
int busqueda_ite(unsigned long long vector[], int n_columnas, int num_buscado); //parte 2
