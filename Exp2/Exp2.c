#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execute_flawed_routine(void) {
    printf("\n--- Starting Flawed Routine ---\n");
    
    size_t initial_size = 5;
    size_t new_size = 10;
    
    int *ptr = (int *)malloc(1000000000000000ULL * sizeof(int));
    printf("[Flawed] Malloc ptr value: %p\n", (void *)ptr);
    
    ptr[0] = 42; 
    printf("[Flawed] Value written successfully: %d\n", ptr[0]);

    ptr = (int *)malloc(initial_size * sizeof(int));
    printf("[Flawed] Valid Malloc ptr value: %p, size: %zu elements\n", (void *)ptr, initial_size);
    
    ptr = (int *)realloc(ptr, new_size * sizeof(int));
    printf("[Flawed] Realloc ptr value: %p, size: %zu elements\n", (void *)ptr, new_size);
    
    free(ptr);
    printf("[Flawed] Free called. Dangling ptr value remains: %p\n", (void *)ptr);

    ptr[0] = 99; 
    printf("[Flawed] Value after free (Use-after-free): %d\n", ptr[0]);
}

void execute_secure_routine(void) {
    printf("\n--- Starting Corrected Routine ---\n");
    
    size_t initial_size = 5;
    size_t new_size = 10;
    
    int *ptr = (int *)malloc(initial_size * sizeof(int));
    if (ptr == NULL) {
        fprintf(stderr, "[Secure] Error: Memory allocation failed!\n");
        return;
    }
    printf("[Secure] Malloc successful. Ptr: %p, Size: %zu elements\n", (void *)ptr, initial_size);
    
    for (size_t i = 0; i < initial_size; i++) {
        ptr[i] = (int)(i + 1);
    }
    
    int *temp = (int *)realloc(ptr, new_size * sizeof(int));
    if (temp == NULL) {
        fprintf(stderr, "[Secure] Error: Reallocation failed!\n");
        free(ptr);
        ptr = NULL;
        return;
    }
    ptr = temp; 
    printf("[Secure] Realloc successful. Ptr: %p, Size: %zu elements\n", (void *)ptr, new_size);
    
    for (size_t i = initial_size; i < new_size; i++) {
        ptr[i] = (int)(i + 1);
    }
    
    free(ptr);
    ptr = NULL; 
    printf("[Secure] Memory freed and pointer nullified. Ptr: %p\n", (void *)ptr);
    
    if (ptr != NULL) {
        ptr[0] = 99;
    } else {
        printf("[Secure] Pointer is NULL. Safe access prevented.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [0|1]\n", argv[0]);
        return 1;
    }
    
    int choice = atoi(argv[1]);
    
    if (choice == 1) {
        execute_flawed_routine();
    } else if (choice == 0) {
        execute_secure_routine();
    } else {
        fprintf(stderr, "Invalid option. Use 0 for Secure, 1 for Flawed.\n");
        return 1;
    }
    
    return 0;
}
