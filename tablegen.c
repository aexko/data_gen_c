// Code convention used:
// https://users.ece.cmu.edu/~eno/coding/CCodingStandard.html#classnames

#include "tablegen.h"
#include "generate.h"
#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char user_input_column_list[20];
char user_input_menu_choice;
int row_count;
char output_file_name[20];

int main() {
  // test purposes
  generate_password();

  //  "/Users/alex/Documents/comp348/a1_Kao_Alex_40286533/first_names.txt"
  //  "/Users/alex/Documents/comp348/a1_Kao_Alex_40286533/last_names.txt"
  //  "/Users/alex/Documents/comp348/a1_Kao_Alex_40286533/countries.txt"
  //  "/Users/alex/Documents/comp348/a1_Kao_Alex_40286533/email_suffixes.txt"

  //  read_file("first_names.txt");
  //  read_file("last_names.txt");
  //  read_file("countries.txt");
  //  read_file("email_suffixes.txt");

  // prompting user start, reading input and clearing console
  prompt_user_for_input(MENU);

  switch (user_input_menu_choice) {
  case NEW_TABLE:

    prompt_user_for_input(NEW_TABLE);
    prompt_user_for_input(ROW_NUMBER);
    prompt_user_for_input(OUTPUT_NAME);
    display_summary_properties();
    prompt_user_for_input(CONFIRMATION);

    //    generate_data();

    break;
  case EXIT:
    display_message(EXIT);
    break;
  default:
    display_message(ERROR_INPUT);
    break;
  }

  return 0;
}

// source:https://stackoverflow.com/questions/15822660/how-to-parse-a-string-separated-by-commas
// useless for now
void cleanUserInput() {
  char delim[] = ",";
  char *pointer = strtok(user_input_column_list, delim);
  int size_cleaned_array = 0;

  while (pointer != NULL) {
    pointer = strtok(NULL, delim);
    size_cleaned_array++;
  }
  printf("There are %d numbers\n", size_cleaned_array);

  char clean_array[size_cleaned_array];
  // counts size
  printf("clean_array: %s \n", clean_array);
}

void display_summary_properties() {
  printf("Columns: %s\n", user_input_column_list);
  printf("Row count: %d\n", row_count);
  printf("File name: %s\n", output_file_name);
}

void prompt_user_for_input(int type) {
  char proceed;

  switch (type) {

  case MENU:
    display_message(MENU);
    scanf("%c", &user_input_menu_choice);
    break;

  case NEW_TABLE:
    display_message(NEW_TABLE);
    scanf("%s", user_input_column_list);
    break;

  case ROW_NUMBER:
    display_message(ROW_NUMBER);
    scanf("%d", &row_count);

    if (row_count < 0 || row_count >= 1000000) {
      display_message(ERROR_INPUT);
      printf("Error: Row count is negative or exceeds 1M.");
      exit(1);
    }
    break;

  case OUTPUT_NAME:
    display_message(OUTPUT_NAME);
    scanf("%s", output_file_name);
    break;

  case CONFIRMATION:
    display_message(CONFIRMATION);
    do {
      scanf("%c", &proceed);
    } while ((proceed != 'c') && (proceed != 'C'));

    break;

  default:
    // default case not required, it should never come here
    printf("Error...");
    break;
  }
  system("clear");
}

void display_message(int type) {
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
  char CONFIRMATION_MSG[] = "Press 'c' or 'C' to continue\n";

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
  case CONFIRMATION:
    printf("%s", CONFIRMATION_MSG);
    break;

  default:
    // default case not required, it should never come here
    printf("Error in default case...");
    break;
  }
}