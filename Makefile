CFLAGS = g++ -g -I $(HEADERSPATH) -c $(SRCPATH)
SRCPATH = src/
HEADERSPATH = headers/

#Paths to the storage files
ACTIVITYFILEPATH = /home/josh/Documents/CS240/CP3/storageFiles/ActivityFile.txt
USERFILEPATH = /home/josh/Documents/CS240/CP3/storageFiles/UserFile.txt
ATTENDANCEFILEPATH = /home/josh/Documents/CS240/CP3/storageFiles/AttendanceFile.txt
VENUEFILEPATH = /home/josh/Documents/CS240/CP3/storageFiles/VenueFile.txt

ALLPATHS = $(VENUEFILEPATH) $(USERFILEPATH) $(ACTIVITYFILEPATH) $(ATTENDANCEFILEPATH)
FULLCOMPILELIST = User.o Time.o Venue.o Activity.o LinkedList.o

#Makefile for CP3

all: main runProgram

runProgram:cp3.exe
	./cp3.exe $(ALLPATHS)

runProgramWithDebug: cp3.exe
	./cp3.exe $(ALLPATHS) y

bug: main runProgramWithDebug

main: $(FULLCOMPILELIST) main.o 
	g++ $(FULLCOMPILELIST) main.o -o cp3.exe

main.o: $(SRCPATH)main.cpp
	$(CFLAGS)main.cpp -o main.o

Activity.o: $(SRCPATH)Activity.cpp
	$(CFLAGS)Activity.cpp -o Activity.o 

LinkedList.o: $(SRCPATH)LinkedList.cpp
	$(CFLAGS)LinkedList.cpp -o LinkedList.o

User.o: $(SRCPATH)User.cpp
	$(CFLAGS)User.cpp -o User.o

Time.o: $(SRCPATH)Time.cpp
	$(CFLAGS)Time.cpp -o Time.o

Venue.o: $(SRCPATH)Venue.cpp
	$(CFLAGS)Venue.cpp -o Venue.o

#Test target

test: $(FULLCOMPILELIST) Test.o
	g++ $(FULLCOMPILELIST) Test.o -o test

Test.o: $(SRCPATH)Test.cpp
	$(CFLAGS)Test.cpp -o Test.o 

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -rf *.o .nfs* *.exe test

clear: clean
	clear