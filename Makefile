CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror -Wpedantic

all: test

main: main.cpp
    $(CXX) $(CXXFLAGS) main.cpp -o main

test: test.cpp
    $(CXX) $(CXXFLAGS) test.cpp -o test

clean:
    rm -f main test
