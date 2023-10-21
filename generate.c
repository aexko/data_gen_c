
#include "generate.h"
#include "io.h"
#include "sort.h"
#include "tablegen.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int initial_id = 1;
extern char user_input_column_list[20];
extern const int row_count;
extern char **first_names;
extern char **last_names;
extern char **countries;
extern char **email_suffixes;
extern char output_file_name[20];

/**
 * This is the main function that generates the data, it will call all the other
 * functions to generate the data and then write it to the file. It starts with
 * initializing the list of people, then it will generate the data for each
 * column, then it will sort the list of people, and finally it will write the
 * data to the file.
 */
void generate_data() {
  struct Person list_people[row_count];
  int count = 0;
  add_csv_extension();
  FILE *file_handler = fopen(output_file_name, "w+");

  while (count != row_count) {
    for (int i = 0; i < MAX_LENGTH_INPUT; i++) {
      if (isdigit(user_input_column_list[i])) {
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
  qsort(list_people, row_count, sizeof(struct Person), compare);

  count = 0;
  for (int j = 0; j < row_count; j++) {
    for (int i = 0; i < MAX_LENGTH_INPUT; i++) {
      if (isdigit(user_input_column_list[i])) {
        switch (user_input_column_list[i]) {
        case USER_ID:
          fprintf(file_handler, "%s,", list_people[count].id);
          break;

        case FIRST_NAME:
          fprintf(file_handler, "%s,", list_people[count].first_name);
          break;

        case LAST_NAME:
          fprintf(file_handler, "%s,", list_people[count].last_name);
          break;

        case COUNTRY:
          fprintf(file_handler, "%s,", list_people[count].country);
          break;

        case PHONE_NUMBER:
          fprintf(file_handler, "%s,", list_people[count].phone_number);
          break;

        case EMAIL_ADDRESS:
          fprintf(file_handler, "%s,", list_people[count].email);
          break;

        case SIN:
          fprintf(file_handler, "%s,", list_people[count].sin);
          break;

        case PASSWORD:
          fprintf(file_handler, "%s,", list_people[count].password);
          break;
        }
      }
    }
    count++;
    /* Skips a line after generating a row */
    fprintf(file_handler, "\n");
  }
  fclose(file_handler);
}

/**
 * This function generates an id for the person. It will increment the initial
 * id by 1 and then return it as a string.
 * @return id_str - the id as a string
 */
char *generate_id() {
  printf("generating id            | ");
  unsigned int id_int = initial_id++;
  // max length of id is 8 because of 1M + we need to add 1 for null char
  char *id_str = malloc(8 * sizeof(char));
  sprintf(id_str, "%d", id_int);
  return id_str;
}

/**
 * This function generates a first name for the person. It will generate a
 * random number between 0 and 999 and then use that number as an index to
 * retrieve a first name from the first_names array.
 * @return first_name_str - the first name as a string
 */
char *generate_first_name() {
  printf("generating first_name    | ");
  char *first_name_str;
  unsigned int random_number = generate_random_number(0, 999);
  first_name_str = first_names[random_number];
  return first_name_str;
}

/**
 * This function generates a last name for the person. It will generate a
 * random number between 0 and 999 and then use that number as an index to
 * retrieve a last name from the last_names array.
 * @return last_name_str - the last name as a string
 */
char *generate_last_name() {
  printf("generating last_name     | ");
  char *last_name_str;
  unsigned int random_number = generate_random_number(0, 999);
  last_name_str = last_names[random_number];
  return last_name_str;
}

/**
 * This function generates a country for the person. It will generate a
 * random number between 0 and 194 and then use that number as an index to
 * retrieve a country from the countries array.
 * @return country_str - the country as a string
 */
char *generate_country() {
  printf("generating country       | ");
  char *country_str;
  unsigned int random_number = generate_random_number(0, 194);
  country_str = countries[random_number];
  return country_str;
}

/**
 * This function generates a phone number for the person. It will generate a
 * random number between 0 and 9 and then use that number as an index to
 * retrieve an index code from the list_index_codes array. Then it will
 * generate a random number between 1000 and 9999 and use that as the last
 * digits of the phone number. Finally it will append the index code and the
 * last digits to create the phone number.
 * @return phone_number_str - the phone number as a string
 */
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

/**
 * This function generates an email address for the person. It will generate a
 * random number between 0 and 99 and then use that number as an index to
 * retrieve an email suffix from the email_suffixes array. Then it will
 * generate the prefix of the email address by taking the first letter of the
 * first name and the full last name. Finally it will append the prefix and the
 * suffix to create the email address.
 * @param first_name - the first name of the person
 * @param last_name - the last name of the person
 * @return email_str - the email address as a string
 */
char *generate_email_address(char *first_name, char *last_name) {
  printf("generating email_address | ");
  unsigned int random_number = generate_random_number(0, 99);
  char *email_suffix_str = email_suffixes[random_number];

  /* first letter of first_name + full last_name + null */
  unsigned int prefix_len = 1 + strlen(last_name) + 1;
  char prefix[prefix_len];
  prefix[prefix_len - 1] = '\0';

  /* using sprintf to convert the first letter of the first name to a
   * string so that I can append it later */
  char first_letter_str[2];
  char first_letter = first_name[0];
  sprintf(first_letter_str, "%c", first_letter);

  /* using sprintf to convert the at symbol to a string so that I can append
   * it later */
  char at_str[2];
  char at = '@';
  sprintf(at_str, "%c", at);

  /* using a custom function to append the strings together */
  char *email_str = append_strings(first_letter_str, last_name);
  email_str = append_strings(email_str, at_str);
  email_str = append_strings(email_str, email_suffix_str);

  return email_str;
}

/**
 * This function generates a sin for the person. It will generate a
 * random number between 100000000 and 999999999 and then return it as a string.
 * @return sin_str - the sin as a string
 */
char *generate_sin() {
  printf("generating sin           | ");
  unsigned int sin_int = generate_random_number(100000000, 999999999);
  /* converting the SIN to a string so that I can return it */
  /* max length of id is 8 because of 1M + we need to add 1 for null char */
  char *sin_str = malloc(8 * sizeof(int));
  sprintf(sin_str, "%d", sin_int);
  return sin_str;
}

/**
 * This function generates a password for the person. It will generate a random
 * number between 8 and 16 and then use that number as the length of the
 * password. Then it will generate a random character for each index of the
 * password.
 * @return
 */
char *generate_password() {
  printf("generating password      | ");
  /* generating a random number between 8 and 16 to determine the length
   * of the password */
  unsigned int random_password_length =
      generate_random_number(PASSWORD_MIN_VALUE, PASSWORD_MAX_VALUE);

  /* using malloc to allocate memory for the password */
  char *password_ptr = malloc(sizeof(char) * random_password_length + 1);
  for (int i = 0; i < random_password_length; i++) {
    password_ptr[i] = generate_random_char();
  }
  /* adding a null character at the end of the password */
  password_ptr[random_password_length] = '\0';
  return password_ptr;
}

/**
 * This function generates a random character. It will generate a random number
 * between 0 and 93 and then use that number as an index to retrieve a character
 * from the chars_authorized array. The chars_authorized array contains all the
 * characters that are allowed in a password. The reason why the random number
 * is between 0 and 93 is because the chars_authorized array contains 94
 * items. The coma is not included because it is used as a delimiter in the csv
 * file.
 * @return random_char - the random character
 */
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

/**
 * This function generates a random number between min and max. It will use the
 * rand() function to generate a random number between 0 and max - min + 1. Then
 * it will add min to the random number to get a random number between min and
 * max. This function is called many times in the generate.c.
 * @param min - the minimum value of the random number
 * @param max - the maximum value of the random number
 * @return random_number - the random number between min and max (inclusive)
 */
unsigned int generate_random_number(int min, int max) {
  unsigned int random_number;
  random_number = (rand() % (max - min + 1)) + min;
  return random_number;
}

/**
 * This function appends two strings together. It will create a new string that
 * is the length of the two strings combined. Then it will copy the first string
 * into the new string, and then it will copy the second string into the new
 * string. Finally it will add a null character at the end of the new string. It
 * will then return the new string. The reason why we need to create a new
 * string is because we cannot modify the size of the first string. We need to
 * create a new string that is the size of the two strings combined. Then we can
 * copy the two strings into the new string. We need to add a null character at
 * the end because the new string is not initialized with a null character.
 * @param first_string - the first string
 * @param second_string - the second string
 * @return result - the two strings combined into one string
 */
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