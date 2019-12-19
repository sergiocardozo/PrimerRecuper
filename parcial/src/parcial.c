#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "controller.h"
#include "parser.h"
#include "Linkedlist.h"
#include "eComputer.h"

int main()
{
	LinkedList* listaComputer = ll_newLinkedList();
	LinkedList* listaDesktop = ll_newLinkedList();
	int opcion;
	int flag = 0;
	char nombreArchivo[20];
	do
	{
		printf("\n/****************************************************\
		\nMenu:\
		\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\
		\n\n2. Ordenar por tipo\
		\n3. Listar\
		\n4. Generar campo oferta y listar\
		\n5. filtrar archivo solo desktop\
		\n6. Guardar archivo salida\
		\n7. Salir\
		\n*****************************************************/");
		utn_getUnsignedInt("\nElija una opcion: ","Error,Ingrese solo numeros",1,sizeof(int),1,7,3,&opcion);
		switch(opcion)
		{
		case 1:
			// Leer entregas de archivo data.csv
			if(flag ==  0)
			{

				utn_getTexto("\nIngrese nombre del archivo: ","\nError, vuelva a ingresar el nombre",0,29,3,nombreArchivo);
				controller_loadFromText(nombreArchivo,listaComputer);
				flag = 1;

			}
			else if(flag == 1)
			{
				printf("\nEl archivo ya se cargo correctamente");
			}
			break;
		case 2:
			if(flag == 1)
			{
				controller_sortComputer(listaComputer);
				printf("\nArchivo ordenado correctamente");
			}
			else
				printf("\nDebe cargar un archivo vuelva a la opcion 1");
			break;
		case 3:
			if(flag == 1)
			{
				controller_ListComputer(listaComputer);
			}
			else
				printf("\nDebe cargar un archivo vuelva a la opcion 1");
			break;
		case 4:
			if(flag == 1)
			{
				ll_map(listaComputer,computer_mappeado);
				controller_ListComputer(listaComputer);
			}
			else
				printf("\nDebe cargar un archivo vuelva a la opcion 1");
			break;
		case 5:
			if(flag == 1)
			{
				listaDesktop = ll_filter(listaComputer,computer_filterSoloDesktop);
				printf("\nSe filtraron los archivos correctamente");
			}
			else
				printf("\nDebe cargar un archivo vuelva a la opcion 1");
			break;
		case 6:
			if(flag == 1)
			{
				controller_saveAsText("filtrado.csv",listaDesktop);
				printf("\nArchivo con los datos filtrados guardado correctamente");
			}
			else
				printf("\nDebe cargar un archivo vuelva a la opcion 1");
			break;
		case 7:
			break;
		default:
			printf("\nOpcion invalida, ingrese una opcion de 1 a 7,");
		}

	}while(opcion!= 7);

	return 0;
}
