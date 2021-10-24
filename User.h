#include <string>
#include <string.h>
#include "NodeHeader.h"
#include "Activity.h"

using namespace std;

class User
{
public:
    User();
    User(string userName);
    
    string getName() { return userName; }
    void setName(string newName) { this->userName = newName; }

private:
    string userName;
    NodeHeader<Activity> *listOfActivities;
};
