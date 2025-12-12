#pragma once

#include <iostream>

#include "../UI/clsScreen.h"
#include "../Public/clsInputValidate.h"
#include "clsCurrency.h"

class clsFindCurrencyScreen : protected clsScreen
{
private:
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

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\n\t\t\t\t\tCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\n\t\t\t\t\tCurrency Was not Found :-(\n";
        }
    }

public:
    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("\t  Find Currency Screen");

        short Answer = 1;
        cout << "\n\t\t\t\t\tFind By: [1] Code or [2] Country ? ";
        cin >> Answer;

        if (Answer == 1)
        {
            string CurrencyCode;
            cout << "\n\t\t\t\t\tPlease Enter CurrencyCode: ";
            CurrencyCode = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            _ShowResults(Currency);
        }
        else
        {
            string Country;
            cout << "\n\t\t\t\t\tPlease Enter Country Name: ";
            Country = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCountry(Country);
            _ShowResults(Currency);
        }
    }
};
