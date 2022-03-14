#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void main()
{	char buff[100];
	int f1,size;
	f1=open("file_4kb.txt",O_CREAT|O_RDWR,777);
	size=write(f1,buff,4096);
	printf("size=%d",size);
	close(f1);


}
