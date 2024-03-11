#Tianze Ren
#tr2bx@virginia.edu
#10/14/2022


CXX = clang++ $(CXXFLAGS)
CXXFLAGS = -Wall
DEBUG = -g

OBJECTS: AVLNode.o AVLTree.o AVLPathTest.o
	$(CXX)$(DEBUG) AVLNode.o AVLTree.o AVLPathTest.o

AVLNode.o: AVLNode.cpp AVLNode.h

AVLTree.o: AVLTree.cpp AVLNode.h AVLTree.h

AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h

.PHONY: clean
clean:
    
	-rm -f *.o output

