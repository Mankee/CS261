#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cirListDeque.h"

/* internal functions interface */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, struct DLink *newLnk);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);

/* ************************************************************************
	Deque Functions
************************************************************************ */

/* Initialize deque.

	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
*/
void initCirListDeque (struct cirListDeque *q)
{
	assert(q != 0);
	q->Sentinel = (struct DLink *)malloc(sizeof(struct DLink));
	assert(q->Sentinel != 0);
	q->Sentinel->next = q->Sentinel;
	q->Sentinel->prev = q->Sentinel;
	q->Sentinel->value = 0;
	q->size = 0;
}

/* Create a link for a value.

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
    struct DLink* link = (struct DLink *)malloc(sizeof(struct DLink));
    link->value = val;
    link->next = 0;
    link->prev = 0;
    return link;
}

/* Adds a link after another link

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	newLnk	pointer to the new link to add after the existing link
	pre:	q is not null
	pre: 	lnk and newLnk are not null
	pre:	lnk is in the deque
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, struct DLink *newLnk)
{
    newLnk->next = lnk->next;
    lnk->next = newLnk;
    newLnk->prev = lnk;
    newLnk->next->prev = newLnk;
    q->size++;

}

/* Adds a link to the back of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val)
{
    struct DLink* nl = _createLink(val);
    assert(nl != 0);
    _addLinkAfter(q, q->Sentinel->prev, nl);
}

/* Adds a link to the front of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
    struct DLink* nl = _createLink(val);
    assert(nl != 0);
    _addLinkAfter(q, q->Sentinel, nl);
}

/* Get the value of the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q)
{
    struct DLink *front = q->Sentinel->next;
    return front->value;
}

/* Get the value of the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
	struct DLink *back = q->Sentinel->prev;
    return back->value;
}
/* Remove a link from the deque

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	pre:	lnk is in the deque
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
	assert(lnk != 0);
	free(lnk);
	q->size--;
}

/* Remove the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {

	struct DLink *front = q->Sentinel->next->next;
	struct DLink *sen = q->Sentinel;
    assert(q->size > 0);

	_removeLink(q, q->Sentinel->next);
	q->Sentinel->next = front;
	front->prev = sen;
}


/* Remove the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
    struct DLink *back = q->Sentinel->prev->prev;
    struct DLink *sen = q->Sentinel;
    assert(q->size > 0);

    _removeLink(q, q->Sentinel->prev);
    back->next = sen;
    sen->prev = back;
}

/* De-allocate all links of the deque

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including backSentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	struct DLink *current = q->Sentinel->next;
	struct DLink *nextcurrent = q->Sentinel->next->next;
	int i;

	for(i=0; i < q->size; i++){
        free(current);
        current = nextcurrent;
	q->size--;
	}
	free(q->Sentinel);
}

/* Check whether the deque is empty

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {
	if(q->size == 0){
        return 1;
	}
	return 0;
}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{
    int i;
    struct DLink *Ptr = q->Sentinel->next;

    for(i = 0; i < q->size; i++){
        printf("...%d", Ptr->value);
        Ptr = Ptr->next;
    }
    printf("\n");
}

/* Reverse the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed
*/
void reverseCirListDeque(struct cirListDeque *q)
{
	struct DLink *current = q->Sentinel;
	struct DLink *temp = q->Sentinel->next;

    int i;
    for(i = 0; i <= q->size; i++){
        current->next = current->prev;
        current->prev = temp;
        current = temp;
        temp = temp->next;
    }
}
