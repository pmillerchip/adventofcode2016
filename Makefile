CPP=g++
CPPFLAGS=-g -std=c++11

aoc1: aoc1.o
	$(CPP) $(CPPFLAGS) aoc1.o -o $@

clean:
	rm -f aoc1 *.o

.SUFFIXES: .cpp .o

.cpp.o:
	$(CPP) $(CPPFLAGS) -c $<

