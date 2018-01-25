#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<time.h>
#define BUFFER_SIZE 5
typedef int buffer_item;
extern buffer_item buffer[BUFFER_SIZE];

extern int in;
extern int out;
//int j;
extern pthread_t ptid[30];
extern pthread_t ctid[30];
extern buffer_item item;
extern clock_t _current_time;
 
extern sem_t empty;
extern sem_t full;

extern pthread_mutex_t mutex;
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);


void *producer(void *ptr);
void *consumer(void *ptr);
int insert_item(buffer_item item);
int remove_item(buffer_item item);
int current_time();
void* g_start_timer(void *secs);

