#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#pragma region Prototypes and Questions
/*
7. Concurrency (if applicable)
Problem: Implement a simple semaphore or mutex for synchronization.
Concepts: Concurrency, synchronization mechanisms.
Example: Write a simple semaphore or mutex mechanism to control access to shared resources.
*/
void* thread(void*)

sem_t mutex;
#pragma endregion

int main(void)
{
    sem_init(&mutex, 0, 1);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,thread,NULL);
    sleep(2);
    pthread_create(&t2,NULL,thread,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&mutex);
    return 0;
}

#pragma region Concurrency
void* thread(void* arg)
{
    //wait
    sem_wait(&mutex);
    printf("\nEntered..\n");

    //critical section
    sleep(4);
    
    //signal
    printf("\nJust Exiting...\n");
    sem_post(&mutex);
}
#pragma endregion

