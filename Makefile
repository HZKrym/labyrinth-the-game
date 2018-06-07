CC = g++
FLAGS = -Wall -std=c++17 -O2
LIBRARIES = -lncurses
SOURCES = interface.cc engine.cc main.cc classes/map.cc classes/hero.cc
OBJECTS = $(SOURCES:.cc=.o)
EXECUTABLE = labyrinth-the-game

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LIBRARIES) $(OBJECTS) -o $@

.cc.o:
	$(CC) -c $(FLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
