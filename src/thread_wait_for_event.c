#include "thread_wait_for_event.h"

int wait_for(pthread_cond_t* cond, pthread_mutex_t* mutex, int (*f)(void), int val)
{
	int ret = 0;
	while(1)
	{
		pthread_cond_wait(cond, mutex);

		if((ret = f()) == val)
		{
			pthread_mutex_unlock(mutex);
			break;
		}
	}
	return ret;
}