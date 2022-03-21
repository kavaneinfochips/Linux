#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>


void child_exec()
{
    printf("Child in process \n");
    printf("moving to new program \n");
    pid_t  pd;
     char *buff[]={"lseek","linux",NULL};
    printf("pid of exe1.c=%d \n",getpid());
    execv("./exe2",buff);
    printf("exec1\n");

}

void fileOp()
{   int fd;
    char rd[200];

    fd=open("fd1.txt",O_RDONLY);
    read(fd,rd,200);
    printf("%s \n",rd);
}

void main()
{
    printf("the parent pid =%d \n",getpid());
    pid_t p1;
    
    p1=fork();
    printf("fork return :%d \n",p1);

    if(!p1)
    {
        printf("the child pid =%d \n",getpid());
        child_exec();

    }
    printf("parent process \n");
    wait(NULL);
    printf("process end \n");

}