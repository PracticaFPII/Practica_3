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
	int vector[MAX_TABLA], num_columnas, contador; /* Tabla cargada con la que se trabaja */

	srand((unsigned int)time(NULL)); // Iniciamos la semilla para generar numeros aleatorios

	/* Bucle del Menu y los procedimientos */
	while (!salir)
	{
		/* Menú principal */
		do
		{
			printf("\n MENU:\n");
            printf(" [1] - Ordenar por seleccion\n");
            printf(" [2] - Ordenar por burbuja\n");
            printf(" [3] - Ordenar por insercion\n");
            printf(" [4] - Busqueda dicotomica\n");
			printf(" [5] - Medir coste de los procesos de ordenacion\n");
			printf(" [6] - Realizar pruebas busqueda dicotomica\n");
			printf(" [0] - Salir\n\n");

			printf (" Escribe tu eleccion (el numero entre corchetes): ");
			scanf("%d", &opcion);
			printf("\n ------------------------------------\n\n");
		} while (opcion < 0 || opcion > 6);
		
        /* Realizamos las opciones */
		switch (opcion)
		{	
			case 0: /** SALIR **/
                salir = true;
				printf(" Gracias por utilizar el programa\n");
				printf("\n ------------------------------------\n");
				break;
				
			
			case 1: /** Ordenar por seleccion **/
				crear_vector(vector, &num_columnas);
				ver_vector(vector, num_columnas);

                contador = orden_seleccion(vector, num_columnas);

				ver_vector(vector, num_columnas);
				printf(" Se han realizado %d intercambios\n", contador);
                printf("\n ------------------------------------\n");
				break;
			
			case 2: /** Ordenar por burbuja **/
				crear_vector(vector, &num_columnas);
				ver_vector(vector, num_columnas);

                contador = orden_burbuja(vector, num_columnas);

				ver_vector(vector, num_columnas);
				printf(" Se han realizado %d intercambios\n", contador);
                printf("\n ------------------------------------\n");
				break;
			
			case 3: /** Ordenar por insercion **/
				crear_vector(vector, &num_columnas);
				ver_vector(vector, num_columnas);

				contador = orden_insercion(vector, num_columnas);

				ver_vector(vector, num_columnas);
				printf(" Se han realizado %d intercambios\n", contador);
                printf("\n ------------------------------------\n");
				break;
			
			case 4: /** Ver contenido del vector **/
				crear_vector(vector, &num_columnas);
				orden_seleccion(vector, num_columnas);

				busqueda_dicotomica(vector, num_columnas);

                printf("\n ------------------------------------\n");
				break;
			
			case 5: /** Prueba sistemas de ordenacion **/
				test_ordenacion(vector, &num_columnas);
				test_caso_mejor(vector, &num_columnas);
                printf("\n ------------------------------------\n");
				break;
			
			case 6: /** Prueba busqueda dicotomica **/
				test_busqueda(vector, &num_columnas);
                printf("\n ------------------------------------\n");
				break;
		}
	}
	return 0; 
} 