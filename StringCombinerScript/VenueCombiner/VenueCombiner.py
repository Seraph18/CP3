from os import stat
import random
import sys


venueList = open("/home/josh/Documents/CS240/CP3/StringCombinerScript/ListOfVenues.txt", 'r')
statesList = open("/home/josh/Documents/CS240/CP3/StringCombinerScript/ListOfStates.txt", 'r')

listOfVenues = venueList.readlines()
for i in listOfVenues:
    currVenue = i
    currVenue = currVenue.strip()
    currVenue = currVenue.replace("\n", "")
    currVenue = currVenue.replace(" ", "_")
    listOfVenues[listOfVenues.index(i)] = currVenue

listOfStates = statesList.readlines()
for i in listOfStates:
    currState = i.strip()
    listOfStates[listOfStates.index(i)] = currState.replace("\n", "")
venueFileFinal = open("/home/josh/Documents/CS240/CP3/storageFiles/VenueFile.txt", 'w')

for i in range(len(listOfVenues)):
    numberOfPeople =  str(random.randint(300, 10000))
    #print(listOfVenues[i] + numberOfPeople + " " + listOfStates[i])
    venueFileFinal.write(listOfVenues[i] + " " + numberOfPeople + " " + listOfStates[i] + "\n")

venueList.close()
statesList.close()
venueFileFinal.close()
