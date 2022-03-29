//#Name : Yihui Qin
//#Date : 1 / 11 / 2022
//#Title : Lab2 – step 5
//#Description : This program computes forks the current process and assign
//#different tasks for parent and child process

/*Sample C program for Lab assignment 1*/
#include <stdio.h>     /* printf, stderr */
#include <sys/types.h> /* pid_t */
#include <unistd.h>    /* fork */
#include <stdlib.h>    /* atoi */
#include <errno.h>     /* errno */
#include <sys/wait.h>
/* main function with command-line arguments to pass */
int main(int argc, char *argv[])
{
    if(argc < 2)
    {
       printf("wrong input fromat: need 1 argument for number of processes");
       return -1;
    }
    pid_t pid1, pid2, pid3, pid4, pid5, pid6, pid7;
    int i;    
    int numProcess = atoi(argv[1]);
    printf("\n Before forking.\n");
   // while(i < numProcess)
   // {
   	pid1 = fork();
   	if (pid1 == -1)
    	{
        	fprintf(stderr, "can't fork, error %d\n", errno);
    	}	
    	if (pid1)
    	{
        	// Parent process
        	pid2 = fork();
        
             	if(pid2 == 0)
                {    
                      printf("Child with id: %d and its Parent id: %d \n", getpid(),getppid()); 
                      pid4 = fork();
                      if(pid4 == 0)
                      {
                          printf("Child with id: %d and its Parent id: %d \n", getpid(),getppid());
                      }
                      else
                      {
                          pid6 = fork();
                          if(pid6 == 0)
                          { 
                              printf("Child with id: %d and its Parent id: %d \n", getpid(),getppid()); 
                          }
                      }   
        	}else{
                        
             	       ;	//printf("Child with id: %d and its Parent id: %d \n", getpid(),getppid()); 
        	}
        }
   	else
    	{
        	// Child process
                printf("Child with id: %d and its Parent id: %d \n", getpid(),getppid());
                pid3 = fork();
                if(pid3 == 0)
                {
                   printf("Child with id: %d and its Parent id: %d \n", getpid(),getppid());      
                }
                else{
                   printf("This is a parent process");
                   pid5 = fork();
                   
                   if(pid5 == 0)
                   {
                       printf("Child with id: %d and its Parent id: %d \n", getpid(),getppid());
                   }
                }  
    	}
   // 
   for(i=0; i<numProcess; i++)
   { 
 	 wait(NULL);  
   }

    	return 0;
}
