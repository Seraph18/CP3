CFLAGS = g++ -g -c
#Makefile for CP3

all:

Activity.o: Activity.cpp
	$(CFLAGS) Activity.cpp -o Activity.o 

LinkedList.o: LinkedList.cpp
	$(CFLAGS) LinkedList.cpp -o LinkedList.o

User.o: User.cpp
	$(CFLAGS) User.cpp -o User.o

#Test target

test: Activity.o LinkedList.o User.o Test.o
	g++ Activity.o LinkedList.o Test.o User.o -o test.exe

Test.o: Test.cpp
	$(CFLAGS) Test.cpp -o Test.o 
	
# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -rf *.o .nfs* *.exe

clear: clean
	clear