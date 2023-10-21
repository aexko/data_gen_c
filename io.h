#ifndef A1_KAO_ALEX_40286533_IO_H
#define A1_KAO_ALEX_40286533_IO_H

/* 8k buffer */
#define BUFFER_SIZE 8192
int check_file(char *file_name);
void count_rows_file(char *file_name);
int determine_max_lines(char *name);
void read_file(char *file_name);
void bind_data(char *file_name);
void save();
void add_csv_extension();
void free_memory();

#endif
