#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc,int *argv[])
{

    pid_t  pd;
    char *buff[]={"lseek","linux",NULL};
    printf("pid of exe1.c=%d \n",getpid());
    execv("./exe2",buff);
    printf("exec1\n");

return 0;
}