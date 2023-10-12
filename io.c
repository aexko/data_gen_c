#include <stdio.h>
#include <stdlib.h>
#include "io.h"

void readFile(char *fileName) {
//    char fileName[] = "/Users/alex/Documents/comp348/a1_Kao_Alex_40286533/first_names.txt";

    FILE *fileHandler = fopen(fileName, "r");
    //    FILE *fileHandler = fopen("first_names.txt", "r");
    if (fileHandler != NULL) {
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



    } else {
        printf("Error on opening a file.\n");
        exit(1);
    }
    fclose(fileHandler);

}
