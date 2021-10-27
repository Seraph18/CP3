#include "Venue.h"

Venue::Venue(){
    this->venueName = "";
    this->location = "";
    this->capacity = -1;
}

Venue::Venue(string venueName, string location, int capacity){
    this->venueName = venueName;
    this->location = location;
    this->capacity = capacity;
}

void Venue::print(){
    cout << "Venue Name : " << venueName << " Location: " << location << " Max Capacity: " << capacity << endl;
}
