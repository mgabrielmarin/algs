CC=g++
CXXFLAGS=-g -Wall
OBJS= fltdbll closure

.PHONY: clean

all: $(OBJS)

closure: closure.o

closure.o: closure.cpp

fltdbll: fltdbll.o

fltdbll.o: fltdbll.cpp

clean:
	rm -rf *.o *~
	rm -rf $(OBJS)
