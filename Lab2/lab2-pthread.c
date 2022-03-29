//#Name : Yihui Qin
//#Date : 1 / 11 / 2022
//#Title : Lab2 – step 6
//#Description : This program creates two threads
//#that runs in the same process

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void *PrintHello(void *threadid) {
   long tid;
   tid = (long)threadid;
   printf("Hello World! Thread ID, %ld\n", tid);
   pthread_exit(NULL);
}
int main (int argc, char *argv[]) {
   if(argc != 2)
   {
       printf("wrong format: needs to be ./exe param1"\n);
   }
   NUM_THREADS = atoi(argv[1]);
   pthread_t threads[NUM_THREADS];
   int rc;
   int i, n = atoi(argv[1]);
   for( i = 0; i < NUM_THREADS; i++ ) {
      printf("main() : creating thread,%d\n ",i);
      rc = pthread_create(&threads[i], NULL, PrintHello, (void *)threads[i]);
      if (rc) {
         printf("Error:unable to create thread, %d\n", rc);
         exit(-1);
      }
      usleep(n);
   }
   for(i = 0; i < NUM_THREADS; i++){
	 pthread_join(threads[i],NULL);
   }
   pthread_exit(NULL);
}
