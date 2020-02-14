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

    printf("%s has been encrpyted to file %s \n", readfile, writefile);
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

void encrpyt_to_console(char *readfile){
    FILE *readfilePnt;
    char ch_In, ch_Out;

    readfilePnt = fopen(readfile, "r");
    printf("Printing %s(encrypted) to console:\n", readfile);
    printf("\n");

    while ((ch_In = fgetc(readfilePnt)) != EOF){
        ch_Out = rot13_encrypt(ch_In);
        putchar(ch_Out);
    }
    printf("\n");
    fclose(readfilePnt);
}
void encrypt_from_console(char *writefile){
    FILE *writefilePnt;
    char ch_In, ch_Out;

    writefilePnt = fopen(writefile, "w");
    printf("Enter text to be encrypted to %s\n", writefile);
    while ((ch_In = getchar()) != '\n'){
        ch_Out = rot13_encrypt(ch_In);
        fputc(ch_Out, writefilePnt);
    }
    printf("Input encrypted to %s\n", writefile);
    fclose(writefilePnt);

}

void encrpyt_to_from_console(){
    char ch_In, ch_Out;

    printf("Enter text to be encrypted\n");
    while ((ch_In = getchar()) != '\n'){
        ch_Out = rot13_encrypt(ch_In);
        putchar(ch_Out);
    }
    printf("\n");
}

int choose_case(char *readfile, char *writefile){
    int case_num = 0; //no flags present

 
    if (readfile != NULL && writefile != NULL){ // both flags present
        case_num = 1;
    }
    else if (readfile != NULL && writefile == NULL){ //-F present only
        case_num = 2;
    }
    else if (readfile == NULL && writefile != NULL){ //-O present only
        case_num = 3;
    }

    return case_num;
    
}

