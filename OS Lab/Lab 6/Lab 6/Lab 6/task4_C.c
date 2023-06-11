#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main(void) 
{
	
	int shmid_A,shmid_B;
	key_t key_A,key_B;
	long long int *shared_memory_A,*shared_memory_B;

	key_A = 1122;
	
	shmid_A = shmget(key_A, 1024, 0666 | IPC_CREAT);
		
	shared_memory_A = shmat(shmid_A, NULL, 0);
	key_B = 1133;
	
	shmid_B = shmget(key_B, 1024, 0666| IPC_CREAT);
	shared_memory_B = shmat(shmid_B, NULL, 0);
  
	long long int a,b,sum,n= 10;
    printf("%d ) Fabonacci Series  %lld .\n%d ) Fabonacci Series is %lld .\n",1,*shared_memory_A,2,*shared_memory_B);

    for(int i=0;i<n;i++)
	 {

            a=*shared_memory_A;
            b=*shared_memory_B;
            sum=a+b;
            *shared_memory_A=*shared_memory_B;
            *shared_memory_B=sum;
            printf("%d)  Fabonacci Series: %lld .\n",i+3,sum);    

	 }

         *shared_memory_A='*';
         *shared_memory_B='*';
         printf("\n");
         exit(0);
}
