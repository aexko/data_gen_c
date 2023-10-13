#include  "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// https://www.youtube.com/watch?v=vQno9S3yF80
#define MAX_LENGTH 30
#define MAX_LINES 1001


const char *list_first_names[1000];


void read_file(char *fileName) {
    FILE *file_handler = fopen(fileName, "r");
    if (file_handler == NULL) {
        printf("One of the files could not be opened. Please make sure that "
               "the required .txt files are present in the local repository. "
               "Thank you!\n");
        exit(1);
    } else {
        char data[MAX_LINES][MAX_LENGTH];

        int line = 0;

        while (!feof(file_handler) && !ferror(file_handler)) {
          if (fgets(data[line], MAX_LENGTH, file_handler) != NULL) {
            line++;
          }
        }

        for (int i = 0; i < line; i++) {
          printf("%s", data[i]);
        }

    }
    fclose(file_handler);


}
