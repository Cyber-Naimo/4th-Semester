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
	int shmid = shmget((key_t)1122,1024,0666|IPC_CREAT);
 	char* shared_memory = shmat(shmid,NULL,0);
 	
 	// now read the number from shared memory
 	int num = atoi(shared_memory);
 	
 	// now write ready in the shared memory
 	strcpy(shared_memory,"ready");
 	
 	// Now here wait for the first program to write * 
 	int i = 1;
 	
 	while(i!=10)
 	{
 		while(strcmp(shared_memory,"*")!=0)
		 {
		 	sleep(2);
		 }	
		 
		 char table[1024];
		 sprintf(table,"%d",i*num);
		 strcpy(shared_memory,table);
		 printf("\n %s \n",shared_memory);
		 
		 // now put a * in the shared memory
		 strcpy(shared_memory,"*");
		 i++;
	}
	return 0;
}

