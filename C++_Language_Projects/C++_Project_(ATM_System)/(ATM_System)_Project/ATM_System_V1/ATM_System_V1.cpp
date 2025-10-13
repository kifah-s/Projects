#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void ShowATMMainMenu();
void Login();

const string clientsFileName = "clients.txt";

struct stClient
{
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalance;
    bool markForDelete = false;
};

stClient currentClient;

enum enClientInformation
{
    clientInfo_accountNumber = 0,
    clientInfo_pinCode = 1,
    clientInfo_name = 2,
    clientInfo_phone = 3,
    clientInfo_accountBalance = 4
};

enum enATMMainMenuOptions
{
    ATMMainMenuOpt_quickWithdraw = 1,
    ATMMainMenuOpt_normalWithdraw = 2,
    ATMMainMenuOpt_deposit = 3,
    ATMMainMenuOpt_checkBalance = 4,
    ATMMainMenuOpt_logout = 5
};

enum enQuickWithdrawOptions
{
    quickWithdrawOpt_20 = 1,
    quickWithdrawOpt_50 = 2,
    quickWithdrawOpt_100 = 3,
    quickWithdrawOpt_200 = 4,
    quickWithdrawOpt_400 = 5,
    quickWithdrawOpt_600 = 6,
    quickWithdrawOpt_800 = 7,
    quickWithdrawOpt_1000 = 8,
    quickWithdrawOpt_exit = 9,

};

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

    // Use find() function to get the position of the delimiters.
    while ((pos = s1.find(delim)) != std::string::npos)
    {
        sWord = s1.substr(0, pos); // Store the word.

        if (sWord != "")
        {
            vecString.push_back(sWord);
        }

        s1.erase(0, pos + delim.length()); // Erase() until postion and move to next word.
    }

    if (s1 != "")
    {
        vecString.push_back(s1); // It adds last word of the string.
    }

    return vecString;
}

stClient ConvertClientLinetoRecord(string line, string separator = "#//#")
{
    stClient client;
    vector<string> vecClientData;

    vecClientData = SplitString(line, separator);

    client.accountNumber = vecClientData[enClientInformation::clientInfo_accountNumber];
    client.pinCode = vecClientData[enClientInformation::clientInfo_pinCode];
    client.name = vecClientData[enClientInformation::clientInfo_name];
    client.phone = vecClientData[enClientInformation::clientInfo_phone];
    client.accountBalance = stod(vecClientData[enClientInformation::clientInfo_accountBalance]); // Cast string to double.

    return client;
}

vector<stClient> LoadClientsDataFromFile(string fileName)
{
    vector<stClient> vecClients;

    fstream myFile;
    myFile.open(fileName, ios::in); // Read Mode.

    if (myFile.is_open())
    {
        string line;
        stClient client;

        while (getline(myFile, line))
        {
            client = ConvertClientLinetoRecord(line);

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

bool LoadClientInfo(string accountNumber, string pinCode)
{
    if (FindClientByAccountNumberAndPinCode(accountNumber, pinCode, currentClient))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void LoginScreen()
{
    system("cls");
    WelcomeMessage();
    cout << "\n---------------------------------\n";
    cout << "\tLogin Screen";
    cout << "\n---------------------------------\n";
}

string ReadAccountNumber()
{
    string accountNumber;

    cout << "Please, enter account number: ";
    cin >> accountNumber;

    return accountNumber;
}

string ReadPinCode()
{
    string pinCode;

    cout << "Please, Enter pin code: ";
    cin >> pinCode;

    return pinCode;
}

short ReadATMMainMenuOption()
{
    short choice = 0;
    cout << "Choose what do you want to do? [1 to 5]: ";
    cin >> choice;

    return choice;
}

void GoBackToATMMainMenu()
{
    cout << "\n\nPress any key to go back to ATM main menu...";
    system("pause > nul");

    ShowATMMainMenu();
}

void ShowCheckBalanceScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t  Check Balance Screen\n";
    cout << "===========================================\n";

    cout << "\nYour Balance is: " << currentClient.accountBalance << "$" << endl;
}

short ReadQuickWithdrawOption()
{
    short choice = 0;
    cout << "\nChoose what to withdraw from [1 to 8]: ";
    cin >> choice;

    return choice;
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

vector<stClient> UpdateClientBalance(vector<stClient> vecClients)
{
    for (stClient &c : vecClients)
    {
        if (c.accountNumber == currentClient.accountNumber)
        {
            c.accountBalance = currentClient.accountBalance;
            break;
        }
    }

    return vecClients;
}

void SaveClientsDataToFile(string fileName, vector<stClient> vecClients)
{
    fstream myFile;
    myFile.open(fileName, ios::out); // Write Mode.

    string dataLine;

    if (myFile.is_open())
    {
        for (stClient &c : vecClients)
        {
            dataLine = ConvertRecordToLine(c);
            myFile << dataLine << endl;
        }

        myFile.close();
    }
}

void BalanceWithdrawalCalculation(stClient &currentClient, short withdrawalAmount)
{
    char answer = 'n';

    cout << "\n\nAre you sure you want perfrom this transaction? (y/n): ";
    cin >> answer;

    if (answer == 'y' || answer == 'Y')
    {
        if (currentClient.accountBalance >= withdrawalAmount)
        {
            currentClient.accountBalance -= withdrawalAmount;
            cout << "\nDone successfully. new balance is: " << currentClient.accountBalance << "$" << endl;
        }
        else
        {
            cout << "\nThe withdrawal amount is greater than your balance." << endl;
        }
    }

    vector<stClient> vecClients = LoadClientsDataFromFile(clientsFileName);
    vecClients = UpdateClientBalance(vecClients);
    SaveClientsDataToFile(clientsFileName, vecClients);
}

void PerformQuickWithdrawOption(enQuickWithdrawOptions quickWithdrawOption)
{
    switch (quickWithdrawOption)
    {
    case enQuickWithdrawOptions::quickWithdrawOpt_20:
        BalanceWithdrawalCalculation(currentClient, 20);
        break;

    case enQuickWithdrawOptions::quickWithdrawOpt_50:
        BalanceWithdrawalCalculation(currentClient, 50);
        break;

    case enQuickWithdrawOptions::quickWithdrawOpt_100:
        BalanceWithdrawalCalculation(currentClient, 100);
        break;

    case enQuickWithdrawOptions::quickWithdrawOpt_200:
        BalanceWithdrawalCalculation(currentClient, 200);
        break;

    case enQuickWithdrawOptions::quickWithdrawOpt_400:
        BalanceWithdrawalCalculation(currentClient, 400);
        break;

    case enQuickWithdrawOptions::quickWithdrawOpt_600:
        BalanceWithdrawalCalculation(currentClient, 600);
        break;

    case enQuickWithdrawOptions::quickWithdrawOpt_800:
        BalanceWithdrawalCalculation(currentClient, 800);
        break;

    case enQuickWithdrawOptions::quickWithdrawOpt_1000:
        BalanceWithdrawalCalculation(currentClient, 1000);
        break;

    case enQuickWithdrawOptions::quickWithdrawOpt_exit:
        ShowATMMainMenu();
        break;
    }
}

void ShowQuickWithdrawScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t  Quick Withdraw\n";
    cout << "===========================================\n";
    cout << "[1] 20          [2] 50\n";
    cout << "[3] 100         [4] 200\n";
    cout << "[5] 400         [6] 600\n";
    cout << "[7] 800         [8] 1000\n";
    cout << "[9] Exit.\n";
    cout << "===========================================\n";

    cout << "\nYour Balance is: " << currentClient.accountBalance << "$" << endl;
    PerformQuickWithdrawOption((enQuickWithdrawOptions)ReadQuickWithdrawOption());
}

short ReadWithdrawAmount()
{
    short withdrawAmount = 0;

    do
    {
        cout << "\nPlease, enter an amount (multiple of 5's): ";
        cin >> withdrawAmount;
    } while (withdrawAmount % 5 != 0);

    return withdrawAmount;
}

void ShowNormalWithdrawScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t  Normal Withdraw\n";
    cout << "===========================================\n";
    cout << "\nYour Balance is: " << currentClient.accountBalance << "$" << endl;
    BalanceWithdrawalCalculation(currentClient, ReadWithdrawAmount());
}

short ReadDepositAmount()
{
    short depositAmount = 0;

    cout << "\nPlease, enter a positive deposit amount: ";
    cin >> depositAmount;

    return depositAmount;
}

void BalanceDepositCalculation(stClient &currentClient, short depositAmount)
{
    char answer = 'n';

    cout << "\n\nAre you sure you want perfrom this transaction? (y/n): ";
    cin >> answer;

    if (answer == 'y' || answer == 'Y')
    {

        currentClient.accountBalance += depositAmount;
        cout << "\nDone successfully. new balance is: " << currentClient.accountBalance << "$" << endl;
    }

    vector<stClient> vecClients = LoadClientsDataFromFile(clientsFileName);
    vecClients = UpdateClientBalance(vecClients);
    SaveClientsDataToFile(clientsFileName, vecClients);
}

void ShowDepositScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t  Deposit\n";
    cout << "===========================================\n";
    cout << "\nYour Balance is: " << currentClient.accountBalance << "$" << endl;
    BalanceDepositCalculation(currentClient, ReadDepositAmount());
}

void PerformATMMainMenuOption(enATMMainMenuOptions ATMMainMenuOption)
{
    switch (ATMMainMenuOption)
    {
    case enATMMainMenuOptions::ATMMainMenuOpt_quickWithdraw:
    {
        ShowQuickWithdrawScreen();
        GoBackToATMMainMenu();
        break;
    }
    case enATMMainMenuOptions::ATMMainMenuOpt_normalWithdraw:
        ShowNormalWithdrawScreen();
        GoBackToATMMainMenu();
        break;

    case enATMMainMenuOptions::ATMMainMenuOpt_deposit:
        ShowDepositScreen();
        GoBackToATMMainMenu();
        break;

    case enATMMainMenuOptions::ATMMainMenuOpt_checkBalance:
        ShowCheckBalanceScreen();
        GoBackToATMMainMenu();
        break;

    case enATMMainMenuOptions::ATMMainMenuOpt_logout:
        system("cls");
        Login();
        break;
    }
}

void ShowATMMainMenu()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t    ATM Main Menu Screen\n";
    cout << "===========================================\n";
    cout << "[1] Quick Withdraw.\n";
    cout << "[2] Normal Withdraw.\n";
    cout << "[3] Deposit.\n";
    cout << "[4] Check Balance.\n";
    cout << "[5] Logout.\n";
    cout << "===========================================\n";

    PerformATMMainMenuOption((enATMMainMenuOptions)ReadATMMainMenuOption());
}

void Login()
{
    bool loginFailed = false;
    string accountNumber, pinCode;

    do
    {
        LoginScreen();

        if (loginFailed)
        {
            cout << "\nInvalid account number / pin code !!\n\n";
        }

        accountNumber = ReadAccountNumber();
        pinCode = ReadPinCode();

        loginFailed = !LoadClientInfo(accountNumber, pinCode);

    } while (loginFailed);

    ShowATMMainMenu();
}

int main()
{
    Login();

    cout << endl
         << endl;

    return 0;
}