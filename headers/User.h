#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>

using namespace std;

class User
{
private:
    string userName;
    string firstName;
    string lastName;

public:
    User();
    User(string userName, string firstName, string lastName)
    {
        this->userName = userName;
        this->firstName = firstName;
        this->lastName = lastName;
    }
    //~User();

    string getUserName() { return userName; }
    string getFirstName() { return firstName; }
    string getLastName() { return lastName; }

    void setUsername(string userName) { this->userName = userName; }

    void print();

    bool operator==(const User &other);
};
#endif