CC=g++
CFLAGS=-c -Wall -std=c++0x
LDFLAGS=
SOURCES=$(wildcard *.c *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECTUABLE=oop1

all: $(SOURCES) $(EXECTUABLE)

$(EXECTUABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECTUABLE)