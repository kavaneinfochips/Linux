#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
                 //add library 
pthread_t tid2 ,tid; 
int count=0;
void *thread1(void *arg)
{
    printf("new thread \n");
	//sleep (1);
	while(1)
	{
		count++;
		printf("count=%d \n",count);
		if(count==4)
		{pthread_cancel(tid);
		pthread_exit(NULL);
		}

	}
    return NULL;
}

void *thread2(void *arg)
{
    printf("thread2\n");

}

void main()
{       
        pthread_t tid,tid2; 
        pthread_create(&tid,NULL,thread1,NULL); 
        pthread_create(&tid2,NULL,thread2,NULL);

        printf("created thread \n");    
        //sleep(2);
        pthread_join(tid,NULL);
        pthread_join(tid2,NULL);

 //pthread_join makes the particular thread with the main process exectution and
 // making the main process to wait till termination


}
