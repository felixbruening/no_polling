#include <pthread.h>

#include "data.h"

pthread_cond_t change_event = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int val = 0;

int get_val()
{
	int v = 0;
	pthread_mutex_lock(&mutex);
	v = val;
	pthread_mutex_unlock(&mutex);
	return v;
}

void set_val(int x)
{
	pthread_mutex_lock(&mutex);
	val = x;
	pthread_cond_broadcast(&change_event);
	pthread_mutex_unlock(&mutex);
}