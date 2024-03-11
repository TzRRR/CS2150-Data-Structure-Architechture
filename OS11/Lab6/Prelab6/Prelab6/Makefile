#Tianze Ren
#tr2bx@virginia.edu
#10/18/2022


CXX = clang++ $(CXXFLAGS)
CXXFLAGS = -Wall
DEBUG = -g

OBJECTS: hashTable.o	wordPuzzle.o
	$(CXX)$(DEBUG) hashTable.o	wordPuzzle.o

hashTable.o: hashTable.cpp hashTable.h

wordPuzzle.o: wordPuzzle.cpp hashTable.h

.PHONY: clean
clean:
    
	-rm -f *.o output

