// config.c
// 
// 

#include "config.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/errno.h>  // for errno
#include <string.h>     // for strerror()


char* loadConfig(void){
    FILE* inputFile;
    char* inputFileName = "magnet.conf";
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    inputFile = fopen(inputFileName, "r");
    
    if (inputFile == NULL) {
        fprintf(stderr, "input file: %s: %s\n", inputFileName, strerror(errno));
        exit(EXIT_FAILURE);
    }

    read = getline(&line, &len, inputFile);
    if (read == -1) {
        fprintf(stderr, "Failed to read the first line of %s\n", inputFileName);
        fclose(inputFile);
        free(line);
        exit(EXIT_FAILURE);
    }

    fclose(inputFile);

    return line;  // Caller must free this!
}
