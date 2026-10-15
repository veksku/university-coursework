PROGRAM = program.out
CXX = g++
CXXFLAGS = -g -std=c++17 -Wall -Wextra

$(PROGRAM): main.o test.o text.o
	$(CXX) -o $@ $^
	
main.o: main.cpp text.hpp
	$(CXX) -c -o $@ $(CXXFLAGS) $<
	
test.o: test.cpp text.hpp
	$(CXX) -c -o $@ $(CXXFLAGS) $<
	
text.o: text.cpp text.hpp
	$(CXX) -c -o $@ $(CXXFLAGS) $<
	
.PHONY: clean

clean:
	rm *.o $(PROGRAM)
