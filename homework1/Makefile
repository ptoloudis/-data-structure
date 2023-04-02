compile: tree3

CC = gcc
CFLAGS = -Wall -Wextra -g -std=c99

tree3: tree3.c stack.o tree.o fifo.o dlist.o
	$(CC) $(CFLAGS) tree3.c dlist.o tree.o stack.o fifo.o -o tree3

tree.o: tree.c tree.h
	$(CC) $(CFLAGS) tree.c -c -o tree.o

dlist.o: dlist.c dlist.h
	$(CC) $(CFLAGS) dlist.c -c -o dlist.o

stack.o: dlist.o stack.c stack.h 
	$(CC) $(CFLAGS) stack.c -c -o stack.o
	
fifo.o: dlist.o fifo.c fifo.h 
	$(CC) $(CFLAGS) fifo.c -c -o fifo.o

.PHONY: clean
clean: 
		rm-f*.o