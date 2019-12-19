#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "parser.h"
#include "Linkedlist.h"
#include "eComputer.h"

eComputer* computer_new()
{
    return (eComputer*) malloc(sizeof(eComputer));
}

int computer_delete(eComputer* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }

    return retorno;
}

eComputer* eComputer_newParametros(char* idStr, char* descripcionStr, char* precioStr,
                           char* tipoStr)
{
    eComputer* pComputer = computer_new();

    if(pComputer != NULL)
    {
    	pComputer->id = atoi(idStr);
    	strcpy(pComputer->descripcion,descripcionStr);
    	pComputer->precio = atoi(precioStr);
    	pComputer->idTipo = atoi(tipoStr);

    }

    return pComputer;
}

int computer_setId(eComputer* this, int value)
{
	int retorno = -1;

    if(this != NULL)
    {
    	this->id = value;
    	retorno = 0;

    }
    return retorno;
}

int computer_getId(eComputer* this, int* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
        *value = this->id;

        retorno = 0;
    }
    return retorno;
}

int computer_setDescripcion(eComputer* this, char* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL && isValidTexto(value))
    {
        if(strlen(value) > 0)
        {
            strncpy(this->descripcion, value, sizeof(this->descripcion));
            retorno = 0;
        }
    }
    return retorno;
}

int computer_getDescripcion(eComputer* this, char* value)
{
    int retorno = -1;

    if(this != NULL && value != NULL)
    {
        strncpy(value, this->descripcion, sizeof(this->descripcion));

        retorno = 0;
    }
    return retorno;
}

int computer_setPrecio(eComputer* this, int value)
{
	int retorno = -1;

	if(this != NULL )
	{
		this->precio = value;
		retorno = 0;

	}
	return retorno;
}

int computer_getPrecio(eComputer* this, int* value)
{
	int retorno = -1;

	if(this != NULL && value != NULL)
	{
		*value = this->precio;

		retorno = 0;
	}
	return retorno;
}

int computer_setIdTipo(eComputer* this, int value)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->precio = value;
		retorno = 0;

	}
	return retorno;
}

int computer_getIdTipo(eComputer* this, int* value)
{
	int retorno = -1;

	if(this != NULL && value != NULL)
	{
		*value = this->idTipo;

		retorno = 0;
	}
	return retorno;

}

int computer_setOferta(eComputer* this, char* value)
{
	int retorno = -1;

	if(this != NULL && value != NULL && isValidName(value)) // && isFecha(value))
	{
		if(strlen(value) > 0)
		{
			strncpy(this->oferta, value, sizeof(this->oferta));
			retorno = 0;
		}
	}
	return retorno;
}

int computer_getOferta(eComputer* this, char* value)
{
	int retorno = -1;
	if(this != NULL)
	{
		if(isValidName(value))
		{
			strncpy(this->oferta,value,sizeof(this->oferta));
			retorno = 0;
		}

	}
	return retorno;
}

int computer_sort(void* thisA, void* thisB )
{
	int retorno = 0;
	int idTipoThisA;
	int idTipoThisB;

	computer_getIdTipo((eComputer*)thisA,&idTipoThisA);
	computer_getIdTipo((eComputer*)thisB,&idTipoThisB);

	if(idTipoThisA > idTipoThisB)
	{
		retorno=1;
	}
	else if(idTipoThisA < idTipoThisB)
	{
		retorno=-1;
	}
	else
	{
		retorno = 0;
	}
	return retorno;
}

int computer_mappeado(void* pComputer)
{
	int retorno = -1;
	eComputer* pComputerAux = pComputer;
	int idTipo;
	int auxPrecio;

	computer_getIdTipo(pComputerAux, &idTipo);
	computer_getPrecio(pComputerAux, &auxPrecio);

	if(idTipo == 1 && auxPrecio >= 20000)
	{
		strcpy(pComputerAux->oferta,"50% DESCUENTO");
		retorno = 0;
	}
	else if(idTipo == 2)
	{
		strcpy(pComputerAux->oferta,"SIN DATOS");
		retorno = 0;
	}
	return retorno;
}

int computer_filterSoloDesktop(void* pComputer)
{
    int retorno = -1;
    eComputer* pAuxComputer = pComputer;

    if(pAuxComputer->idTipo == 2)
    {
        retorno = 0;
    }

    return retorno;
}

