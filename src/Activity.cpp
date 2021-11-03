#include "Activity.h"
#include "LinkedList.cpp"

Activity::Activity()
{
    this->activityTitle = "";
    this->creator = "";
    this->venue.setVenueName("");
    this->exclusive = true;

    this->startTime.setDateAndTime("00-00-0000", "00:00:00");
    this->endTime.setDateAndTime("00-00-0000", "00:00:00");
}

Activity::Activity(string activityTitle,
                   string creator,
                   string venue,
                   string startTime,
                   string startDate,
                   string endTime,
                   string endDate,
                   string exclusive)
{
    this->activityTitle = activityTitle;
    this->creator = creator;
    this->venue.setVenueName(venue);
    this->startTime.setDateAndTime(startDate, startTime);
    this->endTime.setDateAndTime(endDate, endTime);

    if (exclusive == "y")
    {
        this->exclusive = true;
    }
    else
    {
        this->exclusive = false;
    }
}

Activity::Activity(string activityTitle,
                   string creator,
                   Venue *venue,
                   string startTime,
                   string startDate,
                   string endTime,
                   string endDate,
                   string exclusive)
{
    this->activityTitle = activityTitle;
    this->creator = creator;
    this->venue = *venue;
    this->startTime.setDateAndTime(startDate, startTime);
    this->endTime.setDateAndTime(endDate, endTime);

    if (exclusive == "y")
    {
        this->exclusive = true;
    }
    else
    {
        this->exclusive = false;
    }
}

// Object specialized constructor
Activity::Activity(string activityTitle, string creator, Venue venue, Time startTime, Time endTime, bool exclusive)
{
    this->activityTitle = activityTitle;
    this->creator = creator;
    this->venue = venue;
    this->startTime = startTime;
    this->endTime = endTime;
    this->exclusive = exclusive;
}

bool Activity::checkIfActivityConflicts(Activity *activityToCheck, LinkedList<Activity> *listOfAllActivities, int currentLine, string activityPath)
{
    Node<Activity> *currNode = listOfAllActivities->getFirstNode();

    for (int i = 0; i < listOfAllActivities->getNElements(); ++i)
    {
        if (currNode->data.startTime < activityToCheck->startTime && activityToCheck->startTime < currNode->data.endTime)
        {
            cout << "Activity file " << activityPath << "line " << currentLine
                 << ": Activity " << activityToCheck->getTitle() << " would conflict with "
                 << currNode->data.getTitle() << " - ignoring." << endl;

            return true;
        }
        else if (activityToCheck->startTime < currNode->data.startTime && currNode->data.startTime < activityToCheck->endTime)
        {
            cout << "Activity file " << activityPath << "line " << currentLine
                 << ": Activity " << activityToCheck->getTitle() << " would conflict with "
                 << currNode->data.getTitle() << " - ignoring." << endl;

            return true;
        }
    }
    return false;
}

void Activity::print()
{
    cout << activityTitle << ": ";
    cout << "Creator: " << creator << " ";
    cout << "Begins: [" << startTime.getTime() << ", " << startTime.getDate() << "] ";
    cout << "Ends: [" << endTime.getTime() << ", " << endTime.getDate() << "] ";
    cout << "@ [" << venue.getVenueName() << "]" << endl;
}

bool Activity::operator==(const Activity &other)
{
    if (this->activityTitle == other.activityTitle)
    {
        return true;
    }
    return false;
}

string Activity::getOutput()
{
    string total = "";
    total += this->getTitle() + " ";
    total += this->creator + " ";
    total += this->getStartTime().getTime() + " ";
    total += this->getStartTime().getDate() + " ";
    total += this->getEndTime().getTime() + " ";
    total += this->getEndTime().getDate() + " ";
    total += this->getVenue().getVenueName() + " ";

    if (this->exclusive)
        total += "y";
    else
        total += "n";

    total += "\n";
    return total;
}