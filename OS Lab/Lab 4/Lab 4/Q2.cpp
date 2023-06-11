#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
int main ()
{
 	int n;
 	printf("Enter the No of Child Processes you want to create ? \n");
 	scanf("%d",&n);
 	
 	// now creating n times child processess
 	
 	for(int i=0;i<n;i++)
 	{
 		int j = fork();
 		if(j == 0)
 		{
 				print("Enter a No: ");
 				scanf("%d",&no);
 				print("A No: ",no);
 				printf("\nParents PID: %d   --->   Childs PID: %d \n ",getppid(),getpid());
 				exit(NULL);
		}
		else if(j>0)
		{
			wait(NULL);
		}
		else
		{
			printf("\nUnsuccesfull Child Process Creation!\n");
 			exit(1);
		}
	}
	
	return 0;
}
