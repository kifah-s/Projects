

//* >>>>>>>>>>>>>>> Supermarket Billing <<<<<<<<<<<<<<< *//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//* ............ Classes ............
// Creat class.
class shopping
{
private:
    int pCode;
    float price;
    float discount;
    string pName;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};
//* ............ End Classes ............

//* ............ Function ............
// Menu function.
void shopping ::menu()
{
m:

    // Declare variable.
    int choice;
    string email, password;

    // Print main menu.
    cout << "\n.....................\n";
    cout << "SUPERMARKET MAIN MENU";
    cout << "\n.....................\n\n";
    cout << "1) Administrator..\n\n";
    cout << "2) Buyer..\n\n";
    cout << "3) Exit..\n";
    cout << "_________________________________\n\n";

    // Receive user select.
    cout << "Please enter your choice: ";
    cin >> choice;

    // Create switch.
    switch (choice)
    {
    case 1: // Administrator case.
    {
        // Receive email and password from user.
        cout << "\n.. \" Login \" ..\n";
        cout << "\nPlease enter \"Email\": ";
        cin >> email;
        cout << "Please enter \"Password\": ";
        cin >> password;

        // Check email and password.
        if (email == "kifah@email.com" && password == "12345")
        {
            administrator();
        }
        else
        {
            cout << "\nInvalid email or password..\n";
        }
    }
    break;

    case 2: // Buyer case.
    {
        buyer();
    }
    break;

    case 3: // Exit case.
    {
        exit(0);
    }
    break;

    default:
    {
        cout << "\nPlease select from the given options..\n";
    }
    break;
    }

    goto m;
}
// End Menu function.

// administrator function.
void shopping ::administrator()
{
m:

    // Declare variable.
    int choice;

    // Print administrator menu.
    cout << "\n..................\n";
    cout << "ADMINISTRATOR MENU";
    cout << "\n..................\n\n";
    cout << "1) Add Product..\n\n";
    cout << "2) Edit Product..\n\n";
    cout << "3) Remove Product..\n\n";
    cout << "4) Back to main menu..\n";
    cout << "_________________________________\n\n";

    // Receive user select.
    cout << "Please enter your choice: ";
    cin >> choice;

    // Create switch.
    switch (choice)
    {
    case 1: // Add Product case.
    {
        add();
    }
    break;

    case 2: // Edit Product case.
    {
        edit();
    }
    break;

    case 3: // Remove Product case.
    {
        rem();
    }
    break;

    case 4: // Menu case.
    {
        menu();
    }
    break;

    default:
    {
        cout << "\nInvalid choice..\n";
    }
    break;
    }

    goto m;
}
// End administrator function.

// buyer function.
void shopping ::buyer()
{
m:

    // Declare variable.
    int choice;

    // Print administrator menu.
    cout << "\n..........\n";
    cout << "BUYER MENU";
    cout << "\n..........\n\n";
    cout << "1) Buy Product..\n\n";
    cout << "2) Go to main menu..\n\n";
    cout << "_________________________________\n\n";

    // Receive user select.
    cout << "Please enter your choice: ";
    cin >> choice;

    // Create switch.
    switch (choice)
    {
    case 1: // Buy Product case.
    {
        receipt();
    }
    break;

    case 2: // Go to main menu
    {
        menu();
    }
    break;

    default:
    {
        cout << "\nInvalid choice..\n";
    }
    break;
    }

    goto m;
}
// End buyer function.

// Add function.
void shopping ::add()
{
m:

    // file.
    fstream data;

    // Declare variable.
    int c, token = 0;
    float p, d;
    string n;

    // Add new product.
    cout << "\n...............\n";
    cout << "ADD NEW PRODUCT";
    cout << "\n...............\n\n";
    cout << "Product Code: ";
    cin >> pCode;
    cout << "Product Name: ";
    cin >> pName;
    cout << "Product Price: ";
    cin >> price;
    cout << "Product Discount: ";
    cin >> discount;

    // Open file.
    data.open("database.txt", ios::in);

    if (!data) // Write in file.
    {
        // Open or create file.
        data.open("database.txt", ios::app | ios::out);
        // Write in file.
        data << " " << pCode << " " << pName << " " << price << " " << discount << "\n";
        // Close file.
        data.close();
    }
    else // check product code in file.
    {
        data >> c >> n >> p >> d;

        while (!data.eof())
        {
            if (c == pCode)
            {
                token++;
            }

            data >> c >> n >> p >> d;
        }
        data.close();

        if (token == 1)
        {
            cout << "\nSorry, Product Code Already Exists..\n";
            goto m;
        }
        else
        {
            // Open or create file.
            data.open("database.txt", ios::app | ios::out);
            // Write in file.
            data << " " << pCode << " " << pName << " " << price << " " << discount << "\n";
            // Close file.
            data.close();
        }
    }
    cout << "\nRecord inserted..\n";
}
// End add function.

// Edit function.
void shopping ::edit()
{
    // file.
    fstream data, data1;

    // Declare variables.
    int pKey, token = 0, c;
    float p, d;
    string n;

    // Edit product.
    cout << "\n............\n";
    cout << "EDIT PRODUCT";
    cout << "\n............\n\n";
    cout << "Product Code: ";
    cin >> pKey;

    // open file.
    data.open("database.txt", ios ::in);

    if (!data)
    {
        cout << "\nFile doesn't exist..\n";
    }
    else
    {
        // Open file.
        data1.open("database1.txt", ios ::app | ios ::out);

        data >> pCode >> pName >> price >> discount;

        while (!data.eof())
        {
            if (pKey == pCode)
            {
                // New product.
                cout << "\nNew Product Code: ";
                cin >> c;
                cout << "Product Name: ";
                cin >> n;
                cout << "Product Price: ";
                cin >> p;
                cout << "Product Discount: ";
                cin >> d;

                data1 << " " << c << " " << n << " " << p << " " << d << "\n";

                cout << "\nRecord edited..\n";

                token++;
            }
            else
            {
                data1 << " " << pCode << " " << pName << " " << price << " " << discount << "\n";
            }
            data >> pCode >> pName >> price >> discount;
        }
        // Closed files.
        data.close();
        data1.close();

        // Rename file.
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\nSorry, Record not found..\n";
        }
    }
}
// End edit function.

// Remove function.
void shopping ::rem()
{
    // file.
    fstream data, data1;

    // Declare variables.
    int pKey, token = 0;

    // Remove product.
    cout << "\n..............\n";
    cout << "REMOVE PRODUCT";
    cout << "\n..............\n\n";
    cout << "Product Code: ";
    cin >> pKey;

    // open file.
    data.open("database.txt", ios ::in);

    if (!data)
    {
        cout << "\nFile doesn't exist..\n";
    }
    else
    {
        // Open file.
        data1.open("database1.txt", ios ::app | ios ::out);

        data >> pCode >> pName >> price >> discount;

        while (!data.eof())
        {
            if (pKey == pCode)
            {
                // New product.
                cout << "\nProduct deleted successfully..\n";

                token++;
            }
            else
            {
                data1 << " " << pCode << " " << pName << " " << price << " " << discount << "\n";
            }
            data >> pCode >> pName >> price >> discount;
        }
        // Closed files.
        data.close();
        data1.close();

        // Rename file.
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\nSorry, Record not found..\n";
        }
    }
}
// End remove function.

// List function.
void shopping ::list()
{
    // File.
    fstream data;

    // Open file.
    data.open("database.txt", ios ::in);

    // List products.
    cout << "\n.............\n";
    cout << "List PRODUCT";
    cout << "\n.............\n\n";
    cout << "Number..........Name..........Price\n";

    data >> pCode >> pName >> price >> discount;

    while (!data.eof())
    {
        cout << pCode << "              " << pName << "           " << price << "\n";
        data >> pCode >> pName >> price >> discount;
    }
    data.close();
}
// End List function.

// Receipt function.
void shopping ::receipt()
{
    // File.
    fstream data;

    // Declare variable.
    int arrC[100], arrQ[100], c = 0;
    float amount = 0, dis = 0, total = 0;
    char choice;

    // Open file,
    data.open("database.txt", ios ::in);

    if (!data)
    {
        cout << "\nEmpty List..\n\n";
    }
    else
    {
        // Close file.
        data.close();

        // List function.
        list();

        // Select order.
        cout << "\nPlease place the order..\n";

        do
        {
        m:

            cout << "\nEnter product number: ";
            cin >> arrC[c];
            cout << "Enter product quantity: ";
            cin >> arrQ[c];

            for (int i = 0; i < c; i++)
            {
                if (arrC[c] == arrC[i])
                {
                    cout << "\nDuplicate product code.. Please try agin !!\n";

                    goto m;
                }
            }
            c++;

            cout << "\nDo you want to bay another product ?? .. if yes please enter 'y', if no please enter 'n': ";
            cin >> choice;

        } while (choice == 'y');

        cout << "\n________ RECEIPT ________\n";
        cout << "\nProNumber    ProName    ProQuantity    ProPrice    Amount    Amount with discount\n";

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios ::in);

            data >> pCode >> pName >> price >> dis;

            while (!data.eof())
            {
                if (pCode == arrC[i])
                {
                    amount = price * arrQ[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;

                    cout << "\n"
                         << pCode << "             " << pName << "          " << arrQ[i] << "           " << price << "          " << amount << "              " << dis;
                }
                data >> pCode >> pName >> price >> dis;
            }
            data.close();
        }
    }
    cout << "\n\nTotal Amount: " << total << endl;
}
// End receipt function.

//* ............ End Function ............

int main()
{
    // Creat object.
    shopping c1;
    c1.menu();

    return 0;
}