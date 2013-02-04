/* CS261- Assignment 1 - Program2*/
/* Name: Austin Dubina
 * Date: 6/26/2012
 * Solution description:
    -A function that doubles the value of int x, sets y to half its value, and returns x + y using pointers
 */

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = (*a) * 2;
    /*Set b to half its original value*/
    *b = (*b) / 2;
    /*Assign a+b to c*/
    c = (*a) + (*b);
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;
    /*Print the values of x, y and z*/
    printf("Value of x: %d \n",x);
    printf("Value of y: %d \n",y);
    printf("Value of z: %d \n",z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    foo(&x,&y,z);
    /*Print the values of x, y and z*/
    printf("Value of x: %d \n",x);
    printf("Value of y: %d \n",y);
    printf("Value of z: %d \n",z);
    /*Print the value returned by foo*/
    printf("Value of foo %d \n", foo(&x,&y,z));
    /*Is the return value different than the value of z?  Why?*/
    /* Yes, because c is not a pointer to int z. z remains unchanged after the function foo is called. */
    return 0;
}


