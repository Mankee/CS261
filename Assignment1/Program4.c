/* CS261- Assignment 1 - Program4*/
/* Name: Austin Dubina
 * Date: 6/26/2012
 * Solution description:
    -allocates memory for array of size n, generates random values for array, and sorts array in accending order.
 */

#include <stdio.h>
#include <stdlib.h>

void sort(int* number, int n){
    /*Sort the given array number , of length n*/
    int j, k, temp;
    for (j = (n - 1); j > 0; j--){
        for (k = 1; k <= j; k++){
            if (number[k - 1] > number[k]){
                temp = number[k-1];
                number[k-1] = number[k];
                number[k] = temp;
            }
        }
    }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    int i;
    /*Allocate memory for an array of n integers using malloc.*/
    int *array = malloc(n * sizeof(int));
    /*Fill this array with random numbers, using rand().*/
    for(i = 0; i < n; i++){
        array[i] = rand();
    }
    /*Print the contents of the array.*/
    for(i = 0; i < n; i++){
        printf("Unsorted: %d",array[i]);
        printf("\n");
    }
    /*Pass this array along with n to the sort() function of part a.*/
    sort(array, n);
    printf("\n");
    /*Print the contents of the array.*/
    for(i = 0; i < n; i++){
        printf("sorted: %d",array[i]);
        printf("\n");
    }
    free(array);
    return 0;

}
