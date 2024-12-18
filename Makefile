# Compiler and Flags
CC = gcc
CFLAGS = -Wall -pthread

# Target to build the main executable
all: main

# Rule to create the final executable
main: main.o
	$(CC) $(CFLAGS) -o main main.o

# Rule to compile the C file into an object file
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

# Rule to clean the object files and the executable
clean:
	rm -f *.o main
