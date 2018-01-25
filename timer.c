#include "functions.h"
clock_t _current_time = 0;

/* get the current time of work */
int current_time()
{
printf("\n current time is  %d",(int) _current_time);
    return (int) _current_time / CLOCKS_PER_SEC;
}

/* start the timing in another thread */
void* g_start_timer(void *secs)
{
    printf("\n Starting timer  thread\n");
    int seconds = (int) secs;
    printf("g_start_timer: %d\n", (int) seconds);
   
  _current_time = clock() + seconds * CLOCKS_PER_SEC;
 
    /* loop until given seconds has reached */
    while(clock() < _current_time){}
    pthread_exit(NULL);
}
