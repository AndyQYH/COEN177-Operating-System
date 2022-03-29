/*
#Name : Yihui Qin
#Date : 01 / 25 / 2022
#Title : Lab4 – Step1 - thread hello
#Description : This program computes multi-thread applications with each thread print a statement upon creation
*/

/**************************************************************
*	threadHello.c - simple multi-threaded program.            *
*   compile with: >gcc -lp threadHello.c -o threadHello       *                                              *
**************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NTHREADS 20

void *go(void *);
pthread_t threads[NTHREADS];

int main() {
    static int i;
    for (i = 0; i < NTHREADS; i++)  
        pthread_create(&threads[i], NULL, go, &i);
   // for (i = 0; i < NTHREADS; i++) {
       // pthread_join(threads[i],NULL);
	   // printf("Thread %d returned \n", i);
   // }
    printf("Main thread done.\n");
}
void *go(void *arg) {
    printf("Hello from thread %d with thread ID %d \n", *(int *)arg, (int)pthread_self());
    return (NULL);
}

