// Producer-Consumer Problem using Semaphore & Mutex (Bounded Buffer)

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t empty, full;
pthread_mutex_t mutex;

void* producer(void* arg) {
    int item, i;
    for (i = 0; i < 10; i++) {
        item = rand() % 100;  // Produce a random item

        sem_wait(&empty);          // Wait if buffer is full
        pthread_mutex_lock(&mutex);  // Acquire mutex lock

        buffer[in] = item;
        printf("Producer produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);  // Release mutex lock
        sem_post(&full);              // Signal that buffer has new item

        sleep(1);  // Sleep for visibility
    }
    pthread_exit(NULL);
}

void* consumer(void* arg) {
    int item, i;
    for (i = 0; i < 10; i++) {
        sem_wait(&full);           // Wait if buffer is empty
        pthread_mutex_lock(&mutex);  // Acquire mutex lock

        item = buffer[out];
        printf("Consumer consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);  // Release mutex lock
        sem_post(&empty);             // Signal that buffer has empty space

        sleep(1);  // Sleep for visibility
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t prod, cons;

    // Initialize semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // Create producer and consumer threads
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    // Destroy semaphores and mutex
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
