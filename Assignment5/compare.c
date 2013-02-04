#include <stdio.h>
#include "bst.h"
#include "assert.h"
#include "structs.h"
#include "type.h"

/*----------------------------------------------------------------------------
 very similar to the compareTo method in java or the strcmp function in c. it
 returns an integer to tell you if the left value is greater then, less then, or
 equal to the right value. you are comparing the number variable, letter is not
 used in the comparison.

 if left < right return -1
 if left > right return 1
 if left = right return 0
 */

/*Define this function type casting the value of void * to the desired type*/
int compare(TYPE left, TYPE right) {
    struct Data *L = (struct Data *)left;
    struct Data *R = (struct Data *)right;

    if(L->number < R->number){
        return 1;
    }
    else if(L->number > R->number){
        return -1;
    }
    else{
        return 0;
    }
}

/*Define this function type casting the value of void * to the desired type*/
void print_type(TYPE curval) {
    struct Data *printer = (struct Data *)curval;
    printf("%d", printer->number);
}


