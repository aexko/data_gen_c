#include "io.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rows_first_names;
int rows_last_names;
int rows_countries;
int rows_email_suffixes;

int nb_rows = 0;
int max_lines;

/* 2d arrays */
char **first_names;
char **last_names;
char **countries;
char **email_suffixes;

char **data;

/**
 * This function is not working, it creates segmentation fault as an error
 */
// void free_memory() {
//   size_t length = strlen((const char *)first_names);
//   for (int i = 0; i < length; i++) {
//     printf("freeing %d", i);
//     free(first_names[i]);
//   }
//
//   length = strlen((const char *)last_names);
//   for (int i = 0; i < length; i++) {
//     printf("freeing %d", i);
//     free(last_names[i]);
//   }
//
//   length = strlen((const char *)countries);
//   for (int i = 0; i < length; i++) {
//     printf("freeing %d", i);
//     free(countries[i]);
//   }
//
//   length = strlen((const char *)email_suffixes);
//   for (int i = 0; i < length; i++) {
//     printf("freeing %d", i);
//     free(email_suffixes[i]);
//   }
//
//   free(first_names);
//   free(last_names);
//   free(countries);
//   free(email_suffixes);
// }

int check_file(char *file_name) {
  FILE *file_handler = fopen(file_name, "r");
  if (file_handler == NULL) {
    printf("%s could not be opened. Please make sure that "
           "the required .txt files are present in the local repository. "
           "Thank you!\n",
           file_name);
    exit(1);
  } else {
    count_rows_file(file_name);
    fclose(file_handler);
    return 0;
  }
}

void read_file(char *file_name) {
  FILE *file_handler = fopen(file_name, "r");
  max_lines = determine_max_lines(file_name);

  data = malloc(sizeof(char *) * max_lines);
  char buffer[BUFFER_SIZE];
  unsigned length;
  for (int i = 0; i < max_lines; i++) {

    fgets(buffer, max_lines, file_handler);
    length = strlen(buffer);
    buffer[length - 1] = '\0';
    data[i] = malloc(length * sizeof(char));
    strcpy(data[i], buffer);
  }


  for (int i = 0; i < max_lines; i++) {
    printf("printing the array of pointers: %s\n", data[i]);
  }

  //  for (int i = 0; i < max_lines; i++) {
  //    free(data[i]);
  //  }
  //  free(data);

  fclose(file_handler);
}

int determine_max_lines(char *file_name) {
  if (strcmp(file_name, "first_names.txt") == 0) {
    max_lines = rows_first_names;
  }
  if (strcmp(file_name, "last_names.txt") == 0) {
    max_lines = rows_last_names;
  }
  if (strcmp(file_name, "countries.txt") == 0) {
    max_lines = rows_countries;
  }
  if (strcmp(file_name, "email_suffixes.txt") == 0) {
    max_lines = rows_email_suffixes;
  }
  return max_lines;
}

void count_rows_file(char *file_name) {
  FILE *file_handler = fopen(file_name, "r");
  int c;
  while (!feof(file_handler) && !ferror(file_handler)) {
    c = fgetc(file_handler);
    if (c == '\n') {
      nb_rows++;
    }
  }

  if (strcmp(file_name, "first_names.txt") == 0) {
    rows_first_names = nb_rows;
    printf("first_names.txt: %d\n", rows_first_names);
  }
  if (strcmp(file_name, "last_names.txt") == 0) {
    rows_last_names = nb_rows;
    printf("last_names.txt: %d\n", rows_last_names);
  }
  if (strcmp(file_name, "countries.txt") == 0) {
    rows_countries = nb_rows;
    printf("countries.txt %d\n", rows_countries);
  }
  if (strcmp(file_name, "email_suffixes.txt") == 0) {
    rows_email_suffixes = nb_rows;
    printf("email_suffixes.txt %d\n", rows_email_suffixes);
  }

  nb_rows = 0;

  fclose(file_handler);
}
