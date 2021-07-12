myprog: adjacency.o
	gcc -g -Wall -ansi -pedantic adjacency.o -o myprog -lm
adjacency.o: adjacency.c
	gcc -c -Wall -ansi -pedantic adjacency.c -o adjacency.o -lm


