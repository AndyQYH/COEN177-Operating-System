/*
# Name: Yihui Qin
# Date: 02/01/2022 
# Title: Lab1 – task 2 - conditional variables
# Description: This program solves the producer-consumer problem with one customer thread and one producer thread, which is a multi-threaded program with mutual exclusion using mutex and conditional variables.
*/
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
pthread_mutex_t mutex;
pthread_cond_t full, empty;
int buffer[BUFFERSIZE];
int in = 0, out = 0;

//Producer thread
void * producer(void *arg)
{
    int pitem;
    do { 
        
        //produce next item
        sleep(rand() % 5);
        pitem = rand() % 5;
        pthread_mutex_lock(&mutex);
        while ((in + 1) % BUFFERSIZE == out % BUFFERSIZE)
        {
            pthread_cond_wait(&empty, &mutex);
        }
            
        //add the item to buffer
        buffer[in] = pitem;
        printf("Producer %d: Insert Item %d at %d\n", *((int *)arg),buffer[in],in);
        in = (in + 1) % BUFFERSIZE;
        pthread_cond_signal(&full);
        pthread_mutex_unlock(&mutex);
    }while (1);
}

//Consumer thread
void * consumer(void *arg)
{
    int citem;
    do { 
        sleep(rand() % 5);
        pthread_mutex_lock(&mutex);
        while (out % BUFFERSIZE == in % BUFFERSIZE)
        {
            pthread_cond_wait(&full, &mutex);
        }
        
        
        //remove next item from buffer
        citem = buffer[out];
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)arg),citem, out);
        out = (out + 1) % BUFFERSIZE;
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);
        
        //consume the item
        
    } while (1);
}

int main() { 
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&full, NULL);
    pthread_cond_init(&empty, NULL);
    static int i;
    
    pthread_create(&threads[0], NULL, producer, (void *)&threads[0]);
    pthread_create(&threads[1], NULL, consumer, (void *)&threads[1]);

    for (i = 0; i < 2; i++) {
        pthread_join(threads[i],NULL);
        printf("\t\t\tThread %d returned \n", i);
    }
    printf("Main thread done.\n");
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&empty);
    pthread_cond_destroy(&full);
    return 0; 
} 