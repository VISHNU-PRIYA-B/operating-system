#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 3

int buffer[BUFFER_SIZE];
int count = 0;
int in = 0;
int out = 0;

void *producer(void *arg) {
    int i;
    for (i = 0; i < 4; i++) {
        while (count == BUFFER_SIZE) ; 
        buffer[in] = i;
        printf("Producer produced %d\n", i);
        in = (in + 1) % BUFFER_SIZE;
        count++;
    }
    return NULL;
}

void *consumer(void *arg) {
    int i;
    for (i = 0; i < 1; i++) {
        while (count == 0) ; 
        int data = buffer[out];
        printf("Consumer consumed %d\n", data);
        out = (out + 1) % BUFFER_SIZE;
        count--;
    }
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    if (count == 0) {
        printf("Buffer is empty\n");
    } else if (count == BUFFER_SIZE) {
        printf("Buffer is full\n");
    } else {
        printf("Buffer is partially full\n");
    }

    return 0;
}
