#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "parser.h"
#include "Linkedlist.h"
#include "eComputer.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int retorno = -1;
	if(pArrayListEmployee != NULL)
	{
		pFile = fopen(path,"r+");
		if(pFile != NULL)
		{
			parser_parseComputer(pFile , pArrayListEmployee);
			fclose(pFile);
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortComputer(LinkedList* pArrayListComputer)
{
	int retorno = -1;
    if(pArrayListComputer != NULL)
    {
    	ll_sort(pArrayListComputer,computer_sort,1);
    	retorno = 0;
    }
	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *><
 */
int controller_ListComputer(LinkedList* pArrayListComputer)
{
	eComputer* pComputer;
	int retorno=-1;
	int i;
	int auxId;
	char auxDescripcion[199];
	int auxPrecio;
	int auxIdTipo;
	char auxOferta[49];
	char auxTipoStr[20];
	if(pArrayListComputer!=NULL)
	{
		printf("\nId,Descripcion,Precio,IdTipo,Oferta");
		for(i=0;i<ll_len(pArrayListComputer);i++)
		{
			pComputer = ll_get(pArrayListComputer,i);
			strcpy(auxDescripcion,pComputer->descripcion);
			strcpy(auxOferta,pComputer->oferta);
			computer_getId(pComputer,&auxId);
			computer_getDescripcion(pComputer,auxDescripcion);
			computer_getPrecio(pComputer,&auxPrecio);
			computer_getIdTipo(pComputer,&auxIdTipo);
			computer_getOferta(pComputer,auxOferta);
			if(auxIdTipo==1)
				strcpy(auxTipoStr,"DESKTOP");
			else
				strcpy(auxTipoStr,"LAPTOP");
			printf("\n%d %s %d %s %s\n",auxId,auxDescripcion,auxPrecio,auxTipoStr,auxOferta);
			retorno = 0;
		}
	}
	return retorno;
}

int controller_map(LinkedList* pArrayListComputer)
{
	int retorno = -1;

	if(pArrayListComputer)
	{
		ll_map(pArrayListComputer,computer_mappeado);
		retorno = 0;
	}
	return retorno;
}

int controller_saveAsText(char* fileName, LinkedList* pArrayListComputer)
{
    int retorno = -1;
    eComputer* pComputer;
    int i;

    FILE* pFile = fopen(fileName,"w+");

    if(pArrayListComputer != NULL && pFile != NULL)
    {
        fprintf(pFile, "Id,Descripcion,Precio,idTipo,Oferta\n");

        for (i=0;i<ll_len(pArrayListComputer);i++)
        {
            pComputer = ll_get(pArrayListComputer, i);

            if(pComputer != NULL)
            {
                fprintf(pFile,"%d,%s,%d,%d,%s\n", pComputer->id,
													pComputer->descripcion,
													pComputer->precio,
													pComputer->idTipo,
													pComputer->oferta);
            }
        }

        fclose(pFile);

        retorno = 1;
    }

    return retorno;

}
