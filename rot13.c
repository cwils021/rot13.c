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

    int case_num = choose_case(readfile, writefile);

    printf("read: %s, write: %s\n", readfile, writefile);
    printf("case: %d\n", case_num);
    
    if(case_num == 1){
        bothFlags_encrypt(readfile, writefile);
    }
    else if (case_num == 2){
        encrpyt_to_console(readfile);
    }
    else if (case_num == 3){
        encrypt_from_console(writefile);
    }
    else{
        encrpyt_to_from_console();
    }






    return 0;
}