#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>
#include <string.h>
#include <iostream>
#include "Time.h"
#include "User.h"
#include "Venue.h"

using namespace std;

class Activity
{
private:
    string activityTitle;
    User creator;
    Venue venue;
    bool exclusive;

    Time startTime;
    Time endTime;

public:
    Activity();
    Activity(string activityTitle,
             string creator,
             string venue, 
             Time startTime, 
             Time endTime,
             bool exclusive);
    Activity(string activityTitle,
             User creator,
             Venue venue, 
             Time startTime, 
             Time endTime,
             bool exclusive);

    string getTitle() { return this->activityTitle; }
    User getCreator() { return this->creator; }
    Venue getVenue() { return this->venue; }
    bool isExclusive() { return exclusive; }

    Time getStartTime() { return startTime; }
    Time getEndTime() { return endTime; }

    void print();
};
#endif