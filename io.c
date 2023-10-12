#include "io.h"
#include <stdio.h>
#include <stdlib.h>

void readFile(char *fileName) {

  FILE *fileHandler = fopen(fileName, "r");
  //    FILE *fileHandler = fopen("first_names.txt", "r");
  if (fileHandler == NULL) {
    printf("One of the files could not be opened. Please make sure that "
           "the required .txt files are present in the local repository. "
           "Thank you.!\n");
    exit(1);
  } else {

    //        char c;
    //        while ((c = fgetc(fileHandler)) != EOF) {
    //            if (c == '%0') {
    //                printf("\n");
    //            } else {
    //                printf("%c", c);
    //
    //            }
    //        }
    char buffer[255];

    fgets(buffer, 255, fileHandler);
    printf("%s", buffer);
  }
  fclose(fileHandler);
}
