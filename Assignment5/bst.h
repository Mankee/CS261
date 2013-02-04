#ifndef __BST_H
#define __BST_H
#include "type.h"

/*
  File: bst.h
  Interface definition of the binary search tree data structure.
 */
struct BSTree;
/* Declared in the c source file to hide the structure members from the user. */

/* Initialize binary search tree structure. */
void initBSTree(struct BSTree *tree);

/* Allocate and initialize search tree structure. */
struct BSTree *newBSTree();

/* Deallocate nodes in BST. */
void clearBSTree(struct BSTree *tree);
void deleteBSTree(struct BSTree *tree);

/* Deallocate nodes in BST and BST structure. */
void changeBSTree(struct BSTree *tree);

/*-- BST Bag interface --*/
int isEmptyBSTree(struct BSTree *tree);
int sizeBSTree(struct BSTree *tree);

void addBSTree(struct BSTree *tree, TYPE val);
int containsBSTree(struct BSTree *tree, TYPE val);
void removeBSTree(struct BSTree *tree, TYPE val);
void printTree(struct BSTree *tree);
TYPE leftMost(struct BSTree *tree);
#endif
