#ifndef A1_KAO_ALEX_40286533_GENERATE_H
#define A1_KAO_ALEX_40286533_GENERATE_H

#define USER_ID '1'
#define FIRST_NAME '2'
#define LAST_NAME '3'
#define COUNTRY '4'
#define PHONE_NUMBER '5'
#define EMAIL_ADDRESS '6'
#define SIN '7'
#define PASSWORD '8'
#define SIN_LENGTH '9'
#define PASSWORD_MAX_VALUE 16
#define PASSWORD_MIN_VALUE 6
#define BUFFER_SIZE 8192

void generate_data();

char generate_random_char();
int generate_random_number(int min, int max);

char *generate_id();
char *generate_first_name();
const char *generate_last_name();
const char *generate_country();
void generate_phone_number();
void generate_email_address();
char *generate_password();
void generate_sin();

#endif
