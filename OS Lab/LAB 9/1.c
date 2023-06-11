#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
sem_t weighting;
sem_t seceurity ;
sem_t boarding ;
sem_init(weighting,0,1);
sem_init(seceurity,0,1);
sem_init(boarding,0,1);
void *airport(void *argc)
{
	// first customer came to the weight the luagage and wait for 4 seconds after that move the customer to the seceurity check
	sem_wait(weighting);
	sleep(4);
	sem_post(weighting);
	
	// secondly customer came to the seceurity check to weight the luagage and wait for 7 seconds and move the customer to the boarding pass
	sem_wait(seceurity);
	sleep(7);
	sem_post(seceurity);
	
	// thirdly customer came to the boarding pass and wait for 7 seconds
	sem_wait(boarding);
	sleep(3);
	sem_post(boarding);
	
	pthread_exit(NULL);
}
int main ()
{
	// threads for the customers we have here 10 max
 	pthread_t arr[10];
 	for(int i=0;i<10;i++)
 	{
 		pthread_create(&arr[i],NULL,airport,NULL);
	}
	
	
 	for(int i=0;i<10;i++)
 	{
 		pthread_join(&arr[i],NULL);
	}
	return 0;
}
