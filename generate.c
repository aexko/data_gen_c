#include "generate.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_MAX_VALUE 16
#define PASSWORD_MIN_VALUE 6
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
  int random_length = rand() % ((PASSWORD_MAX_VALUE + 1) - PASSWORD_MIN_VALUE) +
                      PASSWORD_MIN_VALUE;
  char password_generated[random_length];

  for (int i = 0; i < 100; i++) {
    //    password_generated[i] = ''
  }
  //  printf("%s", password_generated);
  //  return password_generated;
}
