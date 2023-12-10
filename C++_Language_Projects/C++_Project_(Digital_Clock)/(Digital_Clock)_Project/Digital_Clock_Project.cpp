

//* >>>>>>>>>>>>>>> Digital Clock Project <<<<<<<<<<<<<<< *//

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    //* Variables
    int hou = 0, min = 0, sec = 0;
    //* End Variables

    //* Welcome massage.
    cout << "\n\nYou welcome in Digital Clock\n\n";

    //* Receive value from user.
    cout << "Please enter Hours: ";
    cin >> hou;
    cout << "Please enter Minutes: ";
    cin >> min;
    cout << "Please enter Seconds: ";
    cin >> sec;

    //* Clock.
    while (true)
    {
        //* Clear screen.
        system("cls");

        if (sec > 59)
        {
            min++;
            sec = 0;
        }
        if (min > 59)
        {
            hou++;
            min = 0;
        }
        if (hou > 23)
        {
            hou = 0;
        }
        cout << "Clock: " << hou << " : " << min << " : " << sec;
        sec++;
        Sleep(1000);
    }

    return 0;
}