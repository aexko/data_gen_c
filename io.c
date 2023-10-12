#include "io.h"
#include <stdio.h>
#include <stdlib.h>

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
    char buffer[255];

    fgets(buffer, 255, file_handler);
    printf("%s", buffer);
  }
  fclose(file_handler);
}
