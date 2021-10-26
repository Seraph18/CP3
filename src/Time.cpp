#include "Time.h"

using namespace std;

Time::Time(string time, string date){
    if(timeValid(time)){
        this->time = time;
    }
    if(dateValid(date)){
        this->date = date;
    }
}

Time::Time(){
    this->time = "";
    this->date = "";
}

bool Time::dateValid(string date){ //MM-DD-YYYY
    int dashCount = 0;
    
    if (date.length() > 10 || date.length() < 8) //Length Test
    { 
        return false;
    }
    //Longer check
    for (int i = 0; i < date.length() - 1; ++i)
    { //Check to make sure dashes are there
        if (date.substr(i, 1) == "-")
        {
            ++dashCount;
        }
        if (dashCount > 2)
        {
            return false;
        }
    }
    return true;
}

bool Time::timeValid(string time) //MM:HH:SS
{
    int colonCount = 0;

    //Length Test
    if (time.length() != 8)
    {
        return false;
    }

    //Colon test
    if(time.substr(2, 1) != ":" || time.substr(5, 1) != ":"){
        return false;
    }

    return true;
}

void Time::setTime(string time){ //HH:MM:SS
    this->time = time;
    this->hour = stoi(time.substr(0, 2));
    this->minute = stoi(time.substr(3, 2));
    this->second = stoi(time.substr(6, 2));

    //Load into array
    this->dateAndTimeArr[3] = hour;
    this->dateAndTimeArr[4] = minute;
    this->dateAndTimeArr[5] = second;
}

void Time::setDate(string date){ //MM-DD-YYYY
    this->date = date;
    this->month = stoi(date.substr(0, 2));
    this->day = stoi(date.substr(3, 2));
    this->year = stoi(date.substr(6, 4));

    //Load into array
    this->dateAndTimeArr[0] = month;
    this->dateAndTimeArr[1] = day;
    this->dateAndTimeArr[2] = year;
}

void Time::setDateAndTime(string date, string time){
    this->setDate(date);
    this->setTime(time);
}

string Time::getTime(){return this->time;}
string Time::getDate(){return this->date;}