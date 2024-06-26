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
#define PASSWORD_MAX_VALUE 16
#define PASSWORD_MIN_VALUE 6
#define BUFFER_SIZE 8192

struct Person {
  char *id;
  char *first_name;
  char *last_name;
  char *country;
  char *phone_number;
  char *email;
  char *sin;
  char *password;
};

void generate_data();

char *generate_id();
char *generate_first_name();
char *generate_last_name();
char *generate_country();
char *generate_phone_number();
char *generate_email_address(char *first_name, char *last_name);
char *generate_sin();
char *generate_password();

char generate_random_char();
unsigned int generate_random_number(int min, int max);
char *append_strings(char *first_string, char *second_string);

#endif
