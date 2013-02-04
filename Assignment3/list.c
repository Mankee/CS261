#include "listbag.h"
#include "type.h"
#include <assert.h>
#include <stdlib.h>

/*
	function to initialize the list, set the sentinels and set the size
	param lst the list
	pre: lst is not null
	post: lst size is 0
*/

void initList (struct list *lst) {
    assert(lst != NULL);
    lst->head = (struct DLink*)malloc(sizeof(struct DLink));
    assert(lst->head != 0);
    lst->tail = (struct DLink*)malloc(sizeof(struct DLink));
    assert(lst->tail != 0);
    lst->head->next = lst->tail;
    lst->tail->prev = lst->head;
    lst->head->prev = NULL;
    lst->tail->next = NULL;
    lst->size = 0;
}


/*
	_addLink
	Funtion to add a value v to the list before the link l
	param: lst the list
	param: lnk the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: lnk is not null
	post: lst is not empty
*/

void _addLink(struct list *lst, struct DLink *lnk, TYPE v)
{
    struct DLink *newlink = (struct DLink*)malloc(sizeof(struct DLink));
    assert(newlink != 0);
    newlink->value = v;
    newlink->prev = lnk->prev;
    newlink->next = lnk;
    lnk->prev->next = newlink;
    lnk->prev = newlink;
    lst->size++;
}


/*
	addFrontList
	Function to add a value to the front of the list, can use _addLink()
	param: lst the list
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addFrontList(struct list *lst, TYPE e)
{
    _addLink(lst, lst->head->next, e);

}

/*
	addBackList
	Function to add a value to the back of the list, can use _addlink()
	param: lst the list
	pre: lst is not null
	post: lst is not empty
*/

void addBackList(struct list *lst, TYPE e)
{
	_addLink(lst, lst->tail, e);
}

/*
	frontList
	function to return the element in the front of the  list
	param: lst the list
	pre: lst is not null
	pre: lst is not empty
	post: none
*/

TYPE frontList (struct list *lst) {
    assert(lst != 0);
    assert(lst->size > 0);
    return lst->head->next->value;
}

/*
	backList
	function to return the element in the back of the  list
	param: lst the list
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/

TYPE backList(struct list *lst)
{
	assert(lst != 0);
    assert(lst->size > 0);
    return lst->tail->prev->value;
}

/*
	_removeLink
	Function to remove a given link
	param: lst the list
	param: lnk the linke to be removed
	pre: lst is not null
	pre: lnk is not null
	post: lst size is reduced by 1
*/

void _removeLink(struct list *lst, struct DLink *lnk)
{
    lnk->prev->next = lnk->next;
    lnk->next->prev = lnk->prev;
    free(lnk);
    lst->size--;
}

/*
	removeFrontList
	Function to remove element from front of list, can use _removelink()
	param: lst the list
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct list *lst) {
    assert(isEmptyList(lst) != 1);
    _removeLink(lst, lst->head->next);
}

/*
	removeBackList
	Function to remove element from back of list, can use _removelink()
	param: lst the list
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/

void removeBackList(struct list *lst)
{
    assert(isEmptyList(lst) != 1);
    _removeLink(lst, lst->tail->prev);
}

/*
	isEmptyList
	param: q the list
	pre: q is not null
	post: none
*/

int isEmptyList(struct list *lst) {
    if(lst->head->next == lst->tail && lst->tail->prev == lst->head){
        return 1;
    }
    return 0;
}



/* Recursive implementation of contains()
 Pre: current is not null
 Post: 1 if found, 0 otherwise
 */
int _contains_recursive(struct DLink* current, TYPE e){
    if(current->next->value == e){
        return 1;
    }
    else if(current->next->next == NULL){
        return 0;
    }
    else{
        return (_contains_recursive(current->next, e));
    }
}

/* Wrapper function for contains
 Pre: lst is not null
 Post: 1 if found, 0 otherwise
 */
int listContains (struct list *lst, TYPE e) {
	assert(!isEmptyList(lst));
	return _contains_recursive(lst->head, e);
}

/* Wrapper for remove()*/
void listRemove (struct list *lst, TYPE e) {
    assert(!isEmptyList(lst));
    struct DLink *current = lst->head->next;

    int i;
    for(i = 0; i < lst->size; i++){
        if(current->value == e){
            _removeLink(lst, current);
            break;
        }
        else if(current->next == NULL){
            break;
        }
        else{
            current = current->next;
        }
    }

}


void freeList(struct list *q)
{
    free(q);
}



