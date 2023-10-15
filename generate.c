#include "generate.h"
#include "tablegen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define USER_ID 1
#define FIRST_NAME 2
#define LAST_NAME 3
#define COUNTRY 4
#define PHONE_NUMBER 5
#define EMAIL_ADDRESS 6
#define SIN 7
#define PASSWORD 8

#define SIN_LENGTH 9

#define PASSWORD_MAX_VALUE 16
#define PASSWORD_MIN_VALUE 6

int initial_id = 1;

// source:https://stackoverflow.com/questions/15822660/how-to-parse-a-string-separated-by-commas
void generate_data() {
  char delim[] = ",";
  // TO FIX SO NO ERROR
  char *user_input_column_list;
  char *pointer = strtok(user_input_column_list, delim);
  int true_length_user_input = 0;

  while (pointer != NULL) {
    pointer = strtok(NULL, delim);
    true_length_user_input++;
  }

  for (int i = 0; i < true_length_user_input; i++) {
    switch (user_input_column_list[i]) {
    case USER_ID:
      generate_id();
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

// id
int generate_id() { return initial_id++; }

void generate_first_name() {}

void generate_last_name() {}

void generate_country() {}

void generate_phone_number() {}

void generate_email_address() {}

void generate_password() {
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
}

void generate_sin() {
  for (int i = 0; i < SIN_LENGTH; i++) {
    generate_random_number(0, 9);
  }
}

// to find total char in pointer
// https://stackoverflow.com/questions/13551017/find-the-size-of-a-string-pointed-by-a-pointer
char generate_random_char() {
  const char chars_authorized[] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjk"
                                  "lzxcvbnm~!@#$%^&*()_+{}:\"<>?./;'[]";
  int chars_authorized_length =
      sizeof(chars_authorized) / sizeof(chars_authorized[0]);
  unsigned char random_char = generate_random_number(0, chars_authorized_length);
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
