// Code convention used:
// https://users.ece.cmu.edu/~eno/coding/CCodingStandard.html#classnames

#include "tablegen.h"
#include "generate.h"
#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char user_input_menu_choice;
char user_input_column_list[MAX_LENGTH_INPUT];
int row_count;
char output_file_name[MAX_LENGTH_INPUT];

int main() {

  system("clear");


  initialize_program();

  prompt_user_input(MENU);

  switch (user_input_menu_choice) {
  case NEW_TABLE:

    prompt_user_input(NEW_TABLE);
    prompt_user_input(ROW_NUMBER);
    if (row_count < 0 || row_count >= 1000000) {
      display_message(ERROR_INPUT);
      printf("The reason could be the row count is negative or exceeds 1M.\n");
      return 0;
    }
    prompt_user_input(OUTPUT_NAME);
    display_summary_properties();
    prompt_user_input(CONFIRMATION);
    generate_data();
    break;
  case EXIT:
    display_message(EXIT);
    break;
  default:
    display_message(ERROR_INPUT);
    break;
  }

//    free_memory();

  return 0;
}

void test() {}

void prompt_user_input(int type) {
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
    int c;

    scanf("%d", &row_count);
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

void initialize_program() {
  check_file("first_names.txt");
  check_file("last_names.txt");
  check_file("countries.txt");
  check_file("email_suffixes.txt");

  read_file("first_names.txt");
  read_file("last_names.txt");
  read_file("countries.txt");
  read_file("email_suffixes.txt");
}

void display_summary_properties() {
  printf("Columns: %s\n", user_input_column_list);
  printf("Row count: %d\n", row_count);
  printf("File name: %s\n", output_file_name);
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
  char CONFIRMATION_MSG[] = "Press 'c' or 'C' to continue: ";

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