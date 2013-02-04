#include<stdio.h>
#include<stdlib.h>
#include "bst.h"
#include "type.h"
#include "structs.h"

/* Example main file to begin exercising your tree */

int main(int argc, char *argv[]) {
    struct BSTree *tree = newBSTree();

    /*Create value of the type of data that you want to store*/
    struct Data myData1;
    struct Data myData2;
    struct Data myData3;
    struct Data myData4;
    struct Data myData5;
    struct Data myData6;
    struct Data myData7;

    myData1.number = 5;
    myData1.name = "rooty";
    myData2.number = 1;
    myData2.name = "lefty";
    myData3.number = 10;
    myData3.name = "righty";
    myData4.number = 3;
    myData4.name = "righty";
    myData5.number = 9;
    myData5.name = "lefty";
    myData6.number = 8;
    myData6.name = "lefty";
    myData7.number = 7;
    myData7.name = "lefty";

    fprintf(stderr, "Adding value...\n");
    /*add the values to BST*/
    addBSTree(tree, &myData1);
    addBSTree(tree, &myData2);
    addBSTree(tree, &myData3);
    addBSTree(tree, &myData4);
    addBSTree(tree, &myData5);
    addBSTree(tree, &myData6);
    addBSTree(tree, &myData7);


    /*Print the entire tree*/
    printTree(tree);
    /*(( 1 ( 3 ) ) 5 ( 10 ))*/

    printf("\nReturn of Contains for value %d = ", myData1.number);
    printf("%d\n", containsBSTree(tree, &myData1));

    struct Data *findNode = (struct Data *)leftMost(tree);
    printf("Left most node = %d\n",findNode->number);

    printf("removing node from tree...\n");
    removeBSTree(tree, &myData1);
    printTree(tree);

    printf("\nReturn of Contains for value %d = ", myData1.number);
    printf("%d\n", containsBSTree(tree, &myData1));

    return 1;
}

