/*
#Name : Yihui(Andy) Qin
#Date : 01 / 18 / 2022
#Title : Lab3 – step 2-3
#Description : This programs creates a simple pipeline between parent and child processes
               to receive and send system buffers through read and write (Inter-Process-Communication)
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/wait.h> 

// main
int main(int argc,char *argv[]){
   int  fds[2];
   char buff[60];
   int count;
   int i;
   pipe(fds);
   
   if (fork()==0){
       printf("\nWriter on the upstream end of the pipe -> %d arguments \n",argc);
        close(fds[0]);
      // for(i=0;i<argc;i++){
          // write(fds[1],argv[i],strlen(argv[i]));
      // }
       dup2(fds[1], 1);
      // close(fds[0]);
       execlp("ls", "ls", 0);
       exit(0);
   }
   else if(fork()==0){
       printf("\nReader on the downstream end of the pipe \n");
       close(fds[1]);
       while((count=read(fds[0],buff,60))>0){
           for(i=0;i<count;i++){
               write(1,buff+i,1);
               write(1," ",1);
           }
           printf("\n");
       }
       exit(0);
    }
   else{     
      close(fds[0]);
      close(fds[1]);
      wait(0);
      wait(0);
   }
return 0;
}
