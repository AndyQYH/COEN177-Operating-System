/*
#Name : Yihui(Andy) Qin
#Date : 01 / 18 / 2022
#Title : Lab3 – step 4
#Description : This programs creates a simple pipeline between parent and child processes
               to receive and send system calls of mimicing cat /etc/passwd | grep root
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
//main
int main()
{
    int fds[2];
    pipe(fds);
    /*child 1 duplicates downstream into stdin */
    if (fork() == 0)
    {
        dup2(fds[0], 0);
        close(fds[1]);
        execlp("grep","grep","root",0);
    }
    /*child 2 duplicates upstream into stdout */
    else if (fork() == 0)
    {
        dup2(fds[1], 1);
        close(fds[0]);
        execlp("/bin/cat","/bin/cat", "/etc/passwd",0);
    }
    else
    { /*parent closes both ends and wait for children*/
        close(fds[0]);
        close(fds[1]);
        wait(0);
        wait(0);
    }
}
