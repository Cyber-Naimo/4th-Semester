#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
	
   printf("I am Process 10 and my PID is %d and My Parents PID: %d \n",getpid(),getppid());
   int i = fork();
   if(i==0)
   {
   		 printf("I am Process 6 and my PID is %d and My Parents PID: %d \n",getpid(),getppid());
   }
   else
   {
   	  i=fork();
   	  if(i==0)
   	  {
   	  	    printf("I am Process 4 and my PID is %d and My Parents PID: %d \n",getpid(),getppid());
	  }
	  else
	  {
		  	i=fork();
		  	if(i==0)
		  	{
		  		 printf("I am Process 8 and my PID is %d and My Parents PID: %d \n",getpid(),getppid());
			}
			else
			{
				i=fork();
				if(i==0)
				{
				 	 printf("I am Process 18 and my PID is %d and My Parents PID: %d \n",getpid(),getppid());
				}
				else
				{
					i=fork();
					if(i==0)
					{
					 	 printf("I am Process 15 and my PID is %d and My Parents PID: %d \n",getpid(),getppid());
					}
					else
					{
						i=fork();
						if(i==0)
						{
						 	 printf("I am Process 21 and my PID is %d and My Parents PID: %d \n",getpid(),getppid());
						}
					}
				}
			}		
	   }
   }
}

