#pragma once

#include <iostream>
#include <string>

#include "InterfaceCom.h"

using namespace std;

class clsPerson : public InterfaceCommunication
{
private:
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:
    // Constructors.
    clsPerson(string FirstName, string LastName, string Email, string Phone)
    {
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    // Getter and Setter.
    void SetFirstName(string FirstName) { _FirstName = FirstName; }
    string GetFirstName() { return _FirstName; }

    void SetLastName(string LastName) { _LastName = LastName; }
    string GetLastName() { return _LastName; }

    void SetEmail(string Email) { _Email = Email; }
    string GetEmail() { return _Email; }

    void SetPhone(string Phone) { _Phone = Phone; }
    string GetPhone() { return _Phone; }

    string GetFullName() { return _FirstName + " " + _LastName; }

    void SendEmail(string Title, string Body)
    {
    }

    void SendFax(string Title, string Body)
    {
    }

    void SendSMS(string Title, string Body)
    {
    }
};