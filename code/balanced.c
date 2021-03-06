#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"
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
    parse(tok, argv[1], ptree); //parses input string which generates parse tree following the head node ptree
    printf("Parse Tree: ");
    traverse(ptree); //prints the parse tree using pre-order traversal
    printf("\n");
    free_ptree(ptree); //deallocates memory
    tok_free(tok); //deallocates memory
    return 0;
}
