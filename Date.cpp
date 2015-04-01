//-----------------------------------------------------------------------------
// Name: Date.cpp
// Description: Implementation of member functions for Date class (based on
//              Fig. 18.11 on pages 646-647)
//-----------------------------------------------------------------------------

#include <iostream>
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */
#include "Date.h" // include Date class definition
using namespace std;

// The defualt constructor sets date to the current date
//-------------------------------------------------------------
Date::Date()
{
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );

    year = now->tm_year + 1900;
    month = now->tm_mon + 1;
    day =  now->tm_mday;
} // end Date constructor


// constructor confirms proper value for month; calls
// the utility function isValidDate to confirm proper value for day;
// in case of an invalid date, the constructor uses the current date to
//to assign to the member variables year, month, day
//-------------------------------------------------------------
Date::Date( int mn, int dy, int yr )
{
    month = mn;
    year = yr;
    day = dy ;
    if(!isValidDate())
    {
        time_t t = time(0);   // get time now
        struct tm * now = localtime( & t );

        year = now->tm_year + 1900;
        month = now->tm_mon + 1;
        day =  now->tm_mday;

    }
} // end Date constructor

// The Copy constructor
// Note that a validity check is not needed as the dateToCopyFrom must be a valid date
// since the object already exists
//-------------------------------------------------------------
Date::Date (const Date & dateToCopyFrom) // copy constructor
{
    month = dateToCopyFrom.month;
    day = dateToCopyFrom.day;
    year = dateToCopyFrom.year;
}

// The assignment operator
//-------------------------------------------------------------
Date & Date::operator = (const Date & other) // assignmenrt operator
{
    month = other.month;
    day = other.day;
    year = other.year;

    return *this;

}

// setDate date using user input
//-------------------------------------------------------------
void Date::setDate()
{
    bool flag = false;
    int mn,dy,yr;
    do
    {
        cout << "(month day year): ";
        cin >> mn >> dy >> yr;
        year = yr;
        month = mn;
        day = dy;

        if(yr < 1900)
        {
            cout << "Cannot handle dates prior to 1900 AD" << endl;
            cout << "Try again!" << endl;
            flag = false;
        }
        else if(!isValidDate())
        {
            cout << "Invalid date" << endl;
            cout << "Try again!" << endl;
            flag = false;
        }
        else
            flag = true;
    }

    while (!flag);

}


// print date  in month/day/year format
//-------------------------------------------------------------
void Date::print() const
{
    std::cout << month << '/' << day << '/' << year;
} // end function print

// A dummy detructor
//-------------------------------------------------------------
Date::~Date()
{
} // end ~Date destructor

// The greater operator
// It allows you to check which date is earlier between two dates
//-------------------------------------------------------------
bool Date::operator>(const Date &dateOnRight) // greater than operator
{
    bool greater;

    if(dateOnRight.getYear() > year)
        greater = false;

    else if(dateOnRight.getYear() == year && dateOnRight.getMonth() > month)
        greater = false;

    else if(dateOnRight.getYear() == year && dateOnRight.getMonth() == month && dateOnRight.getDay() >= day)
        greater = false;
    else
        greater = true;

    return greater;

}
// add one year to date
//-------------------------------------------------------------
void Date::addYears(int nyears)
{
    year = year + nyears;
    if (day == 29 && month == 2 && !isLeapYear(year))
    {
        day = 28;
    }

}

// returnsa boolean output to indicate whether the date belongs to a leap year
//-------------------------------------------------------------
bool Date::isLeapYear(int year)
{
    bool leapYear = false;
    if (year % 400 == 0)
    {
        leapYear = true;
    }
    else
    {
        if (year % 100 == 0)
        {
            leapYear = false;
        }
        else
        {
            if (year % 4 == 0)
                leapYear = true;
            else
                leapYear = false;
        }
    }
    // cout << "leapYear  " << leapYear << endl;
    return leapYear;

}

// Check whether a date is a valid one
// it is an utility function
// the validity is checked everytime a date is constructed or it is modified
//-------------------------------------------------------------
bool Date::isValidDate()
{
    bool validDate;
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(month < 1 || month > 12
            || day < 0 || !((isLeapYear(year) && month == 2 && day <= 29)
                            || (day <= monthDays[month - 1])))
        validDate = false;
    else
        validDate = true;

    // cout << "validDate  " << validDate << endl;
    return validDate;
}

