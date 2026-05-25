.PHONY: clean uninstall install

CC = gcc
CXX = g++

CFLAGS = -Wall -c --std=c99
CXXFLAGS = -Wall -c --std=c++98
LDFLAGS = `fox-config --libs`

PREFIX=/usr/local

SOURCES = visix.cxx
OBJECTS = visix.o
ICONS = res/*.gif res/toolbar/*.gif
EXECUTABLE = visix

CXXFLAGS += `fox-config --cflags`

all: $(EXECUTABLE)

$(OBJECTS): res/foxres.h

res/foxres.h: $(ICONS)
	reswrap -d -p resico_ -o res/foxres.h $(ICONS)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

clean:
	rm -f res/foxres.h $(OBJECTS) $(EXECUTABLE)

install: $(EXECUTABLE)
	cp visix $(PREFIX)/bin/visix
	strip $(PREFIX)/bin/visix

uninstall:
	rm -f $(PREFIX)/bin/visix
