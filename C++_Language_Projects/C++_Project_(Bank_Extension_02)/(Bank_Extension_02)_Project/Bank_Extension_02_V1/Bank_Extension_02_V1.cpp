#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Global Constants and Variables
const string clientsFileName = "clients.txt";
const string usersFileName = "users.txt";

// Forward Declarations
void ShowMainMenu();
void ShowTransactionsScreen();
void Logout();
void ShowManageUsersMenuScreen();
void AccessDeniedScreen();

// Data Structures
struct stClient
{
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalance;
    bool markForDelete = false;
};

struct stUserAccount
{
    string userName;
    string password;
    int permissions;
    bool markForDelete = false;
};

// Global variable to store the current user
stUserAccount currentUser;

// Enums
enum enMainMenuOptions
{
    opShowClientsList = 1,
    opAddNewClient = 2,
    opDeleteClient = 3,
    opUpdateClientInfo = 4,
    opFindClient = 5,
    opTransactions = 6,
    opManageUsers = 7,
    opLogout = 8
};

enum enManageUsersMenuOptions
{
    opShowUsersList = 1,
    opAddNewUser = 2,
    opDeleteUser = 3,
    opUpdateUser = 4,
    opFindUser = 5,
    opUsersMainMenu = 6
};

enum enTransactionsMenuOptions
{
    opDeposit = 1,
    opWithdraw = 2,
    opTotalBalance = 3,
    opTransMainMenu = 4
};

enum enClientInformation
{
    accountNumber = 0,
    pinCode = 1,
    name = 2,
    phone = 3,
    accountBalance = 4
};

enum enUserInformation
{
    userName = 0,
    password = 1,
    permissions = 2
};

enum enPermissions
{
    perAll = -1,
    perShowClientsList = 1 << 0,  // 1
    perAddNewClient = 1 << 1,     // 2
    perDeleteClient = 1 << 2,     // 4
    perUpdateClientInfo = 1 << 3, // 8
    perFindClient = 1 << 4,       // 16
    perTransactions = 1 << 5,     // 32
    perManageUsers = 1 << 6,      // 64
};

// Permission Management
bool HasPermission(stUserAccount user, enPermissions permission);

// General Utility Functions
void WelcomeMessage()
{
    cout << "\n\nWelcome to the Project ..\n"
         << endl;
}

short ReadMainMenuOption()
{
    short userChoice = 0;

    cout << "Chose what do you want to do [1 / 8]: ";
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

// Client Management Functions
stClient ConvertLineToRecordForClientsFile(string line, string separator = "#//#")
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

vector<stClient> LoadClientsDataFromFile(string clientsFileName)
{
    vector<stClient> vecClients;

    fstream myFile;
    myFile.open(clientsFileName, ios::in);

    if (myFile.is_open())
    {
        string line;
        stClient client;

        while (getline(myFile, line))
        {
            client = ConvertLineToRecordForClientsFile(line);
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
    vector<stClient> vecClients = LoadClientsDataFromFile(clientsFileName);

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

bool ClientExistsByAccountNumber(string accountNumber, string clientsFileName)
{
    vector<stClient> vecClients;

    fstream myFile;
    myFile.open(clientsFileName, ios::in); // read Mode

    if (myFile.is_open())
    {
        string line;
        stClient client;

        while (getline(myFile, line))
        {
            client = ConvertLineToRecordForClientsFile(line);

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

    while (ClientExistsByAccountNumber(client.accountNumber, clientsFileName))
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

    AddDataLineToFile(clientsFileName, ConvertRecordToLine(client));
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
    cout << "\tAdd New Client Screen" << endl;
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

vector<stClient> SaveClientsDataToFile(string clientsFileName, vector<stClient> vecClients)
{
    fstream myFile;
    myFile.open(clientsFileName, ios::out);

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
            SaveClientsDataToFile(clientsFileName, vecClients);
            vecClients = LoadClientsDataFromFile(clientsFileName);
            cout << "\nClient Deleted Successfully.";
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!";
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
    cout << "\tDelete Client Screen" << endl;
    cout << "--------------------------------------------" << endl;

    vector<stClient> vecClients = LoadClientsDataFromFile(clientsFileName);
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

            SaveClientsDataToFile(clientsFileName, vecClients);
            cout << "\n\nClient Updated Successfully.";
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!";
    }
}

void ShowUpdateClientScreen()
{
    cout << "--------------------------------------------" << endl;
    cout << "\tUpdate Client Screen" << endl;
    cout << "--------------------------------------------" << endl;

    vector<stClient> vecClients = LoadClientsDataFromFile(clientsFileName);
    string accountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(accountNumber, vecClients);
}

void ShowFindClientScreen()
{
    cout << "--------------------------------------------" << endl;
    cout << "\tFind Client Screen" << endl;
    cout << "--------------------------------------------" << endl;

    vector<stClient> vecClients = LoadClientsDataFromFile(clientsFileName);
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

// Transaction Management Functions
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

void DepositBalanceToClientByAccountNumber(string accountNumber, double depositAmount, vector<stClient> &vecClients)
{
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

        SaveClientsDataToFile(clientsFileName, vecClients);
    }
}

void AddDepositToClientAccount()
{
    string accountNumber = ReadClientAccountNumber();
    vector<stClient> vecClients = LoadClientsDataFromFile(clientsFileName);
    stClient client;

    while (!FindClientByAccountNumber(accountNumber, vecClients, client))
    {
        cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!" << endl;
        accountNumber = ReadClientAccountNumber();
    }
    PrintClientCard(client);

    double depositAmount = ReadDepositAmount();

    DepositBalanceToClientByAccountNumber(accountNumber, depositAmount, vecClients);
}

void ShowDepositScreen()
{
    cout << "\n----------------------------------------" << endl;
    cout << "\tDeposit Screen" << endl;
    cout << "----------------------------------------" << endl;

    AddDepositToClientAccount();
}

double ReadWithdrawAmount(string accountNumber, vector<stClient> vecClients, stClient client)
{
    double withdrawAmount = 0;
    cout << "\nPlease, Enter Withdraw Amount: ";
    cin >> withdrawAmount;

    while (withdrawAmount > client.accountBalance)
    {
        cout << "\nAmount Excited The Balance, You Can Withdraw Up To: " << client.accountBalance << endl;
        withdrawAmount = ReadWithdrawAmount(accountNumber, vecClients, client);
    }

    return withdrawAmount;
}

void WithdrawFromClientAccount()
{
    string accountNumber = ReadClientAccountNumber();
    vector<stClient> vecClients = LoadClientsDataFromFile(clientsFileName);
    stClient client;

    while (!FindClientByAccountNumber(accountNumber, vecClients, client))
    {
        cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!" << endl;
        accountNumber = ReadClientAccountNumber();
    }
    PrintClientCard(client);

    double withdrawAmount = ReadWithdrawAmount(accountNumber, vecClients, client);

    DepositBalanceToClientByAccountNumber(accountNumber, withdrawAmount * -1, vecClients);
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
    vector<stClient> vecClients = LoadClientsDataFromFile(clientsFileName);
    double totalBalances = 0;

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
            totalBalances += client.accountBalance;
            cout << endl;
        }
    }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
    cout << "\t\t\t\tTotal Balances: " << totalBalances << endl;
    cout << "_______________________________________________________";
    cout << "_________________________________________" << endl;
}

void ShowTotalBalancesScreen()
{
    ShowAllClientForTotalBalancesScreen();
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

    case enTransactionsMenuOptions::opTransMainMenu:
        ShowMainMenu();
        break;
    }
}

void ShowTransactionsScreen()
{
    TransactionsMenuScreen();
    PerformTransactionsMenuOption((enTransactionsMenuOptions)ReadTransactionsMenuOption());
}

// Main Menu Functions
void PerformMainMenuOption(enMainMenuOptions mainMenuOptions, stUserAccount user)
{
    switch (mainMenuOptions)
    {
    case enMainMenuOptions::opShowClientsList:
        if (HasPermission(user, enPermissions::perShowClientsList))
        {
            ShowAllClientScreen();
            GoBackToMainMenu();
        }
        else
        {
            AccessDeniedScreen();
        }
        break;

    case enMainMenuOptions::opAddNewClient:
        if (HasPermission(user, enPermissions::perAddNewClient))
        {
            ShowAddNewClientsScreen();
            GoBackToMainMenu();
        }
        else
        {
            AccessDeniedScreen();
        }
        break;

    case enMainMenuOptions::opDeleteClient:
        if (HasPermission(user, enPermissions::perDeleteClient))
        {
            ShowDeleteClientScreen();
            GoBackToMainMenu();
        }
        else
        {
            AccessDeniedScreen();
        }
        break;

    case enMainMenuOptions::opUpdateClientInfo:
        if (HasPermission(user, enPermissions::perUpdateClientInfo))
        {
            ShowUpdateClientScreen();
            GoBackToMainMenu();
        }
        else
        {
            AccessDeniedScreen();
        }
        break;

    case enMainMenuOptions::opFindClient:
        if (HasPermission(user, enPermissions::perFindClient))
        {
            ShowFindClientScreen();
            GoBackToMainMenu();
        }
        else
        {
            AccessDeniedScreen();
        }
        break;

    case enMainMenuOptions::opTransactions:
        if (HasPermission(user, enPermissions::perTransactions))
        {
            ShowTransactionsScreen();
        }
        else
        {
            AccessDeniedScreen();
        }
        break;

    case enMainMenuOptions::opManageUsers:
        if (HasPermission(user, enPermissions::perManageUsers))
        {
            ShowManageUsersMenuScreen();
        }
        else
        {
            AccessDeniedScreen();
        }
        break;

    case enMainMenuOptions::opLogout:
        Logout();
        break;
    }
}

void ShowMainMenu()
{
    cout << "\n\n==================================================" << endl;
    cout << "\t\tMain Menu Screen" << endl;
    cout << "==================================================" << endl;
    cout << "[1]: Show Client List." << endl;
    cout << "[2]: Add New Client." << endl;
    cout << "[3]: Delete Client." << endl;
    cout << "[4]: Update Client Info." << endl;
    cout << "[5]: Find Client." << endl;
    cout << "[6]: Transactions." << endl;
    cout << "[7]: Manage Users." << endl;
    cout << "[8]: Logout." << endl;
    cout << "==================================================" << endl;

    PerformMainMenuOption((enMainMenuOptions)ReadMainMenuOption(), currentUser);
}

// Login Functions
void LoginScreen()
{
    cout << "\n----------------------------------------" << endl;
    cout << "\tLogin Screen" << endl;
    cout << "----------------------------------------" << endl;
}

stUserAccount ReadUserNameAndPassword()
{
    stUserAccount user;

    cout << "Please, enter user name: ";
    getline(cin >> ws, user.userName);

    cout << "Please, enter password: ";
    cin >> user.password;

    return user;
}

stUserAccount ConvertLineToRecordForUsersFile(string line, string separator = "#//#")
{
    stUserAccount user;
    vector<string> vecUserData;

    vecUserData = SplitString(line, separator);

    user.userName = vecUserData[enUserInformation::userName];
    user.password = vecUserData[enUserInformation::password];
    user.permissions = stoi(vecUserData[enUserInformation::permissions]);

    return user;
}

vector<stUserAccount> LoadUsersDataFromFile(string usersFileName)
{
    vector<stUserAccount> vecUsers;

    fstream myFile;
    myFile.open(usersFileName, ios::in);

    if (myFile.is_open())
    {
        string line;
        stUserAccount user;

        while (getline(myFile, line))
        {
            user = ConvertLineToRecordForUsersFile(line);
            vecUsers.push_back(user);
        }

        myFile.close();
    }

    return vecUsers;
}

bool FindUserByUserNameAndPassword(string userName, string password, vector<stUserAccount> vecUsers)
{
    for (stUserAccount &user : vecUsers)
    {
        if (user.userName == userName && user.password == password)
        {
            return true;
        }
    }

    return false;
}

void ShowLoginScreen()
{
    LoginScreen();

    stUserAccount user = ReadUserNameAndPassword();
    vector<stUserAccount> vecUsers = LoadUsersDataFromFile("users.txt");

    while (!FindUserByUserNameAndPassword(user.userName, user.password, vecUsers))
    {
        cout << "\nInvalid UserName / Password.\n\n";
        user = ReadUserNameAndPassword();
    }

    // Store the current user's data
    for (stUserAccount &u : vecUsers)
    {
        if (u.userName == user.userName && u.password == user.password)
        {
            currentUser = u; // Assign the current user
            break;
        }
    }

    ShowMainMenu();
}

void Logout()
{
    ShowLoginScreen();
}

// User Management Functions
short ReadManageUsersMenuOption()
{
    short userChoice = 0;

    cout << "Chose what do you want to do [1 / 6]: ";
    cin >> userChoice;

    return userChoice;
}

void GoBackToManageUsersMenu()
{
    cout << "\nPress Any Key To Go Back Manage Users Menu ...";
    system("pause > nul");

    ShowManageUsersMenuScreen();
}

void PrintUsersRecord(stUserAccount user)
{
    cout << "| " << setw(15) << left << user.userName;
    cout << "| " << setw(10) << left << user.password;
    cout << "| " << setw(40) << left << user.permissions;
}

void ShowAllUsersScreen()
{
    vector<stUserAccount> vecUsers = LoadUsersDataFromFile(usersFileName);

    cout << "\n\n_______________________________________________________";
    cout << "_________________________________________" << endl;
    cout << "\n\t\t\t\tUser List (" << vecUsers.size() << ") User(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
    cout << "| " << left << setw(15) << "User Name";
    cout << "| " << left << setw(10) << "Password";
    cout << "| " << left << setw(40) << "Permissions";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;

    for (stUserAccount user : vecUsers)
    {
        PrintUsersRecord(user);
        cout << endl;
    }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
}

bool FindUserByUserName(string userName, vector<stUserAccount> vecUsers, stUserAccount &user)
{
    for (stUserAccount &u : vecUsers)
    {
        if (u.userName == userName)
        {
            user = u;
            return true;
        }
    }

    return false;
}

void PrintUserCard(stUserAccount user)
{
    cout << "\nThe following are the user details:\n";
    cout << "\nUsername   : " << user.userName;
    cout << "\nPassword   : " << user.password;
    cout << "\nPermissions: " << user.permissions << endl;
}

bool MarkUserForDeleteByUserName(string userName, vector<stUserAccount> &vecUsers)
{
    for (stUserAccount &u : vecUsers)
    {
        if (u.userName == userName)
        {
            u.markForDelete = true;
            return true;
        }
    }

    return false;
}

string ConvertRecordToLine(stUserAccount user, string separator = "#//#")
{
    string stUserRecord = "";

    stUserRecord += user.userName + separator;
    stUserRecord += user.password + separator;
    stUserRecord += to_string(user.permissions) + separator;

    return stUserRecord;
}

vector<stUserAccount> SaveUsersDataToFile(string usersFileName, vector<stUserAccount> vecUsers)
{
    fstream myFile;
    myFile.open(usersFileName, ios::out);

    string DataLine = "";

    if (myFile.is_open())
    {
        for (stUserAccount &u : vecUsers)
        {
            if (u.markForDelete == false)
            {
                DataLine = ConvertRecordToLine(u);
                myFile << DataLine << endl;
            }
        }

        myFile.close();
    }

    return vecUsers;
}

void DeleteUserByUserName(string userName, vector<stUserAccount> &vecUsers)
{
    stUserAccount user;
    char answer = 'n';

    if (userName == "Admin")
    {
        cout << "\nYou cannot delete this user." << endl;
        GoBackToManageUsersMenu();
    }

    if (FindUserByUserName(userName, vecUsers, user))
    {
        PrintUserCard(user);
        cout << "\n\nAre you sure you want delete this user? (y / n): ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            MarkUserForDeleteByUserName(userName, vecUsers);
            SaveUsersDataToFile(usersFileName, vecUsers);
            vecUsers = LoadUsersDataFromFile(usersFileName);
            cout << "\nUser Deleted Successfully." << endl;
        }
    }
    else
    {
        cout << "\nUser with user name (" << userName << ") is not found!" << endl;
    }
}

string ReadUserName()
{
    string userName = "";

    cout << "Please enter user name: ";
    cin >> userName;

    return userName;
}

void ShowDeleteUsersScreen()
{
    cout << "\n--------------------------------------------" << endl;
    cout << "\tDelete Users Screen" << endl;
    cout << "--------------------------------------------" << endl;

    vector<stUserAccount> vecUsers = LoadUsersDataFromFile(usersFileName);
    string userName = ReadUserName();
    DeleteUserByUserName(userName, vecUsers);
}

void ShowFindUserScreen()
{
    cout << "\n--------------------------------------------" << endl;
    cout << "\tFind User Screen" << endl;
    cout << "--------------------------------------------" << endl;

    vector<stUserAccount> vecUsers = LoadUsersDataFromFile(usersFileName);
    string userName = ReadUserName();
    stUserAccount user;

    if (FindUserByUserName(userName, vecUsers, user))
    {
        PrintUserCard(user);
    }
    else
    {
        cout << "\nUser with user name (" << userName << ") is not found!" << endl;
    }
}

bool UserExistsByUserName(string userName, string usersFileName)
{
    vector<stUserAccount> vecUsers;

    fstream myFile;
    myFile.open(usersFileName, ios::in); // Read Mode.

    if (myFile.is_open())
    {
        string line;
        stUserAccount user;

        while (getline(myFile, line))
        {
            user = ConvertLineToRecordForUsersFile(line);

            if (user.userName == userName)
            {
                myFile.close();
                return true;
            }

            vecUsers.push_back(user);
        }

        myFile.close();
    }

    return false;
}

// User Permission Assignment
void GrantPermission(stUserAccount &user, enPermissions permission)
{
    user.permissions |= permission;
}

stUserAccount GivePermissionsToUser(stUserAccount user)
{
    char answer;
    cout << "\nDo you want to give full access? (Y/N): ";
    cin >> answer;

    if (tolower(answer) == 'y')
    {
        user.permissions = enPermissions::perAll;
    }
    else
    {
        cout << "\nDo you want to give access to: " << endl;
        cout << "Show Client List? (Y/N): ";
        cin >> answer;
        if (tolower(answer) == 'y')
        {
            GrantPermission(user, enPermissions::perShowClientsList);
        }

        cout << "Add New Client? (Y/N): ";
        cin >> answer;
        if (tolower(answer) == 'y')
        {
            GrantPermission(user, enPermissions::perAddNewClient);
        }

        cout << "Delete Client? (Y/N): ";
        cin >> answer;
        if (tolower(answer) == 'y')
        {
            GrantPermission(user, enPermissions::perDeleteClient);
        }

        cout << "Find Client? (Y/N): ";
        cin >> answer;
        if (tolower(answer) == 'y')
        {
            GrantPermission(user, enPermissions::perFindClient);
        }

        cout << "Transactions? (Y/N): ";
        cin >> answer;
        if (tolower(answer) == 'y')
        {
            GrantPermission(user, enPermissions::perTransactions);
        }

        cout << "Manage Users? (Y/N): ";
        cin >> answer;
        if (tolower(answer) == 'y')
        {
            GrantPermission(user, enPermissions::perManageUsers);
        }
    }

    return user;
}

bool HasPermission(stUserAccount user, enPermissions permission)
{
    if (user.permissions == enPermissions::perAll)
    {
        return true;
    }

    return (user.permissions & permission) != 0;
}

void AccessDeniedScreen()
{
    cout << "\n----------------------------------------" << endl;
    cout << "Access Denied,\nYou dont have permission to do this,\nPlease contact your admin." << endl;
    cout << "----------------------------------------" << endl;

    GoBackToMainMenu();
}

stUserAccount ReadNewUser()
{
    stUserAccount user;

    cout << "Please, enter Username: ";
    // Usage of std::ws will extract all the whitespace character.
    getline(cin >> ws, user.userName);

    while (UserExistsByUserName(user.userName, usersFileName))
    {
        cout << "User with username [" << user.userName << "] already exists .. Please, enter another user name: ";
        // Usage of std::ws will extract all the whitespace character.
        getline(cin >> ws, user.userName);
    }

    cout << "Please, enter password: ";
    getline(cin, user.password);

    user = GivePermissionsToUser(user);

    return user;
}

void AddNewUser()
{
    stUserAccount user;

    user = ReadNewUser();

    AddDataLineToFile(usersFileName, ConvertRecordToLine(user));
}

void AddNewUsers()
{
    char addMore = 'Y';

    do
    {
        // system("cls");
        AddNewUser();
        cout << "\nClient Added Successfully, do you want to add more clients? (Y / N): ";
        cin >> addMore;
    } while (toupper(addMore) == 'Y');
}

void ShowAddNewUsersScreen()
{
    cout << "\n--------------------------------------------" << endl;
    cout << "\tAdd New User Screen" << endl;
    cout << "--------------------------------------------" << endl;

    AddNewUsers();
}

stUserAccount ChangeUserRecord(string userName)
{
    stUserAccount user;

    user.userName = userName;

    cout << "\nPlease, enter Password: ";
    getline(cin >> ws, user.password);

    user.permissions = 0;
    user = GivePermissionsToUser(user);

    return user;
}

void UpdateUserByUserName(string userName, vector<stUserAccount> &vecUsers)
{
    stUserAccount user;
    char answer = 'n';

    if (FindUserByUserName(userName, vecUsers, user))
    {
        PrintUserCard(user);

        cout << "\n\nAre you sure you want update this user? (y / n): ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            for (stUserAccount &u : vecUsers)
            {
                if (u.userName == userName)
                {
                    u = ChangeUserRecord(userName);
                    break;
                }
            }

            SaveUsersDataToFile(usersFileName, vecUsers);
            cout << "\n\nUsers Updated Successfully.";
        }
    }
    else
    {
        cout << "\nUsers with user name (" << userName << ") is not found!";
    }
}

void ShowUpdateUsersScreen()
{
    cout << "--------------------------------------------" << endl;
    cout << "\tUpdate User Screen" << endl;
    cout << "--------------------------------------------" << endl;

    vector<stUserAccount> vecUsers = LoadUsersDataFromFile(usersFileName);
    string userName = ReadUserName();
    UpdateUserByUserName(userName, vecUsers);
}

void PerformManageUsersMenuOption(enManageUsersMenuOptions manageUsersMenuOptions)
{
    switch (manageUsersMenuOptions)
    {
    case enManageUsersMenuOptions::opShowUsersList:
        ShowAllUsersScreen();
        GoBackToManageUsersMenu();
        break;

    case enManageUsersMenuOptions::opAddNewUser:
        ShowAddNewUsersScreen();
        GoBackToManageUsersMenu();
        break;

    case enManageUsersMenuOptions::opDeleteUser:
        ShowDeleteUsersScreen();
        GoBackToManageUsersMenu();
        break;

    case enManageUsersMenuOptions::opUpdateUser:
        ShowUpdateUsersScreen();
        GoBackToManageUsersMenu();
        break;

    case enManageUsersMenuOptions::opFindUser:
        ShowFindUserScreen();
        GoBackToManageUsersMenu();
        break;

    case enManageUsersMenuOptions::opUsersMainMenu:
        ShowMainMenu();
        break;
    }
}

void ShowManageUsersMenuScreen()
{
    cout << "\n\n==================================================" << endl;
    cout << "\t  Manage Users Menu Screen" << endl;
    cout << "==================================================" << endl;
    cout << "[1]: Show Users List." << endl;
    cout << "[2]: Add New User." << endl;
    cout << "[3]: Delete User." << endl;
    cout << "[4]: Update User." << endl;
    cout << "[5]: Find User." << endl;
    cout << "[6]: Main Menu." << endl;
    cout << "==================================================" << endl;

    PerformManageUsersMenuOption((enManageUsersMenuOptions)ReadManageUsersMenuOption());
}

// Main Program
int main()
{
    WelcomeMessage();

    ShowLoginScreen();

    cout << endl
         << endl;

    return 0;
}