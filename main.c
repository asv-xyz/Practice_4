#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// mutex declaration
pthread_mutex_t mutex;
int counter = 0;

// thread function prototype
void* routine();

int main(int argc, char* argv[]) {
    pthread_t threads[5];

    // mutex initialization
    pthread_mutex_init(&mutex, NULL);

    // creating threads
    for (int i = 0; i<5; i++) {
        if (pthread_create(&threads[i], NULL, &routine, NULL)) return EXIT_FAILURE;
        printf("Thread %d has been created\n", i);
    }
    printf("\n");
    // waiting for thread to close
    for (int i = 0; i<5; i++) {
        pthread_join(threads[i], NULL);
        printf("Thread %d has stopped\n", i);
    }
    printf("\n");

    //mutex destruction
    pthread_mutex_destroy(&mutex);
    
    printf("%d\n", counter);

    return EXIT_SUCCESS;
}

//thread function
void* routine() {
    
    // making mutex to prevent threads from race conditions

    // mutex lock
    pthread_mutex_lock(&mutex);

    counter++;

    // mutex unlock
    pthread_mutex_unlock(&mutex);

    return NULL;
}