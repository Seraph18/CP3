#ifndef VENUE_H
#define VENUE_H
#include <string>
#include <iostream>

using namespace std;

class Venue
{
private:
    string venueName;
    int capacity;
    string location;

public:
    Venue();
    Venue(string venueName, string location, int capacity);
    //~Venue();

    string getVenueName() { return venueName; }
    string getVenueLocation() { return location; }
    int getVenueCapacity() { return capacity; }

    void setVenueName(string venueName) { this->venueName = venueName; }

    void print();
};
#endif