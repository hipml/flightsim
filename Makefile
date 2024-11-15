# Makefile for OpenGL flight simulator
# ------------------------------------

# Object files list
OBJS = flightsim.o plane.o vector_operations.o

# Executable name
EXENAME = flightsim

# Macros
CC = g++
CCOPTS = -c -g -O0 -Wall -Wno-deprecated
LINK = g++
LINKOPTS = -o

.PHONY: all clean

all : $(EXENAME)

# Testing for OS X v Linux
OS = $(shell uname -s)

ifeq ($(OS), Darwin)
	LIBS = -framework GLUT -framework OpenGL -framework Cocoa
else
	LIBS = -lGL -lGLU -lglut
endif

# The compiling step
$(EXENAME) : $(OBJS)
	$(LINK) $(LINKOPTS) $(EXENAME) $(OBJS) $(LIBS)

# Object files
flightsim.o : flightsim.cpp flightsim.h
	$(CC) $(CCOPTS) flightsim.cpp
plane.o : plane.cpp plane.h
	$(CC) $(CCOPTS) plane.cpp
vector_operations.o : vector_operations.cpp vector_operations.h
	$(CC) $(CCOPTS) vector_operations.cpp

clean :
	rm -f *.o $(EXENAME) 2>/dev/null


