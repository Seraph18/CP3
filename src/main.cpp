#include "LinkedList.h"

#include "LinkedList.cpp"

#include <iostream>
#include <fstream>

using namespace std;

void readVenueFile(string venuePath, LinkedList<Venue> *listOfAllVenues, bool debugging)
{
    ifstream venueFile;
    venueFile.open(venuePath);

    string currLine;
    string currentVal = "";
    // Parse out each userPath line
    while (getline(venueFile, currLine))
    {

        string venueName = "";
        string location = "";
        int capacity = -1;
        for (int i = 0; i < currLine.size(); ++i)
        {
            currentVal += currLine.at(i);
            if (currLine.at(i) == ' ')
            {
                if (venueName == "")
                {
                    venueName = currentVal.substr(0, currentVal.size() - 1);
                    currentVal = "";
                    if (debugging)
                    {
                        cout << "Venue name set to: " << venueName << endl;
                    }
                }
                else if (capacity < 0)
                {
                    capacity = stoi(currentVal.substr(0, currentVal.size() - 1));
                    currentVal = "";
                    if (debugging)
                    {
                        cout << "Capacity set to: " << capacity << endl;
                    }
                }
            }
            if (i == currLine.size() - 1)
            {
                location = currentVal;
                currentVal = "";
                if (debugging)
                {
                    cout << "Location set to: " << location << endl;
                }
            }
        }
        Venue v(venueName, location, capacity);
        listOfAllVenues->addNewNode(v);
    }

    venueFile.close();

    if (debugging)
    {
        listOfAllVenues->print();
    }
}

void readUserFile(string userPath, LinkedList<User> *listOfAllUsers, bool debugging)
{
    ifstream userFile;
    userFile.open(userPath);

    string currLine;
    string currentVal = "";

    while (getline(userFile, currLine))
    {
        string userName = "";
        string firstName = "";
        string lastName = "";

        for (int i = 0; i < currLine.size(); ++i)
        {
            currentVal += currLine.at(i);
            if (currLine.at(i) == ' ')
            {
                if (userName == "")
                {
                    userName = currentVal;
                    currentVal = "";
                }
                else if (firstName == "")
                {
                    firstName = currentVal.substr(0, currentVal.size() - 1);
                    currentVal = "";
                }
            }
            if (i == currLine.size() - 1)
            {
                lastName = currentVal;
                currentVal = "";
            }
        }
        User newUser(userName, firstName, lastName);
        listOfAllUsers->addNewNode(newUser);
    }
    userFile.close();

    if (debugging)
    {
        listOfAllUsers->print();
    }
}

void readActivityFile(string activityPath, LinkedList<Activity> *listOfAllActivities, bool debugging)
{

    ifstream ActivityFile;
    ActivityFile.open(activityPath);

    string currLine = "";
    string currentVal = "";
    while (getline(ActivityFile, currLine))
    {
        string activityTitle = "";
        string creator = "";
        string venue = "";
        string startTime = "";
        string startDate = "";
        string endTime = "";
        string endDate = "";
        string exclusive = "";

        for (int i = 0; i < currLine.size(); ++i)
        {

            currentVal += currLine.at(i);

            if (currLine.at(i) == ' ')
            {
                if (activityTitle == "")
                {
                    activityTitle = currentVal.substr(0, currentVal.size() - 1);
                    currentVal = "";
                }
                else if (creator == "")
                {
                    creator = currentVal.substr(0, currentVal.size() - 1);
                    currentVal = "";
                }
                else if (venue == "")
                {
                    venue = currentVal.substr(0, currentVal.size() - 1);
                    currentVal = "";
                }
                else if (startTime == "")
                {
                    startTime = currentVal.substr(0, currentVal.size() - 1);
                    currentVal = "";
                }
                else if (startDate == "")
                {
                    startDate = currentVal.substr(0, currentVal.size() - 1);
                    currentVal = "";
                }
                else if (endTime == "")
                {
                    endTime = currentVal.substr(0, currentVal.size() - 1);
                    currentVal = "";
                }
                else if (endDate == "")
                {
                    endDate = currentVal.substr(0, currentVal.size() - 1);
                    currentVal = "";
                }
            }
            if (i == currLine.size() - 1)
            {
                exclusive = currentVal.substr(0, currentVal.size() - 1);
                currentVal = "";
            }
        }
        Activity a(activityTitle, creator, venue, startTime, startDate, endTime, endDate, exclusive);
        listOfAllActivities->addNewNode(a);
    }
    ActivityFile.close();

    if (debugging)
    {
        listOfAllActivities->print();
    }
}

// Input layout = ./cp3 <venuefile> <userfile> <activityfile> <attendancefile> <Debugging?: 'y' | 'n'>

int main(int argc, char *const argv[])
{
    string venuePath = argv[1];
    string userPath = argv[2];
    string activityPath = argv[3];
    string attendancePath = argv[4];
    bool debugging = false;

    LinkedList<Venue> *listOfAllVenues = new LinkedList<Venue>;
    LinkedList<User> *listOfAllUsers = new LinkedList<User>;
    LinkedList<Activity> *listOfAllActivities = new LinkedList<Activity>;

    if (argc > 5)
    {
        string bugString = argv[5];
        if (bugString == "y")
        {
            debugging = true;
        }
    }

    // Deal with venuesFirst
    readVenueFile(venuePath, listOfAllVenues, debugging);

    // Deal with list of users
    readUserFile(userPath, listOfAllUsers, debugging);

    // Deal with list of activities
    readActivityFile(activityPath, listOfAllActivities, debugging);

    return 0;
}