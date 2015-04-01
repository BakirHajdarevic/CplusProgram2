//-----------------------------------------------------------------------------
// Programmer: Bakir Hajdarevic, Bilal Rashid, Nick Collins
// Name: main.cpp
// Description: This program consists of menu based car insurance management system.
// It maintains a directory of car insurance accounts using the map class from the C++ 
// standard library. The driver’s license is used as the key in the map. Four different 
// classes are used in this project: (1) Date, (2) PersonalRec, 3) AccidentList, 
// (4) CarInsuranceAccountRec.
//-----------------------------------------------------------------------------
/* Pseudocode:
Include files, library functions, and class header files: iostream, string, math.h, studio.h, map, 
    Date.h, AccidenList.h, PersonalRec.h, and CarInsuranceAccountRec.h

Global Variable: Date currentdate;

Initialize function main

    Define variables:
        two counter variables for while loops
        Initialize Userinput variable to store user's menu choices
        Initialize a variable to store User's driver license number
        Initialize a bool variable if license exits
        Initialize 3 map variabes:
            < int, CarInsuranceAccountRec > userDLNumMap;
            < int, CarInsuranceAccountRec >::iterator DLIter;
            <int, CarInsuranceAccountRec >::iterator Iter;
        while counter != true
            Prompt User with initial menu:
                Welcome to the 3 Goonies Car Insurance Management System
                Please select from the following:
                    1) Open a new account
                    2) Operate on an existing account
                    3) Print all accidents
                    4) Set current date
                    0) Terminate the Program
            OPTION 1 - Open a new account
                Prompt User for ONLY a 5 digit driver's license number
                Iterate through through map of insurance accounts and test if license # exists in there.
                If license # exits:
                    An account with this DLN already exists.
                Else
                    Create car insurance account
                    Initialize two strings to store first and last names
                    Prompt User for first and last name
                    Get User's date of birth by calling setDate function with Date file
                    Store information with the User driver license map
                    
            OPTION 2 - Operate on an existing account.
                Prompt User for driver's license number
                Test to see if driver's license exists in map.
                if License is found
                    Create a pointer to object of type CarInsuranceAccountRec
                    Assigns Object to corresponding driver's license value in map
                    Call Member Function displayPersonalRec to display account detail information
                    BEGIN 2nd Menu
                    while counter2 != true
                        Prompt User:
                            1) Inquire renewal cost
                                 Calls the member function displayRenewCost() to print the renewal status and cost information
                            2) Renew account
                                 Calls the member function renewInsurance() to renew the insurance of the account
                            3) Report an accident
                                 Reads the accident description and the cost and a new accident by calling the member function        
                                 reportAccident(accidentDescription, cost); then prints the account information by calling the member 
                                 function displayAccountInformation()
                            4) Display account information
                                 print the account information by calling the member function displayAccountInformation()
                            5) Return to main menu                      
            OPTION 3 - PRINT ALL ACCOUNTS
                Print all account information
                Iterate through account directory
            OPTION 4 - Set Current Date
                Prompt User for the current date by calling function setDate within Date.cpp
            terminate program
                Done = true
        Clear driver license numbers
    Return 0
*/
#include<iostream>
#include<string>
#include<math.h>
#include <stdio.h>
#include <map>

#include "Date.h"
#include "AccidentList.h"
#include "PersonalRec.h"
#include "CarInsuranceAccountRec.h"

/** Global Variable **/
Date currentDate;

int main()
{
    bool done = false;
    bool done2 = false;
    int userInput1;
    int userDLNum;

    bool licenseExists;

    std::map< int, CarInsuranceAccountRec* > userDLNumMap;
    std::map< int, CarInsuranceAccountRec* >::iterator DLIter;
    std::map<int, CarInsuranceAccountRec* >::iterator Iter;
    while(!done)
    {
        std::cout << std::endl;
        std::cout << "Welcome to the 3 Goonies Car Insurance Management System" << std::endl;
        std::cout << "Please select from the following: " << std::endl;
        std::cout << "1) Open a new account" << std::endl;
        std::cout << "2) Operate on an existing account" << std::endl;
        std::cout << "3) Print all accidents" << std::endl;
        std::cout << "4) Set current date" << std::endl;
        std::cout << "0) Terminate the Program" << std::endl;;
        std::cin >> userInput1;

        //OPTION 1 - Open a new account
        if(userInput1 == 1)
        {
           std::cout << "Please enter your drivers license number: " << std::endl;
           std::cin >> userDLNum;
           while(userDLNum < 10000 || userDLNum > 99999)
           {
                std::cout << "Incorrect. Please enter a 5 digit driver license number: " << std::endl;
                std::cin >> userDLNum;
           }
            /*Iterate through through map of insurance accounts and test if license # exists in there.*/
            for(DLIter = userDLNumMap.begin(); DLIter != userDLNumMap.end(); DLIter++)
            {
                int DLValue = DLIter->first;

                if(DLValue == userDLNum)
                {
                    licenseExists = true;
                    DLIter = userDLNumMap.end();
                }
                else
                {
                    licenseExists = false;
                }
            }

           if(licenseExists)
           {
                std::cout << "An account with this DLN already exists." << std::endl;
           }

           /*Create car insurance account*/
           else if (!licenseExists)
           {
                std::string firstName;
                std::string lastName;

                std::cout << "Please enter your first name: " << std::endl;
                std::cin >> firstName;
                std::cout << "Please enter your last name: " << std::endl;
                std::cin >> lastName;
                std::cout << "Please enter your date of birth in the form M/D/Y: " << std::endl;

                Date DOB;
                DOB.setDate();

                userDLNumMap[userDLNum] = new CarInsuranceAccountRec(firstName, lastName, DOB);
           }

        }

        //OPTION 2 - Operate on an existing account.
        else if(userInput1 == 2)
        {
            int drivers_license;

            std::cout <<"Please enter your drivers license number: " << std::endl;
            std::cin >> drivers_license;

            /*Test to see if driver's license exists in map.*/

            /*License is found*/
            if (userDLNumMap.count(drivers_license))
            {

                /*Creates a pointer to object of type CarInsuranceAccountRec*/
                CarInsuranceAccountRec *CarInsuranceAccountRecObject;

                /*Assigns Object to corresponding driver's license value in map*/
                (CarInsuranceAccountRecObject) = userDLNumMap[drivers_license];

                /*Calls Member Function displayPersonalRec to display account detail information.*/
                CarInsuranceAccountRecObject->displayAccountInformation();

                /*BEGIN 2nd Menu*/
                while(!done2)
                {
                    std::cout << "1) Inquire renewal cost" << std::endl;
                    std::cout << "2) Renew account " << std::endl;
                    std::cout << "3) Report an accident " << std::endl;
                    std::cout << "4) Display account information " << std::endl;
                    std::cout << "5) Return to main menu " << std::endl;
                    int userInput4;
                    std::cin >> userInput4;


                    if(userInput4 == 1)//Inquire renewal cost
                    {
                        (*CarInsuranceAccountRecObject).displayRenewalCost();
                    }

                    else if(userInput4 == 2)//Renew account
                    {
                        (*CarInsuranceAccountRecObject).renewInsurance();
                    }
                    else if(userInput4 == 3)//Report an accident
                    {
                        CarInsuranceAccountRecObject->reportAccident();
                        CarInsuranceAccountRecObject->displayAccountInformation();
                    }
                    else if(userInput4 == 4)//Display account information
                    {
                        CarInsuranceAccountRecObject->displayAccountInformation();
                    }
                    else
                    {//return to main menu
                        done2 = true;
                    }

                }//while loop bracket
                done2 = false;
            }

            /*License number is not found in map*/
            else
            {
                std::cout << "Sorry, we couldn't find your license number in our records." << std::endl;
                std::cout << "You will be returned to the main menu." << std::endl;
            }

        }//Option 2 bracket

        //OPTION 3 - PRINT ALL ACCOUNTS
        if(userInput1 == 3)
        {
            /*print account info*/
            /*Iterate through account directory*/
            CarInsuranceAccountRec *CIAR;
            for(Iter = userDLNumMap.begin(); Iter != userDLNumMap.end(); Iter++)
            {
                std::cout << "Driver License number: " << Iter->first << std::endl;
                (CIAR) = userDLNumMap[Iter->first];
                CIAR->displayAccountInformation();
            }
        }

        //OPTION 4 - Set Current Date
        else if(userInput1 == 4)
        {
            std::cout << "Set current date: "<< std::endl;
            currentDate.setDate();
        }
        //terminate program
        else if (userInput1 == 0)
        {
            done = true;
        }
    }//end big while loop

    return 0;
} //end main


