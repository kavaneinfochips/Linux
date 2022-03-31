#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct my_thread
{
    int thread_id;
    char msg[100];
};

void *print(void *a)
{
    pthread_t p;
    struct my_thread *t1;
    t1=(struct my_thread *) a;
    p=pthread_self();
    printf("%d thread ID and mess=%s",t1->thread_id,t1->msg);


}


int main()
{

    pthread_t p1,p2,p3,p4 ,tid;
    int rc;

    struct my_thread t2,t3,t4;
    t4.thread_id=4;
    strcpy(t4.msg,"4th thread \n");
    tid=pthread_self();
    
    
    printf("ITS main \n");
   

    t2.thread_id=2; 
    strcpy(t2.msg,"thread2 here\n"); 
    t3.thread_id=3; 
    strcpy(t3.msg," thread3 here\n"); 
    
  
    pthread_create(&p2,NULL,print,(void *)&t2); 
    pthread_create(&p3,NULL,print,(void *)&t3);
    pthread_create(&p4,NULL,print,&t4);
      sleep(2);
    

}