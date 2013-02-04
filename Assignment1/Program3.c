/* CS261- Assignment 1 - Program3 */
/* Name: Austin Dubina
 * Date: 6/26/2012
 * Solution description:
    -A program that allocates memory of type student and assigns random values to id and score.
    -prints out the values of the student and calculates the average, min, and max of those values
    -student id's are not unique values. two students may have the same id number, which ranges from from 1-10.
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student *x = malloc(10*(sizeof(struct student)));
     /*return the pointer*/
     return x;
}

void generate(struct student* students){
    /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/

    int i;
    printf("ID SCORE \n");
    for( i = 0; i < 10; i++){
        students[i].id = ((rand() % 10) + 1);
        students[i].score = ((rand() % 100) + 1);
    }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    int i;
    for( i = 0; i < 10; i++){
        printf("ID%d Score%d \n",students[i].id, students[i].score);
    }
}

void summary(struct student* students){
    /*Compute and print the minimum, maximum and average scores of the ten students*/
    	int i;
    	int sum = 0;
	int avg = 0;
	int min = 100;
	int max = 0;

    /*computing average*/
    for(i = 0; i < 10; i++){
        sum += students[i].score;
    }
    avg = sum / 10;

    /*computing minimum*/
    for(i = 0; i < 10; i++){
        if(students[i].score < min){
            min = students[i].score;
        }
    }

    /*computing maximum*/
    for(i = 0; i < 10; i++){
        if(students[i].score > max){
            max = students[i].score;
        }
    }
    printf("Average Score: %d \n", avg);
    printf("Minimum Score: %d \n", min);
    printf("Maximum Score: %d \n", max);
}

void deallocate(struct student* stud){
    /*Deallocate memory from stud*/
    free(stud);
}

int main(){
    struct student* stud = NULL;
    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);
    return 0;
}
