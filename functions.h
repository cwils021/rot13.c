#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char rot13_encrypt(char ch);

void bothFlags_encrypt(char *readfile, char *writefile);

char* get_readfile(int argc, char** argv);

char* get_writefile(int argc, char** argv);