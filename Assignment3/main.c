#include "listbag.h"
#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*Function to get number of milliseconds elapsed since program started execution*/
double getMilliseconds() {
   return 1000.0 * clock() / CLOCKS_PER_SEC;
}

int main(){

	struct bag* b = (struct bag*)malloc(sizeof(struct bag));/*Create new bag*/
	initBag(b);/*Initialize*/

    printf("size of list = %d \n", b->lst->size);
    printf("\n");

    addFrontList(b->lst, 3);
    addFrontList(b->lst, 2);
    addBackList(b->lst, 4);
    addBackList(b->lst, 5);
    addBackList(b->lst, 6);
    addFrontList(b->lst, 1);

    int i;
    struct DLink *currentlink = b->lst->head->next;
    for(i = 1; i <= b->lst->size; i++){
            printf("index %d = %d \n", i, currentlink->value);
            currentlink = currentlink->next;
    }
    printf("\n");
    printf("front = %d \n", frontList(b->lst));
    printf("back = %d \n", backList(b->lst));
    printf("is list empty? = %d \n", isEmptyList(b->lst));
    printf("size of list = %d \n", b->lst->size);
    printf("list contains = %d \n", listContains(b->lst, 12));

    printf("\n");
    addToBag(b, 10);
    removeFromBag(b, 1);
    struct DLink *link = b->lst->head->next;
    for(i = 1; i <= b->lst->size; i++){
            printf("index %d = %d \n", i, link->value);
            link = link->next;
    }
    printf("list contains = %d \n", bagContains(b, 100));

    return 0;

}
