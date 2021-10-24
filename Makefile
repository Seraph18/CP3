CFLAGS = g++ -g -c
#Makefile for CP3

# Specifiy the target
all:	main

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
main:	main.o NodeHeader.o Node.o
	g++ main.o NodeHeader.o Node.o -o calendar.exe

# Specify how the object files should be created from source files

main.o:	main.cpp
	$(CFLAGS) main.cpp -o main.o

NodeHeader.o: NodeHeader.cpp
	$(CFLAGS) NodeHeader.cpp -o NodeHeader.o

Node.o: Node.cpp
	$(CFLAGS) Node.cpp -o Node.o


#make the test file

test: Test.o Node.o	 NodeHeader.o 
	g++ Test.o Node.o NodeHeader.o -o test.exe

Test.o: Test.cpp
	$(CFLAGS) Test.cpp -o Test.o 
	
# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -rf *.o .nfs* *.exe

clear: clean
	clear