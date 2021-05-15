/********************************************************************************
*                PRACTICA 3 - ORDENACIÓN, BUSQUEDA Y COSTE                      *
* POR CRISTIAN FERNANDEZ LOPEZ, DANIEL CLAVERO LAHERA, MASSIN LAAOUAJ MADROUNI  *
*                                    FPII                                       *
********************************************************************************/

#include <stdio.h>
#include <stdbool.h>

#define MAX_TABLA 100000 // el tamaño maximo es de 100 000

/** =========================    FUNCIONES   ================================ **/

void crear_vector(); // CREAR VECTOR
void vector_aleatorio(); // parte 1
void vector_ordenado(); // parte 2 (adicional)

void orden_seleccion(); //parte 1
void orden_burbuja(); // parte 1
void orden_insercion(); // parte 1
void ver_vector(); // parte 1

void busqueda_dicotomica(); // parte 2
