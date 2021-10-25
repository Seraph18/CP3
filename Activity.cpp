#include "Activity.h"

Activity::Activity()
{
    this->activityTitle = "";
    this->creator = "";
    this->venue = "";
    this->exclusive = true;
}

Activity::Activity(string activityTitle, string creator, string venue, bool exclusive)
{
    this->activityTitle = activityTitle;
    this->creator = creator;
    this->venue = venue;
    this->exclusive = exclusive;
}

void Activity::print()
{
    cout << "Title: " << this->activityTitle << " Creator: " \
    << creator << " Venue: " << venue << endl;
}