#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

int main(int argc, char** argv){

    char *readfile, *writefile;

    readfile = argv[1];
    writefile = argv[2];

    bothFlags_encrypt(readfile, writefile);






    return 0;
}