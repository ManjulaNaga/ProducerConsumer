#include "functions.h"

int main(int argc,char* argv[])
{
 fflush(stdout);
 pthread_t ptid[30];
 pthread_t ctid[30];
 pthread_mutex_t mutex;	
 pthread_t thread_id;
 pthread_mutex_init(&mutex,NULL);

 sem_t empty;
 sem_t full;
 sem_init(&empty, 0, BUFFER_SIZE);
 sem_init(&full, 0, 0);
 int time =atoi(argv[1]);
 int p = atoi(argv[2]);
 int c = atoi(argv[3]);
 int i;
	printf("\n Length of time program should run = %d",time);
	printf("\n No of producer threads = %d",p);
	printf("\n No of consumer threads = %d\n",c);

	int temp =pthread_create(&thread_id,NULL,g_start_timer,(void*)time);
	if(temp){printf("\n timer thread not created\n");}
	printf("\n *********** Main Thread started ***********\n ");
	for(i=0;i<p;i++)
	{
	  	int m=pthread_create(&ptid[i],NULL,producer,NULL);
        	if(m){printf("\n thread not created.");}
   	printf(" Creating producer thread with id %lu\n",ptid[i]);
	}
	
	for(i=0;i<c;i++)
	{
	 	int m=	pthread_create(&ctid[i],NULL,consumer,NULL);
       		if(m){printf("\n thread not created.");}				printf(" Creating consumer thread with id %lu\n",ctid[i]);
	}
        //sleep(time);
	
	pthread_mutex_destroy(&mutex);
	sem_destroy(&full);
	sem_destroy(&empty);

	printf("\nCurent time: %d\n", current_time());
	printf("\n  *************Main thread Exiting********* \n");
	return EXIT_SUCCESS;
}
