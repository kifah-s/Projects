#include <iostream>
#include <iomanip>

#include "Classes/Login_and_Per/clsLoginScreen.h"

using namespace std;

void WelcomeMessage()
{
    cout << "\n\nWelcome to the Project ..\n"
         << endl;
}

int main()
{
    WelcomeMessage();

    while (true)
    {
        clsLoginScreen::ShowLoginScreen();
    }

    cout << endl
         << endl;

    return 0;
}