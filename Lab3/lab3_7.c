/*
#Name : Yihui(Andy) Qin
#Date : 01 / 18 / 2022
#Title : Lab3 – step 7
#Description : This programs creates a multi-threaded application where each thread prints its
               creation order in ascending order and non-overlapping printings.
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *go(void *);
#define NTHREADS 10
int n = 0;
pthread_t threads[NTHREADS];
int ids[NTHREADS];

int main() {
    int i;
    
    for (i = 0; i < NTHREADS; i++){
        ids[i] = i; 
        pthread_create(&threads[i], NULL, go, &ids[i]);
        //sleep(1);
    }
    for (i = 0; i < NTHREADS; i++) {
	printf("Thread %d returned\n", i);
        pthread_join(threads[i],NULL);
    }
    printf("Main thread done.\n");
    
    return 0;
}
void *go(void *arg) {
 
 int i = *(int *)arg;

 printf("Hello from thread %d with iteration %d\n",  (int)pthread_self(), i);

 return 0;
}


