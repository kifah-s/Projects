#include <iostream>

using namespace std;

void WelcomeMessage()
{
    cout << "\n\nWelcome to the Project ..\n"
         << endl;
}

class clsCalculator
{
private:
    int _result = 0;

public:
    // Clear.
    void clear()
    {
        _result = 0;
    }

    // Get Result.
    int getResult()
    {
        return _result;
    }

    // Add.
    void add(int result)
    {
        _result = _result + result;
        cout << "\nResult after Adding " << result << " is: " << getResult() << endl;
    }

    // Subtract.
    void subtract(int result)
    {
        _result = _result - result;
        cout << "\nResult after Subtracting " << result << " is: " << getResult() << endl;
    }

    // Multiply.
    void multiply(int result)
    {
        _result = _result * result;
        cout << "\nResult after Multiplying " << result << " is: " << getResult() << endl;
    }

    // Divide.
    void divide(int result)
    {
        if (result <= 0)
        {
            result = 1;
        }

        _result = _result / result;
        cout << "\nResult after Divideing " << result << " is: " << getResult() << endl;
    }
};

int main()
{
    WelcomeMessage();

    clsCalculator calculator1;

    calculator1.add(10);
    calculator1.add(10);
    calculator1.subtract(5);
    calculator1.multiply(2);
    calculator1.divide(3);
    calculator1.divide(0);
    calculator1.clear();

    cout << endl
         << endl;

    return 0;
}