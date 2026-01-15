#include <iostream>
#include "Lib_clsString.h"

using namespace std;

void WelcomeMessage()
{
    cout << "\n\nWelcome to the Project ..\n"
         << endl;
}

int main()
{
    WelcomeMessage();

    // Lib_clsString:clsString string1;
    clsString string1;
    string1.SetValue("kifah saloum");

    clsString string2("kifah madal saloum");

    // cout << "String 1: " << string1.GetValue() << endl;
    // cout << "String 2: " << string2.GetValue() << endl;

    // cout << "Number of words: " << string1.CountWords(string1.GetValue()) << endl;

    // cout << "Number of words: " << string1.CountWords() << endl;
    // cout << "Number of words: " << string1.CountWords("kifah madal saloum") << endl;
    // cout << "Number of words: " << clsString::CountWords("kifah madal saloum") << endl;

    cout << "Number of vowel: " << string1.CountVowel() << endl;
    cout << "Number of vowel: " << string1.CountVowel("kifah madal saloum") << endl;
    cout << "Number of vowel: " << clsString::CountVowel("kifah madal saloum") << endl;

    cout << endl
         << endl;

    return 0;
}