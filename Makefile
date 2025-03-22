CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror -Wpedantic
INCLUDES = -IHeader_Files -I.

SRC_DIR = Implementation_Files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

all: main

main: main.cpp $(SRC_FILES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o main


test: test.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) test.cpp -o test

clean:
	rm -f main test