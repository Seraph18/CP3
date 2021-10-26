#include "Activity.h"

Activity::Activity()
{
    this->activityTitle = "";
    this->creator = "";
    this->venue = "";
    this->exclusive = true;

    this->startTime.setDateAndTime("00-00-0000", "00:00:00");
    this->endTime.setDateAndTime("00-00-0000", "00:00:00");
}

Activity::Activity(string activityTitle, string creator, string venue, Time startTime, Time endTime, bool exclusive)
{
    this->activityTitle = activityTitle;
    this->creator = creator;
    this->venue = venue;
    this->startTime = startTime;
    this->endTime = endTime;
    this->exclusive = exclusive;
}

void Activity::print()
{
    cout << activityTitle << ": ";
    cout << "Creator: " << creator << " ";
    cout << "Begins: [" << startTime.getTime() << " " << startTime.getDate() << "] ";
    cout << "Ends: [" << endTime.getTime() << " " << endTime.getDate() << "] ";
    cout << "@ [" << venue << "] " << endl;
}