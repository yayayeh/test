CC=g++
LDFLAGS=-std=c++11 -O3 -lm -g
SOURCES=src/module.cpp src/tech.cpp src/main.cpp
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=place
INCLUDES=src/module.h src/tech.h

all: $(SOURCES) bin/$(EXECUTABLE)

bin/$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o:  %.c  ${INCLUDES}
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o bin/$(EXECUTABLE)
