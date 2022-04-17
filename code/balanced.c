#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RDparser.h"
#include "ptree.h"

int main(int argc, char* argv[]) {
    assert(argv[1]); //to hold the terminal characters of the grammar
    assert(argv[2]); //to hold the input string
    token *tok = init_tokens(argv[2]);
    node *ptree = init_exp_node();
    if(!tok){
        fprintf(stderr, "could not allocate memory to token members");
        exit(1);
    }
    parse(tok, argv[1], ptree);
    printf("Parse Tree: ");
    traverse(ptree); //prints the parse tree 
    printf("\n");
    free_ptree(ptree);
    free(tok);
    return 0;
}
