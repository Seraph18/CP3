#include "Activity.h"
#include "LinkedList.cpp"

Activity::Activity()
{
    this->activityTitle = "";
    this->creator = "";
    this->venue = nullptr;
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
    this->venue->setVenueName(venue);
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
    this->venue = venue;
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

bool Activity::checkIfActivityConflicts(LinkedList<Activity> &listOfAllActivities, int currentLine, string activityPath)
{
    bool originalIsExclusive = this->isExclusive();
    Node<Activity> *currNode = listOfAllActivities.getFirstNode();

    for (int i = 0; i < listOfAllActivities.getNElements(); ++i)
    {
        if (this->venue == currNode->data.getVenue())
        {
            if (this->startTime < currNode->data.startTime && currNode->data.endTime < this->endTime)
            {
                if (currNode->data.isExclusive() || originalIsExclusive)
                {
                    cout << "Activity file " << activityPath << " line " << currentLine
                         << ": Activity " << this->getTitle() << " would conflict with "
                         << currNode->data.getTitle() << " - ignoring." << endl;

                    return true;
                }
            }
            else if (currNode->data.startTime < this->startTime && this->startTime < currNode->data.endTime)
            {
                if (currNode->data.isExclusive() || originalIsExclusive)
                {
                    cout << "Activity file " << activityPath << "line " << currentLine
                         << ": Activity " << this->getTitle() << " would conflict with "
                         << currNode->data.getTitle() << " - ignoring." << endl;

                    return true;
                }
            }
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
    cout << "@ [" << venue->getVenueName() << "]" << endl;
}

bool Activity::operator==(const Activity &other)
{
    if (this->activityTitle == other.activityTitle)
    {
        return true;
    }
    return false;
}

void Activity::addParticipant(){
    this->venue->increaseCurrentCapacity();
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
    total += this->getVenue()->getVenueName() + " ";

    if (this->exclusive)
        total += "y";
    else
        total += "n";

    total += "\n";
    return total;
}