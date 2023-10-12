#include "tablegen.h"
#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MENU '0'
#define NEW_TABLE '1'
#define EXIT '2'
#define ERROR_INPUT '3'
#define ROW_NUMBER '4'
#define OUTPUT_NAME '5'

int main() {
  //  "/Users/alex/Documents/comp348/a1_Kao_Alex_40286533/first_names.txt"
  //  "/Users/alex/Documents/comp348/a1_Kao_Alex_40286533/last_names.txt"
  //  "/Users/alex/Documents/comp348/a1_Kao_Alex_40286533/countries.txt"
  //  "/Users/alex/Documents/comp348/a1_Kao_Alex_40286533/email_suffixes.txt"

  readFile("first_names.txt");
  readFile("last_names.txt");
  readFile("countries.txt");
  readFile("email_suffixes.txt");

  // prompting user start, reading input and clearing console
  promptUserForInput(MENU);

  switch (userInputMenuChoice) {
  case NEW_TABLE:

    promptUserForInput(NEW_TABLE);

    promptUserForInput(ROW_NUMBER);

    promptUserForInput(OUTPUT_NAME);

    displaySummaryProperties();

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

// source:https://stackoverflow.com/questions/15822660/how-to-parse-a-string-separated-by-commas
// useless for now
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

void displaySummaryProperties() {
  printf("Columns: %s\n", userInputColumnList);
  printf("Row count: %d\n", rowCount);
  printf("File name: %s\n", outputFileName);
}

void promptUserForInput(int type) {
  switch (type) {

  case MENU:
    displayMessage(MENU);
    scanf("%c", &userInputMenuChoice);
    system("clear");
    break;

  case NEW_TABLE:
    displayMessage(NEW_TABLE);
    scanf("%s", userInputColumnList);
    break;

  case ROW_NUMBER:
    displayMessage(ROW_NUMBER);
    scanf("%d", &rowCount);
    system("clear");

    if (rowCount < 0 || rowCount >= 1000000) {
      displayMessage(ERROR_INPUT);
      printf("Error: Row count is negative or exceeds 1M.");
      exit(1);
    }
    break;

  case OUTPUT_NAME:
    displayMessage(OUTPUT_NAME);
    scanf("%s", outputFileName);
    system("clear");
    break;

  default:
    // it should never come here, but I still left the default case.
    printf("Error...");
    break;
  }
  system("clear");
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
    // default case not required, it should never come here
    printf("Error in default case...");
    break;
  }
}