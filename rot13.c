#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

int main(int argc, char** argv){

    char *readfile, *writefile;

    if (argc > 5){
        printf("Too many arguments given\n");
        printf("\n");
        exit(0);
    }

    readfile = get_readfile(argc, argv);
    writefile = get_writefile(argc, argv);

    printf("read: %s, write: %s\n", readfile, writefile);


    bothFlags_encrypt(readfile, writefile);






    return 0;
}