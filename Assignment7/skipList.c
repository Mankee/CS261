#include <stdio.h>
#include <stdlib.h>
#include "skipList.h"
#include <time.h>	

#define assert

/* ************************************************************************
Internal Functions
 ************************************************************************ */

/* Coin toss function:
 param: 	no parameters
 pre:	no parameres
 post: output is a random intiger number in {0,1} */
int flipSkipLink()
{
	return rand() %2;	
}

/* Move to the right as long as the next element is smaller than the input value:
 param: 	current -- pointer to a place in the list from where we need to slide to the right
 param:	e --  input value
 pre:	current is not NULL
 post: returns one link before the link that contains the input value e */
struct skipLink * slideRightSkipList(struct skipLink *current, TYPE e){
	while ((current->next != 0) && compare(current->next->value, e) == -1)
		current = current->next;
	return current;
}


/* Create a new skip link for a value
	param: e	 -- the value to create a link for
	param: nextLnk	 -- the new link's next should point to nextLnk
	param: downLnk -- the new link's down should point to downLnk
	pre:	none
	post:	a link to store the value */
struct skipLink* newSkipLink(TYPE e, struct skipLink * nextLnk, struct skipLink* downLnk) {
	struct skipLink * tmp = (struct skipLink *) malloc(sizeof(struct skipLink));
	assert(tmp != 0);
	tmp->value = e;
	tmp->next = nextLnk;
	tmp->down = downLnk;
	return tmp;
}


/* Add a new skip link recursively
 param: current -- pointer to a place in the list where the new element should be inserted
 param: e	 -- the value to create a link for
 pre:	current is not NULL
 post: a link to store the value */ 
struct skipLink* skipLinkAdd(struct skipLink * current, TYPE e) {
	struct skipLink *newLink, *downLink;
	newLink = NULL;
	if (current->down == 0) {
		newLink = newSkipLink(e, current->next, 0);
		current->next = newLink;
	}
	else {
		downLink = skipLinkAdd(slideRightSkipList(current->down, e), e);
		if (downLink != 0 && flipSkipLink()) {
			newLink = newSkipLink(e, current->next, downLink);
			current->next = newLink;
		}
	}
	return newLink;
}


/* ************************************************************************
Public Functions
 ************************************************************************ */

/* Initialize skip list:
 param:  slst -- pointer to the skip list
 pre:	slst is not null
 post: the sentinels are allocated, the pointers are set, and the list size equals zero */
void initSkipList (struct skipList *slst) 
{
	slst->topSentinel = (struct skipLink*)malloc(sizeof(struct skipLink));
	slst->size = 0;
	slst->topSentinel->next = NULL;
	slst->topSentinel->down = NULL;
	slst->bottomSentinel = slst->topSentinel;
	
}

/* Checks if an element is in the skip list:
 param: slst -- pointer to the skip list
 param: e -- element to be checked
 pre:	slst is not null
 post: returns true or false  */
int containsSkipList(struct skipList *slst, TYPE e)
{
	struct skipLink *current = slst->topSentinel;
	while(current != NULL){
		current = slideRightSkipList(current,e);
		if ((current->next != NULL) && (current->next->value == e))
			return 1;
		else current = current->down;
		
	}
	return 0;
}


/* Remove an element from the skip list:
 param: slst -- pointer to the skip list
 param: e -- element to be removed
 pre:	slst is not null
 post: the new element is removed from all internal sorted lists */
void removeSkipList(struct skipList *slst, TYPE e)
{
	struct skipLink *current;
	struct skipLink *next;
	current = slst->topSentinel;
	while(current != NULL){
		current = slideRightSkipList(current,e);
		if((current->next != NULL) && (current->next->value == e)){
			next = current->next;
			current->next = current->next->next;
			free(next);
			if(current->down == NULL)
			slst->size--;
		}
		current = current->down;
	}
}




/* Add a new element to the skip list:
	param: slst -- pointer to the skip list
	param: e -- element to be added
	pre:	slst is not null
	post:	the new element is added to the lowest list and randomly to higher-level lists */
void addSkipList(struct skipList *slst, TYPE e)
{
	struct skipLink *downLink, *newLink;
	struct skipLink *newSentinel;
	downLink = skipLinkAdd(slideRightSkipList(slst->topSentinel,e),e);
	if ((downLink != NULL) && (flipSkipLink() == 1)){
		newLink = newSkipLink(e,NULL,downLink);
		newSentinel = newSkipLink(0,newLink,slst->topSentinel);
		slst->topSentinel = newSentinel;
	}
	slst->size++;
}


/* Find the number of elements in the skip list: 
 param: slst -- pointer to the skip list
 pre:	slst is not null
 post: the number of elements */
int sizeSkipList(struct skipList *slst)
{
	
	return slst->size;
}

/* Print the links in the skip list:
	param: slst -- pointer to the skip list
	pre:	slst is not null and slst is not empty
	post: the links in the skip list are printed breadth-first, top-down */
void printSkipList(struct skipList *slst)
{
struct skipLink * level = slst->topSentinel;
struct skipLink *current = slst->topSentinel;
while(level != NULL){
	while(current->next != NULL){
   		printf("%g ",current->next->value);
		current = current->next;
		}
	printf("\n");
	current = level = level->down;
	}
}
/* Merge two skip lists, by adding elements of skip list 2 to skip list 1 
   that are not already contained in skip list 1. 
   The function is also supposed to remove the entire skip list 2 from the memory.
   param: slst1 -- pointer to the skip list 1
   param: slst2 -- pointer to the skip list 2
   pre: slst1 and slst2 are not null, and skip list 1 and skip list 2 are not empty
   post: slst1 points to the merger skip list,  slst2 is null*/
void mergeSkipList(struct skipList *slst1, struct skipList *slst2)
{
	struct skipLink *current,*level;
	current =  slst2->topSentinel;
	while(current->down != NULL)
		current = current->down;
	while(current->next != NULL){
		if (!containsSkipList(slst1,current->next->value)){
			addSkipList(slst1,current->next->value);
		}
		current = current->next;
	}
	
	current = slst2->topSentinel;
	while(current->down != NULL){
		current = current->down;
	}
	
	current = current->next;
	level = current->next;
	while(current->next != NULL){
		removeSkipList(slst2,current->value);
		current = level;
		level = level->next;
	}
}

void removeMinSkipList(struct skipList *slst)
{
	removeSkipList(slst, slst->bottomSentinel->next->value);
}







