#ifndef PersonalRec_H
#define PersonalRec_H
#include<string>
#include "Date.h"

using namespace std;

class PersonalRec
{
public:
    /*TODO: Prototype for public methods*/    
    PersonalRec ();
    PersonalRec (std::string firstName, std::string lastName, Date DoB);
protected:
    /*TODO: Prototype for protected methods*/
    void displayPersonalRec() const;
    int getAgeInYears() const;


private:
	/*TODO: Declaration of private data members*/
    
    string m_FirstName; 
    string m_LastName; 
    Date m_DoB;
};

#endif



