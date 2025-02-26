#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // if (argc != 2) {
    //     printf("Usage: %s <memory_size>\n", argv[0]);
    //     return 1;
    // }

    // Convert argv[1] to integer using atoi
    int size = atoi(argv[1]);
    // No need to check for negative values
    // if (size <= 0) {
    //     printf("Invalid memory size.\n");
    //     return 1;
    // }

    // Allocate memory using malloc
    char *memory = (char*) malloc(size);
    if (memory == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Fill the memory with 'A' to 'Z' and '1' to '9' in a loop
    char pattern[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
    int pattern_size = 35;
    
    for (int i = 0; i < size; i++) {
        memory[i] = pattern[i % pattern_size];
    }

    // Print the generated string
    printf("Generated String: %.*s\n", size, memory);

    // Process memory with an int pointer and while loop
    int *int_ptr = (int*) memory;
    int bytes_processed = 0;

    while (bytes_processed + sizeof(int) <= size) {
        printf("%d : %d\n", *int_ptr, *int_ptr - 1);
        int_ptr++;
        bytes_processed += sizeof(int);
    }

    // Free allocated memory
    free(memory);

    return 0;
}
