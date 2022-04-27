#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"
#include "ptree.c"

//Recursive Descent Parser Implentation for Balanced-Strings

/**
Initializes token struct
@param argv - array of characters (string)
@return tok - token struct
**/
token *init_tokens(char *argv){
    if(!argv) {
        fprintf(stderr, "empty input string\n");
        exit(1);
    }
    size_t sz = 0;
    //while loop calculates the size of input string
    while(argv[sz] != '\0'){
        sz++;
    }
    sz++;
    token *tok = malloc(sizeof(token));
    if(!tok){
        return NULL;
    }
    char *t = calloc(sz, sizeof(char));
    if(!t){
        return NULL;
    }
    memcpy(t,argv,sz);
    tok->t = t;
    tok->pos = 0;
    return tok;
}
/**
Increments position of char array 't' by one
@param tok - token struct
**/
void tok_next(token *tok){
    tok->pos += 1;
}
/**
Checks if the current character in 't' is equal to val
@param tok - token sturct
@param val - char
**/
void match(token *tok, char val){
    if((*tok).t[tok->pos] != val || (*tok).t[tok->pos] == '\0'){
        fprintf(stderr, "String not accepted\n");
        exit(1);
    }
    tok_next(tok);
}
/**
Implementation of the productions of the grammar
@param tok - token struct
@param grammar - two character array consisting of both terminals in the grammar
@param ptree - node struct
**/
void balanced(token *tok, char *grammar, node *ptree){
    if((*tok).t[tok->pos] == grammar[0]){
        insert(ptree, grammar[0], '\0', grammar[1]);
        ptree->mid = init_exp_node();
        ptree = ptree->mid;
        match(tok,grammar[0]);
        balanced(tok, grammar, ptree);
        match(tok,grammar[1]);
    }
}
/**
Public function that calls balanced and determines whether the input string is accepted by the grammar
@param tok - token struct
@param grammar - two character array consisting of both terminals in the grammar
@param ptree - node struct
**/
void parse(token *tok, char *grammar, node *ptree){
    if(!tok){
        fprintf(stderr, "token struct is NULL\n");
    }
    balanced(tok, grammar, ptree);
    if((*tok).t[tok->pos] != '\0'){
        fprintf(stderr, "String not accepted\n");
        exit(1);
    }
    printf("String accepted\n");
}
/**
Public function that frees the dynamically allocated memory from the program
@param tok - token sturct
**/
void tok_free(token *tok){
    free(tok->t);
    free(tok);
}
