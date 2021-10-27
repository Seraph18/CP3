CFLAGS = g++ -g -I $(HEADERSPATH) -c $(SRCPATH)
SRCPATH = src/
HEADERSPATH = headers/

#Paths to the storage files
ACTIVITYFILEPATH = /home/josh/Documents/CS240/CP3/storageFiles/ActivityFile.txt
USERFILEPATH = /home/josh/Documents/CS240/CP3/storageFiles/UserFile.txt
ATTENDANCEFILEPATH = /home/josh/Documents/CS240/CP3/storageFiles/AttendanceFile.txt
VENUEFILEPATH = /home/josh/Documents/CS240/CP3/storageFiles/VenueFile.txt

ALLPATHS = $(VENUEFILEPATH) $(USERFILEPATH) $(ACTIVITYFILEPATH) $(ATTENDANCEFILEPATH)


#Makefile for CP3

all: main runProgram

runProgram:cp3.exe
	./cp3.exe $(ALLPATHS)

main: Venue.o Activity.o ActivityLinkedList.o User.o Time.o VenueLinkedList.o main.o 
	g++ Venue.o Activity.o ActivityLinkedList.o User.o Time.o VenueLinkedList.o main.o -o cp3.exe

main.o: $(SRCPATH)main.cpp
	$(CFLAGS)main.cpp -o main.o

Activity.o: $(SRCPATH)Activity.cpp
	$(CFLAGS)Activity.cpp -o Activity.o 

ActivityLinkedList.o: $(SRCPATH)ActivityLinkedList.cpp $(HEADERSPATH)LinkedList.h
	$(CFLAGS)ActivityLinkedList.cpp -o ActivityLinkedList.o

VenueLinkedList.o: $(SRCPATH)VenueLinkedList.cpp $(HEADERSPATH)LinkedList.h
	$(CFLAGS)VenueLinkedList.cpp -o VenueLinkedList.o

User.o: $(SRCPATH)User.cpp
	$(CFLAGS)User.cpp -o User.o

Time.o: $(SRCPATH)Time.cpp
	$(CFLAGS)Time.cpp -o Time.o

Venue.o: $(SRCPATH)Venue.cpp
	$(CFLAGS)Venue.cpp -o Venue.o

#Test target

test: Activity.o ActivityLinkedList.o User.o Test.o Time.o
	g++ Activity.o ActivityLinkedList.o Test.o User.o Time.o -o test.exe

Test.o: $(SRCPATH)Test.cpp
	$(CFLAGS)Test.cpp -o Test.o 

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -rf *.o .nfs* *.exe

clear: clean
	clear