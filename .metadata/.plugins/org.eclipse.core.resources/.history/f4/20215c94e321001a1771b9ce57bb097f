#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Entidad.h"
#include "parser.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* EntidadArray)
{
	Entidad* pAux;
	char bufId[20];
	char bufDescrip[100];
	char bufprecio[20];
	char bufoferta[20];
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufId,bufDescrip,bufprecio,bufoferta);//Para no imprimir la linea 1
	while(!feof(pFile))
	{

		fflush(stdout);
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufId,bufDescrip,bufprecio,bufoferta);
		// pAux=employee_newParametros(&bufId,&bufDescrip,&bufprecio,&bufoferta);
		 pAux=entidad_newParametros(&bufId,&bufDescrip,&bufprecio,&bufoferta);
		 if(pAux!=NULL)
		 {
			 ll_add(EntidadArray,pAux);
		 }
	}

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* EntidadArray)
{
	/*char bufId[20];
	char bufNombre[20];
	char bufHorasTrabajadas[20];
	char bufSueldo[20];
	int retorno = -1;
    //fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufId,bufNombre,bufHorasTrabajadas,bufSueldo);//Para no imprimir la linea 1
	while(!feof(pFile))
	{

		 //fread(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufId,bufNombre,bufHorasTrabajadas,bufSueldo);
        Employee* pAux = employee_new();
		 fread(pAux,sizeof(Employee),1,pFile);
		// pAux=employee_newParametros(bufId,bufNombre,bufHorasTrabajadas,bufSueldo);
		 if(pAux!=NULL)
		 {
			 ll_add(pArrayListEmployee,pAux);
			 retorno = 0;
		 }
	}*/


    return 0;
}
