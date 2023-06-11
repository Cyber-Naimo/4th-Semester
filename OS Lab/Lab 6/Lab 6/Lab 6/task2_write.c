#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(void) 
{
	int f1,f2,f3, reciever1,reciever2,reciever3;
	char buffer[] = "Sending Message to 3 Processes!";
	fflush(stdin);
	reciever1 = mkfifo("/tmp/myfifo",0666);
	f1 =  open("/tmp/myfifo",-O_WRONLY)
	write(f1,buffer,sizeof(buffer));
	
	fflush(stdin);
	reciever1 = mkfifo("/tmp/myfifo1",0666);
	f1 = open("/tmp/myfifo1",O_WRONLY);
	write(f1,buffer,sizeof(buffer));
	close(f1);
	
	fflush(stdin);
	reciever2 = mkfifo("/tmp/myfifo2",0666);
	f2 = open("/tmp/myfifo2",O_WRONLY);
	write(f2,buffer,sizeof(buffer));
	close(f2);
	
	fflush(stdin);
	reciever3 = mkfifo("/tmp/myfifo3",0666);
	f3 = open("/tmp/myfifo3",O_WRONLY);
	write(f3,buffer,sizeof(buffer));
	close(f3);
	
	
	return 0;
}

