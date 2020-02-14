#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char rot13_encrypt(char ch);

void bothFlags_encrypt(char *readfile, char *writefile);

char* get_readfile(int argc, char** argv);

char* get_writefile(int argc, char** argv);

void encrpyt_to_console(char *readfile);

void encrypt_from_console(char *writefile);

void encrpyt_to_from_console();

int choose_case(char *readfile, char *writefile);