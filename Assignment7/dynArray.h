/* 	dynArray.h : Dynamic Array implementation. */
#ifndef DYNAMIC_ARRAY_INCLUDED
#define DYNAMIC_ARRAY_INCLUDED 1

#include "type.h"


struct DynArr
{
	TYPE *data;		/* pointer to the data array */
	long size;		/* Number of elements in the array */
	long capacity;	/* capacity ofthe array */
};

typedef struct DynArr DynArr;


/* Dynamic Array Functions */
void initDynArr(DynArr *v, long capacity);	
DynArr *newDynArr(long cap);

void freeDynArr(DynArr *v);
void deleteDynArr(DynArr *v);

void _dynArrSetCapacity(DynArr *v, long newCap);
long sizeDynArr(DynArr *v);

void addDynArr(DynArr *v, TYPE val);
TYPE getDynArr(DynArr *v, long pos);
void putDynArr(DynArr *v, long pos, TYPE val);
void swapDynArr(DynArr *v, long i, long  j);
void removeAtDynArr(DynArr *v, long idx);
int isEmptyDynArr(DynArr *v);

void copyDynArr(DynArr *source, DynArr *destination);

/* Heap-based Priority Queue Interface */
TYPE getMinHeap(DynArr *heap);
void addHeap(DynArr *heap, TYPE node);
void removeMinHeap(DynArr *heap);
void sortHeap(DynArr *heap);

#endif
