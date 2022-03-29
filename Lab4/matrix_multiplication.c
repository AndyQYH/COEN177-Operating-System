/*
#Name : Yihui Qin
#Date : 01 / 25 / 2022
#Title : Lab4 – Step2 - matrix multipication
#Description : This program computes matrix multiplication in parallel with N number of threads,
                where N = row size
*/
// C Program to multiply two matrix using pthreads with
// use of global variables
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#define M 1024
#define N 1024
#define L 1024

double matrixA[N][M];
double matrixB[N][M];
double matrixC[N][L];
int ids[N];
//Each thread computes single element in the resultant matrix
void *mult(void *arg)
{
    int i = *(int *)arg,j,k;
    printf("thread %d \n",i);
    for (j = 0; j < L; j++){
      double temp = 0;
      for (k = 0; k < M; k++){
          temp += matrixA[i][k] * matrixB[k][j];
      }
      matrixC[i][j] = temp;
    }

    //Used to terminate a thread and the return value is passed as a pointer
    pthread_exit(NULL);
}

//Driver code
int main()
{
    int i, j, k;

    // Generating random values in matA
    srand(time(NULL));
    for(i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            matrixA[i][j] = rand() % 10;

    // Generating random values in matB
    srand(time(NULL));
    for(i = 0; i < M; i++)
        for (j = 0; j < L; j++)
            matrixB[i][j] = rand() % 10;

    // Displaying matA
    printf("matrix A: \n");
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
            printf("%0.1f ", matrixA[i][j]);
        printf("\n");
    }

    // Displaying matB
    printf("matrix B: \n");
    for(i = 0; i < M; i++)
    {
        for(j = 0; j < L; j++)
            printf("%0.1f ", matrixB[i][j]);
        printf("\n");
    }


    //declaring array of threads of size r1*c2
    pthread_t threads[N];

    int count = 0;
   
    for(i = 0; i < N; i++)
    {
        //creating threads
        ids[i] = i;
        pthread_create(&threads[count++], NULL, mult, &ids[i]);
        printf("creating thread %d \n",i);
    }

    for(i = 0; i < N; i++)
    {
        //Joining all threads and collecting return value
        pthread_join(threads[i], NULL);
        printf("Thread %d returned \n", i);  
    }
    printf("RESULTANT MATRIX IS :- \n");

    for(j = 0; j < M; j++)
    {
        for(k = 0; k < L; k++)
        {
             printf("%0.1f ",matrixC[j][k]); 

        }
        printf("\n");
    }
    pthread_exit(0);
    return 0;
}
