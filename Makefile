CFLAGS = g++ -g -I $(HEADERSPATH) -c $(SRCPATH)
SRCPATH = src/
HEADERSPATH = headers/
#Makefile for CP3

all:

Activity.o: $(SRCPATH)Activity.cpp
	$(CFLAGS)Activity.cpp -o Activity.o 

LinkedList.o: $(SRCPATH)LinkedList.cpp
	$(CFLAGS)LinkedList.cpp -o LinkedList.o

User.o: $(SRCPATH)User.cpp
	$(CFLAGS)User.cpp -o User.o

Time.o: $(SRCPATH)Time.cpp
	$(CFLAGS)Time.cpp -o Time.o

#Test target

test: Activity.o LinkedList.o User.o Test.o Time.o
	g++ Activity.o LinkedList.o Test.o User.o Time.o -o test.exe

Test.o: $(SRCPATH)Test.cpp
	$(CFLAGS)Test.cpp -o Test.o 

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -rf *.o .nfs* *.exe

clear: clean
	clear