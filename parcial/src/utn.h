/*
 * utn.h
 *
 *  Created on: 12 dic. 2019
 *      Author: alumno
 */

#ifndef UTN_H_
#define UTN_H_

int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado);

int utn_getName(char* msg,char* msgError,int min,int max,int reintentos,char* resultado);
int isValidName(char* stringRecibido);

int utn_getUnsignedInt(  char* msg,char* msgError,int minSize,int maxSize,int min,int max,int reintentos,int* input);
int isValidNumber(char* stringRecibido);

int utn_getTexto(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);
int isValidTexto(char* stringRecibido);

int utn_getChar(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
int isValidChar(char charRecibido);

int utn_getDate(char* msg, char* msgError, int minDate, int maxDate, int reintentos, int* resultado);

int utn_getEdad(char* msg, char* msgError, int minAge, int maxAge, int reintentos, int* resultado);



#endif /* UTN_H_ */
