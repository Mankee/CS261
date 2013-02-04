#ifndef __LIST_H
#define __LIST_H

#include "type.h"

struct DLink{/*Structure for a link/node in the list*/
	TYPE value; /*Value of the link*/
	struct DLink* next; /*Ptr to next link*/
	struct DLink* prev; /*Ptr to prev link*/
};

struct list{/*Structure for the list*/
	struct DLink* head; /*Head sentinel of the list*/
	struct DLink* tail; /*Tail sentinel of the list*/
	int size; /*Size of list*/
};

struct bag{/*Sturcture for the bag - just a wrapper - so that you can pass a bag pointer to the bag functions :)*/
	struct list* lst;/*List that implements the bag*/
};

/*Linked list with 2 sentinels*/
void   initList(struct list *l);
int 	isEmptyList(struct list *l);
void  addBackList(struct list *l, TYPE val);
void 	addFrontList(struct list *l, TYPE val);
TYPE  frontList(struct list *l);
TYPE 	backList(struct list *l);
void  removeFrontList(struct list *l);
void 	removeBackList(struct list *l);
int listContains(struct list *lst, TYPE e);
void listRemove (struct list *lst, TYPE e);
void freeList(struct list *lst);

/*Bag interface*/
void initBag(struct bag* b);
void addToBag(struct bag* b, TYPE val);
void removeFromBag(struct bag* b, TYPE val);
int bagContains(struct bag* b, TYPE val);
int isEmptyBag(struct bag* b);
void freeBag(struct bag *b);

#endif
