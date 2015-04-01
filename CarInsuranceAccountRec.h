#ifndef INSURANCE_H
#define INSURANCE_H

#include "PersonalRec.h"
#include "Date.h"
#include "AccidentList.h"

class CarInsuranceAccountRec : public PersonalRec
{

public:
    /*TODO: Prototype for public member functions*/
    CarInsuranceAccountRec();
    CarInsuranceAccountRec(std::string FirstName, std::string LastName, Date DoB);

    void set_accDateOfOpening(Date accDateOfOpening);
    void set_accDateOfExpiry(Date accDateOfExpiry);
    void set_accRenewalCost(int accRenewalCost);

    void renewInsurance();
    void displayRenewalCost();
    void displayAccountInformation();
    void reportAccident();
    void updateAccidents();

    double accRenewalCost;

    int checkValidityRenewal();
    double findRenewalCost();

private:
    static const int FLAT_RATE = 135;
    Date m_accDateOfOpening;
    Date m_accDateOfExpiry;
    AccidentList m_accAccidentRecord;
    double m_accRenewalCost;

    /*TODO: Declaration of private member variables*/
    /*TODO: Prototype for private member functions*/

};


#endif



