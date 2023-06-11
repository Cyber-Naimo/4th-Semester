#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
	
   printf("I am Process 1 and my PID is %d and My Parents PID: %d \n",getpid(),getppid());
   int i = fork();
   if(i==0)
   {
   		 printf("I am Process 5 and my PID is %d and My Parents PID: %d \n",getpid(),getppid());
   }
   else
   {
   	  i=fork();
   	  if(i==0)
   	  {
   	  	    printf("I am Process 3 and my PID is %d and My Parents PID: %d \n",getpid(),getppid());
	  }
	  else
	  {
		  	i=fork();
		  	if(i==0)
		  	{
		  		 printf("I am Process 4 and my PID is %d and My Parents PID: %d \n",getpid(),getppid());
			}
	  }
   	  
   }
}

