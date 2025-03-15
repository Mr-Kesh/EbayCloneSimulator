CXX = g++  # the compiler
CXXFLAGS = -std=c++17 -Wall -Werror -Wpedantic

# runs for "make all"
all: main test

# runs for "make main"
main: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o main

# runs for "make test"
test: test.cpp
	$(CXX) $(CXXFLAGS) test.cpp -o test
	
clean:
	rm -f main test