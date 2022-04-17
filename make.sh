#!/bin/bash

gcc -c ptree.c
gcc -c RDparser.c
gcc -o balanced balanced.c RDparser.o

#a very bootleg and temporary build file.
