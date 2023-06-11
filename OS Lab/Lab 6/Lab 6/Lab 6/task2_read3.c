#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(void) 
{
	int file_open,reciever;
 	char buffer[512] = "";
 	file_open = open("/tmp/myfifo3",O_RDONLY);
 	reciever = read(file_open,buffer,sizeof(buffer));
 	fflush(stdin);
 	write(1,buffer,sizeof(buffer));
	printf("\n");
 	close(file_open);
	return 0;
}

