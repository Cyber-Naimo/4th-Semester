#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>


void *Registration(void *val)
{
	int participant = *(int*)val;
	printf("Participants(%d) Your ID  00%d.\n",participant,participant);
	printf("Volunteer 1 manages On day registration of participant %d.\n",participant);
	pthread_exit(NULL);
}

void *Announcement(void *val)
{
	int participant = *(int*)val;
	printf("Volunteer 2 handles announcements of participant %d.\n",participant);
	pthread_exit(NULL);
}

void *Sponsoring(void *val)
{
	int participant = *(int*)val;
	printf("Volunteer 3 handles sponsors of participant %d.\n",participant);
	pthread_exit(NULL);
}

void *HelpDesk(void *val)
{
	int participant = *(int*)val;
	printf("Volunteer 4 resolve queries of participant %d.\n",participant);
	pthread_exit(NULL);
}

int main()
{
	pthread_t volunteers[4];
	int participants[10] = {1,2,3,4,5,6,7,8,9,10};
		
	for(int i=0;i<10;i++)
	{
		pthread_create(&volunteers[0],NULL,Registration,&participants[i]);
		pthread_create(&volunteers[1],NULL,Announcement,&participants[i]);
		pthread_create(&volunteers[2],NULL,Sponsoring,&participants[i]);
		pthread_create(&volunteers[3],NULL,HelpDesk,&participants[i]);
	}
	
	for (int i = 0; i < 4; i++)
	{
       	pthread_join(volunteers[i], NULL);
    }

}