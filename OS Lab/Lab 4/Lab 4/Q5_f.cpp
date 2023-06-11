#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
	
   printf("I am Process A and my PID is %d and My Parents PID: %d \n",getpid(),getppid());
   int i = fork();
   if(i==0)
   {
   		 printf("I am Process B and my PID is %d and My Parents PID: %d \n",getpid(),getppid());
   }
   else
   {
   	  i=fork();
   	  if(i==0)
   	  {
   	  	    printf("I am Process D and my PID is %d and My Parents PID: %d \n",getpid(),getppid());
	  }
	  else
	  {
		  	i=fork();
		  	if(i==0)
		  	{
		  		 printf("I am Process C and my PID is %d and My Parents PID: %d \n",getpid(),getppid());
			}
			else
			{
				i=fork();
				if(i==0)
				{
				 	 printf("I am Process E and my PID is %d and My Parents PID: %d \n",getpid(),getppid());
				}
				else
				{
					i=fork();
					if(i==0)
					{
					 	 printf("I am Process F and my PID is %d and My Parents PID: %d \n",getpid(),getppid());
					}
				}
			}		
	   }
   }
}

