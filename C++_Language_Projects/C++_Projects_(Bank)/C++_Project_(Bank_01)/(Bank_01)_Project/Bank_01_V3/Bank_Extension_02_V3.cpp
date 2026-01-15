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

struct stUser
{
    string userName;
    string password;
    int permissions;
    bool markForDelete = false;
};

enum enMainMenuOptions
{
    mainMenuOpt_listClients = 1,
    mainMenuOpt_addNewClient = 2,
    mainMenuOpt_deleteClient = 3,
    mainMenuOpt_updateClient = 4,
    mainMenuOpt_findClient = 5,
    mainMenuOpt_showTransactionsMenu = 6,
    mainMenuOpt_manageUsers = 7,
    mainMenuOpt_logout = 8
};

enum enManageUsersMenuOptions
{
    manageUserOpt_listUsers = 1,
    manageUserOpt_addNewUser = 2,
    manageUserOpt_deleteUser = 3,
    manageUserOpt_updateUser = 4,
    manageUserOpt_findUser = 5,
    manageUserOpt_mainMenu = 6
};

enum enTransactionsMenuOptions
{
    traMenuOpt_deposit = 1,
    traMenuOpt_withdraw = 2,
    traMenuOpt_showTotalBalance = 3,
    traMenuOpt_showMainMenu = 4
};

enum enMainMenuPermissions
{
    mainMenuPer_all = -1,
    mainMenuPer_listClients = 1 << 0,  // 1
    mainMenuPer_addNewClient = 1 << 1, // 2
    mainMenuPer_deleteClient = 1 << 2, // 4
    mainMenuPer_updateClient = 1 << 3, // 8
    mainMenuPer_findClient = 1 << 4,   // 16
    mainMenuPer_transactions = 1 << 5, // 32
    mainMenuPer_manageUsers = 1 << 6,  // 64
};

enum enClientInformation
{
    clientInfo_accountNumber = 0,
    clientInfo_pinCode = 1,
    clientInfo_name = 2,
    clientInfo_phone = 3,
    clientInfo_accountBalance = 4
};

enum enUserInformation
{
    userInfo_userName = 0,
    userInfo_password = 1,
    userInfo_permissions = 2
};

const string clientsFileName = "clients.txt";
const string usersFileName = "users.txt";

stUser currentUser;

void ShowMainMenu();
void ShowTransactionsMenu();
void ShowManageUsersMenu();
bool CheckAccessPermission(enMainMenuPermissions Permission);
void Login();

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

stClient ConvertLinetoRecord(string line, string separator = "#//#")
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

stUser ConvertUserLinetoRecord(string line, string separator = "#//#")
{
    stUser user;
    vector<string> vecUserData;

    vecUserData = SplitString(line, separator);

    user.userName = vecUserData[enUserInformation::userInfo_userName];
    user.password = vecUserData[enUserInformation::userInfo_password];
    user.permissions = stoi(vecUserData[enUserInformation::userInfo_permissions]);

    return user;
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

string ConvertUserRecordToLine(stUser user, string separator = "#//#")
{
    string userRecord = "";

    userRecord += user.userName + separator;
    userRecord += user.password + separator;
    userRecord += to_string(user.permissions);

    return userRecord;
}

bool ClientExistsByAccountNumber(string accountNumber, string fileName)
{
    fstream myFile;
    myFile.open(fileName, ios::in); // Read Mode.

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
        }

        myFile.close();
    }

    return false;
}

bool UserExistsByUsername(string username, string fileName)
{
    fstream myFile;
    myFile.open(fileName, ios::in); // Read Mode.

    if (myFile.is_open())
    {
        string line;
        stUser user;

        while (getline(myFile, line))
        {
            user = ConvertUserLinetoRecord(line);

            if (user.userName == username)
            {
                myFile.close();

                return true;
            }
        }

        myFile.close();
    }

    return false;
}

stClient ReadNewClient()
{
    stClient client;

    cout << "Please, Enter Account Number: ";
    getline(cin >> ws, client.accountNumber); // Usage of std::ws will extract all the whitespace character.

    while (ClientExistsByAccountNumber(client.accountNumber, clientsFileName))
    {
        cout << "\nClient with [" << client.accountNumber << "] already exists, Please enter another account number: ";
        getline(cin >> ws, client.accountNumber);
    }

    cout << "Please, enter pin code: ";
    getline(cin, client.pinCode);

    cout << "Please, enter name: ";
    getline(cin, client.name);

    cout << "Please, enter phone: ";
    getline(cin, client.phone);

    cout << "Please, enter account balance: ";
    cin >> client.accountBalance;

    return client;
}

int ReadPermissionsToSet()
{
    int permissions = 0;
    char answer = 'n';

    cout << "\nDo you want to give full access? (y/n): ";
    cin >> answer;

    if (answer == 'y' || answer == 'Y')
    {
        return -1;
    }

    cout << "\nDo you want to give access to: ";

    cout << "\nShow Client List? (y/n): ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        permissions += enMainMenuPermissions::mainMenuPer_listClients;
    }

    cout << "\nAdd New Client? (y/n): ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        permissions += enMainMenuPermissions::mainMenuPer_addNewClient;
    }

    cout << "\nDelete Client? (y/n): ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        permissions += enMainMenuPermissions::mainMenuPer_deleteClient;
    }

    cout << "\nUpdate Client? (y/n): ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        permissions += enMainMenuPermissions::mainMenuPer_updateClient;
    }

    cout << "\nFind Client? (y/n): ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        permissions += enMainMenuPermissions::mainMenuPer_findClient;
    }

    cout << "\nTransactions? (y/n): ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        permissions += enMainMenuPermissions::mainMenuPer_transactions;
    }

    cout << "\nManage Users? (y/n): ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        permissions += enMainMenuPermissions::mainMenuPer_manageUsers;
    }

    return permissions;
}

stUser ReadNewUser()
{
    stUser user;

    cout << "Please, enter Username: ";
    getline(cin >> ws, user.userName); // Usage of std::ws will extract all the whitespace character.

    while (UserExistsByUsername(user.userName, usersFileName))
    {
        cout << "\nUser with [" << user.userName << "] already exists, Please, enter another username: ";
        getline(cin >> ws, user.userName);
    }

    cout << "Please, enter password: ";
    getline(cin, user.password);

    user.permissions = ReadPermissionsToSet();

    return user;
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

            client = ConvertLinetoRecord(line);

            vecClients.push_back(client);
        }

        myFile.close();
    }

    return vecClients;
}

vector<stUser> LoadUsersDataFromFile(string fileName)
{
    vector<stUser> vecUsers;

    fstream myFile;
    myFile.open(fileName, ios::in); // Read Mode.

    if (myFile.is_open())
    {
        string line;
        stUser user;

        while (getline(myFile, line))
        {
            user = ConvertUserLinetoRecord(line);

            vecUsers.push_back(user);
        }

        myFile.close();
    }

    return vecUsers;
}

void PrintClientRecordLine(stClient client)
{
    cout << "| " << setw(15) << left << client.accountNumber;
    cout << "| " << setw(10) << left << client.pinCode;
    cout << "| " << setw(40) << left << client.name;
    cout << "| " << setw(12) << left << client.phone;
    cout << "| " << setw(12) << left << client.accountBalance;
}

void PrintUserRecordLine(stUser user)
{
    cout << "| " << setw(15) << left << user.userName;
    cout << "| " << setw(10) << left << user.password;
    cout << "| " << setw(40) << left << user.permissions;
}

void PrintClientRecordBalanceLine(stClient client)
{
    cout << "| " << setw(15) << left << client.accountNumber;
    cout << "| " << setw(40) << left << client.name;
    cout << "| " << setw(12) << left << client.accountBalance;
}

void ShowAccessDeniedMessage()
{
    cout << "\n------------------------------------\n";
    cout << "Access denied, \nYou dont have permission to do this,\nPlease conact your admin.";
    cout << "\n------------------------------------\n";
}

void ShowAllClientsScreen()
{
    if (!CheckAccessPermission(enMainMenuPermissions::mainMenuPer_listClients))
    {
        ShowAccessDeniedMessage();
        return;
    }

    vector<stClient> vecClients = LoadClientsDataFromFile(clientsFileName);

    cout << "\n\t\t\t\t\tClient List (" << vecClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;

    if (vecClients.size() == 0)
    {
        cout << "\t\t\t\tNo clients available in the system!";
    }
    else
    {
        for (stClient &client : vecClients)
        {
            PrintClientRecordLine(client);
            cout << endl;
        }
    }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
}

void ShowAllUsersScreen()
{
    vector<stUser> vecUsers = LoadUsersDataFromFile(usersFileName);

    cout << "\n\t\t\t\tUsers List (" << vecUsers.size() << ") User(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;

    cout << "| " << left << setw(15) << "User Name";
    cout << "| " << left << setw(10) << "Password";
    cout << "| " << left << setw(40) << "Permissions";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;

    if (vecUsers.size() == 0)
    {
        cout << "\t\t\t\tNo users available in the system!";
    }
    else
    {
        for (stUser &user : vecUsers)
        {
            PrintUserRecordLine(user);
            cout << endl;
        }
    }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
}

void ShowTotalBalances()
{
    vector<stClient> vecClients = LoadClientsDataFromFile(clientsFileName);

    cout << "\n\t\t\t\t\tBalances List (" << vecClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;

    double totalBalances = 0;

    if (vecClients.size() == 0)
    {
        cout << "\t\t\t\tNo clients available in the system!";
    }
    else
    {
        for (stClient &client : vecClients)
        {

            PrintClientRecordBalanceLine(client);
            totalBalances += client.accountBalance;

            cout << endl;
        }
    }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;

    cout << "\t\t\t\t\t   Total Balances: " << totalBalances;
}

void PrintClientCard(stClient client)
{
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------";
    cout << "\nAccount Number: " << client.accountNumber;
    cout << "\nPin Code     : " << client.pinCode;
    cout << "\nName         : " << client.name;
    cout << "\nPhone        : " << client.phone;
    cout << "\nAccount Balance: " << client.accountBalance;
    cout << "\n-----------------------------------\n";
}

void PrintUserCard(stUser user)
{
    cout << "\nThe following are the user details:\n";
    cout << "-----------------------------------";
    cout << "\nUsername    : " << user.userName;
    cout << "\nPassword    : " << user.password;
    cout << "\nPermissions : " << user.permissions;
    cout << "\n-----------------------------------\n";
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

bool FindUserByUsername(string username, vector<stUser> vecUsers, stUser &user)
{
    for (stUser &u : vecUsers)
    {
        if (u.userName == username)
        {
            user = u;

            return true;
        }
    }

    return false;
}

bool FindUserByUsernameAndPassword(string username, string password, stUser &user)
{
    vector<stUser> vecUsers = LoadUsersDataFromFile(usersFileName);

    for (stUser &u : vecUsers)
    {
        if (u.userName == username && u.password == password)
        {
            user = u;

            return true;
        }
    }

    return false;
}

stClient ChangeClientRecord(string accountNumber)
{
    stClient client;

    client.accountNumber = accountNumber;

    cout << "\n\nPlease, enter Pin code: ";
    getline(cin >> ws, client.pinCode);

    cout << "Please, enter name: ";
    getline(cin, client.name);

    cout << "Please, enter phone: ";
    getline(cin, client.phone);

    cout << "Please, enter account balance: ";
    cin >> client.accountBalance;

    return client;
}

stUser ChangeUserRecord(string username)
{
    stUser user;

    user.userName = username;

    cout << "\n\nPlease, enter password: ";
    getline(cin >> ws, user.password);

    user.permissions = ReadPermissionsToSet();

    return user;
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

bool MarkUserForDeleteByUsername(string username, vector<stUser> &vecUsers)
{
    for (stUser &u : vecUsers)
    {
        if (u.userName == username)
        {
            u.markForDelete = true;

            return true;
        }
    }

    return false;
}

vector<stClient> SaveClientsDataToFile(string fileName, vector<stClient> vecClients)
{
    fstream myFile;
    myFile.open(fileName, ios::out); // Write Mode.

    string dataLine;

    if (myFile.is_open())
    {
        for (stClient &c : vecClients)
        {
            if (c.markForDelete == false)
            {
                // We only write records that are not marked for delete.
                dataLine = ConvertRecordToLine(c);
                myFile << dataLine << endl;
            }
        }

        myFile.close();
    }

    return vecClients;
}

vector<stUser> SaveUsersDataToFile(string fileName, vector<stUser> vecUsers)
{
    fstream myFile;
    myFile.open(fileName, ios::out); // Write Mode.

    string dataLine;

    if (myFile.is_open())
    {
        for (stUser &u : vecUsers)
        {
            if (u.markForDelete == false)
            {
                // We only write records that are not marked for delete.
                dataLine = ConvertUserRecordToLine(u);
                myFile << dataLine << endl;
            }
        }

        myFile.close();
    }

    return vecUsers;
}

void AddDataLineToFile(string fileName, string dataLine)
{
    fstream myFile;
    myFile.open(fileName, ios::out | ios::app);

    if (myFile.is_open())
    {
        myFile << dataLine << endl;

        myFile.close();
    }
}

void AddNewClient()
{
    stClient client;

    client = ReadNewClient();

    AddDataLineToFile(clientsFileName, ConvertRecordToLine(client));
}

void AddNewUser()
{
    stUser user;

    user = ReadNewUser();

    AddDataLineToFile(usersFileName, ConvertUserRecordToLine(user));
}

void AddNewClients()
{
    char addMore = 'Y';

    do
    {
        // system("cls");
        cout << "Adding New Client:\n\n";

        AddNewClient();

        cout << "\nClient added successfully, do you want to add more clients? (y/n): ";
        cin >> addMore;

    } while (toupper(addMore) == 'Y');
}

void AddNewUsers()
{
    char addMore = 'Y';

    do
    {
        // system("cls");
        cout << "Adding New User:\n\n";

        AddNewUser();

        cout << "\nUser added successfully, do you want to add more users? (y/n): ";
        cin >> addMore;

    } while (toupper(addMore) == 'Y');
}

bool DeleteClientByAccountNumber(string accountNumber, vector<stClient> &vecClients)
{
    stClient client;
    char answer = 'n';

    if (FindClientByAccountNumber(accountNumber, vecClients, client))
    {
        PrintClientCard(client);

        cout << "\n\nAre you sure you want delete this client? (y/n): ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(accountNumber, vecClients);
            SaveClientsDataToFile(clientsFileName, vecClients);

            // Refresh Clients
            vecClients = LoadClientsDataFromFile(clientsFileName);

            cout << "\n\nClient Deleted Successfully.";

            return true;
        }
        
    }
    else
    {
        cout << "\nClient with account number (" << accountNumber << ") is not found!";

        return false;
    }

    return false;
}

bool DeleteUserByUsername(string username, vector<stUser> &vecUsers)
{
    if (username == "Admin")
    {
        cout << "\n\nYou cannot delete this user.";

        return false;
    }

    stUser user;
    char answer = 'n';

    if (FindUserByUsername(username, vecUsers, user))
    {
        PrintUserCard(user);

        cout << "\n\nAre you sure you want delete this user? (y/n): ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            MarkUserForDeleteByUsername(username, vecUsers);
            SaveUsersDataToFile(usersFileName, vecUsers);

            // Refresh Clients
            vecUsers = LoadUsersDataFromFile(usersFileName);

            cout << "\n\nUser Deleted Successfully.";

            return true;
        }
    }
    else
    {
        cout << "\nUser with username (" << username << ") is not found!";

        return false;
    }

    return false;
}

bool UpdateClientByAccountNumber(string accountNumber, vector<stClient> &vecClients)
{
    stClient client;
    char answer = 'n';

    if (FindClientByAccountNumber(accountNumber, vecClients, client))
    {
        PrintClientCard(client);

        cout << "\n\nAre you sure you want update this client? (y/n): ";
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

            return true;
        }
    }
    else
    {
        cout << "\nClient with account number (" << accountNumber << ") is not found!";

        return false;
    }

    return false;
}

bool UpdateUserByUsername(string username, vector<stUser> &vecUsers)
{
    stUser user;
    char answer = 'n';

    if (FindUserByUsername(username, vecUsers, user))
    {
        PrintUserCard(user);

        cout << "\n\nAre you sure you want update this user? (y/n): ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            for (stUser &u : vecUsers)
            {
                if (u.userName == username)
                {
                    u = ChangeUserRecord(username);
                    break;
                }
            }

            SaveUsersDataToFile(usersFileName, vecUsers);

            cout << "\n\nUser Updated Successfully.";

            return true;
        }
    }
    else
    {
        cout << "\nUser with user name (" << username << ") is not found!";

        return false;
    }

    return false;
}

bool DepositBalanceToClientByAccountNumber(string accountNumber, double amount, vector<stClient> &vecClients)
{
    char answer = 'n';

    cout << "\n\nAre you sure you want perfrom this transaction? (y/n): ";
    cin >> answer;

    if (answer == 'y' || answer == 'Y')
    {
        for (stClient &c : vecClients)
        {
            if (c.accountNumber == accountNumber)
            {
                c.accountBalance += amount;

                SaveClientsDataToFile(clientsFileName, vecClients);

                cout << "\n\nDone Successfully.. New balance is: " << c.accountBalance;

                return true;
            }
        }

        return false;
    }

    return false;
}

string ReadClientAccountNumber()
{
    string accountNumber = "";

    cout << "\nPlease enter account number: ";
    cin >> accountNumber;

    return accountNumber;
}

string ReadUserName()
{
    string username = "";

    cout << "\nPlease enter username: ";
    cin >> username;

    return username;
}

void ShowListUsersScreen()
{
    ShowAllUsersScreen();
}

void ShowAddNewUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tAdd New User Screen";
    cout << "\n-----------------------------------\n";

    AddNewUsers();
}

void ShowDeleteUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDelete Users Screen";
    cout << "\n-----------------------------------\n";

    vector<stUser> vecUsers = LoadUsersDataFromFile(usersFileName);

    string username = ReadUserName();

    DeleteUserByUsername(username, vecUsers);
}

void ShowUpdateUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Users Screen";
    cout << "\n-----------------------------------\n";

    vector<stUser> vecUsers = LoadUsersDataFromFile(usersFileName);

    string username = ReadUserName();

    UpdateUserByUsername(username, vecUsers);
}

void ShowDeleteClientScreen()
{
    if (!CheckAccessPermission(enMainMenuPermissions::mainMenuPer_deleteClient))
    {
        ShowAccessDeniedMessage();

        return;
    }

    cout << "\n-----------------------------------\n";
    cout << "\tDelete Client Screen";
    cout << "\n-----------------------------------\n";

    vector<stClient> vecClients = LoadClientsDataFromFile(clientsFileName);

    string accountNumber = ReadClientAccountNumber();

    DeleteClientByAccountNumber(accountNumber, vecClients);
}

void ShowUpdateClientScreen()
{
    if (!CheckAccessPermission(enMainMenuPermissions::mainMenuPer_updateClient))
    {
        ShowAccessDeniedMessage();

        return;
    }

    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Client Info Screen";
    cout << "\n-----------------------------------\n";

    vector<stClient> vecClients = LoadClientsDataFromFile(clientsFileName);

    string accountNumber = ReadClientAccountNumber();

    UpdateClientByAccountNumber(accountNumber, vecClients);
}

void ShowAddNewClientsScreen()
{
    if (!CheckAccessPermission(enMainMenuPermissions::mainMenuPer_addNewClient))
    {
        ShowAccessDeniedMessage();

        return;
    }

    cout << "\n-----------------------------------\n";
    cout << "\tAdd New Clients Screen";
    cout << "\n-----------------------------------\n";

    AddNewClients();
}

void ShowFindClientScreen()
{
    if (!CheckAccessPermission(enMainMenuPermissions::mainMenuPer_findClient))
    {
        ShowAccessDeniedMessage();

        return;
    }

    cout << "\n-----------------------------------\n";
    cout << "\tFind Client Screen";
    cout << "\n-----------------------------------\n";

    vector<stClient> vecClients = LoadClientsDataFromFile(clientsFileName);

    stClient client;
    string accountNumber = ReadClientAccountNumber();

    if (FindClientByAccountNumber(accountNumber, vecClients, client))
    {
        PrintClientCard(client);
    }
    else
    {
        cout << "\nClient with account number[" << accountNumber << "] is not found!";
    }
}

void ShowFindUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tFind User Screen";
    cout << "\n-----------------------------------\n";

    vector<stUser> vecUsers = LoadUsersDataFromFile(usersFileName);

    stUser user;
    string username = ReadUserName();

    if (FindUserByUsername(username, vecUsers, user))
    {
        PrintUserCard(user);
    }
    else
    {
        cout << "\nUser with username [" << username << "] is not found!";
    }
}

void ShowEndScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tProgram Ends :-)";
    cout << "\n-----------------------------------\n";
}

void ShowDepositScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n-----------------------------------\n";

    stClient client;

    vector<stClient> vecClients = LoadClientsDataFromFile(clientsFileName);
    string accountNumber = ReadClientAccountNumber();

    while (!FindClientByAccountNumber(accountNumber, vecClients, client))
    {
        cout << "\nClient with [" << accountNumber << "] does not exist.\n";

        accountNumber = ReadClientAccountNumber();
    }

    PrintClientCard(client);

    double amount = 0;
    cout << "\nPlease enter deposit amount: ";
    cin >> amount;

    DepositBalanceToClientByAccountNumber(accountNumber, amount, vecClients);
}

void ShowWithDrawScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tWithdraw Screen";
    cout << "\n-----------------------------------\n";

    stClient client;

    vector<stClient> vecClients = LoadClientsDataFromFile(clientsFileName);
    string accountNumber = ReadClientAccountNumber();

    while (!FindClientByAccountNumber(accountNumber, vecClients, client))
    {
        cout << "\nClient with [" << accountNumber << "] does not exist.\n";

        accountNumber = ReadClientAccountNumber();
    }

    PrintClientCard(client);

    double amount = 0;
    cout << "\nPlease enter withdraw amount: ";
    cin >> amount;

    // Validate that the amount does not exceeds the balance.
    while (amount > client.accountBalance)
    {
        cout << "\nAmount exceeds the balance, you can withdraw up to : " << client.accountBalance << endl;
        cout << "Please enter another amount: ";
        cin >> amount;
    }

    DepositBalanceToClientByAccountNumber(accountNumber, amount * -1, vecClients);
}

void ShowTotalBalancesScreen()
{
    ShowTotalBalances();
}

bool CheckAccessPermission(enMainMenuPermissions permission)
{
    if (currentUser.permissions == enMainMenuPermissions::mainMenuPer_all)
    {
        return true;
    }

    if ((permission & currentUser.permissions) == permission)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void GoBackToMainMenu()
{
    cout << "\n\nPress any key to go back to main menu...";
    system("pause > nul");

    ShowMainMenu();
}

void GoBackToTransactionsMenu()
{
    cout << "\n\nPress any key to go back to transactions menu...";
    system("pause > nul");

    ShowTransactionsMenu();
}

void GoBackToManageUsersMenu()
{
    cout << "\n\nPress any key to go back to transactions menu...";
    system("pause > nul");

    ShowManageUsersMenu();
}

short ReadTransactionsMenuOption()
{
    short choice = 0;
    cout << "Choose what do you want to do? [1 to 4]: ";
    cin >> choice;

    return choice;
}

void PerfromTransactionsMenuOption(enTransactionsMenuOptions transactionMenuOption)
{
    switch (transactionMenuOption)
    {
    case enTransactionsMenuOptions::traMenuOpt_deposit:
    {
        system("cls");
        ShowDepositScreen();
        GoBackToTransactionsMenu();
        break;
    }

    case enTransactionsMenuOptions::traMenuOpt_withdraw:
    {
        system("cls");
        ShowWithDrawScreen();
        GoBackToTransactionsMenu();
        break;
    }

    case enTransactionsMenuOptions::traMenuOpt_showTotalBalance:
    {
        system("cls");
        ShowTotalBalancesScreen();
        GoBackToTransactionsMenu();
        break;
    }

    case enTransactionsMenuOptions::traMenuOpt_showMainMenu:
    {
        ShowMainMenu();
    }
    }
}

void ShowTransactionsMenu()
{
    if (!CheckAccessPermission(enMainMenuPermissions::mainMenuPer_transactions))
    {
        ShowAccessDeniedMessage();
        GoBackToMainMenu();
        return;
    }

    system("cls");
    cout << "===========================================\n";
    cout << "\t\tTransactions Menu Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Deposit.\n";
    cout << "\t[2] Withdraw.\n";
    cout << "\t[3] Total Balances.\n";
    cout << "\t[4] Main Menu.\n";
    cout << "===========================================\n";

    PerfromTransactionsMenuOption((enTransactionsMenuOptions)ReadTransactionsMenuOption());
}

short ReadMainMenuOption()
{
    short choice = 0;
    cout << "Choose what do you want to do? [1 to 8]: ";
    cin >> choice;

    return choice;
}

void PerfromManageUsersMenuOption(enManageUsersMenuOptions manageUsersMenuOption)
{
    switch (manageUsersMenuOption)
    {
    case enManageUsersMenuOptions::manageUserOpt_listUsers:
    {
        system("cls");
        ShowListUsersScreen();
        GoBackToManageUsersMenu();
        break;
    }

    case enManageUsersMenuOptions::manageUserOpt_addNewUser:
    {
        system("cls");
        ShowAddNewUserScreen();
        GoBackToManageUsersMenu();
        break;
    }

    case enManageUsersMenuOptions::manageUserOpt_deleteUser:
    {
        system("cls");
        ShowDeleteUserScreen();
        GoBackToManageUsersMenu();
        break;
    }

    case enManageUsersMenuOptions::manageUserOpt_updateUser:
    {
        system("cls");
        ShowUpdateUserScreen();
        GoBackToManageUsersMenu();
        break;
    }

    case enManageUsersMenuOptions::manageUserOpt_findUser:
    {
        system("cls");

        ShowFindUserScreen();
        GoBackToManageUsersMenu();
        break;
    }

    case enManageUsersMenuOptions::manageUserOpt_mainMenu:
    {
        ShowMainMenu();
    }
    }
}

short ReadManageUsersMenuOption()
{
    short choice = 0;
    cout << "Choose what do you want to do? [1 to 6]: ";
    cin >> choice;

    return choice;
}

void ShowManageUsersMenu()
{
    if (!CheckAccessPermission(enMainMenuPermissions::mainMenuPer_manageUsers))
    {
        ShowAccessDeniedMessage();
        GoBackToMainMenu();
        return;
    }

    system("cls");
    cout << "===========================================\n";
    cout << "\t  Manage Users Menu Screen\n";
    cout << "===========================================\n";
    cout << "[1] List Users.\n";
    cout << "[2] Add New User.\n";
    cout << "[3] Delete User.\n";
    cout << "[4] Update User.\n";
    cout << "[5] Find User.\n";
    cout << "[6] Main Menu.\n";
    cout << "===========================================\n";

    PerfromManageUsersMenuOption((enManageUsersMenuOptions)ReadManageUsersMenuOption());
}

void PerfromMainMenuOption(enMainMenuOptions mainMenuOption)
{
    switch (mainMenuOption)
    {
    case enMainMenuOptions::mainMenuOpt_listClients:
    {
        system("cls");
        ShowAllClientsScreen();
        GoBackToMainMenu();
        break;
    }
    case enMainMenuOptions::mainMenuOpt_addNewClient:
        system("cls");
        ShowAddNewClientsScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::mainMenuOpt_deleteClient:
        system("cls");
        ShowDeleteClientScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::mainMenuOpt_updateClient:
        system("cls");
        ShowUpdateClientScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::mainMenuOpt_findClient:
        system("cls");
        ShowFindClientScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::mainMenuOpt_showTransactionsMenu:
        system("cls");
        ShowTransactionsMenu();
        break;

    case enMainMenuOptions::mainMenuOpt_manageUsers:
        system("cls");
        ShowManageUsersMenu();
        break;

    case enMainMenuOptions::mainMenuOpt_logout:
        system("cls");
        // ShowEndScreen();
        Login();

        break;
    }
}

void ShowMainMenu()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t    Main Menu Screen\n";
    cout << "===========================================\n";
    cout << "[1] Show Client List.\n";
    cout << "[2] Add New Client.\n";
    cout << "[3] Delete Client.\n";
    cout << "[4] Update Client Info.\n";
    cout << "[5] Find Client.\n";
    cout << "[6] Transactions.\n";
    cout << "[7] Manage Users.\n";
    cout << "[8] Logout.\n";
    cout << "===========================================\n";

    PerfromMainMenuOption((enMainMenuOptions)ReadMainMenuOption());
}

bool LoadUserInfo(string username, string password)
{
    if (FindUserByUsernameAndPassword(username, password, currentUser))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Login()
{
    bool loginFailed = false;
    string username, password;

    do
    {
        // system("cls");

        cout << "\n---------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n---------------------------------\n";

        if (loginFailed)
        {
            cout << "\nInvalid username/password!\n\n";
        }

        cout << "Please, Enter username: ";
        cin >> username;

        cout << "Please, Enter password: ";
        cin >> password;

        loginFailed = !LoadUserInfo(username, password);

    } while (loginFailed);

    ShowMainMenu();
}

int main()
{
    WelcomeMessage();

    Login();

    cout << endl
         << endl;

    return 0;
}