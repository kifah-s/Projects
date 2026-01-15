#include <iostream>

#include "classes/DS/clsMyString.h"

using namespace std;

void WelcomeMessage()
{
    cout << "\n\nWelcome to the Project ..\n"
         << endl;
}

int main()
{
    WelcomeMessage();

    cout << "Undo / Redo Project" << endl;

    clsMyString S1;

    cout << "\nS1  = " << S1.GetValue() << "\n";

    S1.SetValue("Mohammed");
    cout << "S1  = " << S1.GetValue() << "\n";

    S1.SetValue("Mohammed - 2");
    cout << "S1  = " << S1.GetValue() << "\n";

    S1.SetValue("Mohammed - 3");
    cout << "S1  = " << S1.GetValue() << "\n";

    cout << "\n\nUndo: ";
    cout << "\n__________\n";

    S1.Undo();
    cout << "\nS1  after undo = " << S1.GetValue() << "\n";

    S1.Undo();
    cout << "S1  after undo = " << S1.GetValue() << "\n";

    S1.Undo();
    cout << "S1  after undo = " << S1.GetValue() << "\n";

    cout << "\n\nRedo: ";
    cout << "\n__________\n";

    S1.Redo();
    cout << "\nS1  after Redo = " << S1.GetValue() << "\n";

    S1.Redo();
    cout << "S1  after Redo = " << S1.GetValue() << "\n";

    S1.Redo();
    cout << "S1  after Redo = " << S1.GetValue() << "\n";

    cout << endl
         << endl;

    return 0;
}