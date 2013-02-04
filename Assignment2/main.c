#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "dynArray.h"

int main(){

    int i;
    int number;
    char selection;
    int j;
    int k;

    struct DynArr *array = newDynArr(10);

    for(i = 0; i < array->capacity; i++){
            addDynArr(array, rand() % 100 + 1);
        }

    while(1){

        printf("\n");
        for(i = 0; i < array->size; i++){
            printf("index %d = %d \n",i, array->data[i]);
        }

        printf("\n");
        printf("Capacity = %d \n", array->capacity);
        printf("Size = %d \n", sizeDynArr(array));

        printf("\n");
        printf("What would you like to do? \np(u)sh, p(o)p, (r)emove, (s)wap, (p)ut, (t)op, (g)et (c)ontains... ");
        scanf("%c", &selection);
        printf("\n");

        switch (selection){

            case 's':
                printf("\n");
                printf("Enter the index value of the two numbers you wish to swap\n");
                printf("index i = ");
                scanf("%d", &j);
                printf("index j = ");
                scanf("%d", &k);
                swapDynArr(array, j, k);
                printf("\n");
                break;

            case 'r':
                printf("\n");
                printf("Enter the index value of the number you wish to remove\n");
                printf("index # = ");
                scanf("%d", &number);
                removeAtDynArr(array, number);
                printf("\n");
                break;

            case 'u':
                number = rand() % 100 + 1;
                pushDynArr(array, number);
                break;

            case 'p':
                printf("\n");
                printf("Enter a number and where you would like to put it\n");
                printf("Value = ");
                scanf("%d", &number);
                printf("index = ");
                scanf("%d", &k);
                putDynArr(array, k, number);
                printf("\n");
                break;

            case 't':
                printf("\n");
                printf("%d is at the top of the stack\n", topDynArr(array));
                printf("\n");
                break;

            case 'g':
                printf("\n");
                printf("Enter the the index you wish to get\n");
                printf("index = ");
                scanf("%d", &number);
                printf("\n");
                printf("%d is at index %d", getDynArr(array, number), number);
                printf("\n");
                break;

            case 'c':
                printf("\n");
                printf("Enter the number you wish to find\n");
                printf("Value = ");
                scanf("%d", &number);
                printf("\n");
                if(containsDynArr(array, number) >= 0){
                    printf("%d was found at index %d", number, (containsDynArr(array, number)));
                }
                else if(containsDynArr(array, number) < 0){
                    printf("%d was not found", number);
                }
                printf("\n");
                break;

            case 'o':
                popDynArr(array);
                break;
        }
    }
    deleteDynArr(array);
    return 0;

}
