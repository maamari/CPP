# contact: Mark Redekopp, David Pritchard

CC = compile
# if needed, install from http://bits.usc.edu/cs103/compile/ or use g++ or clang++

LDFLAGS =
SRCS = bmplib.cpp
OBJ = $(SRCS:.cpp=.o)
DEMOSRC = demo.cpp bmplib.cpp
DEMOOBJ = $(DEMOSRC:.cpp=.o)

all: demo

demo: $(DEMOOBJ)
	$(CC) $(DEMOOBJ) -o demo

.cpp.o:
	$(CC) -c $<

bmplib.o : bmplib.h

clean:
	rm -f *.o demo

