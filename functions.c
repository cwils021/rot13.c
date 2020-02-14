#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

char rot13_encrypt(char ch){
    char encrpyted;

    if ('A' <= ch && ch <= 'M'){
        encrpyted = ch + 13;
    }
    else if ('a' <= ch && ch <= 'm'){
        encrpyted = ch + 13;
    }
    else if ('N' <= ch && ch <= 'Z'){
        encrpyted = ch - 13;
    }
    else if ('n' <= ch && ch <= 'z'){
        encrpyted = ch - 13;
    }
    else{
        encrpyted = ch;
    }

    return encrpyted;
}

void bothFlags_encrypt(char *readfile, char *writefile){
    FILE *readfilePnt;
    FILE *writefilePnt;
    char ch_In;
    char ch_Out;

    readfilePnt = fopen(readfile, "r");
    writefilePnt = fopen(writefile, "w");

    ch_In = fgetc(readfilePnt);
    while (ch_In != EOF){
        ch_Out = rot13_encrypt(ch_In);
        fputc(ch_Out, writefilePnt);
        ch_In = fgetc(readfilePnt);
    }
    fclose(readfilePnt);
    fclose(writefilePnt);

    printf("%s has been encrpyted to file %s\n", readfile, writefile);
}
char* get_readfile(int argc, char** argv){
    char *readfile = NULL;

    if (argc > 1 && argc < 6){
        for(int i = 1; i < argc; i++){
            if(strcmp(argv[i], "-F") == 0){
                readfile = argv[i + 1];
                break;

            }
        }
    }

    return readfile;
}

char* get_writefile(int argc, char** argv){
    char *writefile = NULL;

    if (argc > 1 && argc < 6){
        for(int i = 1; i < argc; i++){
            if(strcmp(argv[i], "-O") == 0){
                writefile = argv[i + 1];
                break;

            }
        }
    }

    return writefile;
}
