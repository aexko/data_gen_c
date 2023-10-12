#ifndef A1_KAO_ALEX_40286533_TABLEGEN_H
#define A1_KAO_ALEX_40286533_TABLEGEN_H

char user_input_column_list[20];
char user_input_menu_choice;
int row_count;
char output_file_name[20];

void cleanUserInput();
void display_message(int type);
void prompt_user_for_input(int type);
void display_summary_properties();

#endif
