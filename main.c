#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stddef.h> // for size_t

/***********************
 * Struct Declaration
 ***********************/

typedef struct {
    int *array;        // Pointer to the array
    size_t start;      // Start index of the sub-array
    size_t end;        // End index of the sub-array
} ThreadData;

/***********************
 * Function Declarations
 ***********************/

int* create_array(size_t size);
void fill_array_from_user(int *array, size_t size);
void print_array(const int *array, size_t size);
void free_array(int *array);
void* count_even_numbers(void *arg);


/***********************
 * Function Definitions
 ***********************/

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
    for (size_t i = 0; i < size; i++) {
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

// Function for each thread to count the even numbers in its part of the array
void* count_even_numbers(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int *count = malloc(sizeof(int));
    if (!count) {
        perror("Failed to allocate memory for count");
        pthread_exit(NULL);
    }
    *count = 0;
    for (size_t i = data->start; i < data->end; i++) {
        if (data->array[i] % 2 == 0) {
            (*count)++;
        }
    }
    pthread_exit(count);
}

/***********************
 * Main Function
 ***********************/

int main() {
    size_t array_size;

    // Step 1: Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%zu", &array_size);

    // Step 2: Create an array with the specified size
    int *array = create_array(array_size);

    // Step 3: Fill the array with user input
    fill_array_from_user(array, array_size);
    print_array(array, array_size);

    // Step 4: Prepare thread data for two threads
    pthread_t thread1, thread2;
    ThreadData data1, data2;

    size_t mid = array_size / 2;

    // Initialize data for first half of the array
    data1.array = array;
    data1.start = 0;
    data1.end = mid;

    // Initialize data for second half of the array
    data2.array = array;
    data2.start = mid;
    data2.end = array_size;

    // Step 5: Create two threads to count the even numbers
    if (pthread_create(&thread1, NULL, count_even_numbers, &data1) != 0) {
        perror("Failed to create thread 1");
        free_array(array);
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&thread2, NULL, count_even_numbers, &data2) != 0) {
        perror("Failed to create thread 2");
        free_array(array);
        exit(EXIT_FAILURE);
    }

    // Step 6: Wait for both threads to finish
    void *result1;
    void *result2;

    if (pthread_join(thread1, &result1) != 0) {
        perror("Failed to join thread 1");
    }

    if (pthread_join(thread2, &result2) != 0) {
        perror("Failed to join thread 2");
    }

    // Step 7: Calculate total count of even numbers
    int total_even_count = *(int *)result1 + *(int *)result2;
    free(result1);
    free(result2);

    // Print the result
    printf("Total even numbers in the array: %d\n", total_even_count);

    // Clean up the memory used by the array
    free_array(array);

    return 0;
}
