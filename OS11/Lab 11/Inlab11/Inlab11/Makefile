#Tianze Ren, tr2bx, 11/29/2022, Makefile

# Defines the C++ compiler we'll be using
CXX = clang++

# Defines the flags we'll be passing to the C++ compiler
CXXFLAGS = -Wall -g -std=c++11 -O2

# Defines the assembler
AS = nasm

# Defines the flags for the assembler
ASFLAGS = -f elf64 -g

# All of the .o files for our program
OBJECTS = traveling.o middleearth.o

# Compile our files into a.out
a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)
	doxygen
	
traveling.o: traveling.cpp

middleearth.o: middleearth.cpp middleearth.h

# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not).  This removes object files (*.o) and Emacs
# backup files (*~)
clean:
	-rm -f *.o *~
