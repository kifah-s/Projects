#include <iostream>
#include "Lib_clsDate.h"

using namespace std;

void WelcomeMessage()
{
    cout << "\n\nWelcome to the Project ..\n"
         << endl;
}

int main()
{
    WelcomeMessage();

    clsDate Date1;
    Date1.Print();

    clsDate Date2("31/1/2022");
    Date2.Print();

    clsDate Date3(20, 12, 2022);
    Date3.Print();

    clsDate Date4(250, 2022);
    Date4.Print();

    Date1.IncreaseDateByOneMonth();
    Date1.Print();

    // Date3.PrintYearCalendar();

    // cout << Date2.IsValid() << endl;

    // cout << "My Age InDays:" << clsDate::CalculateMyAgeInDays(  clsDate(6, 11, 1977) );
    
    // You can try any method at your own.

    cout << endl
         << endl;

    return 0;
}