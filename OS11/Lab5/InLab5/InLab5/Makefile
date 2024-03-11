#Tianze Ren
#tr2bx@virginia.edu
#10/10/2022


CXX = clang++ $(CXXFLAGS)
CXXFLAGS = -Wall
DEBUG = -g

OBJECTS: BSTPathTest.o BinarySearchTree.o BinaryNode.o
	$(CXX)$(DEBUG) BSTPathTest.o BinarySearchTree.o BinaryNode.o

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h BinaryNode.h

BinaryNode.o: BinaryNode.h BinaryNode.cpp

.PHONY: clean
clean:
    
	-rm -f *.o output

