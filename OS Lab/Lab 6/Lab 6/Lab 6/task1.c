#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	int arr[2],f;
	char buffer[100];
	pid_t pid;
	// system calll for pipe
	pipe(arr);
	pid = fork();   // creating child process

	if(pid==0)
	{
		fflush(stdin);
		printf("Sending Message to the Parent:\n");
		write(arr[1],"Hello Parent Process!\n",23);
	}
	else if(pid > 0)
	{
		sleep(5);
		fflush(stdin);
		printf("Recieving  Message from the Child Process:\n");
		f = read(arr[0],buffer,100);
		write(1,buffer,f);
	}
	else
	{
		printf("Cannot Create Child Process! Error ");
	}
}

