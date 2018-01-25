#include "functions.h"
buffer_item item;
int t;
pthread_t ptid[30];
pthread_t ctid[30];
void *producer(void *ptr)
{
	fflush(stdout);
	int i=0,slp;
	while(1) {
			//	printf("\n At time= %d  in producer ...........",i); 
				ptid[i] = pthread_self();
				slp = rand()%10;
				printf("\n Producer is sleeping for %d.", slp);
				sleep(slp);
				item = rand()%100+1; //producing item;
				if(insert_item(item)<0) {
					printf("\n Production error: product cannot be produced");
				}
				else {
					printf("\n Producer thread %lu produced item %d ",ptid[i],item);
				}
				i++;
		}
        	return 0;
}

void *consumer(void *ptr)
{
	fflush(stdout);
	int i=0,slp;
	while(1) {
                ctid[i] = pthread_self();
				slp = rand()%3 + 1;
				printf("\n Consumer is sleeping for %d.", slp);
				sleep(slp);
				if(remove_item(item)<0) {
				printf("\nConsumption error: consumer cannot consume.");
	  			}
				else {
                printf("\n Consumer thread %lu consumed item %d ",ctid[i],item);
                }

		i++;
		}
		return 0;
}
