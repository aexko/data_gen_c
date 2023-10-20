
#include "generate.h"
#include "io.h"
#include "sort.h"
#include "tablegen.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int initial_id = 1;
extern char user_input_column_list[20];
extern const int row_count;
extern char **first_names;
extern char **last_names;
extern char **countries;
extern char **email_suffixes;
extern char output_file_name[20];

void generate_data() {
  struct Person list_people[row_count];

  int count = 0;
  add_csv_extension();
  FILE *file_handler = fopen(output_file_name, "w+");
  printf("Saving...\n");

  while (count != row_count) {
    for (int i = 0; i < MAX_LENGTH_INPUT; i++) {
      if (isdigit(user_input_column_list[i])) {
        printf("%c - ", user_input_column_list[i]);

        // I NEED TO CREATE A HEADER FOR EACH COLUMN IF THEY ARE INITIALIZED
        switch (user_input_column_list[i]) {
        case USER_ID:

          list_people[count].id = generate_id();
          printf("%s\n", list_people[count].id);
          break;

        case FIRST_NAME:
          list_people[count].first_name = generate_first_name();
          printf("%s\n", list_people[count].first_name);
          break;

        case LAST_NAME:
          list_people[count].last_name = generate_last_name();
          printf("%s\n", list_people[count].last_name);
          break;

        case COUNTRY:
          list_people[count].country = generate_country();
          printf("%s\n", list_people[count].country);
          break;

        case PHONE_NUMBER:
          list_people[count].phone_number = generate_phone_number();
          printf("%s\n", list_people[count].phone_number);
          break;

        case EMAIL_ADDRESS:
          list_people[count].email = generate_email_address(
              list_people[count].first_name, list_people[count].last_name);
          printf("%s\n", list_people[count].email);
          break;

        case SIN:
          list_people[count].sin = generate_sin();
          printf("%s\n", list_people[count].sin);
          break;

        case PASSWORD:
          list_people[count].password = generate_password();
          printf("%s\n", list_people[count].password);
          break;
        }
      }
    }
    printf("---------------------------------------------------------------- "
           "row %d\n",
           count);
    count++;
  }

  // what if i just sort it here and implement the function in the sort.c
  qsort(list_people, row_count, sizeof(struct Person), compare);

  for (int i = 0; i < row_count; ++i) {
    printf("%s", list_people[i].last_name);
  }
  //  sort_alphabetically(list_people);
  fclose(file_handler);
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

char *generate_phone_number() {
  printf("generating phone_number  | ");

  unsigned int random_number = generate_random_number(0, 9);
  int list_index_codes[10] = {398, 270, 925, 867, 209, 429, 908, 997, 444, 219};
  int index_code = list_index_codes[random_number];
  char index_code_str[4];
  index_code_str[3] = '\0';
  sprintf(index_code_str, "%d", index_code);

  char hyphen_str[2];
  char hyphen = '-';
  sprintf(hyphen_str, "%c", hyphen);

  unsigned int last_digits = generate_random_number(1000, 9999);
  char last_digits_str[5];
  last_digits_str[4] = '\0';
  sprintf(last_digits_str, "%d", last_digits);

  char *phone_number_str = append_strings(index_code_str, hyphen_str);
  phone_number_str = append_strings(phone_number_str, last_digits_str);

  return phone_number_str;
}

char *generate_email_address(char *first_name, char *last_name) {
  printf("generating email_address | ");
  unsigned int random_number = generate_random_number(0, 99);
  char *email_suffix_str = email_suffixes[random_number];
  /* first_letter of first_name + full last_name + @ + email_suffix_str */
  //  int email_len = 1 + strlen(last_name) + 1 + strlen(email_suffix_str);

  /* first letter of first_name + full last_name + null */
  unsigned int prefix_len = 1 + strlen(last_name) + 1;
  char prefix[prefix_len];
  prefix[prefix_len - 1] = '\0';

  char first_letter_str[2];
  char first_letter = first_name[0];

  sprintf(first_letter_str, "%c", first_letter);

  char at_str[2];
  char at = '@';
  sprintf(at_str, "%c", at);

  char *email_str = append_strings(first_letter_str, last_name);
  email_str = append_strings(email_str, at_str);
  email_str = append_strings(email_str, email_suffix_str);
  //

  /* first letter of first_name + last_name + @ */

  //  unsigned int email_suffix_len = 1 + strlen(email_suffix_str);
  //  char *email_str = malloc(sizeof(char) * email_prefix_len +
  //  email_suffix_len);
  //
  //  email_str[0] = first_name[0];
  //  strncat(email_str, last_name, email_prefix_len);
  //  email_str[email_prefix_len - 1] = '@';
  //  strncat(email_str, email_suffix_str, email_prefix_len);
  //  printf("%s\n", email_str);
  // append first_name + last_name + @

  // append email_suffix_str
  return email_str;
}

char *generate_sin() {
  printf("generating sin           | ");
  unsigned int sin_int = generate_random_number(100000000, 999999999);
  // max length of id is 8 because of 1M + we need to add 1 for null char
  char *sin_str = malloc(8 * sizeof(int));
  sprintf(sin_str, "%d", sin_int);
  return sin_str;
}

char *generate_password() {
  printf("generating password      | ");
  unsigned int random_password_length =
      generate_random_number(PASSWORD_MIN_VALUE, PASSWORD_MAX_VALUE);
  char *password_ptr = malloc(sizeof(char) * random_password_length + 1);
  for (int i = 0; i < random_password_length; i++) {
    password_ptr[i] = generate_random_char();
  }
  password_ptr[random_password_length] = '\0';
  return password_ptr;
}

char generate_random_char() {
  char chars_authorized[] = "!\"#$%'()*+-./"
                            "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ["
                            "\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
  int chars_authorized_length =
      sizeof(chars_authorized) / sizeof(chars_authorized[0]);

  unsigned char random_char =
      // -2 because the index starts at 0, and because the last index is a null
      generate_random_number(0, chars_authorized_length - 2);
  return chars_authorized[random_char];
}

unsigned int generate_random_number(int min, int max) {
  unsigned int random_number;
  random_number = (rand() % (max - min + 1)) + min;
  return random_number;
}

char *append_strings(char *first_string, char *second_string) {
  unsigned int total_string_len =
      strlen(first_string) + strlen(second_string) + 1; // +1 for null end

  char *result = calloc(total_string_len, sizeof(char));

  for (int i = 0; i < strlen(first_string); i++) {
    result[i] = first_string[i];
  }

  for (int i = 0; i < strlen(second_string); i++) {
    result[strlen(first_string) + i] = second_string[i];
  }

  result[total_string_len - 1] = '\0';
  return result;
}

void create_copy() {}