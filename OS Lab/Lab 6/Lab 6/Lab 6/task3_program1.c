#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main ()
{
 	
 	// First creating the shared memory space
 	int shmid = shmget((key_t)1122,1024,0666|IPC_CREAT);
 	
	 //then attaching the shared memory with procees A
 	char* shared_memory = shmat(shmid,NULL,0);
 	
 	// now writing that data to shared memory
 	strcpy(shared_memory,"21");
 	
 	// now wait for the Second Program to write ready 
 	while(strcmp(shared_memory,"ready")!=0)
 	{
 		sleep(10000);
	}
	
	// Now print ready on the screen
	printf("\n %s \n",shared_memory);
	
	// now put a * in the shared memory according to given question
	strcpy(shared_memory,"*");
	return 0;
}

