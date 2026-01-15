#pragma once

#include <iostream>
#include <iomanip>

#include "../UI/clsScreen.h"
#include "../UI/User_Menu/clsUser.h"
#include "../UI/Main_Menu/clsMainScreen.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{
private:
    static bool _Login()
    {
        bool LoginFailed = false;
        short FailedLoginCount = 0;
        string Username, Password;

        do
        {
            if (LoginFailed)
            {
                FailedLoginCount++;
                cout << "\n\t\t\t\t\tInvalid Username/Password!\n";
                cout << "\n\t\t\t\t\tYou have " << (3 - FailedLoginCount) << " Trial(s) to login.\n\n";
            }

            if (FailedLoginCount == 3)
            {
                cout << "\n\t\t\t\t\tYour are Locked after 3 failed trails \n\n";
                return false;
            }

            cout << "\t\t\t\t\tEnter Username? ";
            cin >> Username;

            cout << "\t\t\t\t\tEnter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFailed = CurrentUser.IsEmpty();

        } while (LoginFailed);

        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenu();
        return true;
    }

    void _Log()
    {
    }

public:
    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();
    }
};
