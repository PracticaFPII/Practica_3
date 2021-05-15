/********************************************************************************
*                PRACTICA 3 - ORDENACIÓN, BUSQUEDA Y COSTE                      *
* POR CRISTIAN FERNANDEZ LOPEZ, DANIEL CLAVERO LAHERA, MASSIN LAAOUAJ MADROUNI  *
*                                    FPII                                       *
********************************************************************************/

#include <stdio.h> 
#include <stdbool.h> 

/* Incluimos el fichero de las cabezeras de los procedimientos */
#include "include/headers.h"


/** Programa principal **/
int main() 
{
	/* Declaracion de variables */
	int opcion = 0;
	bool salir = false; /* Booleano para salir del programa principal, y repetir el menu */

	/* Bucle del Menu y los procedimientos */
	while (!salir)
	{
		/* Menú principal */
		do
		{
			printf("\n MENU:\n");
			printf(" [1] - Crear vector de contenido aleatorio\n");
            printf(" [2] - Ordenar por seleccion\n");
            printf(" [3] - Ordenar por burbuja\n");
            printf(" [4] - Ordenar por insercion\n");
            printf(" [5] - Ver contenido del vector (si es pequeño)\n");
            printf(" [6] - Busqueda dicotomica (vector ordenado no recursiva)\n");
			printf(" [0] - Salir\n\n");

			printf (" Escribe tu eleccion (el numero entre corchetes): ");
			scanf("%d", &opcion);
			printf("\n ------------------------------------\n\n");
		} while (opcion < 0 || opcion > 7);
		
        /* Realizamos las opciones */
		switch (opcion)
		{	
			case 0: /** SALIR **/
                salir = true;
				printf(" Gracias por utilizar el programa\n");
				printf("\n ------------------------------------\n");
				break;
				
			
			case 1: /** Crear vector de contenido aleatorio **/
                crear_vector();
                printf("\n ------------------------------------\n");
				break;
			
			case 2: /** Ordenar por seleccion **/
                orden_seleccion();
                printf("\n ------------------------------------\n");
				break;
			
			case 3: /** Ordenar por burbuja **/
				orden_burbuja();
                printf("\n ------------------------------------\n");
				break;
			
			case 4: /** Ordenar por insercion **/
				orden_insercion();
                printf("\n ------------------------------------\n");
				break;
			
			case 5: /** Ver contenido del vector **/
				ver_vector();
                printf("\n ------------------------------------\n");
				break;

			case 6: /** Busqueda dicotomica **/
				busqueda_dicotomica();
                printf("\n ------------------------------------\n");
				break;
		}
	}
	return 0; 
} 