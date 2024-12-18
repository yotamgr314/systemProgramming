#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <stddef.h> // for size_t

// Function to create an array of integers with a given size
int* create_array(size_t size);

// Function to fill an array with user input
void fill_array_from_user(int *array, size_t size);

// Function to print an array
void print_array(const int *array, size_t size);

// Function to free the memory allocated for the array
void free_array(int *array);

#endif // INPUT_HANDLER_H
