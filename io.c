#include "io.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FILE_FIRST_NAMES 1
#define FILE_LAST_NAMES 2
#define FILE_COUNTRIES 3
#define FILE_EMAIL_SUFFIXES 4

// https://www.youtube.com/watch?v=vQno9S3yF80
#define MAX_LENGTH 30
#define MAX_LINES 1001
// https://www.quora.com/How-can-I-read-a-file-into-a-buffer-in-C
/* 8k buffer */
#define BUFFER_SIZE 8192

const char *list_first_names[1000];

int rows_first_names;
int rows_last_names;
int rows_countries;
int rows_email_suffixes;


char **first_names;
char **last_names;
char **countries;
char **email_suffixes;

void free_memory(char* name_pointer) {
  for (int i = 0; i < strlen(name_pointer); i++) {
    printf("freeing %d", i);
    free(name_pointer[i]);
  }
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

  char **data;
  int max_lines;

  if (strcmp(file_name, "first_names.txt") == 0) {
    data = malloc(sizeof(char*) * rows_first_names);
    max_lines = rows_first_names;
  }
  if (strcmp(file_name, "last_names.txt") == 0) {
    data = malloc(sizeof(char*) * rows_last_names);
    max_lines = rows_last_names;

  }
  if (strcmp(file_name, "countries.txt") == 0) {
    data = malloc(sizeof(char*) * rows_countries);
    max_lines = rows_countries;

  }
  if (strcmp(file_name, "email_suffixes.txt") == 0) {
    data = malloc(sizeof(char*) * rows_email_suffixes);
    max_lines = rows_email_suffixes;
  }

  char buffer[BUFFER_SIZE];
  int length;
  for (int i = 0; i < max_lines; i++ ) {

    fgets(buffer, max_lines, file_handler);
    length = strlen(buffer);
    buffer[length - 1] = '\0';
    data[i] = malloc(length * sizeof (char));
    strcpy(data[i], buffer);
  }

  first_names = data;
  for (int i = 0; i < max_lines; i++ ) {
    printf("printing the array of pointers: %s\n", first_names[i] );
  }



  fclose(file_handler);
}

void count_rows_file(char *file_name) {
  FILE *file_handler = fopen(file_name, "r");
  int nb_rows = 0;
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

  fclose(file_handler);
}
