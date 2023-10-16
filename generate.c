
#include "generate.h"
#include "io.h"
#include "tablegen.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int initial_id = 0;
extern char user_input_column_list[20];
extern int row_count;
extern char **first_names;
extern char **last_names;
extern char **countries;
extern char **email_suffixes;

char **array_output;

// source:https://stackoverflow.com/questions/15822660/how-to-parse-a-string-separated-by-commas
void generate_data() {
  array_output = malloc(row_count * sizeof(char *));

  for (int j = 0; j < row_count; j++) {
    for (int i = 0; i < MAX_LENGTH_INPUT; i++) {
      if (isdigit(user_input_column_list[i])) {
        switch (user_input_column_list[i]) {
        case USER_ID:
          array_output[i] = generate_id();
          printf("content:: %s\n", array_output[i]);
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
  }

//  save();
}



// id
char *generate_id() {

  printf("generating user_id\n");
  int i = initial_id++;
  char *c;
  c = (char *)&i;
  return strdup(c);
}

// https://stackoverflow.com/questions/1496313/returning-a-c-string-from-a-function
char *generate_first_name() {
  printf("generating first_name\n");
  char *first_name_random;
  int random_number = generate_random_number(0, 1000);
  printf("random number: %s\n", first_names[random_number]);
  //  printf("data: %s", first_names[random_number]);
  //  first_name_random = first_names[random_number];
  //  int length = strlen(first_name_random);
  //  first_name_random = malloc(length * sizeof(char));
  //  first_name_random[length - 1] = '\0';
  return first_name_random;
}

char *generate_last_name() {
  printf("generating last_name\n");
  char *last_name_random;
  int random_number = generate_random_number(0,1000);

  return last_name_random;
}

char *generate_country() {
  printf("generating country\n");

  return NULL;
}

void generate_phone_number() { printf("generating phone_number\n"); }

void generate_email_address() { printf("generating email_adress\n"); }

char *generate_password() {
  printf("printing password\n");
  srand(time(NULL));
  int random_password_length =
      rand() % ((PASSWORD_MAX_VALUE + 1) - PASSWORD_MIN_VALUE) +
      PASSWORD_MIN_VALUE;
  char password_generated[random_password_length];
  printf("password length is %d\n", random_password_length);

  for (int i = 0; i < random_password_length; i++) {
    password_generated[i] = generate_random_char();
  }
  printf("password is %s\n", password_generated);
  return NULL;
}

void generate_sin() {
  printf("generating sin\n");
  int buffer[BUFFER_SIZE];

  for (int i = 0; i < SIN_LENGTH; i++) {
    buffer[i] = generate_random_number(0, 9);
  }
}

// to find total char in pointer
// https://stackoverflow.com/questions/13551017/find-the-size-of-a-string-pointed-by-a-pointer
char generate_random_char() {
  const char chars_authorized[] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjk"
                                  "lzxcvbnm~!@#$%^&*()_+{}:\"<>?./;'[]";
  int chars_authorized_length =
      sizeof(chars_authorized) / sizeof(chars_authorized[0]);
  unsigned char random_char =
      generate_random_number(0, chars_authorized_length);
  printf("%c\n", chars_authorized[random_char]);
  return chars_authorized[random_char];
}

// to generate random int between range:
// https://stackoverflow.com/questions/17846212/generate-a-random-number-between-1-and-10-in-c
int generate_random_number(int min, int max) {
  int random_number;
  random_number = rand() % ((max + 1) - min) - min;
  return random_number;
}
