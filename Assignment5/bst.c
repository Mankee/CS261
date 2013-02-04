/*
 File: bst.c
 Implementation of the binary search tree data structure.

 */
#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "type.h"
#include "bst.h"
#include "structs.h"

struct Node {
    TYPE val;
    struct Node *left;
    struct Node *right;
};

struct BSTree {
    struct Node *root;
    int cnt;
};

void initBSTree(struct BSTree *tree) {
    tree->cnt = 0;
    tree->root = 0;
}

struct BSTree* newBSTree() {
    struct BSTree *tree = (struct BSTree *) malloc(sizeof (struct BSTree));
    assert(tree != 0);

    initBSTree(tree);
    return tree;
}

void _freeBST(struct Node *node) {
    if (node != 0) {
        _freeBST(node->left);
        _freeBST(node->right);
        free(node);
    }
}

void clearBSTree(struct BSTree *tree) {
    _freeBST(tree->root);
    tree->root = 0;
    tree->cnt = 0;
}

void deleteBSTree(struct BSTree *tree) {
    clearBSTree(tree);
    free(tree);
}

int isEmptyBSTree(struct BSTree *tree) {
    return (tree->cnt == 0);
}

int sizeBSTree(struct BSTree *tree) {
    return tree->cnt;
}

struct Node *_addNode(struct Node *cur, TYPE val) {
    if(cur == NULL){
        struct Node *newnode = (struct Node *)malloc(sizeof (struct Node));
        assert(newnode != 0);
        newnode->left = 0;
        newnode->right = 0;
        newnode->val = val;
        return newnode;
    }
    else if(compare(val, cur->val) == 1){
        cur->left = _addNode(cur->left, val);
    }
    else{
        cur->right = _addNode(cur->right, val);
    }
    return cur;
}

void addBSTree(struct BSTree *tree, TYPE val) {
    tree->root = _addNode(tree->root, val);
    tree->cnt++;
}

int containsBSTree(struct BSTree *tree, TYPE val) {
    struct Node *cur = tree->root;
    while(cur != NULL){
        if(compare(val, cur->val) == 0){
            return 1;
        }
        else if(compare(val, cur->val) == 1){
            cur = cur->left;
        }
        else if(compare(val, cur->val) == -1){
            cur = cur->right;
        }
    }
    return 0;
}

TYPE _leftMost(struct Node *cur);

TYPE leftMost(struct BSTree *tree) {
    return _leftMost(tree->root);
}

TYPE _leftMost(struct Node *cur) {
    if(cur->left == NULL){
        return cur->val;
    }
    else{
        return _leftMost(cur->left);
    }
}

struct Node *_removeLeftMost(struct Node *cur) {

    if(cur->left != NULL){
        cur->left = _removeLeftMost(cur->left);

    }
    else{
        if(cur->right != NULL){
        struct Node *temp = cur->right;
        free(cur);
        return temp;
        }
        else{
            free(cur);
            return NULL;
        }
    }
    return cur;
}

struct Node* _removeNode(struct Node *cur, TYPE val) {
    if(compare(val, cur->val) == 0){
        if(cur->right == NULL){
            return cur->left;
        }
        else{
            cur->val = _leftMost(cur->right);
            cur->right = _removeLeftMost(cur->right);
        }
    }
    else if(compare(val, cur->val) == 1){
        cur->left = _removeNode(cur->left, val);
    }
    else{
        cur->right = _removeNode(cur->right, val);
    }
    return cur;
}

void removeBSTree(struct BSTree *tree, TYPE val) {
    if (containsBSTree(tree, val)) {
        tree->root = _removeNode(tree->root, val);
        tree->cnt--;
    }
}

/* The following is used only for debugging, set to "#if 0" when used
  in other applications */
#if 1
#include <stdio.h>

void printNode(struct Node *cur) {
    if (cur == 0) return;
    printf("(");
    printNode(cur->left);
    /*Call print_type which prints the value of the TYPE*/
    print_type(cur->val);
    printNode(cur->right);
    printf(")");
}

void printTree(struct BSTree *tree) {
    if (tree == 0) return;
    printNode(tree->root);
}

#endif
