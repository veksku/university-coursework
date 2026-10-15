PROGRAM=4.out
CXX       = g++
CXXFLAGS  = -g -std=c++1z -Wall -I ../range-v3-0.12.0/include

$(PROGRAM): 4.o
	$(CXX) -o $(PROGRAM) 4.o

.PHONY: clean dist

clean:
	-rm *.o $(PROGRAM) *core

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)
