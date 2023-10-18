
#include "generate.h"
#include "io.h"
#include "tablegen.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int initial_id = 1;
extern char user_input_column_list[20];
extern int row_count;
extern char **first_names;
extern char **last_names;
extern char **countries;
extern char **email_suffixes;
extern char output_file_name[20];
char **array_output;

// source:https://stackoverflow.com/questions/15822660/how-to-parse-a-string-separated-by-commas
void generate_data() {
  int count = 0;
  array_output = malloc(row_count * sizeof(char *) + 1);
  array_output[row_count] = NULL;
  FILE *file_handler = fopen(output_file_name, "w+");
  printf("Saving...\n");

  while (count != row_count) {
    for (int i = 0; i < MAX_LENGTH_INPUT; i++) {
      if (isdigit(user_input_column_list[i])) {
        printf("%c - ", user_input_column_list[i]);
        //
        switch (user_input_column_list[i]) {
        case USER_ID:

          array_output[i] = generate_id();
          printf("WOW ITS IN CTHE ARRAY: %s\n", array_output[i]);
          fprintf(file_handler, "%s\n", array_output[0]);

          break;
        case FIRST_NAME:
          generate_first_name();
          break;
        case LAST_NAME:
          generate_last_name();
          break;
        case COUNTRY:
          generate_country();
          break;
        case PHONE_NUMBER:
          generate_phone_number();
          break;
        case EMAIL_ADDRESS:
          generate_email_address();
          break;
        case SIN:
          generate_sin();
          break;
        case PASSWORD:
          generate_password();
          break;
        }
      }
    }

    printf("row %d --------------------------------------\n", count);
    count++;
  };

  //  for (int j = 0; j < MAX_LENGTH_INPUT; j++) {
  //    if (isdigit(user_input_column_list[j])) {
  //      printf("its a digit %d\n", j);
  //
  //
  //    }
  //
  //
  //
  //
  //
  //  }
  fclose(file_handler);
  printf("End of program\n");
  //  save();
}

// id
char *generate_id() {
  printf("generating id            |");
  int id_int = initial_id++;
  // max length of id is 8 because of 1M + we need to add 1 for null char
  char *id_str = malloc(8 * sizeof(char));
  sprintf(id_str, "%d", id_int);
  //  printf("%s\n", id_str);
  return id_str;
}

// https://stackoverflow.com/questions/1496313/returning-a-c-string-from-a-function
char *generate_first_name() {
  printf("generating first_name    |\n");
  //  printf("%s", first_names[10]);
  //  int random_number = generate_random_number(0, 1000);
  //  printf("random number: %s\n", first_names[random_number]);
  //  printf("data: %s", first_names[random_number]);
  //  first_name_random = first_names[random_number];
  //  int length = strlen(first_name_random);
  //  first_name_random = malloc(length * sizeof(char));
  //  first_name_random[length - 1] = '\0';
  return NULL;
}

char *generate_last_name() {
  printf("generating last_name     |\n");
  //  printf("%s", last_names[10]);

  //  char *last_name_random;
  //  int random_number = generate_random_number(0, 1000);

  return NULL;
}

char *generate_country() {
  printf("generating country       |\n");
  //  printf("%s", countries[10]);

  return NULL;
}

void generate_phone_number() { printf("generating phone_number  |\n"); }

void generate_email_address() {
  printf("generating email_address |\n");
  //  printf("%s", email_suffixes[10]);
}

void generate_sin() {
  printf("generating sin           |");
  unsigned int buffer = generate_random_number(100000000, 999999999);
  printf("sin: %d\n", buffer);
}

char *generate_password() {
  printf("generating password      |");
  int random_password_length =
      generate_random_number(PASSWORD_MIN_VALUE, PASSWORD_MAX_VALUE);
  char password_generated[random_password_length + 1];
  for (int i = 0; i < random_password_length; i++) {
    password_generated[i] = generate_random_char();
  }
  password_generated[random_password_length - 1] = '\0';
  printf("password: %s\n", password_generated);
  return NULL;
}

// to find total char in pointer
// https://stackoverflow.com/questions/13551017/find-the-size-of-a-string-pointed-by-a-pointer
char generate_random_char() {
  char chars_authorized[] = "!\"#$'()*+-.\"/"
                            "0123456789:<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ["
                            "\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
  int chars_authorized_length =
      sizeof(chars_authorized) / sizeof(chars_authorized[0]);
  unsigned char random_char =
      generate_random_number(0, chars_authorized_length - 1);
  //  printf("%c\n", chars_authorized[random_char]);
  return chars_authorized[random_char];
}

// to generate random int between range:
// https://stackoverflow.com/questions/17846212/generate-a-random-number-between-1-and-10-in-c
unsigned int generate_random_number(int min, int max) {
  unsigned int random_number;
  random_number = (rand() % (max - min + 1)) + min;
  return random_number;
}
