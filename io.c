#include "io.h"
#include "generate.h"
#include "tablegen.h"
#include <ctype.h>
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

extern char output_file_name[20];
extern char **array_output;
extern const int row_count;
extern int initial_id;
extern char user_input_column_list[20];

/**
 * This function is not working, it creates segmentation fault as an error
 */
void free_memory() {
  free(first_names);
  free(last_names);
  free(countries);
  free(email_suffixes);
  //  for (int i = 0; i < 1000; i++) {
  //    free(first_names[i]);
  //  }

  //  for (int i = 0; i < 1000; i++) {
  //    printf("freeing %d", i);
  //    free(last_names[i]);
  //  }
  //
  //  for (int i = 0; i < 195; i++) {
  //    printf("freeing %d", i);
  //    free(countries[i]);
  //  }
  //
  //  for (int i = 0; i < 100; i++) {
  //    printf("freeing %d", i);
  //    free(email_suffixes[i]);
  //  }
  //    free(first_names);

  //  free(last_names);
  //  free(countries);
  //  free(email_suffixes);
  printf("Memory cleared successfully\n");
}

void add_csv_extension() {
  for (int i = 0; i < MAX_LENGTH_INPUT; i++) {
    if (output_file_name[i] == '\0') {
      output_file_name[i] = '.';
      output_file_name[i + 1] = 'c';
      output_file_name[i + 2] = 's';
      output_file_name[i + 3] = 'v';
      break;
    }
  }
}

void save() {
  add_csv_extension();

  FILE *file_handler = fopen(output_file_name, "w+");
  printf("Saving...\n");

  fprintf(file_handler, "asdasd");
  fprintf(file_handler, "asdasd");

  fclose(file_handler);
  printf("End of program\n");
}

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

  bind_data(file_name);

  //  for (int i =0; i < 1000; i++) {
  //    printf("%s\n", first_names[i]);
  //  }

  fclose(file_handler);
}

void bind_data(char *file_name) {
  if (strcmp(file_name, "first_names.txt") == 0) {
    first_names = malloc(max_lines * sizeof(char *));
    first_names = data;
  }
  if (strcmp(file_name, "last_names.txt") == 0) {
    last_names = malloc(max_lines * sizeof(char *));
    last_names = data;
  }
  if (strcmp(file_name, "countries.txt") == 0) {
    countries = malloc(max_lines * sizeof(char *));
    countries = data;
  }
  if (strcmp(file_name, "email_suffixes.txt") == 0) {
    email_suffixes = malloc(max_lines * sizeof(char *));
    email_suffixes = data;
  }

  // free data pointer
  //  for (int i = 0; i < max_lines; i++) {
  //    free(data[i]);
  //  }
  //  free(data);
  //  data = NULL;
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
  }
  if (strcmp(file_name, "last_names.txt") == 0) {
    rows_last_names = nb_rows;
  }
  if (strcmp(file_name, "countries.txt") == 0) {
    rows_countries = nb_rows;
  }
  if (strcmp(file_name, "email_suffixes.txt") == 0) {
    rows_email_suffixes = nb_rows;
  }

  nb_rows = 0;

  fclose(file_handler);
}
