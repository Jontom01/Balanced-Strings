#ifndef SCANNER_H
#define SCANNER_H

#include <stdbool.h>
#include "ptree.h"

/**
Struct that holds the string of tokens and current position in that string
**/
typedef struct token token;

struct token{
    char *t;
    size_t pos;
};

void tok_next();

token *init_tokens(char *argv);

void parse(token *tok, char *grammar, node *ptree);

void tok_free();

#endif
