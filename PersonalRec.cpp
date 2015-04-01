#include<iostream>
#include<string>
#include<math.h>

#include "Date.h"
#include "PersonalRec.h"

/*** Global variables ***/
extern Date currentDate;

/*** TODO: implement all addiotional member functions under the class "PersonalRec" including the constructor****/

PersonalRec::PersonalRec(std::string firstName, std::string lastName, Date DoB)
{
    //Takes in personal information from main.cpp
    m_FirstName = firstName;
    m_LastName = lastName;
    m_DoB = DoB;

}

void PersonalRec::displayPersonalRec() const
{
    //display personal account full name and DoB
    std::cout << "First name: " << m_FirstName << std::endl;
    std::cout << "Last name: "<< m_LastName << std::endl;
    std::cout << "Date of Birth: ";
    m_DoB.print();
    std::cout<< std::endl;
}

//Returns the age of the account holder
int PersonalRec::getAgeInYears() const{
    int age, year;
    int day = currentDate.getDay();
    int month = currentDate.getMonth();
    year = currentDate.getYear();
    
    if((month > m_DoB.getMonth()) || (month == m_DoB.getMonth() && day > m_DoB.getDay()))
    {
        age = year - m_DoB.getYear();
    }
    else{
        age = year - m_DoB.getYear() - 1;
    }
    
    return age;
}


