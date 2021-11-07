#include "Venue.h"

Venue::Venue(){
    this->venueName = "";
    this->location = "";
    this->capacity = -1;
    this->currentCapacity = 0;
}

Venue::Venue(string name){
    this->venueName = name;
    this->location = "";
    this->capacity = -1;
    this->currentCapacity = 0;
}

Venue::Venue(string venueName, string location, int capacity){
    this->venueName = venueName;
    this->location = location;
    this->capacity = capacity;
    this->currentCapacity = 0;
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

string Venue::getOutput(){
    string total = "";

    total += this->getVenueName() + " ";
    total += to_string(this->getVenueCapacity()) + " ";
    total += this->getVenueLocation();
    total += "\n";

    return total;
}