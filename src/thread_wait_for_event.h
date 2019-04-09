/**
 * @brief
 * 		Function that waits for a specific event.
 * @author
 * 		Felix Brüning
 */
#ifndef THREAD_WAIT_FOR_EVENT_H
#define THREAD_WAIT_FOR_EVENT_H

#include <pthread.h>

/**
 * Function that waits until the function @see f returns the value val.
 *
 * @param cond
 * 			Condition to wait for.
 * @param mutex
 * 			Mutex for condition.
 * @param f
 * 			Function to call until it returns val.
 * @param val
 * 			Value that the function has to return.
 * @return
 * 			value.
 */
int wait_for(pthread_cond_t* cond, pthread_mutex_t* mutex, int (*f)(void), int val);

#endif //THREAD_WAIT_FOR_EVENT_H
