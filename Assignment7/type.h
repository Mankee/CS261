/*	type.h
	
	Defines the type to be stored in the data structure.  These macros
	are for convenience to avoid having to search and replace/dup code
	when you want to build a structure of doubles as opposed to ints
	for example.
*/

#ifndef __TYPE_H
#define __TYPE_H

#define TASK_DESC_SIZE 2

struct Task {
	char description[TASK_DESC_SIZE];  	/* description of the task */
	long priority;			  			/* task priority */  
};


typedef struct Task Task;

# ifndef TYPE
# define TYPE	Task*
# define TYPE_SIZE sizeof(Task*)
# endif

/* function used to compare two TYPE values to each other */
int compare(TYPE left, TYPE right);


#endif
