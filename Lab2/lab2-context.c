//#Name : Yihui Qin
//#Date : 1 / 11 / 2022
//#Title : Lab2 – step 7
//#Description : This program forks the current process and assign
//#different tasks for parent and child process; this time the parent waits for the child
//#to finish before it terminates

/*Sample C program for Lab assignment 1*/
#include <stdio.h>     /* printf, stderr */
#include <sys/types.h> /* pid_t */
#include <unistd.h>    /* fork */
#include <stdlib.h>    /* atoi */
#include <errno.h>     /* errno */
/* main function with command-line arguments to pass */
int main(int argc, char *argv[])
{
    pid_t pid;
    printf("\n Before forking.\n");
    pid = fork();
    if (pid == -1)
    {
        fprintf(stderr, "can't fork, error %d\n", errno);
    }
    if (pid)
    {
        // Parent process
        wait(NULL);
        printf("Child Complete\n");
        exit(0);
    }
    else
    {
        // Child process
        execlp("/bin/ls","ls", NULL);
    }
    return 0;
}
