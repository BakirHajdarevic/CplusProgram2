//-----------------------------------------------------------------------------
// Name: Date.h
// Description: Header file for Date class. This class represents a date
//              (day, month, year). It is based on Fig. 18.10 on page 646.
//-----------------------------------------------------------------------------
#ifndef DATE_H
#define DATE_H

class Date
{
public:
    static const int monthsPerYear = 12; // number of months in a year
    Date (); // default constructor
    Date (int mn, int dy, int yr); // constructor
    Date (const Date& dateToCopyFrom); // copy constructor
    Date & operator = (const Date & other); // assignment operator
    void setDate ();  // sets date using user input
    int getYear() const // returns the year
    {
        return(year);
    };
    int getMonth() const // returns the month
    {
        return (month);
    };
    int getDay() const  // returns the date
    {
        return (day);
    };
    void print() const; // print date in month/day/year format
    bool operator>(const Date &dateOnRight);  //The '>' operator
                                              // It allows you to check which date is earlier between two dates
    void addYears(int nyears);  // add one year to date

    ~Date(); // the destructor
private:
    int month; // 1-12 (January-December)
    int day; // 1-31 based on month
    int year; // any year

    // utility member function to check if day is proper for month and year
    bool isLeapYear(int year); // checks whether the date belongs to a leap year
    bool isValidDate(); // checks whether the date is valid
};


#endif
