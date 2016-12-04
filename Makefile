CPP=g++
CPPFLAGS=-g -std=c++11

all: aoc1 aoc2 aoc3p1 aoc3p2 aoc4

aoc1: aoc1.o
	$(CPP) $(CPPFLAGS) aoc1.o -o $@

aoc2: aoc2.o
	$(CPP) $(CPPFLAGS) aoc2.o -o $@

aoc3p1: aoc3p1.o
	$(CPP) $(CPPFLAGS) aoc3p1.o -o $@

aoc3p2: aoc3p2.o
	$(CPP) $(CPPFLAGS) aoc3p2.o -o $@

aoc4: aoc4.o
	$(CPP) $(CPPFLAGS) aoc4.o -o $@

clean:
	rm -f aoc1 aoc2 aoc3p1 aoc3p2 aoc4 *.o *.bin

.SUFFIXES: .cpp .o

.cpp.o:
	$(CPP) $(CPPFLAGS) -c $<

