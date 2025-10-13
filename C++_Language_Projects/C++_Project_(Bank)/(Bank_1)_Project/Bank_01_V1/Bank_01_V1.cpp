#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string fileName = "clients.txt";

struct stClient
{
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalance;
    bool markForDelete = false;
};

enum enMainMenuScreenOptions
{
    opShowClintList = 1,
    opAddNewClint = 2,
    opDeleteClint = 3,
    opUpdateClintInfo = 4,
    opFindClint = 5,
    opExit = 6
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

short MainMenuScreen()
{
    short userChoice = 0;

    cout << "\n\n==================================================" << endl;
    cout << "\t\tMain Menu Screen" << endl;
    cout << "==================================================" << endl;
    cout << "[1]: Show Clint List." << endl;
    cout << "[2]: Add New Clint." << endl;
    cout << "[3]: Delete Clint." << endl;
    cout << "[4]: Update Clint Info." << endl;
    cout << "[5]: Find Clint." << endl;
    cout << "[6]: Exit." << endl;
    cout << "==================================================" << endl;
    cout << "Chose what do you want to do [1 / 6]: ";
    cin >> userChoice;

    return userChoice;
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

void PrintAllClientsData(vector<stClient> vecClients)
{
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

    for (stClient client : vecClients)
    {
        PrintClientRecord(client);
        cout << endl;
    }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
}

void AddNewClientScreen()
{
    cout << "--------------------------------------------" << endl;
    cout << "\tAdd New Clint Screen" << endl;
    cout << "--------------------------------------------" << endl;
}

bool IsClientExists(string accountNumber)
{
    vector<stClient> vecClients = LoadClientsDataFromFile(fileName);

    for (stClient &client : vecClients)
    {
        if (client.accountNumber == accountNumber)
        {
            return true;
        }
    }

    return false;
}

stClient ReadNewClient()
{
    stClient client;

    cout << "Enter Account Number: ";
    // Usage of std::ws will extract all the whitespace character.
    getline(cin >> ws, client.accountNumber);

    while (IsClientExists(client.accountNumber))
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

void AddClients()
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

void DeleteClientScreen()
{
    cout << "--------------------------------------------" << endl;
    cout << "\tDelete Clint Screen" << endl;
    cout << "--------------------------------------------" << endl;
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
            cout << "\n\nClient Deleted Successfully.";

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

void UpdateClientScreen()
{
    cout << "--------------------------------------------" << endl;
    cout << "\tUpdate Clint Screen" << endl;
    cout << "--------------------------------------------" << endl;
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

void FindClientScreen()
{
    cout << "--------------------------------------------" << endl;
    cout << "\tFind Clint Screen" << endl;
    cout << "--------------------------------------------" << endl;
}

void ExitScreen()
{
    cout << "\n\n==================================================" << endl;
    cout << "\t\tProgram Ends." << endl;
    cout << "==================================================" << endl;
}

void UserChoiceFromMainMenuScreen(short userChoice, vector<stClient> &vecClients)
{
    string accountNumber = "";
    stClient client;

    switch (userChoice)
    {
    case enMainMenuScreenOptions::opShowClintList:
        vecClients = LoadClientsDataFromFile(fileName);
        PrintAllClientsData(vecClients);
        cout << "\nPress any key to go back to Main Menu... ";
        system("pause > nul");
        break;

    case enMainMenuScreenOptions::opAddNewClint:
        AddNewClientScreen();
        AddClients();
        break;

    case enMainMenuScreenOptions::opDeleteClint:
        DeleteClientScreen();
        vecClients = LoadClientsDataFromFile(fileName);
        accountNumber = ReadClientAccountNumber();
        DeleteClientByAccountNumber(accountNumber, vecClients);
        break;

    case enMainMenuScreenOptions::opUpdateClintInfo:
        UpdateClientScreen();
        accountNumber = ReadClientAccountNumber();
        UpdateClientByAccountNumber(accountNumber, vecClients);
        break;

    case enMainMenuScreenOptions::opFindClint:
        FindClientScreen();
        accountNumber = ReadClientAccountNumber();
        if (FindClientByAccountNumber(accountNumber, vecClients, client))
        {
            PrintClientCard(client);
        }
        else
        {
            cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!" << endl;
        }

        cout << "\n\nPress any key to go back to Main Menu... ";
        system("pause > nul");
        break;

    case enMainMenuScreenOptions::opExit:
        ExitScreen();
        break;
    }
}

void Bank()
{
    short userChoice = 0;
    vector<stClient> vecClients;

    do
    {
        userChoice = MainMenuScreen();
        UserChoiceFromMainMenuScreen(userChoice, vecClients);
    } while (userChoice != 6);
}

int main()
{
    WelcomeMessage();

    Bank();

    cout << endl
         << endl;

    return 0;
}