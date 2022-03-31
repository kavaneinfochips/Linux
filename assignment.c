#include<pthread.h> 
#include<stdio.h> 
#include <unistd.h> 

void *my(void *i) 

{ 

printf("\n i am in %d Thread \n",(int *)i); 

} 

main() 

{ 

pthread_t tid; 

struct sched_param param; 

int priority,policy,ret; 
ret = pthread_getschedparam(pthread_self(),&policy,&param);  


if(ret !=0) 
perror("getschedparam\n"); 

printf("\n   Main Thread \n Policy : %d \t Priority : %d\n",policy,param.sched_priority); 
policy=SCHED_FIFO;  
param.sched_priority = 3; 
ret = pthread_setschedparam(pthread_self(),policy,&param); 

if(ret!=0) 
perror("getschedparam\n"); 
ret = pthread_getschedparam(pthread_self(),&policy,&param); 
if(ret!=0) 
perror("getschedparam\n"); 

 

printf("\nMain Thread-----------------\n Policy : %d \t Priority : %d\n",policy,param.sched_priority); 

return 0;
 

} 