#include "generate.h"
#include <stdio.h>
#include <stdlib.h>
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

// to generate random int between range:
// https://stackoverflow.com/questions/17846212/generate-a-random-number-between-1-and-10-in-c
void generate_password() {
  srand(time(NULL));
  int random_password_length =
      rand() % ((PASSWORD_MAX_VALUE + 1) - PASSWORD_MIN_VALUE) +
      PASSWORD_MIN_VALUE;
  char password_generated[random_password_length];

  for (int i = 0; i < random_password_length; i++) {

    //    password_generated[i] = ''
    printf("%c\n", rand());
  }
  //  printf("%s", password_generated);
  //  return password_generated;
}

// to find total char in pointer
// https://stackoverflow.com/questions/13551017/find-the-size-of-a-string-pointed-by-a-pointer
char generate_random_character() {
  char *alphabet_uppercase = "QWERTYUIOPASDFGHJKLZXCVBNM";
  char *lower_case = "qwertyuiopasdfghjklzxcvbnm";
  char *special_characters = "~!@#$%^&*()_+{}:\"<>?";

  



  switch (rand() % 2) {
  case ALPHABET_UPPERCASE:
    break;

  case ALPHABET_LOWERCASE:
    break;

  case SPECIAL_CHARACTERS:
    break;

  default:
    // default not required
    break;
  }
}
