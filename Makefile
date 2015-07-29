.PHONY: all clean
CC=gcc
CPP=g++
AR=ar
RANLIB=ranlib
CFLAGS= -g -Wall -Wno-unused-function
C11FLAGS= -g -Wall -Wno-unused-function -std=c++11
SRCDIR = ./src
IDIR = ./include
ODIR = obj
INCLUDEDIR = -I$(IDIR) -I.
DEPS = 
LIBS = -lm -ltcmalloc
BINDIR = ./bin
_OBJ = vector.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
PROGRAMS = renderer

all: $(PROGRAMS)

renderer: $(SRCDIR)/main.cpp $(OBJ)
	$(CPP) $(C11FLAGS) -o $(BINDIR)/$@ $^ $(INCLUDEDIR) $(LIBS)


vector.o: $(SRCDIR)/vector.cpp $(IDIR)/vector.hpp
	$(CPP) -c $(C11FLAGS) -o $(ODIR)/$@ $< $(INCLUDEDIR)


clean:
	rm -rf $(PROGRAMS) *.dSYM *.o

