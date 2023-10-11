#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"

#define ERROR '-1'
#define MENU '0'
#define NEW_TABLE '1'
#define EXIT '2'

void cleanUserInput(char userInputColumnList[10]);

void displayMessage(int type);

int main() {


    char userInputMenuChoice;
    char userInputColumnList[10];

    readFile();

    // prompting user start, reading input and clearing console
    displayMessage(MENU);
    scanf("%c", &userInputMenuChoice);
    system("clear");

    switch (userInputMenuChoice) {
        case NEW_TABLE:
            displayMessage(NEW_TABLE);
            scanf("%s", userInputColumnList);
            system("clear");
            cleanUserInput(userInputColumnList);
            break;
        case EXIT:
            displayMessage(EXIT);
            break;
        default:
            displayMessage(ERROR);
            break;
    }
    return 0;
}
// source: https://stackoverflow.com/questions/15822660/how-to-parse-a-string-separated-by-commas

void cleanUserInput(char userInputColumnList[10]) {
    char delim[] = ",";
    char *pointer = strtok(userInputColumnList, delim);
    int sizeCleanedArray = 0;

    while (pointer != NULL) {
        pointer = strtok(NULL, delim);
        sizeCleanedArray++;
    }
    printf("There are %d numbers\n", sizeCleanedArray);

    char cleanArray[sizeCleanedArray];


    printf("cleanArray: %s \n", cleanArray);

}

void displayMessage(int type) {
    char MENU_MSG[] = "TableGen Menu\n"
                      "----------\n"
                      "1. Generate new table\n"
                      "2. Exit\n"
                      "\n"
                      "Selection: ";

    char NEW_TABLE_MSG[] = "Column Options\n"
                           "---------------\n"
                           "1. User ID        5. Phone Number\n"
                           "2. First name     6. Email address\n"
                           "3. Last name      7. SIN\n"
                           "4. Country        8. Password\n"
                           "\n"
                           "Enter column list (comma-separated, no spaces): ";

    char EXIT_MSG[] = "Goodbye and thanks for using TableGen\n";
    char ERROR_MSG[] = "Ouch.. did you verify your input? Maybe it's a compilation problem.!\n";

    switch (type) {
        case MENU:
            printf("%s", MENU_MSG);
            break;
        case NEW_TABLE:
            printf("%s", NEW_TABLE_MSG);
            break;
        case EXIT:
            printf("%s", EXIT_MSG);
            break;
        case ERROR:
            printf("%s", ERROR_MSG);
        default:
            // it should never come here, but I still left the default case.
            printf("Error...");
            break;
    }
}
