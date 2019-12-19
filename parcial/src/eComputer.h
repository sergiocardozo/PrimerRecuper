/*
 * entidad.h
 *
 *  Created on: 12 dic. 2019
 *      Author: alumno
 */

#ifndef ECOMPUTER_H_
#define ECOMPUTER_H_


typedef struct
{
	int id;
	char descripcion[200];
	int precio;
	int idTipo;
	char oferta[50];

}eComputer;

eComputer* computer_new();

int computer_delete(eComputer* this);

eComputer* eComputer_newParametros(char* id, char* descripcion, char* precio,
                           char* tipo);

int computer_setId(eComputer* this, int value);
int computer_getId(eComputer* this, int* value);

int computer_setDescripcion(eComputer* this, char* value);
int computer_getDescripcion(eComputer* this, char* value);

int computer_setPrecio(eComputer* this, int value);
int computer_getPrecio(eComputer* this, int* value);

int computer_setIdTipo(eComputer* this, int value);
int computer_getIdTipo(eComputer* this, int* value);

int computer_setOferta(eComputer* this, char* value);
int computer_getOferta(eComputer* this, char* value);

int computer_sort(void* thisA, void* thisB );

int computer_mappeado(void* pComputer);

int computer_filterSoloDesktop(void* pComputer);

#endif /* ECOMPUTER_H_ */
