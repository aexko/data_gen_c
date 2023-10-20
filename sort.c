#include "generate.h"

// sorted alphabetically by last name

void sort_alphabetically(void *list) {
}


int compare(const void *first_element, const void *second_element) {
  struct Person *person_a = (struct Person *)first_element;
  struct Person *person_b = (struct Person *)second_element;
  return (person_b->last_name - person_a->last_name);
}
