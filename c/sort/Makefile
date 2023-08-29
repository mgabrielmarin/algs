CC=gcc
CFLAGS=-Wall -g
OBJS=main 

.PHONY: clean

all: $(OBJS) 

main: main.o

main.o: main.c util.h

clean:
	rm -rf *~ *.o
	rm -rf $(OBJS) 
