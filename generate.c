#include "generate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_MAX_VALUE 16
#define PASSWORD_MIN_VALUE 6
#define ALPHABET_UPPERCASE 0
#define ALPHABET_LOWERCASE 1
#define SPECIAL_CHARACTERS 2
int initial_id = 0;

// id
int generate_id() { return initial_id++; }

// first_name
char generate_first_name() {}

// last_name
// country
// phone_number
// email_address
// sin
// password

void generate_password() {
  srand(time(NULL));
  int random_password_length =
      rand() % ((PASSWORD_MAX_VALUE + 1) - PASSWORD_MIN_VALUE) +
      PASSWORD_MIN_VALUE;
  char password_generated[random_password_length];
  printf("password length is %d\n", random_password_length);

  for (int i = 0; i < random_password_length; i++) {

    password_generated[i] = generate_random_char();
    //    printf("%d\n", generate_random_number(0, 3));
  }
  printf("password is %s\n", password_generated);
  //  return password_generated;
}

// to find total char in pointer
// https://stackoverflow.com/questions/13551017/find-the-size-of-a-string-pointed-by-a-pointer
char generate_random_char() {
  const char chars_authorized[] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjk"
                                  "lzxcvbnm~!@#$%^&*()_+{}:\"<>?./;'[]";
  int chars_authorized_length =
      sizeof(chars_authorized) / sizeof(chars_authorized[0]);
  char random_char = generate_random_number(0, chars_authorized_length);
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
