#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc,char *argv[])
{

   // pid_t  pd;
    //char buff[100]={"lseek","linux"};
    printf("enter in exec2\n");
    printf("pid of exe2=%d \n",getpid());
    for(int i=0;i<argc;i++)
    printf("argument=%s \n",argv[i]);
   

    return 0;

}