#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ptree.h"

//Parse Tree Implementation specified for the Balanced-Strings RDparser

/**
Allocates memory and set members for new terminal node
@param val - data value for node
@return n - node struct
**/
node *init_term_node(char val){
    node *n = malloc(sizeof(node));
    if(!n){
        fprintf(stderr, "could not allocate memory\n");
        exit(1);
    }
    char *buf = malloc(sizeof(char));
    if(!buf){
        fprintf(stderr, "could not allocate memory\n");
        exit(1);
    }
    void *cdata = memmove(buf,&val,sizeof(char));
    n->data = cdata;
    n->exp = false;
    n->left = NULL;
    n->mid = NULL;
    n->right = NULL;
    return n;
}
/**
Allocates memory and set members for new expression node
@return n - node struct
**/
node *init_exp_node(){
    node *n = malloc(sizeof(node));
    if(!n){
        fprintf(stderr, "could not allocate memory\n");
        exit(1);
    }
    char *buf = malloc(sizeof(char)*6);
    if(!buf){
        fprintf(stderr, "could not allocate memory\n");
        exit(1);
    }
    void *cdata = memmove(buf,"<exp>",sizeof(char)*6);
    n->data = cdata;
    n->exp = true;
    n->left = NULL;
    n->mid = NULL;
    n->right = NULL;
    return n;
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
    if(!n){
        return NULL;
    }
    if(left != '\0'){
        node *lnode = init_term_node(left);
        n->left = lnode;
    }
    if(mid != '\0'){
        node *mnode = init_term_node(mid);
        n->mid = mnode;
    }
    if(right != '\0'){
        node *rnode = init_term_node(right);
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
        printf("%s ", (char*)n->data);
    }
    else{
        printf("%c ", *(char*)n->data);
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
        if(n->left){
            free(n->left->data);
            free(n->left); 
        }
        if(n->mid){
            free(n->mid->data);
            free(n->mid);
        }
        if(n->right){
            free(n->right->data);
            free(n->right); 
        }
    }
}
