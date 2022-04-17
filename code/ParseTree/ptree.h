#ifndef PTREE_H
#define PTREE_H

#include <stdbool.h>

/**
Node struct to hold necessary data for a 3 branch parse tree implementation
@member data - holds the value for the terminal
@member exp - true if the node represents an expression instead of a terminal
@member left - pointer to left branch node
@member mid - pointer to middle branch node
@member right - pointer to right branch node
**/
typedef struct node node;

struct node{
    char data;
    bool exp;
    node *left;
    node *mid;
    node *right;
};

node *init_ptree();

node *insert(node *n, char left, char mid, char right);

void traverse(node *n);

void free_ptree(node *n);

#endif
