CXX = g++  # the compiler
CXXFLAGS = -std=c++17 -Wall -Werror -Wpedantic
INCLUDES = -I"Header Files" -I.

# runs for "make all"
all: main test

# runs for "make main"
main: main.cpp Implementation\ Files/Driver.cpp Implementation\ Files/Seller.cpp Implementation\ Files/Product.cpp Implementation\ Files/Buyer.cpp Implementation\ Files/UserFactory.cpp Implementation\ Files/ProductFactory.cpp Implementation\ Files/Electronics.cpp Implementation\ Files/Clothing.cpp Implementation\ Files/Furniture.cpp Implementation\ Files/Books.cpp Implementation\ Files/Tools.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o main

# runs for "make test"
test: test.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) test.cpp -o test
	
clean:
	rm -f main test
	