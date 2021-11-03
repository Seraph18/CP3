#include "LinkedList.cpp"

#include "User.h"

#include <iostream>
#include <fstream>

using namespace std;

// Extension of where output files should go
string const outputLocation = "OutputFiles/";

//Used to find core name of original input file to create a parallel output file later on
string getFileRealName(string filePath)
{
    string realName = "";
    for (int i = 0; i < filePath.size(); ++i)
    {
        if (filePath.at(i) == '/')
        {
            realName = "";
        }
        else
        {
            realName += filePath.at(i);
        }
    }
    return realName;
}


// Read in all the files

/*Read and load the venueFile*/
void readVenueFile(string venuePath, LinkedList<Venue> *listOfAllVenues, bool debugging)
{
    ifstream venueFile;
    venueFile.open(venuePath);

    string currLine;
    string currentVal = "";
    int lineCount = 0;
    // Parse out each userPath line
    while (getline(venueFile, currLine))
    {
        ++lineCount;
        string venueName = "";
        string location = "";
        int capacity = -1;
        bool shouldCreateVenue = false;

        for (int i = 0; i < currLine.size(); ++i)
        {
            currentVal += currLine.at(i);
            if (currLine.at(i) == ' ')
            {
                if (venueName == "")
                {
                    venueName = currentVal.substr(0, currentVal.size() - 1);

                    Venue v(venueName);
                    if (listOfAllVenues->isPresent(v))
                    {
                        cout << "Venue file " << venuePath << " line " << lineCount << ": venue "
                             << venueName << " exists - ignoring." << endl;
                        currentVal = "";
                        break;
                    }

                    currentVal = "";
                }
                else if (capacity < 0)
                {
                    capacity = stoi(currentVal.substr(0, currentVal.size() - 1));
                    currentVal = "";
                }
            }
            if (i == currLine.size() - 1)
            {
                location = currentVal;
                currentVal = "";
                shouldCreateVenue = true;
            }
        }
        if (shouldCreateVenue)
        {
            Venue v(venueName, location, capacity);
            listOfAllVenues->addNewNode(v);
        }
    }

    venueFile.close();

    if (debugging)
    {
        listOfAllVenues->print();
    }
    cout << "Finished Venue Read" << endl;
}

/*Read and load the userFile*/
void readUserFile(string userPath, LinkedList<User> *listOfAllUsers, bool debugging)
{
    ifstream userFile;
    userFile.open(userPath);

    string currLine;
    string currentVal = "";
    int lineCount = 0;

    while (getline(userFile, currLine))
    {
        ++lineCount;
        string userName = "";
        string firstName = "";
        string lastName = "";
        bool shouldCreateUser = false;

        for (int i = 0; i < currLine.size(); ++i)
        {
            currentVal += currLine.at(i);
            if (currLine.at(i) == ' ')
            {
                if (userName == "")
                {
                    userName = currentVal.substr(0, currentVal.size() - 1);
                    User u;
                    u.setUsername(userName);

                    if (listOfAllUsers->isPresent(u))
                    {
                        cout << "User file " << userPath << " line " << lineCount << ": userid "
                             << userName << " exists - ignoring." << endl;
                        currentVal = "";
                        break;
                    }
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
                shouldCreateUser = true;
            }
        }
        if (shouldCreateUser)
        {
            User newUser(userName, firstName, lastName);
            listOfAllUsers->addNewNode(newUser);
        }
    }
    userFile.close();

    if (debugging)
    {
        listOfAllUsers->print();
    }
    cout << "Finished User Read" << endl;
}

/*Read and load the activityfile*/
void readActivityFile(string activityPath, LinkedList<Activity> *listOfAllActivities, LinkedList<Venue> *listOfAllVenues, LinkedList<User> *listOfAllUsers, bool debugging)
{

    ifstream ActivityFile;
    ActivityFile.open(activityPath);
    int lineCount = 0;
    string currLine = "";
    string currentVal = "";
    while (getline(ActivityFile, currLine))
    {
        ++lineCount;
        string activityTitle = "";
        string creator = "";
        Venue venue;
        string startTime = "";
        string startDate = "";
        string endTime = "";
        string endDate = "";
        string exclusive = "";
        bool shouldMakeNewActivity = false;

        for (int i = 0; i < currLine.size(); ++i)
        {

            currentVal += currLine.at(i);

            if (currLine.at(i) == ' ')
            {
                if (activityTitle == "")
                {
                    activityTitle = currentVal.substr(0, currentVal.size() - 1);
                    Activity a;
                    a.setTitle(activityTitle);
                    if (listOfAllActivities->isPresent(a))
                    {
                        cout << "Activity file " << activityPath << " line "
                             << lineCount << ": activity " << activityTitle << " exists - ignoring." << endl;

                        currentVal = "";
                        break;
                    }
                    currentVal = "";
                }
                else if (creator == "")
                {
                    creator = currentVal.substr(0, currentVal.size() - 1);
                    User x;
                    x.setUsername(creator);
                    if (!listOfAllUsers->isPresent(x))
                    {
                        cout << "Activity file " << activityPath << " line " << lineCount << ": user " << creator
                             << " does not exist - ignoring." << endl;
                        currentVal = "";
                        break;
                    }
                    currentVal = "";
                }
                else if (venue.getVenueName() == "")
                {
                    string venueName = currentVal.substr(0, currentVal.size() - 1);
                    // Check if venue exists
                    venue.setVenueName(venueName);
                    if (!listOfAllVenues->isPresent(venue))
                    {
                        currentVal = "";
                        break;
                    }
                    venue = *listOfAllVenues->getitem(venue);
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
                shouldMakeNewActivity = true;
            }
        }
        if (shouldMakeNewActivity)
        {
            Activity a(activityTitle, creator, &venue, startTime, startDate, endTime, endDate, exclusive);
            listOfAllActivities->addNewNode(a);
        }
    }
    ActivityFile.close();

    if (debugging)
    {
        listOfAllActivities->print();
    }
    cout << "Finished Activity Read" << endl;
}

void readAttendanceFile(string attendancePath, LinkedList<Activity> *listOfAllActivities, LinkedList<User> *listOfAllUsers, bool debugging)
{
    ifstream attFile;
    attFile.open(attendancePath);

    Node<Activity> *currNode = listOfAllActivities->getFirstNode();
    for (int i = 0; i < listOfAllActivities->getNElements(); ++i)
    {
        currNode = currNode->next;
    }

    int lineCount = 0;
    string currLine = "";
    string currentVal = "";

    while (getline(attFile, currLine))
    {
        ++lineCount;
        string activityTitle = "";
        string userID = "";
        // Parse through line
        for (int i = 0; i < currLine.size(); ++i)
        {
            currentVal += currLine.at(i);
            if (currLine.at(i) == ' ')
            { // Activity title has been found
                if (activityTitle == "")
                {
                    activityTitle = currentVal.substr(0, currentVal.size() - 1);
                    currentVal = "";
                }
            }
        }
        userID = currentVal;
        currentVal = "";

        User u(userID);

        Activity a;
        a.setTitle(activityTitle);

        if (listOfAllActivities->isPresent(a))
        {
            Activity *activityToAdd = listOfAllActivities->getitem(a);

            if (listOfAllUsers->isPresent(u))
            {
                User *currentUser = listOfAllUsers->getitem(u);
                currentUser->addActivityToUser(activityToAdd, lineCount, attendancePath);
            }
        }
    }

    attFile.close();
    cout << "Finished Attendance Read" << endl;
}

// Output new files

// Write new ActivityFile
void writeActivityFile(LinkedList<Activity> *listOfAllActivities, string inputFilePath, bool debugging)
{
    ofstream activityOut;
    string newFileName = outputLocation + getFileRealName(inputFilePath);
    newFileName = newFileName.replace(newFileName.size() - 3, newFileName.size(), "");
    if (debugging)
        cout << newFileName << endl;
    newFileName += "cp3out.txt";

    activityOut.open(newFileName);

    Node<Activity> *currNode = listOfAllActivities->getFirstNode();
    for (int i = 0; i < listOfAllActivities->getNElements(); ++i)
    {
        activityOut << currNode->data.getOutput();
        currNode = currNode->next;
    }

    activityOut.close();
}

// Write new VenueFile
void writeVenueFile(LinkedList<Venue> *listOfAllVenues, string inputFilePath, bool debugging)
{
    ofstream venueOut;
    string newFileName = outputLocation + getFileRealName(inputFilePath);
    newFileName = newFileName.replace(newFileName.size() - 3, newFileName.size(), "");
    if (debugging)
        cout << newFileName << endl;
    newFileName += "cp3out.txt";

    venueOut.open(newFileName);
    Node<Venue> *currNode = listOfAllVenues->getFirstNode();
    for (int i = 0; i < listOfAllVenues->getNElements(); ++i)
    {
        venueOut << currNode->data.getOutput();
        currNode = currNode->next;
    }

    venueOut.close();
}

// Write new UserFile
void writeUserFile(LinkedList<User> *listOfAllUsers, string inputFilePath, bool debugging)
{
    ofstream userOut;
    string newFileName = outputLocation + getFileRealName(inputFilePath);
    newFileName = newFileName.replace(newFileName.size() - 3, newFileName.size(), "");
    if (debugging)
        cout << newFileName << endl;
    newFileName += "cp3out.txt";

    userOut.open(newFileName);
    Node<User> *currNode = listOfAllUsers->getFirstNode();
    for (int i = 0; i < listOfAllUsers->getNElements(); ++i)
    {
        userOut << currNode->data.getOutput();
        currNode = currNode->next;
    }

    userOut.close();
}

// Write new AttendanceFile
void writeAttendanceFile(LinkedList<User> *listOfAllUsers, string inputFilePath, bool debugging)
{
    ofstream attOut;
    string newFileName = outputLocation + getFileRealName(inputFilePath);
    newFileName = newFileName.replace(newFileName.size() - 3, newFileName.size(), "");
    if (debugging)
        cout << newFileName << endl;
    newFileName += "cp3out.txt";
    attOut.open(newFileName);

    Node<User> *currNode = listOfAllUsers->getFirstNode();
    for (int i = 0; i < listOfAllUsers->getNElements(); ++i)
    {
        attOut << currNode->data.getAttendanceDump();
        currNode = currNode->next;
    }

    attOut.close();
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

    // Read files in

    // Deal with venuesFirst
    readVenueFile(venuePath, listOfAllVenues, debugging);
    if (debugging)
        cout << "Venue Read Done" << endl;
    // Deal with list of users
    readUserFile(userPath, listOfAllUsers, debugging);
    if (debugging)
        cout << "User Read Done" << endl;
    // Deal with list of activities
    readActivityFile(activityPath, listOfAllActivities, listOfAllVenues, listOfAllUsers, debugging);
    if (debugging)
        cout << "Activity Read Done" << endl;
    // Deal with attendance list
    readAttendanceFile(attendancePath, listOfAllActivities, listOfAllUsers, debugging);
    if (debugging)
        cout << "Attendance Read Done" << endl;

    // Write files out
    writeVenueFile(listOfAllVenues, venuePath, debugging);
    if (debugging)
        cout << "Venue Write Done" << endl;
    writeUserFile(listOfAllUsers, userPath, debugging);
    if (debugging)
        cout << "User Write Done" << endl;
    writeActivityFile(listOfAllActivities, activityPath, debugging);
    if (debugging)
        cout << "Activity Write Done" << endl;
    writeAttendanceFile(listOfAllUsers, attendancePath, debugging);
    if (debugging)
        cout << "Attendance Write Done" << endl;

    return 0;
}