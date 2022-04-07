#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int fds[2];

void write_to_parent()
{
	char *write_buf = "LINUXIPC";
	int length = strlen(write_buf);
	close(fds[0]);
	write(fds[1],write_buf,length);
	printf("written to parent");

}

void read_from_child(){
	char read_buf[100];
	int n,i;
	close(fds[1]);
	n = read(fds[0],read_buf,100);
	printf("total characters are = %d\n",n);
	for(i=0;i<n;i++){
		if(read_buf[i]<97 && read_buf[i]!=32)
		{
			printf("%c",read_buf[i]+32);	
		}
		else if(read_buf[i]==32){
			printf("");
		}
		else{
			printf("%c",read_buf[i]-32);	
		}

	}
	printf("\nreading completed");

}

int main(){
	int res;
	pid_t id;
	int p;
	res = pipe(fds);
	printf("%d\n",res);
	if(res==-1){
		perror("pipes");
		exit(1);
	}
	id=fork();
	if(id==0){

		read_from_child();
	}
	else{
		write_to_parent();
	}
	return 0;
}
