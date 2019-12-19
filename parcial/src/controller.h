/*
 * controller.h
 *
 *  Created on: 12 dic. 2019
 *      Author: alumno
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Linkedlist.h"
#include "eComputer.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

int controller_sortComputer(LinkedList* pArrayListComputer);

int controller_ListComputer(LinkedList* pArrayListComputer);

int controller_saveAsText(char* path, LinkedList* pArrayListComputer);

#endif /* CONTROLLER_H_ */
