/*
#Name : Yihui(Andy) Qin
#Date : 01 / 18 / 2022
#Title : Lab3 – step 5
#Description : This programs creates a simple pipeline between parent and child processes
               to solve the consmer-producer problems
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
   
   if(fork()==0){
       printf("\nproducer enter something to the pipe:\n");
       close(fds[0]);
       while((count = read(0, buff,60)) > 0)
       {
           write(fds[1], buff, 60);
           memset(buff,0,60);
       }
       exit(0);
   }
   else if(fork()==0){
       
       close(fds[1]);
       while((count=read(fds[0],buff,60))>0)
       {  
            
             printf("\nconsumer receives: \n");
             printf("%s",buff); 
       
             //write(1," ",1);
             memset(buff,0,60);      
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
