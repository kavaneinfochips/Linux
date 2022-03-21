#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t p1,p2;
    int a,b,c;
    printf("The parent pid=%d \n",getpid());

    p1=fork();
    p2=fork();

    if(!p1)
    {
        printf("pid of p1=%d \n",getpid());
        printf("This is child 1 \n");
        a=1;
        b=6;
        c=a+b;
        printf("c=%d \n",c);

    }
    // else
    // {
    //     printf("the parent process \n");
    //     sleep(3);
    // }

   if(!p2)
    {   printf("pid of p2=%d \n",getpid());
        printf("This is child 2 \n");
        printf("child 1 c=%d\n",c);
        c=b-a;
        printf("new c=%d \n",c);
    }
    else
    {
        printf("the parent process2 \n");
        sleep(3);
    }




}