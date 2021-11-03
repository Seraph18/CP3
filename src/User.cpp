#include "User.h"

User::User()
{
    this->userName = "";
    this->firstName = "";
    this->lastName = "";
}

User::User(string name){
    this->userName = name;
    this->firstName = "";
    this->lastName = "";
}

User::User(string userName, string firstName, string lastName)
    {
        this->userName = userName;
        this->firstName = firstName;
        this->lastName = lastName;
    }

// False if there is a time conflict, Ture if all good
bool User::checkIfActivityConflicts(Activity *activityToCheck, int currentLine, string attendancePath)
{
    Node<Activity> *currNode = this->getListOfActivities()->getFirstNode();

    for (int i = 0; i < this->getListOfActivities()->getNElements(); ++i)
    {
        if (currNode->data.getStartTime() < activityToCheck->getStartTime() && activityToCheck->getStartTime() < currNode->data.getEndTime())
        {
            cout << "Attendance file " << attendancePath << " line " << currentLine << ": \nUser " << this->getUserName() << " cannot attend " << activityToCheck->getTitle() << ": user is busy with " << currNode->data.getTitle() << " - ignoring." << endl;

            return false;
        }
        else if (activityToCheck->getStartTime() < currNode->data.getStartTime() && currNode->data.getStartTime() < activityToCheck->getEndTime())
        {
            cout << "Attendance file " << attendancePath << " line " << currentLine << ": \nUser " << this->getUserName() << " cannot attend " << activityToCheck->getTitle() << ": user is busy with " << currNode->data.getTitle() << " - ignoring." << endl;

            return false;
        }
    }
    return true;
}

bool User::addActivityToUser(Activity *activityToAdd, int currentLine, string attendancePath)
{
    Venue tempVenue = activityToAdd->getVenue();
    // Check if there is room in the venue
    if (tempVenue.getVenueCurrentCapacity() < tempVenue.getVenueCapacity())
    {
        // Check for possible time conflict
        if (!checkIfActivityConflicts(activityToAdd, currentLine, attendancePath))
        {
            return false;
        }
        this->listOfUserActivities.addNewNode(*activityToAdd);
        return true;
    }
    else
    {
        cout << "Attendance file " << attendancePath << "line " << currentLine << ": \nUser " << this->getUserName() << " cannot attend " << activityToAdd->getTitle() << ": venue is full - ignoring." << endl;

        return false;
    }
}

void User::print()
{
    cout << "Username: " << userName << " Real-Name: " << firstName << " " << lastName << endl;
}

bool User::operator==(const User &other)
{
    if (this->getUserName() == other.userName)
    {
        return true;
    }
    return false;
}

string User::getOutput()
{
    string total = "";

    total += this->getUserName() + " ";
    total += this->getFirstName() + " ";
    total += this->getLastName() + " ";
    total += "\n";

    return total;
}

string User::getAttendanceDump()
{
    string total = "";

    Node<Activity> *currNode = listOfUserActivities.getFirstNode();

    for (int i = 0; i < listOfUserActivities.getNElements(); ++i)
    {

        total += currNode->data.getTitle() + " ";
        total += this->userName;
        total += "\n";

        currNode = currNode->next;
    }
    return total;
}
