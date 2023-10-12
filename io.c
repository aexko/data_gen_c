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
  //    FILE *file_handler = fopen("first_names.txt", "r");
  if (file_handler == NULL) {
    printf("One of the files could not be opened. Please make sure that "
           "the required .txt files are present in the local repository. "
           "Thank you.!\n");
    exit(1);
  } else {

    //        char c;
    //        while ((c = fgetc(file_handler)) != EOF) {
    //            if (c == '%0') {
    //                printf("\n");
    //            } else {
    //                printf("%c", c);
    //
    //            }
    //        }
    int max_length_line = 255;
    char buffer[max_length_line];
//    int counter = 0;
    while (!feof(file_handler)) {
      fgets(buffer, max_length_line, file_handler);
//      list_first_names[counter][0] = (char)*buffer;


      printf("%s", buffer);
    }
  }
  fclose(file_handler);
}
