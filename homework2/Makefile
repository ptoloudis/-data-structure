compile: sort1 tree1 tree2 

CC = gcc
CFLAGS = -Wall  -g -std=c99

dlist.o: dlist.c dlist.h
	$(CC) $(CFLAGS) dlist.c -c -o dlist.o

tree.o: tree.c tree.h
	$(CC) $(CFLAGS) tree.c -c -o tree.o

sort.o: sort.c sort.h
	$(CC) $(CFLAGS) sort.c -c -o sort.o

sort1: sort1.c sort.o dlist.o
	$(CC) $(CFLAGS) sort1.c dlist.o sort.o -o sort1 

tree1: tree1.c tree.o dlist.o
	$(CC) $(CFLAGS) tree1.c dlist.o tree.o -o tree1

# tree2: tree2.c tree.o dlist.o
# 	 $(CC) $(CFLAGS) tree2.c dlist.o tree.o -o tree2

.PHONY: clean
clean: 
		rm-f*.o