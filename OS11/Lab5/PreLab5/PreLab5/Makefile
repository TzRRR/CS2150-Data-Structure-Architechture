#Tianze Ren
#tr2bx@virginia.edu
#10/10/2022


CXX = clang++ $(CXXFLAGS)
CXXFLAGS = -Wall
DEBUG = -g

OBJECTS: TreeCalcTest.o TreeCalc.o TreeNode.o
	$(CXX) $(DEBUG) TreeCalcTest.o TreeCalc.o TreeNode.o

TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h

TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h

TreeNode.o: TreeNode.h TreeNode.cpp

.PHONY: clean
clean:
    
	-rm -f *.o ~a.out

