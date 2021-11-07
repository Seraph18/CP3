CFLAGS = g++ -g -I $(HEADERSPATH) -c $(SRCPATH)
SRCPATH = src/
HEADERSPATH = headers/

#Paths to the storage files
ACTIVITYFILEPATH = storageFiles/ActivityFile.txt
USERFILEPATH = storageFiles/UserFile.txt
ATTENDANCEFILEPATH = storageFiles/AttendanceFile.txt
VENUEFILEPATH = storageFiles/VenueFile.txt

ERRORACTIVITYFILEPATH = storageFiles/ErrorTriggerInputs/ActivityFile.txt
ERRORUSERFILEPATH = storageFiles/ErrorTriggerInputs/UserFile.txt
ERRORATTENDANCEFILEPATH = storageFiles/ErrorTriggerInputs/AttendanceFile.txt
ERRORVENUEFILEPATH = storageFiles/ErrorTriggerInputs/VenueFile.txt

ALLPATHS = $(VENUEFILEPATH) $(USERFILEPATH) $(ACTIVITYFILEPATH) $(ATTENDANCEFILEPATH)
ALLERRORPATHS = $(ERRORVENUEFILEPATH) $(ERRORUSERFILEPATH) $(ERRORACTIVITYFILEPATH) $(ERRORATTENDANCEFILEPATH)
FULLCOMPILELIST = LinkedList.o Time.o Venue.o User.o Activity.o

#Makefile for CP3

all: main 

r: main runProgram

runProgram:cp3
	./cp3 $(ALLPATHS)

runProgramWithDebug: cp3
	./cp3 $(ALLPATHS) y

bug: main runProgramWithDebug

main: $(FULLCOMPILELIST) main.o 
	g++ $(FULLCOMPILELIST) main.o -o cp3

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

#Test targets
er: errorTest

errorTest: main runWithErrors

runWithErrors: cp3
	./cp3 $(ALLERRORPATHS)

test: $(FULLCOMPILELIST) Test.o
	g++ $(FULLCOMPILELIST) Test.o -o test

Test.o: $(SRCPATH)Test.cpp
	$(CFLAGS)Test.cpp -o Test.o 

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -rf *.o .nfs* *.exe test OutputFiles/* cp3

clear: clean
	clear