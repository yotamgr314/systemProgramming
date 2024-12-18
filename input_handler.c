#include <stdio.h>
#include <stdlib.h>
#include "input_handler.h"

// Function to create an array dynamically
int* create_array(size_t size) {
    int *array = (int *)malloc(size * sizeof(int));
    if (!array) {
        perror("Failed to allocate memory for the array");
        exit(EXIT_FAILURE);
    }
    return array;
}

// Function to fill an array with user input
void fill_array_from_user(int *array, size_t size) {
    printf("Enter %zu integers:\n", size);
    for (size_t i = 0; i < size; i++)
    {
        printf("Element %zu: ", i + 1);
        scanf("%d", &array[i]);
    }
}

// Function to print the elements of an array
void print_array(const int *array, size_t size) {
    printf("Array: [");
    for (size_t i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Function to free the dynamically allocated array
void free_array(int *array) {
    free(array);
}
