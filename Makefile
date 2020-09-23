CC=clang++
CFLAGS=
LDFLAGS=
SOURCES=$(wildcard *.c *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECTUABLE=oop1

all: $(SOURCES) $(EXECTUABLE)

$(EXECTUABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@