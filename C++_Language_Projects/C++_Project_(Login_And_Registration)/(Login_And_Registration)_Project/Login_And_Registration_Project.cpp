

//* >>>>> Login And Registration System Project <<<<< *//

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void menuFun();
void loginFun();
void registrationFun();
void forgotPasswordFun();
void exitFun();

int main()
{
    //* ... Variables ... *//
    // Declare variable for choice;
    int choice;
    //* ... End Variables ... *//

    // Call menu function.
    menuFun();

    // Receive value from user.
    cout << "Please enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        loginFun();
        break;

    case 2:
        registrationFun();
        break;

    case 3:
        forgotPasswordFun();
        break;

    case 4:
        exitFun();
        break;

    default:
        system("cls");
        cout << "\nNote: Please select from the options given above.";

        // Recursion function.
        main();
    }

    return 0;
}

//* ..... Functions ..... *//

// Menu function.
void menuFun()
{
    cout << "\n\n..............................................................\n";
    cout << "                   Welcome to the login page                  \n";
    cout << "............................ Menu ............................\n";
    cout << "Please enter 1 to (LOGIN)\n";
    cout << "Please enter 2 to (REGISTER)\n";
    cout << "Please enter 3 if you forgot your (PASSWORD)\n";
    cout << "Please enter 4 to (EXIT)\n\n";
}
// End Menu function.

// Login function.
void loginFun()
{
    // Declare variables.
    int count = 0;
    string userId, password, id, pass;

    // clear screen.
    system("cls");

    // Receive user name and password from user.
    cout << "\nPlease enter user name and password: \n";
    cout << "\nUser Name: ";
    cin >> userId;
    cout << "\nPassword: ";
    cin >> password;

    // Open file.
    ifstream input("records.txt");

    // Check id and pass.
    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    // Closed file.
    input.close();

    // Login successful OR Login Error.
    if (count == 1)
    {
        cout << "\n"
             << userId << ",";
        cout << "\nYour login is successful..\n";
        cout << "Thank you for login..\n";

        // Recursion function.
        main();
    }
    else
    {
        cout << "\nLogin Error..\n";
        cout << "Please check your User Name OR Password.\n";

        // Recursion function.
        main();
    }
}
// End Login function.

// Registration function.
void registrationFun()
{
    // Declare variables.
    string regUserId, regPassword, regId, regPass;

    // Clear screen.
    system("cls");

    // Receive user name and password from user.
    cout << "\nPlease enter User Name and Password:\n";
    cout << "\nUser Name: ";
    cin >> regUserId;
    cout << "\nPassword: ";
    cin >> regPassword;

    // Create file.
    ofstream f1("records.txt", ios::app);

    // Write in file.
    f1 << regUserId << ' ' << regPassword << endl;

    // Clear screen.
    system("cls");

    // Massage for user.
    cout << "\nRegistration is successful..\n";

    // Recursion function.
    main();
}
// End Registration function.

// Forgot password function.
void forgotPasswordFun()
{
    // Declare variable.
    int option;

    // Clear screen.
    system("cls");

    // massage for user.
    cout << "\nYou forget the password ?, No Worries..\n";

    // Receive value from user.
    cout << "\nEnter 1 to search your id by User Name.\n";
    cout << "Enter 2 to go back to the main Menu.\n";
    cout << "\nPlease enter Your choice: ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        // Declare variables.
        int count = 0;
        string sUserId, sId, sPass;

        // Receive User Name from user.
        cout << "\nPlease enter User Name which you remembered: ";
        cin >> sUserId;

        // Open file.
        ifstream f2("records.txt");

        // Check password.
        while (f2 >> sId >> sPass)
        {
            if (sId == sUserId)
            {
                count = 1;
            }
        }
        // Closed file.
        f2.close();

        // Found account or not.
        if (count == 1)
        {
            cout << "\nYour account is found..\n";
            cout << "Your password is: " << sPass;

            // Recursion function.
            main();
        }
        else
        {
            cout << "\nSorry!! your account is not found.\n";

            // Recursion function.
            main();
        }
    }
    break;

    case 2:
        // Recursion function.
        main();

        // break;

    default:
        cout << "\nWrong choice!! Please try again.\n";

        // Recursion function.
        forgotPasswordFun();
        
        // break;
    }
}
// End Forgot password function.

// Exit function.
void exitFun()
{
    cout << "\nThank You\n\n";
}
// End Exit function.

//* ..... End Functions ..... *//