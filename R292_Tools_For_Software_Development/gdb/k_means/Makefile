PROGRAM = program.out
CXX = g++
CXXFLAGS = -g -std=c++17 -Wall -Wextra

$(PROGRAM): main.o test.o k_means.o Points.o Point.o RandomEngine.o
	$(CXX) -o $@ $^
	
main.o: main.cpp Point.hpp Points.hpp k_means.hpp
	$(CXX) -c -o $@ $(CXXFLAGS) $<
	
test.o: tests.cpp Point.hpp Points.hpp k_means.hpp RandomEngine.hpp
	$(CXX) -c -o $@ $(CXXFLAGS) $<
	
k_means.o: k_means.cpp Point.hpp Points.hpp k_means.hpp
	$(CXX) -c -o $@ $(CXXFLAGS) $<

Points.o: Points.cpp Point.hpp Points.hpp RandomEngine.hpp
	$(CXX) -c -o $@ $(CXXFLAGS) $<
	
Point.o: Point.cpp Point.hpp
	$(CXX) -c -o $@ $(CXXFLAGS) $<
	
RandomEngine.o: RandomEngine.cpp RandomEngine.hpp
	$(CXX) -c -o $@ $(CXXFLAGS) $<
	
	
.PHONY: clean

clean:
	rm *.o $(PROGRAM)
