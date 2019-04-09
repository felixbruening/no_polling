# no_polling

This repository shows a Pthread implementation that waits until a function returns a specific value.
In this case, the thread that sets the value, sends a broadcast signal to all waiters.

The new wait_for(..) function waits for a thread until the value is set to a specific value.
