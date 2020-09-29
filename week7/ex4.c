#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc/malloc.h>

void *custom_memcpy(void *destination, const void *source, size_t length) {
    char *new_source = (char *) source;
    char *new_destination = (char *) destination;
    size_t i = 0;

    while (i < length) {
        *(new_destination + i) = *(new_source + i);
        i++;
    }

    return new_destination;
}

void *custom_realloc(void *array, size_t new_size) {
    size_t initial_size = malloc_size(array);
    size_t initial_length = initial_size / sizeof(*array);
    size_t new_length = new_size / sizeof(*array);

    if (new_size == 0) {
        free(array);
        return NULL;
    } else if (initial_length == 0) {
        return malloc(new_length);
    } else if (new_length <= initial_length) {
        return array;
    } else {
        void *new_array = malloc(new_size);
        if (new_array) {
            custom_memcpy(new_array, array, initial_length);
            free(array);
        }
        return new_array;
    }
}


int main() {
    srand(time(NULL));

    int n1, n2;
    printf("Input the initial array length: ");
    scanf("%d", &n1);

    int* array = (int *) malloc(n1 * sizeof(int));
    for (int i = 0; i < n1; ++i) {
        *(array + i) = 100;
    }

    for(int i = 0; i < n1; ++i){
        printf("%d ", *(array + i));
    }
    printf("\n");

    printf("Input the new array length: ");
    scanf("%d", &n2);
    array = (int *) custom_realloc(array, n2 * sizeof(int));

    if (n2 > n1) {
        for (int i = n1; i < n2; ++i) {
            *(array + i) = 0;
        }
    }

    for(int i = 0; i < n2; ++i){
        printf("%d ", *(array + i));
    }
    printf("\n");

    return 0;
}