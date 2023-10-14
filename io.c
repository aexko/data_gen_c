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

const char *list_first_names[1000];

int rows_first_names;
int rows_last_names;
int rows_countries;
int rows_email_suffixes;


void check_files() {

}
/**
 * Read And Store All Lines Of A File Into An Array Of Strings
 * Description: Example of reading and storing all the lines of a file into an
 * array of strings in C.
 * Author: Kevin Browne @ https://portfoliocourses.com
 **/
void read_file(char *fileName) {
  FILE *file_handler = fopen(fileName, "r");
  if (file_handler == NULL) {
    printf("One of the files could not be opened. Please make sure that "
           "the required .txt files are present in the local repository. "
           "Thank you!\n");
    exit(1);
  } else {
  }
  fclose(file_handler);
}

void countRowsFile(char *fileName) {
  FILE *file_handler = fopen(fileName, "r");
  int nb_rows = 0;
  int c;
  while (!feof(file_handler) && !ferror(file_handler)) {
    c = fgetc(file_handler);
    if (c == '\n') {
      nb_rows++;
    }
  }

  if (strcmp(fileName, "first_names.txt") == 0) {
    rows_first_names = nb_rows;
    printf("first_names.txt: %d\n", rows_first_names);
  }
  if (strcmp(fileName, "last_names.txt") == 0) {
    rows_last_names = nb_rows;
    printf("last_names.txt: %d\n", rows_last_names);
  }
  if (strcmp(fileName, "countries.txt") == 0) {
    rows_countries = nb_rows;
    printf("countries.txt %d\n", rows_countries);
  }
  if (strcmp(fileName, "email_suffixes.txt") == 0) {
    rows_email_suffixes = nb_rows;
    printf("email_suffixes.txt %d\n", rows_email_suffixes);
  }

  fclose(file_handler);
}
