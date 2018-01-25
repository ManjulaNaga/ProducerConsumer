#include "functions.h"
int in = 0;
int out = 0;
buffer_item buffer[BUFFER_SIZE];
sem_t empty,full;
pthread_mutex_t mutex;
int j=0;

int insert_item(buffer_item item)
{
	sem_wait(&empty);
	pthread_mutex_lock(&mutex);
		buffer[in] = item;
		printf("\n insert_item() inserted %d in  position %d", item, in );
		in = (in+1)% BUFFER_SIZE;
		printf("\nbuffer items \t");
                for(j=0;j<5;j++){
                        printf("[%d] ",buffer[j]);
                 }
                printf(" IN  =%d ",in);
                printf(" OUT = %d ",out); 

	pthread_mutex_unlock(&mutex);
	sem_post(&full);
	return 0;
}


int remove_item(buffer_item item)
{
	sem_wait(&full);
	pthread_mutex_lock(&mutex);
		item = buffer[out];
		buffer[out] = 0;
		printf("\n remove_item() removed %d in  position %d", item, out );
		out = (out+1) % BUFFER_SIZE;
		printf("\nbuffer items \t");
                for(j=0;j<5;j++){
                        printf("[%d]\t",buffer[j]);
                 }
                printf(" IN  =%d ",in);
                printf(" OUT = %d ",out); 

	pthread_mutex_unlock(&mutex);
	sem_post(&empty);
	return 0;
}