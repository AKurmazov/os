#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define true 1
#define false 0
#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int current = 0; // The amount of produced units at a time being

pthread_cond_t cons_cond, prod_cond;
pthread_mutex_t lock;

void * producer(void *arg){
    int counter = 0;
    while(true) {
        pthread_mutex_lock(&lock);
        while (current == BUFFER_SIZE) {
            printf("There are no space to produce so the producer is down\n");
            pthread_cond_wait(&prod_cond, &lock);
        }
        buffer[current] = counter;
        current++;
        while (current == 1) {
            printf("There are something to consume so the consumer is up\n");
            pthread_cond_signal(&cons_cond);
        }
        pthread_mutex_unlock(&lock);
        counter++;
    }
}

void * consumer(void *arg){
    int counter = 0;
    while(true) {
        pthread_mutex_lock(&lock);
        while (current == 0) {
            printf("There is nothing to it so the consumer is down\n");
            pthread_cond_wait(&cons_cond, &lock);
        }
        buffer[current] = 0;
        current--;
        while (current == BUFFER_SIZE - 1) {
            printf("There are some space to produce so producer is up\n");
            pthread_cond_signal(&prod_cond);
        }
        pthread_mutex_unlock(&lock);
        counter++;
    }
}

int main(){
    pthread_t consumer_t, producer_t;

    pthread_cond_init(&cons_cond, 0);
    pthread_cond_init(&prod_cond, 0);
    pthread_mutex_init(&lock, 0);

    pthread_create(&consumer_t, NULL, consumer, NULL);
    pthread_create(&producer_t, NULL, producer, NULL);

    pthread_join(producer_t, NULL);
    pthread_join(consumer_t, NULL);

    pthread_cond_destroy(&cons_cond);
    pthread_cond_destroy(&prod_cond);

    pthread_mutex_destroy(&lock);

    return 0;
}
