
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

struct Person {
  char *id;
  char *first_name;
  char *last_name;
  char *country;
  char *phone_number;
  char *email;
  char *sin;
  char *password;
};

void generate_data() {
  struct Person list_people[row_count];
  int count = 0;
  add_csv_extension();
  array_output = malloc(row_count * sizeof(char *) + 1);
  array_output[row_count] = NULL;
  FILE *file_handler = fopen(output_file_name, "w+");
  printf("Saving...\n");

  while (count != row_count) {
    for (int i = 0; i < MAX_LENGTH_INPUT; i++) {
      if (isdigit(user_input_column_list[i])) {
        printf("%c - ", user_input_column_list[i]);
        switch (user_input_column_list[i]) {
        case USER_ID:

          list_people[i].id = generate_id();
          printf("%s\n", list_people[i].id);
          fprintf(file_handler, "%s,", list_people[i].id);
          break;

        case FIRST_NAME:
          list_people[i].first_name = generate_first_name();
          printf("%s\n", list_people[i].first_name);
          fprintf(file_handler, "%s,", list_people[i].first_name);
          break;

        case LAST_NAME:
          list_people[i].last_name = generate_last_name();
          printf("%s\n", list_people[i].last_name);

          break;

        case COUNTRY:
          list_people[i].country = generate_country();
          printf("%s\n", list_people[i].country);

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

    printf("row %d -------------------------------------------------\n", count);
    count++;
  }

  fclose(file_handler);
  printf("End of program\n");
}

// id
char *generate_id() {
  printf("generating id            | ");
  unsigned int id_int = initial_id++;
  // max length of id is 8 because of 1M + we need to add 1 for null char
  char *id_str = malloc(8 * sizeof(char));
  sprintf(id_str, "%d", id_int);
  return id_str;
}

char *generate_first_name() {
  printf("generating first_name    | ");
  char *first_name_str;
  unsigned int random_number = generate_random_number(0, 999);
  first_name_str = first_names[random_number];
  return first_name_str;
}

char *generate_last_name() {
  printf("generating last_name     | ");
  char *last_name_str;
  unsigned int random_number = generate_random_number(0, 999);
  last_name_str = last_names[random_number];
  return last_name_str;
}

char *generate_country() {
  printf("generating country       | ");
  char *country_str;
  unsigned int random_number = generate_random_number(0, 194);
  country_str = countries[random_number];
  return country_str;
}

void generate_phone_number() { printf("generating phone_number  |\n"); }

void generate_email_address() { printf("generating email_address |\n"); }

void generate_sin() {
  printf("generating sin           | ");


//  int sin_int = initial_id++;
//  // max length of id is 8 because of 1M + we need to add 1 for null char
//  char *id_str = malloc(8 * sizeof(char));
//  sprintf(id_str, "%d", id_int);
//  return id_str;




  unsigned int buffer = generate_random_number(100000000, 999999999);
  printf("sin: %d\n", buffer);
}

char *generate_password() {
  printf("generating password      | ");
  unsigned int random_password_length =
      generate_random_number(PASSWORD_MIN_VALUE, PASSWORD_MAX_VALUE);
  char password_generated[random_password_length + 1];
  for (int i = 0; i < random_password_length; i++) {
    password_generated[i] = generate_random_char();
  }
  password_generated[random_password_length - 1] = '\0';
  printf("password: %s\n", password_generated);
  return NULL;
}

char generate_random_char() {
  char chars_authorized[] = "!\"#$'()*+-.\"/"
                            "0123456789:<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ["
                            "\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
  int chars_authorized_length =
      sizeof(chars_authorized) / sizeof(chars_authorized[0]);
  unsigned char random_char =
      generate_random_number(0, chars_authorized_length - 1);
  return chars_authorized[random_char];
}

unsigned int generate_random_number(int min, int max) {
  unsigned int random_number;
  random_number = (rand() % (max - min + 1)) + min;
  return random_number;
}
