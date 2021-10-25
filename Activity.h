#include <string>
#include <iostream>

using namespace std;

class Activity
{
private:
    string activityTitle;
    string creator;
    string venue;
    bool exclusive;

public:
    Activity();
    Activity(string activityTitle,
             string creator,
             string venue,
             bool exclusive);

    string getTitle() { return this->activityTitle; }
    string getCreator() { return this->creator; }
    string getVenue() { return this->venue; }
    bool isExclusive() { return exclusive; }

    void print();
};