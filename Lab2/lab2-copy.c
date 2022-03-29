//#Name : Yihui Qin
//#Date : 1 / 11 / 2022
//#Title : Lab2 – step1-4
//#Description : This program creates a copy from lab2.c

/*Sample C program for Lab assignment 1*/
#include <stdio.h>     /* printf, stderr */
#include <sys/types.h> /* pid_t */
#include <unistd.h>    /* fork */
#include <stdlib.h>    /* atoi */
#include <errno.h>     /* errno */
/* main function with command-line arguments to pass */
void *printParent(void *arg)
{
    // Parent process
    for (i = 0; i < 100; i++)
    {
        printf("\t \t \t Parent Process %d\n", i);
        //usleep(n);
    }
}
void *printChild(void *arg)
{
    // Child process
    for (i = 0; i < 100; i++)
    {
        printf("Child process %d\n", i);
        //usleep(n);
    }
}
int main(int argc, char *argv[])
{
    pid_t pid;
    int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    
    pthread_t t1, t2;
    int i = 0;
    pthread_create(&t1,NULL,printParent, (void*)i);
    pthread_create(&t2, NULL, printParent, (void *)i);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    pthread_exit();
    return 0;
}
