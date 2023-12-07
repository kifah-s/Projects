

//* >>>>>>>>>>>>>>> Hotel Reservation Project <<<<<<<<<<<<<<< *//

#include <iostream>

using namespace std;

int main()
{
    //* .......... Variables .......... *//
    // Quant and choice variables.
    int quant, choice;
    // Quantity of items present ..
    int quantityRooms = 25, quantityPasta = 100, quantityBurger = 100, quantityNoodles = 100, quantityShake = 100, quantityChicken = 100;
    // The items sold ..
    int soldRooms = 0, soldPasta = 0, soldBurger = 0, soldNoodles = 0, soldShake = 0, soldChicken = 0;
    // Total price of item ..
    int total = 0, totalRooms = 0, totalPasta = 0, totalBurger = 0, totalNoodles = 0, totalShake = 0, totalChicken = 0;
    //* .......... End Variables .......... *//

    cout << "\n\n >>>>> Your welcome in kifah hotel <<<<<";

start:
    cout << "\n\nPlease select from the menu options..\n";
    cout << "\n1) Rooms";
    cout << "\n2) Pasta";
    cout << "\n3) Burger";
    cout << "\n4) Noodles";
    cout << "\n5) Shake";
    cout << "\n6) Chicken";
    cout << "\n\n7) Billing information";
    cout << "\n8) Exit";

    cout << "\n\nPlease enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\nPlease enter the number of rooms you want: ";
        cin >> quant;
        if (quantityRooms - soldRooms >= quant)
        {
            soldRooms = soldRooms + quant;
            totalRooms = totalRooms + quant * 1200;

            cout << "\n"
                 << quant << " Room/Rooms have been allotted to you !!\n";
                 break;
        }
        else
        {
            cout << "\nOh sorry, Only " << quantityRooms - soldRooms << " rooms remaining in hotel !!\n";
            break;
        }

    case 2:
        cout << "\nPlease enter Pasta Quantity: ";
        cin >> quant;
        if (quantityPasta - soldPasta >= quant)
        {
            soldPasta = soldPasta + quant;
            totalPasta = totalPasta + quant * 100;

            cout << "\n"
                 << quant << " Pasta is the order !!\n";
        }
        else
        {
            cout << "\nOh sorry, Only " << quantityPasta - soldPasta << " Pasta remaining in hotel !!\n";
            break;
        }

    case 3:
        cout << "\nPlease enter Burger Quantity: ";
        cin >> quant;
        if (quantityBurger - soldBurger >= quant)
        {
            soldBurger = soldBurger + quant;
            totalBurger = totalBurger + quant * 100;

            cout << "\n"
                 << quant << " Burger is the order !!\n";
        }
        else
        {
            cout << "\nOh sorry, Only " << quantityBurger - soldBurger << " Burger remaining in hotel !!\n";
            break;
        }

    case 4:
        cout << "\nPlease enter Noodles Quantity: ";
        cin >> quant;
        if (quantityNoodles - soldNoodles >= quant)
        {
            soldNoodles = soldNoodles + quant;
            totalNoodles = totalNoodles + quant * 100;

            cout << "\n"
                 << quant << " Noodles is the order !!\n";
        }
        else
        {
            cout << "\nOh sorry, Only " << quantityNoodles - soldNoodles << " Noodles remaining in hotel !!\n";
            break;
        }

    case 5:
        cout << "\nPlease enter Shake Quantity: ";
        cin >> quant;
        if (quantityShake - soldShake >= quant)
        {
            soldShake = soldShake + quant;
            totalShake = totalShake + quant * 100;

            cout << "\n"
                 << quant << " Shake is the order !!\n";
        }
        else
        {
            cout << "\nOh sorry, Only " << quantityShake - soldShake << " Shake remaining in hotel !!\n";
            break;
        }

    case 6:
        cout << "\nPlease enter Chicken Quantity: ";
        cin >> quant;
        if (quantityChicken - soldChicken >= quant)
        {
            soldChicken = soldChicken + quant;
            totalChicken = totalChicken + quant * 100;

            cout << "\n"
                 << quant << " Chicken is the order !!\n";
        }
        else
        {
            cout << "\nOh sorry, Only " << quantityChicken - soldChicken << " Chicken remaining in hotel !!\n";
            break;
        }

        case 7:
            cout << "\n\nYour Billing:";
            cout << "\nTotal Rooms: " << totalRooms;
            cout << "\nTotal Pasta: " << totalPasta;
            cout << "\nTotal Burger: " << totalBurger;
            cout << "\nTotal Noodles: " << totalNoodles;
            cout << "\nTotal Shake: " << totalShake;
            cout << "\nTotal Chicken: " << totalChicken;

            total = totalRooms + totalPasta + totalBurger + totalNoodles + totalShake + totalChicken;
            cout << "\n\nTotal: " << total;

        case 8:
            exit(0);

    default:
        break;
    }

    goto start;

    return 0;
}