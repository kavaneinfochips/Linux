#include<stdio.h>
#include<sting.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<unistd.h>

void main(){
	  key_t key;
    int qid;
    struct  msqid_ds buf;
    key = ftok("progfile", 65);
	qid = msgget(key,IPC_CREAT|0644);
	msgctl(qid,IPC_STAT,&buf);
	printf("msgs %hi\n",buf.msg_qnum);
  
	printf("maximum bytes in q %hi\n",buf.msg_qbytes);
	msgctl(qid,IPC_RMID,&buf);
	
  
}
