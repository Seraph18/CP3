#include "User.h"

User::User(){
    this->userName = "";
    listOfActivities = new NodeHeader<Activity>();
}

User::User(string userName){
    this->userName = userName;
    this->listOfActivities = new NodeHeader<Activity>();
}