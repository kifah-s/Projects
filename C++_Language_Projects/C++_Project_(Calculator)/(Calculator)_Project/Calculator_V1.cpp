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

    // Add.
    void add(int result)
    {
        _result = _result + result;
    }

    // Subtract.
    void subtract(int result)
    {
        _result = _result - result;
    }

    // Multiply.
    void multiply(int result)
    {
        _result = _result * result;
    }

    // Divide.
    void divide(int result)
    {
        if (result <= 0)
        {
            result = 1;
        }

        _result = _result / result;
    }

    // Print Result.
    void printResult()
    {
        cout << "Result: " << _result << endl;
    }
};

int main()
{
    WelcomeMessage();

    clsCalculator calculator1;

    calculator1.add(10);
    calculator1.printResult();

    calculator1.add(10);
    calculator1.printResult();

    calculator1.subtract(5);
    calculator1.printResult();

    calculator1.multiply(2);
    calculator1.printResult();

    calculator1.divide(3);
    calculator1.printResult();

    calculator1.divide(0);
    calculator1.printResult();

    calculator1.clear();
    calculator1.printResult();

    cout << endl
         << endl;

    return 0;
}