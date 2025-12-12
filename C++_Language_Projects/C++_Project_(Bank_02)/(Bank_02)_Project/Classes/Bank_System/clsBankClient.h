#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "../Public/clsString.h"
#include "clsPerson.h"

using namespace std;

struct stTransferLogRecord
{
    string DateTime;
    string SourceAccountNumber;
    string DestinationAccountNumber;
    float Amount;
    float srcBalanceAfter;
    float destBalanceAfter;
    string UserName;
};

class clsBankClient : public clsPerson
{
private:
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1,
        AddNewMode = 2
    } _Mode;

    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkedForDelete = false;

    static clsBankClient _ConvertLineToClientObject(string Line, string Separator = "#//#")
    {
        vector<string> vClientData;

        vClientData = clsString::Split(Line, Separator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

    static string _ConvertClientObjectToLine(clsBankClient Client, string Separator = "#//#")
    {
        string stClientRecord = "";

        stClientRecord += Client.GetFirstName() + Separator;
        stClientRecord += Client.GetLastName() + Separator;
        stClientRecord += Client.GetEmail() + Separator;
        stClientRecord += Client.GetPhone() + Separator;
        stClientRecord += Client.GetAccountNumber() + Separator;
        stClientRecord += Client.GetPinCode() + Separator;
        stClientRecord += to_string(Client.GetAccountBalance());

        return stClientRecord;
    }

    static vector<clsBankClient> _LoadClientsDataFromFile()
    {
        vector<clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Database/Clients.txt", ios::in); // Read Mode.

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLineToClientObject(Line);

                vClients.push_back(Client);
            }
            MyFile.close();
        }
        return vClients;
    }

    static void _SaveClientsDataToFile(vector<clsBankClient> vClients)
    {
        fstream MyFile;
        MyFile.open("Database/Clients.txt", ios::out); // Overwrite.

        string DataLine;

        if (MyFile.is_open())
        {
            for (clsBankClient C : vClients)
            {
                if (C.MarkedForDeleted() == false)
                {
                    // We only write records that are not marked for delete.
                    DataLine = _ConvertClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }
            MyFile.close();
        }
    }

    void _Update()
    {
        vector<clsBankClient> _vClients;

        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient &C : _vClients)
        {
            if (C.GetAccountNumber() == GetAccountNumber())
            {
                C = *this;

                break;
            }
        }

        _SaveClientsDataToFile(_vClients);
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }

    void _AddDataLineToFile(string stDataLine)
    {
        fstream MyFile;
        MyFile.open("Database/Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string Separator = "#//#")
    {
        stTransferLogRecord TransferLogRecord;

        vector<string> vTransferLogRecordLine = clsString::Split(Line, Separator);
        TransferLogRecord.DateTime = vTransferLogRecordLine[0];
        TransferLogRecord.SourceAccountNumber = vTransferLogRecordLine[1];
        TransferLogRecord.DestinationAccountNumber = vTransferLogRecordLine[2];
        TransferLogRecord.Amount = stod(vTransferLogRecordLine[3]);
        TransferLogRecord.srcBalanceAfter = stod(vTransferLogRecordLine[4]);
        TransferLogRecord.destBalanceAfter = stod(vTransferLogRecordLine[5]);
        TransferLogRecord.UserName = vTransferLogRecordLine[6];

        return TransferLogRecord;
    }

    string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient, string UserName, string Separator = "#//#")
    {
        string TransferLogRecord = "";

        TransferLogRecord += clsDate::GetSystemDateTimeString() + Separator;
        TransferLogRecord += GetAccountNumber() + Separator;
        TransferLogRecord += DestinationClient.GetAccountNumber() + Separator;
        TransferLogRecord += to_string(Amount) + Separator;
        TransferLogRecord += to_string(GetAccountBalance()) + Separator;
        TransferLogRecord += to_string(DestinationClient.GetAccountBalance()) + Separator;
        TransferLogRecord += UserName;

        return TransferLogRecord;
    }

    void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
    {
        string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

        fstream MyFile;
        MyFile.open("Database/TransferLog.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }

public:
    // Constructor.
    clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }

    // Setters and Getters.
    string GetAccountNumber() { return _AccountNumber; }

    void SetPinCode(string PinCode) { _PinCode = PinCode; }
    string GetPinCode() { return _PinCode; }

    void SetAccountBalance(float AccountBalance) { _AccountBalance = AccountBalance; }
    float GetAccountBalance() { return _AccountBalance; }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    /*
    No UI Related code iside object.
    void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << FirstName;
        cout << "\nLastName    : " << LastName;
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << Email;
        cout << "\nPhone       : " << Phone;
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";

    }
    */

    static clsBankClient Find(string AccountNumber)
    {
        vector<clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Database/Clients.txt", ios::in); // Read Mode.

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);

                if (Client.GetAccountNumber() == AccountNumber)
                {
                    MyFile.close();

                    return Client;
                }
                vClients.push_back(Client);
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        fstream MyFile;
        MyFile.open("Database/Clients.txt", ios::in); // Read Mode.

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);

                if (Client.GetAccountNumber() == AccountNumber && Client.GetPinCode() == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();
    }

    enum enSaveResults
    {
        svFailedEmptyObject = 0,
        svSucceeded = 1,
        svFailedAccountNumberExists = 2
    };

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFailedEmptyObject;
            }
            break;
        }

        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;
            break;
        }

        case enMode::AddNewMode:
        {
            // This will add new record to file or database
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFailedAccountNumberExists;
            }
            else
            {
                _AddNew();

                // We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }
            break;
        }
        }
    }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        return (!Client1.IsEmpty());
    }

    bool Delete()
    {
        vector<clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient &C : _vClients)
        {
            if (C.GetAccountNumber() == _AccountNumber)
            {
                C._MarkedForDelete = true;
                break;
            }
        }

        _SaveClientsDataToFile(_vClients);

        *this = _GetEmptyClientObject();

        return true;
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    static vector<clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    static double GetTotalBalances()
    {
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();

        double TotalBalances = 0;

        for (clsBankClient Client : vClients)
        {
            TotalBalances += Client.GetAccountBalance();
        }

        return TotalBalances;
    }

    void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

    bool Withdraw(double Amount)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }
        else
        {
            _AccountBalance -= Amount;
            Save();
            return true;
        }
    }

    bool Transfer(float Amount, clsBankClient &DestinationClient, string UserName)
    {
        if (Amount > GetAccountBalance())
        {
            return false;
        }

        Withdraw(Amount);
        DestinationClient.Deposit(Amount);
        _RegisterTransferLog(Amount, DestinationClient, UserName);
        return true;
    }

    static vector<stTransferLogRecord> GetTransfersLogList()
    {
        vector<stTransferLogRecord> vTransferLogRecord;

        fstream MyFile;
        MyFile.open("Database/TransfersLog.txt", ios::in); // Read Mode.

        if (MyFile.is_open())
        {
            string Line;

            stTransferLogRecord TransferRecord;

            while (getline(MyFile, Line))
            {
                TransferRecord = _ConvertTransferLogLineToRecord(Line);

                vTransferLogRecord.push_back(TransferRecord);
            }

            MyFile.close();
        }

        return vTransferLogRecord;
    }
};