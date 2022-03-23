#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t tid;

int k=5;
void *one(void *arg)
{
    int i;
    for(i=0;i<2;i++)
        printf("thd of con \n");
k--;
printf("T1 k=%d\n",k);

}
void *two(void *arg)
{
    int i;
    for(i=0;i<3;i++)
        printf("thd of con2***** \n");
k--;
printf("T2 k=%d\n",k);

}
void *third(void *arg)
{
    int i;
    for(i=0;i<3;i++)
        printf("thd of con3***** \n");
k--;
printf("T3 k=%d\n",k);

}


void *thr_fn(void *arg)
{
    pid_t pid;
    pthread_t tid;
    pid=getpid();
    tid=pthread_self();
    printf("pid %u tid %u \n",(unsigned int)pid,(unsigned int)tid);
    

}


void main()
{


   pthread_t pt1,pt2,pt3,tid;
   //getchar();
   pthread_create(&pt1,NULL,one,NULL);
   pthread_create(&pt2,NULL,two,NULL);
   pthread_create(&pt3,NULL,third,NULL);
  // getchar();
   pthread_join(pt1,NULL);
   pthread_join(pt2,NULL);
   pthread_join(pt3,NULL);

    printf("end \n");
///////////////////////////////////pid and thread///////////////////////////////
   int err;
   err=pthread_create(&tid,NULL,thr_fn,NULL);
    while(1);
    exit(0);
}
