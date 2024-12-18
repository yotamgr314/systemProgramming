#include <stdio.h>
#include <stdlib.h>
#include "input_handler.h"
#include "count_even.h"

int main() {
    size_t array_size;

    // Step 1: Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%zu", &array_size);

    // Step 2: Create an array with the specified size
    int *array = create_array(array_size);

    // Step 3: Fill the array with user input
    fill_array_from_user(array, array_size);

    // Step 4: Print the array
    print_array(array, array_size);

    // Step 5: Count and print the number of even numbers in the array
    int even_count = count_even_numbers(array, array_size);
    printf("Total even numbers in the array: %d\n", even_count);

    // Step 6: Clean up the memory used by the array
    free_array(array);

    return 0;
}
