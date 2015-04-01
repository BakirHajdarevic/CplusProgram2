#include<iostream>
#include<string>
#include<math.h>

#include "Date.h"
#include "AccidentList.h"
#include "PersonalRec.h"
#include "CarInsuranceAccountRec.h"

/*** Global variables ***/
extern Date currentDate;

CarInsuranceAccountRec::CarInsuranceAccountRec(std::string FirstName, std::string LastName, Date DoB) 
    : PersonalRec(FirstName, LastName, DoB)
{     
    
    CarInsuranceAccountRec::set_accDateOfOpening(currentDate);
    CarInsuranceAccountRec::set_accDateOfExpiry(currentDate);
    CarInsuranceAccountRec::set_accRenewalCost(FLAT_RATE);
    //Indicates if new account created
    std::cout << "A new account object constructed" << std::endl;
    //displays account information
    CarInsuranceAccountRec::displayAccountInformation();
}
/*** TODO: Implement all member functions under the class "CarInsuranceAccountRec" ****/
void CarInsuranceAccountRec::set_accDateOfOpening(Date accDateOfOpening)
{
    m_accDateOfOpening = accDateOfOpening;
}
void CarInsuranceAccountRec::set_accDateOfExpiry(Date accDateOfExpiry)
{
    //adds one year to current date to create new expiration date
    accDateOfExpiry.addYears(1);
    m_accDateOfExpiry = accDateOfExpiry;
}
void CarInsuranceAccountRec::set_accRenewalCost(int accRenewalCost)
{
    m_accRenewalCost = accRenewalCost;
}
void CarInsuranceAccountRec::renewInsurance()
{
    //returns the renewal status of the account
    int status = CarInsuranceAccountRec::checkValidityRenewal();
    double cost = 0;

    if (status = 3)//account is renewable
    {
        cost = CarInsuranceAccountRec::findRenewalCost();
        CarInsuranceAccountRec::set_accDateOfExpiry(currentDate);
        CarInsuranceAccountRec::set_accRenewalCost(cost);
        std::cout <<"Cost to renew: " << cost << std::endl; 

        m_accDateOfExpiry.print();
        std::cout << std::endl;
    }
    else if(status = 1)//account is renewable but currently expired
    {
        cost = CarInsuranceAccountRec::findRenewalCost() + 125;
        CarInsuranceAccountRec::set_accDateOfExpiry(currentDate);
        CarInsuranceAccountRec::set_accRenewalCost(cost);

        m_accDateOfExpiry.print();  
    }
    
}
void CarInsuranceAccountRec::displayRenewalCost()
{
    //returns the renewal status of the account holder
    int status = CarInsuranceAccountRec::checkValidityRenewal();

    if(status == 1 || status == 3)//account is renewable
    {
        std::cout<< "Renewal cost is " << findRenewalCost() << std::endl;
    }
    else//renewal not possible
    {
        std::cout << "Renewal is not allowed" << std::endl;
    }
}
void CarInsuranceAccountRec::displayAccountInformation()
{
    //displays the date of opening
    PersonalRec::displayPersonalRec();
    std::cout<< "Date of opening: ";
    std::cout<< std::endl;

    m_accDateOfOpening.print();
    std::cout<< std::endl;
    //displays expiration date
    std::cout <<"Date of expiration: ";
    std::cout<< std::endl;

    m_accDateOfExpiry.print();
    std::cout<< std::endl;
    //displays current date
    std::cout <<"Current date: ";
    std::cout<< std::endl;

    currentDate.print();
    std::cout<< std::endl;
    //displays any accident record
    m_accAccidentRecord.update();
    m_accAccidentRecord.print();
    std::cout<< std::endl;
}
void CarInsuranceAccountRec::reportAccident()//accident report
{
    std::string description;
    double cost;
    //accident description
    std::cout << "Please describe the accident: " << std::endl;
    std::cin.ignore();
    std::getline(cin, description);
    //accident cost
    std::cout << "Please enter the cost of the accident: " << std::endl;
    std:cin >> cost;
    
    m_accAccidentRecord.add(description, cost);
}
void CarInsuranceAccountRec::updateAccidents()
{
    //updates accident history
    m_accAccidentRecord.update();
}
int CarInsuranceAccountRec::checkValidityRenewal()
{
    int d, m, y;
    int status;
    //gets current Date for day, month, year
    d = currentDate.getDay();
    m = currentDate.getMonth();
    y = currentDate.getYear();
    
    //check to see if account is renewable
    if(y > (m_accDateOfExpiry.getYear()+1))
    {
        std::cout <<"It is not allowed to be renewed"<<std::endl;
        status = 2;
    }
    else if(y > m_accDateOfExpiry.getYear())
    {
        std::cout <<"Account is expired"<< std::endl;
        std::cout <<"It can be renewed for $125"<<std::endl;
        status = 1;
    }
    else if (m > m_accDateOfExpiry.getMonth())
    {
        std::cout <<"Account is expired"<< std::endl;
        std::cout <<"It can be renewed for $125"<<std::endl;
        status = 1;
    }
    else if (d > m_accDateOfExpiry.getDay()) 
    {
        std::cout <<"Account is expired"<< std::endl;
        std::cout <<"It can be renewed for $125"<<std::endl;
        status = 1;
    }
    else
    {
        status = 3;
    }    
    return status;
}
//computes the cost of renewal 
double CarInsuranceAccountRec::findRenewalCost()
{
    int age;
    age = PersonalRec::getAgeInYears();
    float flatrate = 0;

    m_accAccidentRecord.update();
    if(age > 30)
    {
       flatrate = m_accRenewalCost - (m_accRenewalCost*0.06);
    }
    else if(age < 30)
    {
        flatrate = m_accRenewalCost - (m_accRenewalCost*0.04);
    }

    flatrate = flatrate + m_accAccidentRecord.getTotalAccidentCost();
    return flatrate;//returns cost of renewal
}





