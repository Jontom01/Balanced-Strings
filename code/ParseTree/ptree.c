#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ptree.h"

//Parse Tree Implementation specified for the Balanced-Strings RDparser

/**
Allocates memory and set members for new node
@return n - node struct
**/
node *init_node(){
    node *n = malloc(sizeof(node));
    if(!n){
        fprintf(stderr, "could not allocate memory\n");
        exit(1);
    }
    n->data = '\0';
    n->exp = false;
    n->left = NULL;
    n->mid = NULL;
    n->right = NULL;
    return n;
}
/**
Returns the starting expression node
@return tree - node struct
**/
node *init_ptree(){
    node *tree = init_node();
    if(!tree){
        fprintf(stderr, "could not allocate memory\n");
        exit(1);
    }
    tree->exp = true;
    return tree;
}
/**
Inserts left, middle and right node of a given node
@param n - node struct
@param left - data for left node
@param mid - data for middle node
@param right - data for right node
@return n - node struct
**/
node *insert(node *n, char left, char mid, char right){
    if(left != '\0'){
        node *lnode = init_node();
        lnode->data = left;
        n->left = lnode;
    }
    if(mid != '\0'){
        node *mnode = init_node();
        mnode->data = mid;
        n->mid = mnode;
    }
    if(right != '\0'){
        node *rnode = init_node();
        rnode->data = right;
        n->right = rnode;
    }
    return n;
}
/**
Implementation of pre-order traversal to print the tree
@param n - node struct
**/
void traverse(node *n){
    if (!n){
        return;
    }
    if(n->exp == true){
        printf("%s", "<expression> ");
    }
    else{
        printf("%c ", n->data);
    }
    traverse(n->left);
    traverse(n->mid);
    traverse(n->right);
}
/**
Implementation of post-order traversal which deallocates memory from all branches of an expression node from the bottom up
@param n - node struct
**/
void free_ptree(node *n){
    if (!n){
        return;
    }
    free_ptree(n->left);
    free_ptree(n->mid);
    free_ptree(n->right);
    if(n->exp == true){
        free(n->left);
        free(n->mid);
        free(n->right);
    }
}
