

//* >>>>>>>>>>>>>>> Airline Reservation Project <<<<<<<<<<<<<<< *//

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void mainMenu();

//* ............. Classes .............
// Create Management class.
class Management
{
public:
    // Constructor.
    Management()
    {
        mainMenu();
    }
};
// End Management class.

// Create details class.
class Details
{
public:
    // Declare variable.
    static string name, gender;
    static int cId;
    int phoneNum, age;
    string add;
    char arr[100];

    void information()
    {
        // Receive client details.
        cout << "Please enter costumer ID: ";
        cin >> cId;

        cout << "Please enter Name: ";
        cin >> name;

        cout << "Please enter Age: ";
        cin >> age;

        cout << "Please enter Address: ";
        cin >> add;

        cout << "Please enter Gender: ";
        cin >> gender;

        cout << "\nYour details are saved with us.";
    }
};
int Details ::cId;
string Details ::name;
string Details ::gender;
// End details class.

// Creat Registration class.
class Registration
{
public:
    // Declare variable.
    static int choice;
    static float charges;
    int back, choice1;

    void flights()
    {
        // Declare array.
        string flightN[] = {"Dubai", "Canada", "UK", "USA", "Australia", "Europe"};

        for (int a = 0; a < 6; a++)
        {
            cout << (a + 1) << ". Flight to " << flightN[a] << ".\n";
        }

        // Select country.
        cout << "\nWelcome to the Airlines ..\n";
        cout << "\nPlease enter the number of the country you want to book the flight: ";
        cin >> choice;

        switch (choice)
        {
        // Dubai.
        case 1:
        {
            // Select flight.
            cout << "\nWelcome to dubai, Enjoy ..\n";
            cout << "\nFollowing are the flights: \n";
            cout << "1. DUB - 123 : (01 - 01 - 2024), (8:00 AM), (1400$)\n";
            cout << "2. DUB - 456 : (02 - 01 - 2024), (8:00 AM), (1400$)\n";
            cout << "3. DUB - 789 : (03 - 01 - 2024), (8:00 AM), (1400$)\n";

            cout << "\nPlease select the flight you want to book: ";
            cin >> choice1;

            if (choice1 == 1)
            {
                charges = 1400;
                cout << "\nYou have successfully booked the flight DUB - 123 ..\n";
                cout << "\nYou can go back to menu and take the ticket.\n";
            }
            else if (choice1 == 2)
            {
                charges = 1400;
                cout << "\nYou have successfully booked the flight DUB - 456 ..\n";
                cout << "\nYou can go back to menu and take the ticket.\n";
            }
            else if (choice1 == 3)
            {
                charges = 1400;
                cout << "\nYou have successfully booked the flight DUB - 789 ..\n";
                cout << "\nYou can go back to menu and take the ticket.\n";
            }
            else
            {
                cout << "\nInvalid input, shifting to the previous menu..\n";

                flights();
            }

            cout << "\nPlease enter any kay to go back to main menu: ";
            cin >> back;
            if (back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }
        }
        break;

        // Canada.
        case 2:
        {
            // Select flight.
            cout << "\nWelcome to Canada, Enjoy ..\n";
            cout << "\nFollowing are the flights: \n";
            cout << "1. CAN - 123 : (01 - 01 - 2024), (10:00 AM), (1600$)\n";
            cout << "2. CAN - 456 : (02 - 01 - 2024), (10:00 AM), (1600$)\n";
            cout << "3. CAN - 789 : (03 - 01 - 2024), (10:00 AM), (1600$)\n";

            cout << "\nPlease select the flight you want to book: ";
            cin >> choice1;

            if (choice1 == 1)
            {
                charges = 1600;
                cout << "\nYou have successfully booked the flight CAN - 123 ..\n";
                cout << "\nYou can go back to menu and take the ticket.\n";
            }
            else if (choice1 == 2)
            {
                charges = 1600;
                cout << "\nYou have successfully booked the flight CAN - 456 ..\n";
                cout << "\nYou can go back to menu and take the ticket.\n";
            }
            else if (choice1 == 3)
            {
                charges = 1600;
                cout << "\nYou have successfully booked the flight CAN - 789 ..\n";
                cout << "\nYou can go back to menu and take the ticket.\n";
            }
            else
            {
                cout << "\nInvalid input, shifting to the previous menu..\n";

                flights();
            }

            cout << "\nPlease enter any kay to go back to main menu: ";
            cin >> back;
            if (back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }
        }
        break;

        // UK.
        case 3:
        {
            // Select flight.
            cout << "\nWelcome to UK, Enjoy ..\n";
            cout << "\nFollowing are the flights: \n";
            cout << "1. UK - 123 : (01 - 01 - 2024), (12:00 PM), (1800$)\n";
            cout << "2. UK - 456 : (02 - 01 - 2024), (12:00 PM), (1800$)\n";
            cout << "3. UK - 789 : (03 - 01 - 2024), (12:00 PM), (1800$)\n";

            cout << "\nPlease select the flight you want to book: ";
            cin >> choice1;

            if (choice1 == 1)
            {
                charges = 1800;
                cout << "\nYou have successfully booked the flight UK - 123 ..\n";
                cout << "\nYou can go back to menu and take the ticket.\n";
            }
            else if (choice1 == 2)
            {
                charges = 1800;
                cout << "\nYou have successfully booked the flight UK - 456 ..\n";
                cout << "\nYou can go back to menu and take the ticket.\n";
            }
            else if (choice1 == 3)
            {
                charges = 1800;
                cout << "\nYou have successfully booked the flight UK - 789 ..\n";
                cout << "\nYou can go back to menu and take the ticket.\n";
            }
            else
            {
                cout << "\nInvalid input, shifting to the previous menu..\n";

                flights();
            }

            cout << "\nPlease enter any kay to go back to main menu: ";
            cin >> back;
            if (back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }
        }
        break;

        // USA.
        case 4:
        {
            // Select flight.
            cout << "\nWelcome to USA, Enjoy ..\n";
            cout << "\nFollowing are the flights: \n";
            cout << "1. USA - 123 : (01 - 01 - 2024), (2:00 PM), (2000$)\n";
            cout << "2. USA - 456 : (02 - 01 - 2024), (2:00 PM), (2000$)\n";
            cout << "3. USA - 789 : (03 - 01 - 2024), (2:00 PM), (2000$)\n";

            cout << "\nPlease select the flight you want to book: ";
            cin >> choice1;

            if (choice1 == 1)
            {
                charges = 2000;
                cout << "\nYou have successfully booked the flight USA - 123 ..\n";
                cout << "\nYou can go back to menu and take the ticket.\n";
            }
            else if (choice1 == 2)
            {
                charges = 2000;
                cout << "\nYou have successfully booked the flight USA - 456 ..\n";
                cout << "\nYou can go back to menu and take the ticket.\n";
            }
            else if (choice1 == 3)
            {
                charges = 2000;
                cout << "\nYou have successfully booked the flight USA - 789 ..\n";
                cout << "\nYou can go back to menu and take the ticket.\n";
            }
            else
            {
                cout << "\nInvalid input, shifting to the previous menu..\n";

                flights();
            }

            cout << "\nPlease enter any kay to go back to main menu: ";
            cin >> back;
            if (back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }
        }
        break;

        // Australia.
        case 5:
        {
            // Select flight.
            cout << "\nWelcome to Australia, Enjoy ..\n";
            cout << "\nFollowing are the flights: \n";
            cout << "1. AUS - 123 : (01 - 01 - 2024), (4:00 PM), (2200$)\n";
            cout << "2. AUS - 456 : (02 - 01 - 2024), (4:00 PM), (2200$)\n";
            cout << "3. AUS - 789 : (03 - 01 - 2024), (4:00 PM), (2200$)\n";

            cout << "\nPlease select the flight you want to book: ";
            cin >> choice1;

            if (choice1 == 1)
            {
                charges = 2200;
                cout << "\nYou have successfully booked the flight AUS - 123 ..\n";
                cout << "\nYou can go back to menu and take the ticket.\n";
            }
            else if (choice1 == 2)
            {
                charges = 2200;
                cout << "\nYou have successfully booked the flight AUS - 456 ..\n";
                cout << "\nYou can go back to menu and take the ticket.\n";
            }
            else if (choice1 == 3)
            {
                charges = 2200;
                cout << "\nYou have successfully booked the flight AUS - 789 ..\n";
                cout << "\nYou can go back to menu and take the ticket.\n";
            }
            else
            {
                cout << "\nInvalid input, shifting to the previous menu..\n";

                flights();
            }

            cout << "\nPlease enter any kay to go back to main menu: ";
            cin >> back;
            if (back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }
        }
        break;

        // Europe.
        case 6:
        {
            // Select flight.
            cout << "\nWelcome to Europe, Enjoy ..\n";
            cout << "\nFollowing are the flights: \n";
            cout << "1. EUR - 123 : (01 - 01 - 2024), (6:00 PM), (2400$)\n";
            cout << "2. EUR - 456 : (02 - 01 - 2024), (6:00 PM), (2400$)\n";
            cout << "3. EUR - 789 : (03 - 01 - 2024), (6:00 PM), (2400$)\n";

            cout << "\nPlease select the flight you want to book: ";
            cin >> choice1;

            if (choice1 == 1)
            {
                charges = 2400;
                cout << "\nYou have successfully booked the flight EUR - 123 ..\n";
                cout << "\nYou can go back to menu and take the ticket.\n";
            }
            else if (choice1 == 2)
            {
                charges = 2400;
                cout << "\nYou have successfully booked the flight EUR - 456 ..\n";
                cout << "\nYou can go back to menu and take the ticket.\n";
            }
            else if (choice1 == 3)
            {
                charges = 2400;
                cout << "\nYou have successfully booked the flight EUR - 789 ..\n";
                cout << "\nYou can go back to menu and take the ticket.\n";
            }
            else
            {
                cout << "\nInvalid input, shifting to the previous menu..\n";

                flights();
            }

            cout << "\nPlease enter any kay to go back to main menu: ";
            cin >> back;
            if (back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }
        }
        break;

        default:
        {
            cout << "\nInvalid input, Shifting you to the main menu..\n";

            mainMenu();
        }
        break;
        }
    }
};
int Registration ::choice;
float Registration ::charges;
// End Registration class.

//  Create Ticket class.
class Ticket : public Details, Registration
{
public:
    void bill()
    {
        // Declare destination variable.
        string destination = "";

        // Create and write in File.
        ofstream outf("records.txt");
        {
            outf << "\n\n.......... Kifah Airlines ..........\n";
            outf << "\n............. Ticket ...............\n\n";

            outf << "Customer ID: " << Details::cId << endl;
            outf << "Customer Name: " << Details::name << endl;
            outf << "Customer Gender: " << Details::gender << endl;

            outf << "\nDescription:" << endl
                 << endl;

            if (Registration ::choice == 1)
            {
                destination = "Dubai";
            }
            else if (Registration ::choice == 2)
            {
                destination = "Canada";
            }
            else if (Registration ::choice == 3)
            {
                destination = "US";
            }
            else if (Registration ::choice == 4)
            {
                destination = "UKA";
            }
            else if (Registration ::choice == 5)
            {
                destination = "Australia";
            }
            else if (Registration ::choice == 6)
            {
                destination = "Europe";
            }

            outf << "Destination: " << destination << endl;
            outf << "Flight cost: " << Registration ::charges << endl;

            outf << "_______________________________\n\n";
        }
        outf.close();
    }

    void disBill()
    {
        ifstream ifs("records.txt");
        {
            if (!ifs)
            {
                cout << "\nFile Error..\n";
            }

            while (!ifs.eof())
            {
                ifs.getline(arr, 100);
                cout << arr << endl;
            }
        }
        ifs.close();
    }
};
// End Ticket class.
//* ............. End Classes .............

//* ............. Function .............
// Create mainMenu function.
void mainMenu()
{
    // Declare variable.
    int lChoice, sChoice, back;

    // Print main menu.
    cout << "\n\n.......... Kifah Airlines ..........\n\n";
    cout << "............ Main menu .............\n\n";
    cout << "Enter (1) to add the customer details.\n";
    cout << "Enter (2) for flight registration.\n";
    cout << "Enter (3) for ticket and charges.\n";
    cout << "Enter (4) to exit.\n";
    cout << "____________________________________\n\n";

    // Receive select from user.
    cout << "Please enter your choice: ";
    cin >> lChoice;

    Details d;
    Registration r;
    Ticket t;

    switch (lChoice)
    {
    case 1:
    {
        cout << "\n............ Customers .............\n\n";

        // Call information function from Details class.
        d.information();

        cout << "\n\nPlease enter any kay to go back to \"Main Menu\": ";
        cin >> back;

        if (back == 1)
        {
            mainMenu();
        }
        else
        {
            mainMenu();
        }
        break;
    }

    case 2:
    {
        cout << "\n............ Book a flight using this system .............\n\n";

        r.flights();

        break;
    }

    case 3:
    {
        cout << "\n\n............ Get your ticket .............\n\n";

        t.bill();

        cout << "Your ticket is printed, you can collect it.\n\n";

        cout << "Please enter (1) to display your ticket: ";
        cin >> back;

        if (back == 1)
        {
            t.disBill();

            cout << "Please enter any kay to go back to \"Main Menu\": ";
            cin >> back;

            if (back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }
        }
        else
        {
            mainMenu();
        }
        break;
    }

    case 4:
    {
        cout << "\n............ Thank you .............\n\n\n";
        break;
    }

    default:
    {
        cout << "\n\nInvalid input, Please try agin.\n";

        mainMenu();

        break;
    }
    }
}
// End mainMenu function.
//* ............. End Function .............

int main()
{
    Management M;

    return 0;
}