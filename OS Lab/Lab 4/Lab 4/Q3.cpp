#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>

int main ()
{
 	int pid1,pid2,pid3;
 	
 	// creating first child call 
 	pid1 = fork();
 	if(pid1 == 0)
 	{
 		sleep(3);
 		printf("Parents PID: %d   ----->   1.Childs  PID: %d  ",getppid(),getpid());
	}
	else
	{
		// creating second child call 
		pid2 = fork();
	 	if(pid2 == 0)
	 	{
	 		sleep(2);
	 		printf("Parents PID: %d   ----->   2.Childs PID: %d  ",getppid(),getpid());
		}
		else
		{
			pid3 = fork();
		 	if(pid3 == 0)
		 	{
		 		sleep(1);
		 		printf("Parents PID: %d   ----->   3.Childs PID: %d  ",getppid(),getpid());
			}
			else
			{
				sleep(3);
				printf("Parents PID: %d",getppid());
			}
		}
		
	}
	return 0;
}
