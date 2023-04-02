compile :tree1 htable1

CC =gcc
CFLAGS = -Wall -g -std=c99

hbtree.o: hbtree.h hbtree.c
	$(CC) $(CFLAGS) hbtree.c -c -o hbtree.o

tree1: tree1.c hbtree.o
	$(CC) $(CFLAGS) tree1.c hbtree.o  -o tree1 -lm

htable.o: htable.h htable.c
	$(CC) $(CFLAGS) htable.c -c -o htable.o

htable1: htable1.c htable.o
	$(CC) $(CFLAGS) htable1.c htable.o  -o htable1

.PHONY: clean
clean: 
		rm-f*.o