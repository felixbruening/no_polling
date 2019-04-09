/**
 * Dummy function for testings.
 */
#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <unistd.h>

#include "thread_wait_for_event.h"
#include "data.h"

pthread_mutex_t mutex_cond = PTHREAD_MUTEX_INITIALIZER;

void* thr_01(void* arg)
{
	wait_for(&change_event, &mutex_cond, (void*)&get_val, 7);
	printf("[THREAD 01]: Got expected value! \n");

	return 0;
}

void* thr_02(void* arg)
{
	wait_for(&change_event, &mutex_cond, (void*)&get_val, 10);
	printf("[THREAD 02]: Got expected value! \n");

	return 0;
}

void* thr_03(void* arg)
{
	static int it = 0;

	while(it != 15)
	{
		set_val(it);
		it++;
		printf("Iteration: %d\n", it);
		sleep(1);
	}
	return 0;
}


int main() {

	pthread_t thr1, thr2, thr3;

	pthread_create(&thr1, NULL, thr_01, NULL);
	pthread_create(&thr2, NULL, thr_02, NULL);
	pthread_create(&thr3, NULL, thr_03, NULL);


	pthread_join(thr1, NULL);
	pthread_join(thr2, NULL);
	pthread_join(thr3, NULL);

	return 0;
}
