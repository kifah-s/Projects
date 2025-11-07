#pragma once

#include <iostream>

using namespace std;

class clsString
{
private:
    string _value;

public:
    clsString() { _value = ""; }
    clsString(string value) { _value = value; }

    void SetValue(string value) { _value = value; }
    string GetValue() { return _value; }

    static short CountWords(string myString)
    {
        string delim = " ", sWord;
        short pos = 0, counter = 0;

        while ((pos = myString.find(delim)) != std::string::npos)
        {
            sWord = myString.substr(0, pos);

            if (sWord != "")
            {
                // cout << sWord << endl;
                counter++;
            }

            myString.erase(0, pos + delim.length());
        }

        if (myString != "")
        {
            // cout << myString << endl;
            counter++;
        }

        return counter;
    }
    short CountWords()
    {
        return CountWords(_value);
    }

    static bool IsVowel(char myChar)
    {
        myChar = tolower(myChar);

        return (myChar == 'a' || myChar == 'e' || myChar == 'i' || myChar == 'o' || myChar == 'u');
    }
    static short CountVowel(string myString)
    {
        short counter = 0;

        for (short i = 0; i < myString.length(); i++)
        {
            if (IsVowel(myString[i]))
            {
                counter++;
            }
        }

        return counter;
    }
    short CountVowel()
    {
        return CountVowel(_value);
    }
};