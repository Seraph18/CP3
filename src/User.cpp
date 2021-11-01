#include "User.h"

User::User(){
    this->userName = "";
    this->firstName = "";
    this->lastName = "";
}

void User::print(){
    cout << "Username: " << userName << " Real-Name: " << firstName << " " << lastName << endl;
}


bool User::operator==(const User& other){
    if(this->getUserName() == other.userName){
        return true;
    }
    return false;
}
