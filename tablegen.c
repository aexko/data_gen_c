#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablegen.h"
#include "io.h"

#define MENU '0'
#define NEW_TABLE '1'
#define EXIT '2'
#define ERROR_INPUT '3'
#define ROW_NUMBER '4'
#define OUTPUT_NAME '5'



int main() {

    readFile("first_names.txt");
    readFile("last_names.txt");
    readFile("countries.txt");
    readFile("email_suffixes.txt");

    // prompting user start, reading input and clearing console
    displayMessage(MENU);
    scanf("%c", &userInputMenuChoice);
    system("clear");

    switch (userInputMenuChoice) {
        case NEW_TABLE:
            displayMessage(NEW_TABLE);
            scanf("%s", userInputColumnList);
            system("clear");

            displayMessage(ROW_NUMBER);
            scanf("%d", &rowCount);



            system("clear");


            if (rowCount < 0 || rowCount >= 1000000) {
                displayMessage(ERROR_INPUT);
                printf("Error: Row count is negative or exceeds 1M.");
                exit(1);
            }


            printf("%d\n", rowCount);

            displayMessage(OUTPUT_NAME);
            scanf("%s", outputFileName);
            system("clear");

            printf("%s\n", outputFileName);

            cleanUserInput();
            break;
        case EXIT:
            displayMessage(EXIT);
            break;
        default:
            displayMessage(ERROR_INPUT);
            break;
    }





    return 0;
}
// source: https://stackoverflow.com/questions/15822660/how-to-parse-a-string-separated-by-commas

void cleanUserInput() {
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
    char ERROR_INPUT_MSG[] = "Ouch.. did you verify your input?\n";
    char ROW_NUMBER_MSG[] = "Enter row count (1 < n < 1M): ";
    char OUTPUT_NAME_MSG[] = "Enter output file name (so suffix): ";

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
        case ERROR_INPUT:
            printf("%s", ERROR_INPUT_MSG);
            break;
        case ROW_NUMBER:
            printf("%s", ROW_NUMBER_MSG);
            break;
        case OUTPUT_NAME:
            printf("%s", OUTPUT_NAME_MSG);
            break;

        default:
            // it should never come here, but I still left the default case.
            printf("Error...");
            break;
    }
}
