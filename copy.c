#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void main()
{

int f1,f2,len,total;

char buff_copy[1000];
char new[1000];

f1=open("creat.c",O_RDONLY,777);
read(f1,buff_copy,1000);
total=lseek(f1,0,SEEK_END);
close(f1);
printf("total=%d \n",total);

f2=open("new_linux.txt",O_CREAT|O_RDWR,777);
write(f2,buff_copy,total);
lseek(f1,0,SEEK_SET);
read(f2,new,total);
printf("the data=%s\n",new);

close(f2);


}
