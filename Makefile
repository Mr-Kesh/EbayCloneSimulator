CXX = g++  # the compiler
CXXFLAGS = -std=c++17 -Wall -Werror -Wpedantic
# flags for the compiler (use c++17 standards, turn on all optional warnings); add -ggdb if you want to use gdb to debug!

# runs for "make all"
all: main test

# runs for "make main"
main: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o main

# Commented and will uncomment for the future
# test: test.cpp
#	$(CXX) $(CXXFLAGS) test.cpp -o test
	
clean:
	rm -f main test