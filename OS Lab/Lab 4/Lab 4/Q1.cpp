#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main ()
{
	// Calling the system call and storing returned value
 	int i_pid = fork();
 	
 	// a
 	if (i_pid < 0)
 	{
 		printf("Unsuccesfull Child Process Creation!\n");
 		exit(1);
	}   // b
	else if (i_pid > 0)
	{
		wait(0);
		for(int i=1;i<=10;i++)
		{
			if(i%2==0)
			{
				printf("%d, ",i);
			}
		}
		printf("\nParents Process End! \n");
	}
	else if (i_pid == 0) 
	{
		
		printf("Parents PID: %d ",getppid());
		for (int i=1;i<=10;i+=2)
		{
			printf("%d, ",i);
		}
		printf("\nChilds End! \n")
	}
	return 0;
}
