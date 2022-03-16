#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>



void new_task()
{

	int fd1,fd2,len;
	char wrt_buff[100]="welcome to linux_2";
	char read_buff[100];
	fd1=open("linux1.txt",O_CREAT|O_RDWR,777);
	len=write(fd1,wrt_buff,18);			//write returns the len of data 						   in bytes and 50 return curr file off moved 50th position
	printf("the len of data =%d \n", len);		//50
							//before read operation lseek is used to set the position
	lseek(fd1,0,SEEK_SET);				//rewind current file offset to 0 location
	read(fd1,read_buff,18);
	printf("read file =%s \n",read_buff);
	close(fd1);




}



void main()
{

	int f1,f2,len;
	char buff[100]="welcome to linux";
	int x;	
	
	f1=open("fd2.txt",O_CREAT|O_RDWR,777);
	if(f1)
	printf("fileopen");
	else	
	printf("error");
	//write(f1,buff,60);

	read(f1,buff,300);
        printf("data buff =%s \n",buff);
	
	close(f1);

	new_task();


	
	//close();

}



