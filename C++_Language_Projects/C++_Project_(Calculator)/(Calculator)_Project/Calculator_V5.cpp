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
    float _result = 0;
    float _previousResult = 0;
    float _lastNumber = 0;

    string _lastOperation = "clear";

    bool _IsZero(float number)
    {
        return (number == 0);
    }

public:
    void Clear()
    {
        _lastNumber = 0;
        _previousResult = 0;
        _lastOperation = "clear";

        _result = 0;
    }

    void Add(float number)
    {
        _lastNumber = number;
        _previousResult = _result;
        _lastOperation = "adding";

        _result = _result + number;
    }

    void Subtract(float number)
    {
        _lastNumber = number;
        _previousResult = _result;
        _lastOperation = "subtracting";

        _result = _result - number;
    }

    void Multiplay(float number)
    {
        _lastNumber = number;
        _previousResult = _result;
        _lastOperation = "multiplaying";

        _result = _result * number;
    }

    void Divid(float number)
    {
        _lastNumber = number;

        if (_IsZero(number))
        {
            number = 1;
        }

        _previousResult = _result;
        _lastOperation = "dividing";

        _result = _result / number;
    }

    float GitFinalResult()
    {
        return _result;
    }

    void CancelLastOperation()
    {
        _lastNumber = 0;
        _lastOperation = "canceling last operation";
        _result = _previousResult;
    }

    void PrintResult()
    {
        cout << "Result after " << _lastOperation << " " << _lastNumber << " is: " << _result << endl;
    }
};

int main()
{
    WelcomeMessage();

    clsCalculator calculator1;

    calculator1.Add(10);
    calculator1.PrintResult();
    
    calculator1.Add(40);
    calculator1.PrintResult();

    calculator1.Subtract(10);
    calculator1.PrintResult();

    calculator1.Multiplay(2);
    calculator1.PrintResult();

    calculator1.Divid(2);
    calculator1.PrintResult();

    calculator1.Clear();
    calculator1.PrintResult();

    cout << endl
         << endl;

    return 0;
}