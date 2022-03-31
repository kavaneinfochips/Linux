#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

static pthread_spinlock_t spinlock;
volatile int slock;
void *spinlockthread(void *i)
{
    int rc;
    int count =0;
    printf("enter thread %d, getting Spin lock \n",(int *)i);
    rc=pthread_spin_lock(&slock);
    printf("%d Thread ulock the spin lock \n",(int *)i);
    
    rc=rc=pthread_spin_unlock(&slock);
    printf("%d threaed compl \n",(int *)i);
     return 0;
}

 int main()
 {


    int rc=0;
    pthread_t p1,p2;

    if(pthread_spin_init(&slock,PTHREAD_PROCESS_PRIVATE)!=0)
        perror("init");
   
    printf("MAin ,get spin lockk \n");
    rc=pthread_spin_lock(&slock);
   
    rc=pthread_create(&p1,NULL,spinlockthread,(int *)1);
    printf("wait for holding thread \n");

    sleep(5);
    
    printf("Main ,now unlock the spin \n");
   
    rc=pthread_spin_unlock(&slock);
    
    if(!rc)
        printf("\n Main  Thread successsssss unlockeddd \n");
    else 
        printf("\n Main  Thread successsssss loccccckeddd \n");  

    printf("main ,wait for the thread to end \n");

    rc=pthread_join(p1,NULL) ;

    rc=pthread_spin_destroy(&slock);    

 }
 
