#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct stClient
{
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalance;
    bool markForDelete = false;
};

enum enMainMenuOptions
{
    mainMenuOpt_quickWithdraw = 1,
    mainMenuOpt_normalWithDraw = 2,
    mainMenuOpt_deposit = 3,
    mainMenuOpt_checkBalance = 4,
    mainMenuOpt_exit = 5
};

enum enClientInformation
{
    clientInfo_accountNumber = 0,
    clientInfo_pinCode = 1,
    clientInfo_name = 2,
    clientInfo_phone = 3,
    clientInfo_accountBalance = 4
};

const string clientsFileName = "clients.txt";

stClient currentClient;

void ShowMainMenu();
void Login();
void ShowQuickWithdrawScreen();
void ShowNormalWithDrawScreen();
void ShowDepositScreen();

void WelcomeMessage()
{
    cout << "\n\nWelcome to the Project ..\n"
         << endl;
}

vector<string> SplitString(string s1, string delim)
{
    vector<string> vecString;

    short pos = 0;
    string sWord; // define a string variable

    // use find() function to get the position of the delimiters
    while ((pos = s1.find(delim)) != std::string::npos)
    {
        sWord = s1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vecString.push_back(sWord);
        }

        s1.erase(0, pos + delim.length()); // erase() until postion and move to next word.
    }

    if (s1 != "")
    {
        vecString.push_back(s1); // it adds last word of the string.
    }

    return vecString;
}

stClient ConvertLinetoRecord(string line, string separator = "#//#")
{
    stClient client;
    vector<string> vecClientData;

    vecClientData = SplitString(line, separator);

    client.accountNumber = vecClientData[enClientInformation::clientInfo_accountNumber];
    client.pinCode = vecClientData[enClientInformation::clientInfo_pinCode];
    client.name = vecClientData[enClientInformation::clientInfo_name];
    client.phone = vecClientData[enClientInformation::clientInfo_phone];
    client.accountBalance = stod(vecClientData[enClientInformation::clientInfo_accountBalance]); // cast string to double

    return client;
}

string ConvertRecordToLine(stClient client, string separator = "#//#")
{
    string clientRecord = "";

    clientRecord += client.accountNumber + separator;
    clientRecord += client.pinCode + separator;
    clientRecord += client.name + separator;
    clientRecord += client.phone + separator;
    clientRecord += to_string(client.accountBalance);

    return clientRecord;
}

vector<stClient> LoadClientsDataFromFile(string fileName)
{
    vector<stClient> vecClients;

    fstream myFile;
    myFile.open(fileName, ios::in); // read Mode

    if (myFile.is_open())
    {
        string line;
        stClient client;

        while (getline(myFile, line))
        {
            client = ConvertLinetoRecord(line);

            vecClients.push_back(client);
        }

        myFile.close();
    }

    return vecClients;
}

bool FindClientByAccountNumberAndPinCode(string accountNumber, string pinCode, stClient &client)
{
    vector<stClient> vecClients = LoadClientsDataFromFile(clientsFileName);

    for (stClient &c : vecClients)
    {
        if (c.accountNumber == accountNumber && c.pinCode == pinCode)
        {
            client = c;

            return true;
        }
    }

    return false;
}

vector<stClient> SaveClientsDataToFile(string fileName, vector<stClient> vecClients)
{
    fstream myFile;
    myFile.open(fileName, ios::out); // overwrite

    string dataLine;

    if (myFile.is_open())
    {
        for (stClient &c : vecClients)
        {
            if (c.markForDelete == false)
            {
                // we only write records that are not marked for delete.
                dataLine = ConvertRecordToLine(c);
                myFile << dataLine << endl;
            }
        }

        myFile.close();
    }

    return vecClients;
}

bool DepositBalanceToClientByAccountNumber(string accountNumber, double amount, vector<stClient> &vecClients)
{
    char answer = 'n';

    cout << "\n\nAre you sure you want perfrom this transaction? y/n: ";
    cin >> answer;

    if (answer == 'y' || answer == 'Y')
    {
        for (stClient &c : vecClients)
        {
            if (c.accountNumber == accountNumber)
            {
                c.accountBalance += amount;

                SaveClientsDataToFile(clientsFileName, vecClients);

                cout << "\n\nDone Successfully. New balance is: " << c.accountBalance << "$";

                return true;
            }
        }

        return false;
    }

    return false;
}

short ReadQuickWithdrawOption()
{
    short choice = 0;

    while (choice < 1 || choice > 9)
    {
        cout << "\nChoose what to do from [1] to [9]: ";
        cin >> choice;
    }

    return choice;
}

short getQuickWithDrawAmount(short quickWithDrawOption)
{
    switch (quickWithDrawOption)
    {
    case 1:
        return 20;
    case 2:
        return 50;
    case 3:
        return 100;
    case 4:
        return 200;
    case 5:
        return 400;
    case 6:
        return 600;
    case 7:
        return 800;
    case 8:
        return 1000;
    default:
        return 0;
    }
}

void PerfromQuickWithdrawOption(short quickWithDrawOption)
{
    if (quickWithDrawOption == 9) // exit
    {
        return;
    }

    short withDrawBalance = getQuickWithDrawAmount(quickWithDrawOption);

    if (withDrawBalance > currentClient.accountBalance)
    {
        cout << "\nThe amount exceeds your balance, make another choice.\n";
        cout << "Press Anykey to continue...";

        system("pause > nul");

        ShowQuickWithdrawScreen();

        return;
    }

    vector<stClient> vecClients = LoadClientsDataFromFile(clientsFileName);
    DepositBalanceToClientByAccountNumber(currentClient.accountNumber, withDrawBalance * -1, vecClients);
    currentClient.accountBalance -= withDrawBalance;
}

double ReadDepositAmount()
{
    double amount;
    cout << "\nEnter a positive Deposit amount: ";
    cin >> amount;

    while (amount <= 0)
    {
        cout << "\nEnter a positive Deposit amount: ";
        cin >> amount;
    }

    return amount;
}

void PerfromDepositOption()
{
    double depositAmount = ReadDepositAmount();

    vector<stClient> vecClients = LoadClientsDataFromFile(clientsFileName);
    DepositBalanceToClientByAccountNumber(currentClient.accountNumber, depositAmount, vecClients);
    currentClient.accountBalance += depositAmount;
}

void ShowDepositScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t  Deposit Screen\n";
    cout << "===========================================\n";

    PerfromDepositOption();
}

void ShowCheckBalanceScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t  Check Balance Screen\n";
    cout << "===========================================\n";

    cout << "\nYour Balance is " << currentClient.accountBalance << "$" << "\n";
}

int ReadWithDrawAmount()
{
    int amount;
    cout << "\nEnter an amount multiple of 5's: ";
    cin >> amount;

    while (amount % 5 != 0)
    {
        cout << "\nEnter an amount multiple of 5's: ";
        cin >> amount;
    }

    return amount;
}

void PerfromNormalWithdrawOption()
{
    int withDrawBalance = ReadWithDrawAmount();

    if (withDrawBalance > currentClient.accountBalance)
    {
        cout << "\nThe amount exceeds your balance, make another choice.\n";
        cout << "Press Anykey to continue...";

        system("pause > nul");

        ShowNormalWithDrawScreen();

        return;
    }

    vector<stClient> vecClients = LoadClientsDataFromFile(clientsFileName);
    DepositBalanceToClientByAccountNumber(currentClient.accountNumber, withDrawBalance * -1, vecClients);
    currentClient.accountBalance -= withDrawBalance;
}

void ShowNormalWithDrawScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tNormal Withdraw Screen\n";
    cout << "===========================================\n";

    PerfromNormalWithdrawOption();
}

void ShowQuickWithdrawScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tQuick Withdraw\n";
    cout << "===========================================\n";
    cout << "\t[1] 20\t\t[2] 50\n";
    cout << "\t[3] 100\t\t[4] 200\n";
    cout << "\t[5] 400\t\t[6] 600\n";
    cout << "\t[7] 800\t\t[8] 1000\n";
    cout << "\t[9] Exit\n";
    cout << "===========================================\n";
    cout << "Your Balance is " << currentClient.accountBalance << "$";

    PerfromQuickWithdrawOption(ReadQuickWithdrawOption());
}

void GoBackToMainMenu()
{
    cout << "\n\nPress any key to go back to Main Menu...";
    system("pause > nul");

    ShowMainMenu();
}

short ReadMainMenuOption()
{
    short choice = 0;
    cout << "Choose what do you want to do? [1 to 5]: ";
    cin >> choice;

    return choice;
}

void PerfromMainMenuOption(enMainMenuOptions mainMenuOption)
{
    switch (mainMenuOption)
    {
    case enMainMenuOptions::mainMenuOpt_quickWithdraw:
    {
        system("cls");
        ShowQuickWithdrawScreen();
        GoBackToMainMenu();
        break;
    }
    case enMainMenuOptions::mainMenuOpt_normalWithDraw:
        system("cls");
        ShowNormalWithDrawScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::mainMenuOpt_deposit:
        system("cls");
        ShowDepositScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::mainMenuOpt_checkBalance:
        system("cls");
        ShowCheckBalanceScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::mainMenuOpt_exit:
        system("cls");
        Login();

        break;
    }
}

void ShowMainMenu()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t  ATM Main Menu Screen\n";
    cout << "===========================================\n";
    cout << "[1] Quick Withdraw.\n";
    cout << "[2] Normal Withdraw.\n";
    cout << "[3] Deposit\n";
    cout << "[4] Check Balance.\n";
    cout << "[5] Logout.\n";
    cout << "===========================================\n";

    PerfromMainMenuOption((enMainMenuOptions)ReadMainMenuOption());
}

bool LoadClientInfo(string accountNumber, string pinCode)
{
    if (FindClientByAccountNumberAndPinCode(accountNumber, pinCode, currentClient))
        return true;
    else
        return false;
}

void Login()
{
    bool loginFailed = false;
    string accountNumber, pinCode;

    do
    {
        system("cls");

        WelcomeMessage();

        cout << "\n---------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n---------------------------------\n";

        if (loginFailed)
        {
            cout << "Invalid Account Number/Pin Code!\n";
        }

        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Pin Code: ";
        cin >> pinCode;

        loginFailed = !LoadClientInfo(accountNumber, pinCode);

    } while (loginFailed);

    ShowMainMenu();
}

int main()
{
    Login();

    cout << endl
         << endl;

    return 0;
}