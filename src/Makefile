# Very very ugly Makefile..
all:
	gcc -c main.c
	gcc -c data.c
	gcc -c thread_wait_for_event.c
	gcc main.o data.o thread_wait_for_event.o -l pthread -o prog

clean:
	rm *.o
	rm prog
