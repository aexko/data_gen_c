#include <stdio.h>
#include <stdlib.h>
#include "generate.c"



void readFile() {
    char fileName[] = "/Users/alex/Documents/comp348/a1_Kao_Alex_40286533/first_names.txt";

    FILE *fileHandler;
    fileHandler = fopen(fileName, "r");
    //    FILE *fileHandler = fopen("first_names.txt", "r");
    char buffer[255];

    fgets(buffer, 255, fileHandler);
    printf("%s", buffer);



//    if (fileHandler != NULL) {
//        char c;
//        while ((c = fgetc(fileHandler)) != EOF) {
//            if (c == '%0') {
//                printf("\n");
//            } else {
//                printf("%c", c);
//
//            }
//        }
//    } else printf("Error on opening file.\n");
    fclose(fileHandler);


}
