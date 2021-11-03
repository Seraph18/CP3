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
    int currentCapacity;
    string location;

public:
    Venue();
    Venue(string name);
    Venue(string venueName, string location, int capacity);
    //~Venue();

    string getVenueName() { return venueName; }
    string getVenueLocation() { return location; }

    int getVenueCurrentCapacity() { return currentCapacity; }
    int getVenueCapacity() { return capacity; }

    void setVenueName(string venueName) { this->venueName = venueName; }

    void print();

    void increaseCurrentCapacity() { ++this->currentCapacity; }

    bool operator==(const Venue& other);

    string getOutput();
};
#endif