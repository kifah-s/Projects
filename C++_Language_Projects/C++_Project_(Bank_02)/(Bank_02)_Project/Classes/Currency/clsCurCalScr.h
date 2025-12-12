#pragma once

#include <iostream>

#include "../UI/clsScreen.h"
#include "../Public/clsInputValidate.h"
#include "clsCurrency.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
    static float _ReadAmount()
    {
        float Amount = 0;
        cout << "\n\t\t\t\t\tEnter Amount to Exchange: ";
        Amount = clsInputValidate::ReadFloatNumber();
        return Amount;
    }

    static clsCurrency _GetCurrency(string Message)
    {
        string CurrencyCode;
        cout << Message << endl;

        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\n\t\t\t\t\tCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        return Currency;
    }

    static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:")
    {
        cout << "\n"
             << Title << "\n";
        cout << "\t\t\t\t\t_____________________________\n";
        cout << "\n\t\t\t\t\tCountry       : " << Currency.GetCountry();
        cout << "\n\t\t\t\t\tCode          : " << Currency.GetCurrencyCode();
        cout << "\n\t\t\t\t\tName          : " << Currency.GetCurrencyName();
        cout << "\n\t\t\t\t\tRate(1$) =    : " << Currency.GetRate();
        cout << "\n\t\t\t\t\t_____________________________\n\n";
    }

    static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
    {
        _PrintCurrencyCard(Currency1, "Convert From:");

        float AmountInUSD = Currency1.ConvertToUSD(Amount);

        cout << Amount << " " << Currency1.GetCurrencyCode() << " = " << AmountInUSD << " USD\n";

        if (Currency2.GetCurrencyCode() == "USD")
        {
            return;
        }

        cout << "\n\t\t\t\t\tConverting from USD to:\n";

        _PrintCurrencyCard(Currency2, "To:");

        float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

        cout << Amount << " " << Currency1.GetCurrencyCode() << " = " << AmountInCurrency2 << " " << Currency2.GetCurrencyCode();
    }

public:
    static void ShowCurrencyCalculatorScreen()
    {
        char Continue = 'y';

        while (Continue == 'y' || Continue == 'Y')
        {
            system("cls");
            _DrawScreenHeader("\tUpdate Currency Screen");

            clsCurrency CurrencyFrom = _GetCurrency("\n\t\t\t\t\tPlease Enter Currency1 Code: ");
            clsCurrency CurrencyTo = _GetCurrency("\n\t\t\t\t\tPlease Enter Currency2 Code: ");
            float Amount = _ReadAmount();

            _PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

            cout << "\n\n\t\t\t\t\tDo you want to perform another calculation? y/n ? ";
            cin >> Continue;
        }
    }
};
