/* CS261- Assignment 1 - Program5*/
/* Name: Austin Dubina
 * Date: 6/30/2012
 * Solution description:
    -allocates memory for array of type student with cardinality of 10
    -assigns random scores and ids to student
    -sorts student scores in accending order

 */

#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
    int j, k, tempscore, tempid;
    for (j = (n - 1); j > 0; j--){
        for (k = 1; k <= j; k++){
            if (students[k - 1].score > students[k].score){
                tempscore = students[k-1].score;
                tempid = students[k-1].id;
                students[k-1].score = students[k].score;
                students[k-1].id = students[k].id;
                students[k].score = tempscore;
                students[k].id = tempid;
            }
        }
    }
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 10;

    /*Allocate memory for n students using malloc.*/
    struct student *students = malloc(10*(sizeof(struct student)));

    /*Generate random IDs and scores for the n students, using rand().*/
    int i;
    for( i = 0; i < n; i++){
        students[i].id = ((rand() % 10) + 1);
        students[i].score = ((rand() % 100) + 1);
    }

    /*Print the contents of the array of n students.*/
    for( i = 0; i < 10; i++){
        printf("ID: %d Score: %d \n",students[i].id, students[i].score);
    }
    /*Pass this array along with n to the sort() function*/
    sort(students, n);
    printf("\n");
    /*Print the contents of the array of n students.*/
    for( i = 0; i < 10; i++){
        printf("ID: %d Score: %d \n",students[i].id, students[i].score);
    }
    return 0;
}
