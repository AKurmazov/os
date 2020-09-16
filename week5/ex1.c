#include <stdio.h>
#include <pthread.h>

#define N 5 // Number of threads

void * print_thread(void * p) {
    printf("Hello from thread #%d!\n", p);
    pthread_exit(NULL);
}

int main() {
    pthread_t ids[N];
    int status;

    for (int i = 0; i < N; ++i) {
        printf("Creating thread #%d\n", ids[i]);
        status = pthread_create(&ids[i], NULL, print_thread, (void *) ids[i]);
        if (status != 0) {
            printf("Something went wrong, status code: %d\n", status);
            return -1;
        }
    }

    // The sequential way
    for (int i = 0; i < N; ++i) {
        printf("Creating thread #%d\n", ids[i]);
        status = pthread_create(&ids[i], NULL, print_thread, (void *) ids[i]);
        if (status != 0) {
            printf("Something went wrong, status code: %d\n", status);
            return -1;
        }
        pthread_join(ids[i], NULL);
    }

    return 0;
}