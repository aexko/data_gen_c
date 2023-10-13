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


        char buffer[64];

        char **lines;
        lines = malloc(sizeof(char *) * MORE_LINES);
        size_t total_lines = 0;
        size_t total_chars = 0;
        char c;

        do {

            c = fgetc(file_handler);
            if (ferror(file_handler)) {
                printf("Error reading from file\n");
                exit(1);
            }

            if (feof(file_handler)) {
                break;
            }

            if (total_chars == 0) {
                lines[total_lines] = malloc(MORE_CHARS);

            }

            lines[total_lines][total_chars] = c;
            total_chars++;

            if (c == '\n') {
                lines[total_lines] = realloc(lines[total_lines], total_chars + 1);
                lines[total_lines][total_chars] = '\0';
                total_lines++;
                total_chars = 0;
                // 11:17
            }

        } while (true);

    }
    fclose(file_handler);
}
