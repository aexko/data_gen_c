#ifndef A1_KAO_ALEX_40286533_TABLEGEN_H
#define A1_KAO_ALEX_40286533_TABLEGEN_H

#define MENU '0'
#define NEW_TABLE '1'
#define EXIT '2'
#define ERROR_INPUT '3'
#define ROW_NUMBER '4'
#define OUTPUT_NAME '5'
#define CONFIRMATION '6'

void initializeProgram();
void display_message(int type);
void prompt_user_for_input(int type);
void display_summary_properties();

#endif
