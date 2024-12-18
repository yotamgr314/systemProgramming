#include <stdio.h>
#include "count_even.h"

// Function to count the even numbers in an array
int count_even_numbers(const int *array, size_t size) {
    int count = 0;
    for (size_t i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}
