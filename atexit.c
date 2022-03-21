#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void fun1()
{printf("fun1 \n");}
void fun2()
{printf("fun2 \n");}
void fun3()
{printf("fun3 \n");}

void main()
{
        printf("Printing in reverse order \n");
        printf("noraml loop \n");
        atexit(fun1);
        printf("donm1 \n");
        atexit(fun2);
        printf("donm2 \n");
        atexit(fun3);
        printf("donm3 \n");

        exit(0);

}