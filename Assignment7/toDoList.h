#ifndef __TODOLIST_H
#define __TODOLIST_H

#include <stdio.h>
#include "dynArray.h"



TYPE createTask (long priority, char *desc);

void saveList(DynArr *heap, FILE *filePtr);

void loadList(DynArr *heap, FILE *filePtr);

void printList(DynArr *heap);

#endif
