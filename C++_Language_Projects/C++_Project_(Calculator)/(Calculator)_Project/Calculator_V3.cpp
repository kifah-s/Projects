#include <iostream>

using namespace std;

void WelcomeMessage()
{
    cout << "\n\nWelcome to the Corrected Calculator Project ..\n"
         << endl;
}

// Using enum to track the last operation.
enum enLastOperation
{
    none = 0,
    add,
    subtract,
    multiply,
    divide,
    clear
};

class clsCalculator
{
private:
    int _currentResult = 0;

    // Stores the last input for use in printResult.
    int _userInput = 0;
    
    // Variable to track the last operation performed.
    enLastOperation _lastOperation = enLastOperation::none;

public:
    // Clear.
    int clear()
    {
        // Resetting the cumulative result.
        _currentResult = 0;
        _userInput = 0;
        _lastOperation = enLastOperation::clear;

        return _currentResult;
    }

    // Add.
    int add(int userInput)
    {
        // Storing the input and operation type.
        _userInput = userInput;
        _lastOperation = enLastOperation::add;
        _currentResult = _currentResult + _userInput;
        
        return _currentResult;
    }

    // Subtract.
    int subtract(int userInput)
    {
        // Storing the input and operation type.
        _userInput = userInput;
        _lastOperation = enLastOperation::subtract;
        _currentResult = _currentResult - _userInput;

        return _currentResult;
    }

    // Multiply.
    int multiply(int userInput)
    {
        // Storing the input and operation type.
        _userInput = userInput;
        _lastOperation = enLastOperation::multiply;
        _currentResult = _currentResult * _userInput;

        return _currentResult;
    }

    // Divide.
    int divide(int userInput)
    {
        // Handling division by zero
        if (userInput == 0)
        {
            cout << "\nError: Cannot divide by zero. Result remains: " << _currentResult << endl;
            // The result and operation are not changed upon error.
        }
        else
        {
            // Storing the input and operation type, and performing the operation.
            _userInput = userInput;
            _lastOperation = enLastOperation::divide;
            _currentResult = _currentResult / _userInput;
        }

        return _currentResult;
    }

    // Print Result.
    void printResult()
    {
        // Using the stored operation for printing.
        string operationName;
        
        switch (_lastOperation)
        {
            case enLastOperation::add:
                operationName = "adding";
                break;

            case enLastOperation::subtract:
                operationName = "subtracting";
                break;

            case enLastOperation::multiply:
                operationName = "multiplying";
                break;

            case enLastOperation::divide:
                operationName = "dividing";
                break;

            case enLastOperation::clear:
                cout << "Calculator cleared. Current result is: " << _currentResult << endl;
                return; // Exit the function

            default:
                cout << "Current Result is: " << _currentResult << endl;
                return; // Exit the function
        }

        cout << "Result after " << operationName << " " << _userInput << " is: " << _currentResult << endl;
    }
};

int main()
{
    WelcomeMessage();

    clsCalculator calculator1;
    
    // 0 + 10 = 10
    calculator1.add(10);
    calculator1.printResult(); 

    // 10 + 10 = 20
    calculator1.add(10);
    calculator1.printResult(); 

    // 20 - 5 = 15
    calculator1.subtract(5);
    calculator1.printResult(); 

    // 15 * 2 = 30
    calculator1.multiply(2);
    calculator1.printResult(); 

    // 30 / 3 = 10
    calculator1.divide(3);
    calculator1.printResult(); 

    // Division by zero (handled as an error, does not change the result)
    calculator1.divide(0);
    calculator1.printResult(); 

    // Clearing the calculator
    calculator1.clear();
    calculator1.printResult(); 

    cout << endl
         << endl;

    return 0;
}