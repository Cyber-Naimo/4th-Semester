#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
	
   printf("I am Process root and my PID is %d and My Parents PID: %d \n",getpid(),getppid());
   int i = fork();
   if(i==0)
   {
   		 printf("I am Process inner node and my PID is %d and My Parents PID: %d \n",getpid(),getppid());
   }
   else
   {
   	  i=fork();
   	  if(i==0)
   	  {
   	  	    printf("I am Process leaf and my PID is %d and My Parents PID: %d \n",getpid(),getppid());
	  }
	  else
	  {
		  	i=fork();
		  	if(i==0)
		  	{
		  		 printf("I am Process leaf and my PID is %d and My Parents PID: %d \n",getpid(),getppid());
			}
			else
			{
				i=fork();
				if(i==0)
				{
				 	 printf("I am Process leaf and my PID is %d and My Parents PID: %d \n",getpid(),getppid());
				}
			}
	  }
   	  
   }
}

