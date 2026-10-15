PROGRAM = program.out
CXX = g++
CXXFLAGS = -g -std=c++17 -Wall -Wextra

$(PROGRAM): main.o line.o grid.o test.o
	$(CXX) -o $@ $^
	
main.o: main.cpp grid.hpp
	$(CXX) -c -o $@ $(CXXFLAGS) $<
	
test.o: tests.cpp grid.hpp
	$(CXX) -c -o $@ $(CXXFLAGS) $<
	
grid.o: grid.cpp grid.hpp
	$(CXX) -c -o $@ $(CXXFLAGS) $<
	
line.o: line.cpp line.hpp
	$(CXX) -c -o $@ $(CXXFLAGS) $<
	
.PHONY: clean

clean:
	rm *.o $(PROGRAM)
