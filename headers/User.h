#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>
#include "LinkedList.h"
#include "Activity.h"

using namespace std;

class User
{
private:
    string userName;
    string firstName;
    string lastName;

    LinkedList<Activity> listOfUserActivities;

public:
    User();
    User(string name);
    User(string userName, string firstName, string lastName);
    //~User();

    string getUserName() { return userName; }
    string getFirstName() { return firstName; }
    string getLastName() { return lastName; }

    void setUsername(string userName) { this->userName = userName; }
    void setFirstName(string firstName) { this->firstName = firstName; }
    void setLastName(string lastName) { this->lastName = lastName; }

    bool checkIfActivityConflicts(Activity *activityToCheck, int currentLine, string attendancePath);

    bool addActivityToUser(Activity *activityToAdd, int currentLine, string attendancePath);

    void print();

    LinkedList<Activity>* getListOfActivities() { return &listOfUserActivities; };

    bool operator==(const User &other);

    string getOutput();

    string getAttendanceDump();
};
#endif