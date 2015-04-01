#include<iostream>
#include<string>
#include <vector>
#include<math.h>

#ifndef ACCIDENT_H
#define ACCIDENT_H

using namespace std;

/* data structure to keep records of an individual accident*/
struct individualAccidentRecord
{
    string descriptionOfAccident;
    Date dateOfAccident;
    double costOfAccident;
}; /* end structure individualAccidentRecord */
typedef struct individualAccidentRecord IndividualAccidentRecord;


class AccidentList
{
public:
    //print all active accident records
    void print()  ;

    // add a new accident
    void add(string description, double cost);

    // compute the number of active accidents
    int count() const;

    // update the record of accidents
    // drop all accidents 3 years or more old
    void update();

    // compute the part of the renewal cost incurred from  accident records
    double getTotalAccidentCost()  ;

    //the destructor
    // clear myAccidents
    ~AccidentList();
private:
    bool isNoAccident() const ;
    vector <IndividualAccidentRecord> myAccidents;
};

#endif



