/*
# Name: Yihui Qin
# Date: 02/01/2022 
# Title: Lab1 – task 2 - conditional variables
# Description: This program solves the producer-consumer problem with one customer thread and one producer thread, which is a multi-threaded program with mutual exclusion using semaphores.
*/


//Shared data: semaphore full, empty, mutex;
//pool of n buffers, each can hold one item
//mutex provides mutual exclusion to the buffer pool
//empty and full count the number of empty and full buffers
//Initially: full = 0, empty = n, mutex = 1
//Producer thread

#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 
#include <semaphore.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  
#define NTHREADS 10
#define BUFFERSIZE 10

pthread_t threads[2];
sem_t mutex, full, empty;
int buffer[BUFFERSIZE];

void *producer(void * arg){
    sleep(1);
    int pitem, in = 0;
    do { 
    //produce next item
    sleep(rand() % 2);
    pitem = rand();
    
    
    sem_wait(&empty);
    sem_wait(&mutex);
    
    //add the item to buffer
    buffer[in] = pitem;
    printf("Producer %d: Insert Item %d at %d\n", *((int *)arg),pitem,in);
    in = (in + 1) % BUFFERSIZE;
    sem_post(&mutex);
    sem_post(&full);
    } while (1);
}

//Consumer thread
void *consumer(void * arg){
    int citem, out = 0;
    do { 
        sleep(rand() % 5);
        sem_wait(&full);
        sem_wait(&mutex);
        
        //remove next item from buffer
        citem = buffer[out];
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)arg),citem, out);
        out = (out + 1) % BUFFERSIZE;
        sem_post(&mutex);
        sem_post(&empty);
        //sleep(1);
        //consume the item
        
    } while (1);
}
 

int main() { 
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, BUFFERSIZE);
    static int i;
    
    pthread_create(&threads[0], NULL, producer, (void *)&threads[0]);
    sleep(3);
    pthread_create(&threads[1], NULL, consumer, (void *)&threads[1]);

    for (i = 0; i < 2; i++) {
        pthread_join(threads[i],NULL);
        printf("\t\t\tThread %d returned \n", i);
    }
    printf("Main thread done.\n");
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0; 
} 