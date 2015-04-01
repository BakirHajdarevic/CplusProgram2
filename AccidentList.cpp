#include<iostream>
#include<string>
#include<math.h>
using namespace std;

#include "Date.h"
#include "AccidentList.h"

/*** Global variables ***/
extern Date currentDate;

// Destructor
//-------------------------------------------------
AccidentList::~AccidentList()
{
    myAccidents.clear(); //clear myAccidents
}// end destructor

// Print all actuve accident records
//-------------------------------------------------
void AccidentList::print()
{
    vector<IndividualAccidentRecord>::iterator it;
    int i = 1;
    for (it = myAccidents.begin(); it != myAccidents.end(); it++)
    {
        cout << "\nAccident No.  " << i << endl;
        cout << "   Accident description: " << it->descriptionOfAccident << endl;
        cout << "   Accident Date:";
        it->dateOfAccident.print();
        cout<< endl;
        cout << "   Accident Cost: " << it->costOfAccident << endl;
        i++;
    }
}//end function print

// add a new accident
//-------------------------------------------------
void AccidentList::add(string description, double cost)
{
    IndividualAccidentRecord newAccidentRecord; //pointer to new node

    newAccidentRecord.descriptionOfAccident = description;
    newAccidentRecord.costOfAccident = cost;
    newAccidentRecord.dateOfAccident = currentDate;

    myAccidents.push_back(newAccidentRecord); // add to end

}/* end function add */



// return the number of active accidents
//-------------------------------------------------
int AccidentList::count() const
{
    return myAccidents.size();
}//end count

// utility member function
//return true if there is no accident ; otherwise, returns false
//-------------------------------------------------
bool AccidentList::isNoAccident() const
{
    return myAccidents.size() == 0;
}//end function isEmpty


// updates the record of accidents; all accidents older than 3 years or more are dropped
//-------------------------------------------------
void AccidentList::update()
{
    vector<IndividualAccidentRecord>::iterator it;
    int flag = 1;
    while (flag)
    {
        flag = 0;
        for (it = myAccidents.begin(); !(myAccidents.empty()) && it != myAccidents.end(); it++)
        {
            Date tDate = it->dateOfAccident;
            tDate.addYears(3);
            if(currentDate > tDate)
            {
                myAccidents.erase(it);
                flag = 1;
            }
        }
    }
}/*end function update*/

// compute the part of the renewal cost incurred from total accident recods
//-------------------------------------------------
double AccidentList::getTotalAccidentCost()
{
    double totalAccidentCost = 0;  // initialize totalAccidentCost

// construct the iterator it to traverse the accident record myAccidents
    vector<IndividualAccidentRecord>::iterator it;

// traverse the accident record myAccidents using iterator it
    for (it = myAccidents.begin(); it != myAccidents.end(); it++)
    {
        if (it->costOfAccident > 5000)
            totalAccidentCost = totalAccidentCost + 50; // add $50 for a severe accident
        else if (it->costOfAccident > 1000)
            totalAccidentCost =totalAccidentCost + 20; // add $20 for a severe accident
    }
    return totalAccidentCost; // return the total accident cost

}

