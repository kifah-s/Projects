#pragma once

#include <iostream>

#include "../UI/clsScreen.h"
#include "../Public/clsInputValidate.h"
#include "clsCurrency.h"

class clsUpdateCurrencyRateScreen : protected clsScreen
{
private:
    static float _ReadRate()
    {
        float NewRate = 0;
        cout << "\n\t\t\t\t\tEnter New Rate: ";
        NewRate = clsInputValidate::ReadFloatNumber();
        return NewRate;
    }

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\n\t\t\t\t\tCurrency Card:\n";
        cout << "\t\t\t\t\t_____________________________\n";
        cout << "\n\t\t\t\t\tCountry    : " << Currency.GetCountry();
        cout << "\n\t\t\t\t\tCode       : " << Currency.GetCurrencyCode();
        cout << "\n\t\t\t\t\tName       : " << Currency.GetCurrencyName();
        cout << "\n\t\t\t\t\tRate(1$) = : " << Currency.GetRate();
        cout << "\n\t\t\t\t\t_____________________________\n";
    }

public:
    static void ShowUpdateCurrencyRateScreen()
    {
        _DrawScreenHeader("\tUpdate Currency Screen");

        string CurrencyCode = "";
        cout << "\n\t\t\t\t\tPlease Enter Currency Code: ";
        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrency(Currency);

        char Answer = 'n';
        cout << "\n\t\t\t\t\tAre you sure you want to update the rate of this Currency y/n? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\n\n\t\t\t\t\tUpdate Currency Rate:";
            cout << "\n\t\t\t\t\t____________________\n";

            Currency.UpdateRate(_ReadRate());

            cout << "\n\t\t\t\t\tCurrency Rate Updated Successfully :-)\n";
            _PrintCurrency(Currency);
        }
    }
};
