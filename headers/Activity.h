#ifndef ACTIVITY_H
#define ACTIVITY_H

#include "Time.h"
#include "Venue.h"
#include "LinkedList.h"

using namespace std;

class Activity
{
private:
    string activityTitle;
    string creator;
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
             string creator,
             string venue,
             string startTime,
             string startDate,
             string endTime,
             string endDate,
             string exclusive);

Activity(string activityTitle,
             string creator,
             Venue *venue,
             string startTime,
             string startDate,
             string endTime,
             string endDate,
             string exclusive);

    Activity(string activityTitle,
             string creator,
             Venue venue,
             Time startTime,
             Time endTime,
             bool exclusive);

    string getTitle() { return this->activityTitle; }
    string getCreator() { return this->creator; }
    Venue getVenue() { return this->venue; }
    bool isExclusive() { return exclusive; }

    void setTitle(string activityTitle) { this->activityTitle = activityTitle; }

    bool checkIfActivityConflicts(Activity *activityToCheck, LinkedList<Activity> *listOfAllActivities, int currentLine, string activityPath);

    Time getStartTime() { return startTime; }
    Time getEndTime() { return endTime; }

    void print();

    bool operator==(const Activity& other);

    string getOutput();
};
#endif