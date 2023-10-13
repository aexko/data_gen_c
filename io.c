#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// https://www.youtube.com/watch?v=vQno9S3yF80
#define MORE_LINES 1024
#define MORE_CHARS 1024


char list_first_names[1000][15];

void read_file(char *fileName) {
    FILE *file_handler = fopen(fileName, "r");
    if (file_handler == NULL) {
        printf("One of the files could not be opened. Please make sure that "
               "the required .txt files are present in the local repository. "
               "Thank you.!\n");
        exit(1);
    } else {

    }
    fclose(file_handler);
}
