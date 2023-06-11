#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(void)
{
	int shmid;
	long long int *shared_memory;

	
	shmid = shmget((key_t)1133, 1024, IPC_CREAT | 0666);
	shared_memory = shmat(shmid, NULL, 0);
	*shared_memory = 1;

        while(*shared_memory!='*')
        sleep(1);
        
        exit(0);
}
