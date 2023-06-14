CC = gcc
CFLAGS = -Wall -g
OBJS = main sorting bubble insertion

.PHONY: all clean

all: $(OBJS) 

main: main.c util.h

bubble: bubble.c

insertion: insertion.c

sorting: sorting.o

sorting.o: sorting.c sorting.h

clean:
	rm -rf *~ *.o
	rm -rf $(OBJS) 
