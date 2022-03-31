#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_once_t  once=PTHREAD_ONCE_INIT;

void *init()
{

    printf("\n init..............\n");
}

void *mythread(void *i)
{

printf("\n I am thread :%d \n",(int *)i);
pthread_once(&once,(void *)init);

printf("\n Exit the threading :%d \n,",(int *)i);

}

int main()
{
    pthread_t p1,p2,p3;

    pthread_create(&p1,NULL,mythread,1);
    sleep(2);
    pthread_create(&p1,NULL,mythread,2);
    sleep(2);
    pthread_create(&p1,NULL,mythread,3);

    printf("Exit from main \n");

    pthread_exit(NULL);




}