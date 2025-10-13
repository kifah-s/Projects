#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string fileName = "clients.txt";

void ShowMainMenu();
void ShowTransactionsScreen();

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
    opShowClintList = 1,
    opAddNewClint = 2,
    opDeleteClint = 3,
    opUpdateClintInfo = 4,
    opFindClint = 5,
    opTransactions = 6,
    opExit = 7
};

enum enTransactionsMenuOptions
{
    opDeposit = 1,
    opWithdraw = 2,
    opTotalBalance = 3,
    opMainMenu = 4
};

enum enClientInformation
{
    accountNumber = 0,
    pinCode = 1,
    name = 2,
    phone = 3,
    accountBalance = 4
};

void WelcomeMessage()
{
    cout << "\n\nWelcome to the Project ..\n"
         << endl;
}

short ReadMainMenuOption()
{
    short userChoice = 0;

    cout << "Chose what do you want to do [1 / 7]: ";
    cin >> userChoice;

    return userChoice;
}

void GoBackToMainMenu()
{
    cout << "\nPress Any Key To Go Back Main Menu ...";
    system("pause > nul");

    ShowMainMenu();
}

vector<string> SplitString(string s1, string delim)
{
    vector<string> vecString;
    short pos = 0;
    string sWord;

    while ((pos = s1.find(delim)) != std::string::npos)
    {
        sWord = s1.substr(0, pos);

        if (sWord != "")
        {
            vecString.push_back(sWord);
        }

        s1.erase(0, pos + delim.length());
    }

    if (s1 != "")
    {
        vecString.push_back(s1);
    }

    return vecString;
}

stClient ConvertLinetoRecord(string line, string separator = "#//#")
{
    stClient client;
    vector<string> vecClientData;

    vecClientData = SplitString(line, separator);

    client.accountNumber = vecClientData[enClientInformation::accountNumber];
    client.pinCode = vecClientData[enClientInformation::pinCode];
    client.name = vecClientData[enClientInformation::name];
    client.phone = vecClientData[enClientInformation::phone];
    client.accountBalance = stod(vecClientData[enClientInformation::accountBalance]);

    return client;
}

vector<stClient> LoadClientsDataFromFile(string fileName)
{
    vector<stClient> vecClients;

    fstream myFile;
    myFile.open(fileName, ios::in);

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

void PrintClientRecord(stClient client)
{
    cout << "| " << setw(15) << left << client.accountNumber;
    cout << "| " << setw(10) << left << client.pinCode;
    cout << "| " << setw(40) << left << client.name;
    cout << "| " << setw(12) << left << client.phone;
    cout << "| " << setw(12) << left << client.accountBalance;
}

void ShowAllClientScreen()
{
    vector<stClient> vecClients = LoadClientsDataFromFile(fileName);

    cout << "\n\n_______________________________________________________";
    cout << "_________________________________________" << endl;
    cout << "\n\t\t\t\tClient List (" << vecClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client name";
    cout << "| " << left << setw(12) << "phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;

    if (vecClients.size() == 0)
    {
        cout << "No Clients Available In The System." << endl;
    }
    else
    {
        for (stClient client : vecClients)
        {
            PrintClientRecord(client);
            cout << endl;
        }
    }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
}

bool ClientExistsByAccountNumber(string accountNumber, string fileName)
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

            if (client.accountNumber == accountNumber)
            {
                myFile.close();
                return true;
            }

            vecClients.push_back(client);
        }

        myFile.close();
    }

    return false;
}

stClient ReadNewClient()
{
    stClient client;

    cout << "Enter Account Number: ";
    // Usage of std::ws will extract all the whitespace character.
    getline(cin >> ws, client.accountNumber);

    while (ClientExistsByAccountNumber(client.accountNumber, fileName))
    {
        cout << "Client with Account Number [" << client.accountNumber << "] Already Exists .. Please, Enter Another Account Number: ";
        // Usage of std::ws will extract all the whitespace character.
        getline(cin >> ws, client.accountNumber);
    }

    cout << "Enter PinCode: ";
    getline(cin, client.pinCode);

    cout << "Enter Name: ";
    getline(cin, client.name);

    cout << "Enter Phone: ";
    getline(cin, client.phone);

    cout << "Enter Account Balance: ";
    cin >> client.accountBalance;

    return client;
}

string ConvertRecordToLine(stClient client, string separator = "#//#")
{
    string stClientRecord = "";

    stClientRecord += client.accountNumber + separator;
    stClientRecord += client.pinCode + separator;
    stClientRecord += client.name + separator;
    stClientRecord += client.phone + separator;
    stClientRecord += to_string(client.accountBalance);

    return stClientRecord;
}

void AddDataLineToFile(string fileName, string strDataLine)
{
    fstream myFile;

    myFile.open(fileName, ios::out | ios::app);

    if (myFile.is_open())
    {
        myFile << strDataLine << endl;

        myFile.close();
    }
}

void AddNewClient()
{
    stClient client;

    client = ReadNewClient();

    AddDataLineToFile(fileName, ConvertRecordToLine(client));
}

void AddNewClients()
{
    char addMore = 'Y';

    do
    {
        // system("cls");
        AddNewClient();
        cout << "\nClient Added Successfully, do you want to add more clients? (Y / N): ";
        cin >> addMore;
    } while (toupper(addMore) == 'Y');
}

void ShowAddNewClientsScreen()
{
    cout << "--------------------------------------------" << endl;
    cout << "\tAdd New Clint Screen" << endl;
    cout << "--------------------------------------------" << endl;

    AddNewClients();
}

void PrintClientCard(stClient client)
{
    cout << "\nThe following are the client details:\n";
    cout << "\nAccount Number: " << client.accountNumber;
    cout << "\nPin Code     : " << client.pinCode;
    cout << "\nName         : " << client.name;
    cout << "\nPhone        : " << client.phone;
    cout << "\nAccount Balance: " << client.accountBalance;
}

bool FindClientByAccountNumber(string accountNumber, vector<stClient> vecClients, stClient &client)
{
    for (stClient &c : vecClients)
    {
        if (c.accountNumber == accountNumber)
        {
            client = c;
            return true;
        }
    }

    return false;
}

bool MarkClientForDeleteByAccountNumber(string accountNumber, vector<stClient> &vecClients)
{
    for (stClient &c : vecClients)
    {
        if (c.accountNumber == accountNumber)
        {
            c.markForDelete = true;
            return true;
        }
    }

    return false;
}

vector<stClient> SaveClientsDataToFile(string fileName, vector<stClient> vecClients)
{
    fstream myFile;
    myFile.open(fileName, ios::out);

    string DataLine = "";

    if (myFile.is_open())
    {
        for (stClient &c : vecClients)
        {
            if (c.markForDelete == false)
            {
                DataLine = ConvertRecordToLine(c);
                myFile << DataLine << endl;
            }
        }

        myFile.close();
    }

    return vecClients;
}

void DeleteClientByAccountNumber(string accountNumber, vector<stClient> &vecClients)
{
    stClient client;
    char answer = 'n';

    if (FindClientByAccountNumber(accountNumber, vecClients, client))
    {
        PrintClientCard(client);
        cout << "\n\nAre you sure you want delete this client? (y / n): ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(accountNumber, vecClients);
            SaveClientsDataToFile(fileName, vecClients);
            vecClients = LoadClientsDataFromFile(fileName);
            cout << "\nClient Deleted Successfully.";

            // return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!";

        // return false;
    }
}

string ReadClientAccountNumber()
{
    string accountNumber = "";

    cout << "Please enter Account Number: ";
    cin >> accountNumber;

    return accountNumber;
}

void ShowDeleteClientScreen()
{
    cout << "--------------------------------------------" << endl;
    cout << "\tDelete Clint Screen" << endl;
    cout << "--------------------------------------------" << endl;

    vector<stClient> vecClients = LoadClientsDataFromFile(fileName);
    string accountNumber = ReadClientAccountNumber();
    DeleteClientByAccountNumber(accountNumber, vecClients);
}

stClient ChangeClientRecord(string accountNumber)
{
    stClient client;

    client.accountNumber = accountNumber;

    cout << "\nEnter Pin Code: ";
    getline(cin >> ws, client.pinCode);

    cout << "Enter Name: ";
    getline(cin, client.name);

    cout << "Enter Phone: ";
    getline(cin, client.phone);

    cout << "Enter Account Balance: ";
    cin >> client.accountBalance;

    return client;
}

void UpdateClientByAccountNumber(string accountNumber, vector<stClient> &vecClients)
{
    stClient client;
    char answer = 'n';

    if (FindClientByAccountNumber(accountNumber, vecClients, client))
    {
        PrintClientCard(client);

        cout << "\n\nAre you sure you want update this client? (y / n): ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            for (stClient &c : vecClients)
            {
                if (c.accountNumber == accountNumber)
                {
                    c = ChangeClientRecord(accountNumber);
                    break;
                }
            }

            SaveClientsDataToFile(fileName, vecClients);
            cout << "\n\nClient Updated Successfully.";

            // return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!";

        // return false;
    }
}

void ShowUpdateClientScreen()
{
    cout << "--------------------------------------------" << endl;
    cout << "\tUpdate Clint Screen" << endl;
    cout << "--------------------------------------------" << endl;

    vector<stClient> vecClients = LoadClientsDataFromFile(fileName);
    string accountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(accountNumber, vecClients);
}

void ShowFindClientScreen()
{
    cout << "--------------------------------------------" << endl;
    cout << "\tFind Clint Screen" << endl;
    cout << "--------------------------------------------" << endl;

    vector<stClient> vecClients = LoadClientsDataFromFile(fileName);
    string accountNumber = ReadClientAccountNumber();
    stClient client;

    if (FindClientByAccountNumber(accountNumber, vecClients, client))
    {
        PrintClientCard(client);
    }
    else
    {
        cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!" << endl;
    }
}

void ShowExitScreen()
{
    cout << "\n\n==================================================" << endl;
    cout << "\t\tProgram Ends." << endl;
    cout << "==================================================" << endl;
}

short ReadTransactionsMenuOption()
{
    short userChoice = 0;

    cout << "Chose what do you want to do [1 / 4]: ";
    cin >> userChoice;

    return userChoice;
}

void TransactionsMenuScreen()
{
    cout << "\n\n========================================" << endl;
    cout << "\tTransactions Menu Screen" << endl;
    cout << "========================================" << endl;
    cout << "[1]: Deposit." << endl;
    cout << "[2]: Withdraw." << endl;
    cout << "[3]: Total Balance." << endl;
    cout << "[4]: Main Menu." << endl;
    cout << "========================================" << endl;
}

void GoBackToTransactionsMenu()
{
    cout << "\nPress Any Key To Go Back Transactions Menu ...";
    system("pause > nul");

    ShowTransactionsScreen();
}

double ReadDepositAmount()
{
    double depositAmount = 0;
    cout << "\n\nPlease, enter deposit amount: ";
    cin >> depositAmount;

    return depositAmount;
}

char ConfirmExecutionThisTransaction()
{
    char answer = 'y';
    cout << "\nAre you sure you want perform this transaction (y / n): ";
    cin >> answer;

    return answer;
}

void AddDepositToClientAccount()
{
    string accountNumber = ReadClientAccountNumber();
    vector<stClient> vecClients = LoadClientsDataFromFile(fileName);
    stClient client;

    while (!FindClientByAccountNumber(accountNumber, vecClients, client))
    {
        cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!" << endl;
        accountNumber = ReadClientAccountNumber();
    }
    PrintClientCard(client);

    double depositAmount = ReadDepositAmount();

    if (tolower(ConfirmExecutionThisTransaction()) == 'y')
    {
        for (stClient &c : vecClients)
        {
            if (c.accountNumber == accountNumber)
            {
                c.accountBalance += depositAmount;
                cout << "\nDone Successfully.. New Balance: " << c.accountBalance << endl;
                break;
            }
        }

        SaveClientsDataToFile(fileName, vecClients);
    }
}

void ShowDepositScreen()
{
    cout << "\n----------------------------------------" << endl;
    cout << "\tDeposit Screen" << endl;
    cout << "----------------------------------------" << endl;

    AddDepositToClientAccount();
}

double ReadWithdrawAmount(string accountNumber, vector<stClient> vecClients)
{
    double withdrawAmount = 0;
    cout << "\nPlease, Enter Withdraw Amount: ";
    cin >> withdrawAmount;

    for (stClient &c : vecClients)
    {
        if (c.accountNumber == accountNumber)
        {
            while (withdrawAmount > c.accountBalance)
            {
                cout << "\nAmount Excited The Balance, You Can Withdraw Up To: " << c.accountBalance << endl;
                withdrawAmount = ReadWithdrawAmount(accountNumber, vecClients);
            }
            break;
        }
    }

    return withdrawAmount;
}

void WithdrawFromClientAccount()
{
    string accountNumber = ReadClientAccountNumber();
    vector<stClient> vecClients = LoadClientsDataFromFile(fileName);
    stClient client;

    while (!FindClientByAccountNumber(accountNumber, vecClients, client))
    {
        cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!" << endl;
        accountNumber = ReadClientAccountNumber();
    }
    PrintClientCard(client);

    double withdrawAmount = ReadWithdrawAmount(accountNumber, vecClients);

    if (tolower(ConfirmExecutionThisTransaction()) == 'y')
    {
        for (stClient &c : vecClients)
        {
            if (c.accountNumber == accountNumber)
            {
                c.accountBalance -= withdrawAmount;
                cout << "\nDone Successfully.. New Balance: " << c.accountBalance << endl;
                break;
            }
        }

        SaveClientsDataToFile(fileName, vecClients);
    }
}

void ShowWithdrawScreen()
{
    cout << "\n----------------------------------------" << endl;
    cout << "\tWithdraw Screen" << endl;
    cout << "----------------------------------------" << endl;

    WithdrawFromClientAccount();
}

void PrintClientRecordForTotalBalancesScreen(stClient client)
{
    cout << "| " << setw(15) << left << client.accountNumber;
    cout << "| " << setw(40) << left << client.name;
    cout << "| " << setw(12) << left << client.accountBalance;
}

void ShowAllClientForTotalBalancesScreen()
{
    vector<stClient> vecClients = LoadClientsDataFromFile(fileName);

    cout << "\n\n_______________________________________________________";
    cout << "_________________________________________" << endl;
    cout << "\n\t\t\t\tBalances List (" << vecClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(40) << "Client name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;

    if (vecClients.size() == 0)
    {
        cout << "No Clients Available In The System." << endl;
    }
    else
    {
        for (stClient client : vecClients)
        {
            PrintClientRecordForTotalBalancesScreen(client);
            cout << endl;
        }
    }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
}

double CalculateTotalBalances()
{
    double totalBalances = 0;
    vector<stClient> clients = LoadClientsDataFromFile(fileName);

    for (stClient &c : clients)
    {
        totalBalances += c.accountBalance;
    }

    return totalBalances;
}

void ShowTotalBalancesScreen()
{
    ShowAllClientForTotalBalancesScreen();

    cout << "\t\t\t\tTotal Balances: " << CalculateTotalBalances() << endl;
    cout << "_______________________________________________________";
    cout << "_________________________________________" << endl;
}

void PerformTransactionsMenuOption(enTransactionsMenuOptions transactionsMenuOptions)
{
    switch (transactionsMenuOptions)
    {
    case enTransactionsMenuOptions::opDeposit:
        ShowDepositScreen();
        GoBackToTransactionsMenu();
        break;

    case enTransactionsMenuOptions::opWithdraw:
        ShowWithdrawScreen();
        GoBackToTransactionsMenu();
        break;

    case enTransactionsMenuOptions::opTotalBalance:
        ShowTotalBalancesScreen();
        GoBackToTransactionsMenu();
        break;

    case enTransactionsMenuOptions::opMainMenu:
        ShowMainMenu();
        break;
    }
}

void ShowTransactionsScreen()
{
    TransactionsMenuScreen();
    PerformTransactionsMenuOption((enTransactionsMenuOptions)ReadTransactionsMenuOption());
}

void PerformMainMenuOption(enMainMenuOptions mainMenuOptions)
{
    switch (mainMenuOptions)
    {
    case enMainMenuOptions::opShowClintList:
        ShowAllClientScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::opAddNewClint:
        ShowAddNewClientsScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::opDeleteClint:
        ShowDeleteClientScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::opUpdateClintInfo:
        ShowUpdateClientScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::opFindClint:
        ShowFindClientScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::opTransactions:
        ShowTransactionsScreen();
        break;

    case enMainMenuOptions::opExit:
        ShowExitScreen();
        break;
    }
}

void ShowMainMenu()
{
    cout << "\n\n==================================================" << endl;
    cout << "\t\tMain Menu Screen" << endl;
    cout << "==================================================" << endl;
    cout << "[1]: Show Clint List." << endl;
    cout << "[2]: Add New Clint." << endl;
    cout << "[3]: Delete Clint." << endl;
    cout << "[4]: Update Clint Info." << endl;
    cout << "[5]: Find Clint." << endl;
    cout << "[6]: Transactions." << endl;
    cout << "[7]: Exit." << endl;
    cout << "==================================================" << endl;

    PerformMainMenuOption((enMainMenuOptions)ReadMainMenuOption());
}

int main()
{
    WelcomeMessage();

    ShowMainMenu();

    cout << endl
         << endl;

    return 0;
}