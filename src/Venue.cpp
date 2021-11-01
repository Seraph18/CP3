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
    cout << "Venue Name: " << this->getVenueName() << " Location: " << this->getVenueLocation() << " Max-Capacity: " << this->getVenueCapacity() << endl;
}

bool Venue::operator==(const Venue& other){
    if(this->venueName == other.venueName){
        return true;
    }
    return false;
}
