/* CS261- Assignment 1 - Program1*/
/* Name: Austin Dubina
 * Date: 6/28/2012
 * Solution description:
    -prints the memory address of x by passing an argument to a function fooA
    -prints the value of the integer pointed to by iptr, the address pointed to by iptr, and the address of iptr itself
 */

#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value of iptr*/
     printf("Value of iptr: %d \n",*iptr);
     /*Print the address pointed to by iptr*/
     printf("Address pointed to by iptr: %p \n",iptr);
     /*Print the address of iptr itself*/
     printf("Address of iptr itself: %p \n",&iptr);
}

int main(){

    /*declare an integer x*/
    int x;
    /*print the address of x*/
    printf("Address of x: %p \n",&x);
    /*Call fooA() with the address of x*/
    fooA(&x);
    /*print the value of x*/
    printf("Value of x: %d \n",x);
    return 0;
}
