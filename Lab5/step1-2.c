/*
# Name: Yihui Qin
# Date: 02/01/2022 
# Title: Lab1 – task 1 - threadsync 2.0
# Description: This program recreate threadsync.c with mutexes instead of semaphores.
*/

// Thread Sychronization
//To compile this code:
//If using the SCU Linux lab first add #include<fcntl.h>
//Then you're ready to compile.
//To compile just add -lpthread to your gcc command like:
//gcc threadSync.c -lpthread
//gcc threadSync.c -o test -lpthread
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 
#include <semaphore.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  
#define NTHREADS 10
pthread_t threads[NTHREADS];
pthread_mutex_t mutex; 
void* go(void* arg) { 
  pthread_mutex_lock(&mutex); //entry section
  printf("Thread %d Entered Critical Section..\n", (int)arg); //critical section 
   sleep(1); 
  pthread_mutex_unlock(&mutex); //exit section 
  return (NULL);
} 
int main() { 
pthread_mutex_init(&mutex, NULL);
static int i;
for (i = 0; i < NTHREADS; i++)  
   pthread_create(&threads[i], NULL, go, (void *)(size_t)i);
for (i = 0; i < NTHREADS; i++) {
   pthread_join(threads[i],NULL);
   printf("\t\t\tThread %d returned \n", i);
   }
printf("Main thread done.\n");
pthread_mutex_destroy(&mutex);
return 0; 
} 