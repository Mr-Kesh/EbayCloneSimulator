CXX = g++  # the compiler
CXXFLAGS = -std=c++17 -Wall -Werror -Wpedantic
INCLUDES = -I"Header Files" -I.

SRC_DIR = Implementation\ Files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(SRC_FILES:.cpp=.o)

# runs for "make all"
all: main test

# runs for "make main"
main: main.cpp $(SRC_FILES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o main

# runs for "make test"
test: test.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) test.cpp -o test

clean:
	rm -f main test $(OBJ_FILES)
