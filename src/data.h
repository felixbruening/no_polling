/**
 * @brief
 * 		C Module to represent a specific Datapool for testings.
 *
 * @author
 * 		Felix Brüning
 */

#ifndef DATA_H
#define DATA_H

/** Condition if data was changed. */
extern pthread_cond_t change_event;
/** Mutex for condition*/
extern pthread_mutex_t mutex;

/**
 * Sets the data-value to a value x.
 *
 * @param x
 * 			Value to set.
 */
extern void set_val(int x);

/**
 * Getter for data-value.
 *
 * @return
 * 		data-value.
 */
extern int get_val();

#endif //DATA_H
