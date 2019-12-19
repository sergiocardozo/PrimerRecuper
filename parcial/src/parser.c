#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "parser.h"
#include "Linkedlist.h"
#include "eComputer.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_parseComputer(FILE* pFile , LinkedList* pArrayListComputer)
{
	eComputer* pComputer;
	int retorno = -1;
	int cantidadDatos;
	char bufId[20];
	char bufDescrip[200];
	char bufprecio[20];
	char bufIdTipo[20];

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufId,bufDescrip,bufprecio,bufIdTipo);//Para no imprimir la linea 1
	while(!feof(pFile))
	{

		fflush(stdout);
		cantidadDatos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufId,bufDescrip,bufprecio,bufIdTipo);
		// pComputer=employee_newParametros(&bufId,&bufDescrip,&bufprecio,&bufoferta);

		if(cantidadDatos == 4) // chequeo si recibí los 4 datos que pedí
		{
			pComputer = eComputer_newParametros(bufId,bufDescrip,bufprecio,bufIdTipo); // acá se carga basura
			if(pComputer!=NULL)
			{
				ll_add(pArrayListComputer,pComputer);

					retorno = 1;


			}

		}

	}
	return retorno;
}
