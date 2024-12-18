CC = gcc
CFLAGS = -Wall -pthread

all: main

main: main.o input_handler.o count_even.o
	$(CC) $(CFLAGS) -o main main.o input_handler.o count_even.o

main.o: main.c input_handler.h count_even.h
	$(CC) $(CFLAGS) -c main.c

input_handler.o: input_handler.c input_handler.h
	$(CC) $(CFLAGS) -c input_handler.c

count_even.o: count_even.c count_even.h
	$(CC) $(CFLAGS) -c count_even.c

clean:
	rm -f *.o main
