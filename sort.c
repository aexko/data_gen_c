#include "generate.h"

/**
 * Function to compare two elements in a list of people by last name
 * @param first_element - first element to compare
 * @param second_element - second element to compare
 * @return -1 if first element is less than second element, 0 if equal, 1 if
 * greater than second element
 */
int compare(const void *first_element, const void *second_element) {
  struct Person *person_a = (struct Person *)first_element;
  struct Person *person_b = (struct Person *)second_element;
  return (person_b->last_name - person_a->last_name);
}
