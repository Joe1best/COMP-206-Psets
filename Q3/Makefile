CC = gcc

update: replace.o main.o update.o
	@$(CC) -s -o update replace.o main.o update.o

replace.o: replace.c
	@$(CC) -s -c replace.c

main.o: main.c replace.h
	@$(CC) -s -c main.c

update.o: update.c main.h
	@$(CC) -s -c update.c
