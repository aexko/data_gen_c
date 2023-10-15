#ifndef A1_KAO_ALEX_40286533_IO_H
#define A1_KAO_ALEX_40286533_IO_H

// https://www.quora.com/How-can-I-read-a-file-into-a-buffer-in-C
/* 8k buffer */
#define BUFFER_SIZE 8192
char user_input_column_list[20];
int check_file(char *file_name);
void read_file(char *file_name);
void count_rows_file(char *file_name);
void free_memory();

#endif
