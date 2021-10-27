#include "LinkedList.h"
#include <iostream>
#include <fstream>

using namespace std;

//Input layout = ./cp3 <venuefile> <userfile> <activityfile> <attendancefile>


int main(int argc, char* const argv[])
{
    string venue = argv[1];
    string userFile = argv[2];
    string activityFile = argv[3];
    string attendanceFile = argv[4];

    //Deal with venuesFirst

    ifstream venueFile;

    venueFile.open(venue);

    VenueLinkedList *listOfAllVenues = new VenueLinkedList;

    string currLine;
    // Parse out each venue line
    while (getline(venueFile, currLine))
    {
       
        string venueName = "";
        string location = "";
        int capacity = -1;
        string currentVal = "";
        for (int i = 0; i < sizeof(currLine); ++i)
        {
            currentVal += (&currLine[i]);
            if (&currLine[i] == " ")
            {
                if(venueName == ""){
                    venueName = currentVal;
                    currentVal = "";
                }
                else if(capacity < 0){
                    capacity = stoi(currentVal);
                    currentVal = "";
                }
            }
            if(i == sizeof(currLine)-1){
                location = currentVal;
            }
        }
        Venue v(venueName, location, capacity);
        listOfAllVenues->addNewNode(v);
    }

    venueFile.close();
    return 0;
}
