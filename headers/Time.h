#ifndef TIME_H
#define TIME_H
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

class Time{
    public:
        Time(string time, string date);
        Time();

        bool dateValid(string date);
        bool timeValid(string time);

        void setTime(string time);
        void setDate(string date);
        void setDateAndTime(string date, string time);

        string getTime();
        string getDate();

        int getMonths(){return month;}
        int getDays(){return day;}
        int getYears(){return year;}

        int getHours(){return hour;}
        int getMinutes(){return minute;}
        int getSeconds(){return second;}

        int getValueFromTimeArr(int i){return dateAndTimeArr[i];}

        bool operator<(const Time& timeToCompare); //Check if the current time comes before

    private:
        string date;
        string time;

        int month;
        int day;
        int year;

        int hour;
        int minute;
        int second;

        int dateAndTimeArr[6];

};
#endif