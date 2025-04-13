#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int value = 0;

// thread function prototype
void* routine();

int main(int argc, char* argv[]) {
    // thread declaration
    pthread_t thread;
    // result declaration
    int* result;

    // creating thread
    if (pthread_create(&thread, NULL, &routine, NULL)) return EXIT_FAILURE;
    if (pthread_join(thread, (void**)&result)) return EXIT_FAILURE;
    printf("%d\n", *result);

    return EXIT_SUCCESS;
}

// thread function
void* routine() {
    value++;
    int* result = malloc(sizeof(int));
    *result = value;

    return result;
}