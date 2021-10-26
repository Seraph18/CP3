#include <string>
#include <iostream>
#include "Time.h"

using namespace std;

class Activity
{
private:
    string activityTitle;
    string creator;
    string venue;
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

    string getTitle() { return this->activityTitle; }
    string getCreator() { return this->creator; }
    string getVenue() { return this->venue; }
    bool isExclusive() { return exclusive; }

    Time getStartTime() { return startTime; }
    Time getEndTime() { return endTime; }

    void print();
};