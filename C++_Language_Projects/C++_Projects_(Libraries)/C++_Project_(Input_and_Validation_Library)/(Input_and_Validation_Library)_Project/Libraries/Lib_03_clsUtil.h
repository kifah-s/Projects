#pragma once

#include <iostream>
#include <string>

#include "Lib_01_clsString.h"
#include "Lib_02_clsDate.h"

using namespace std;

class clsUtil
{
public:
    enum enCharType
    {
        SmallLetter = 1,
        CapitalLetter = 2,
        Digit = 3,
        MixChars = 4,
        SpecialCharacter = 5
    };

    static void Srand()
    {
        // Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    static int RandomNumber(int From, int To)
    {
        // Function to generate a random number between From and To (inclusive)
        int randNum = rand() % (To - From + 1) + From;

        return randNum;
    }

    static char GetRandomCharacter(enCharType CharType)
    {
        // Handle MixChars by randomly selecting from Small, Capital, or Digit
        if (CharType == MixChars)
        {
            CharType = (enCharType)RandomNumber(1, 3);
        }

        switch (CharType)
        {
        case enCharType::SmallLetter:
        {
            return char(RandomNumber(97, 122)); // a - z.
        }

        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90)); // A - Z.
        }

        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57)); // 0 - 9.
        }

        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47)); // ! " # $ % & ' ( ) * + , - . /
        }

        default:
        {
            return char(RandomNumber(65, 90));
        }
        }
    }

    static string GenerateWord(enCharType CharType, short Length)
    {
        string Word = "";

        // Generate a word of specified length with random characters.
        for (int i = 0; i < Length; i++)
        {
            Word += GetRandomCharacter(CharType);
        }

        return Word;
    }

    static string GenerateKey(enCharType CharType = CapitalLetter)
    {
        // Generate a key in format: XXXX-XXXX-XXXX-XXXX.
        string Key = "";

        Key += GenerateWord(CharType, 4) + "-";
        Key += GenerateWord(CharType, 4) + "-";
        Key += GenerateWord(CharType, 4) + "-";
        Key += GenerateWord(CharType, 4);

        return Key;
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType)
    {
        // Print specified number of keys to console.
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Key [" << i << "] : " << GenerateKey(CharType) << endl;
        }
    }

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
    {
        // Fill integer array with random numbers in specified range.
        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = RandomNumber(From, To);
        }
    }

    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short WordLength)
    {
        // Fill string array with random words of specified length.
        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = GenerateWord(CharType, WordLength);
        }
    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
        // Fill string array with random keys.
        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = GenerateKey(CharType);
        }
    }

    static void Swap(int &A, int &B)
    {
        // Swap two integer values.
        int Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(double &A, double &B)
    {
        // Swap two double values.
        double Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(bool &A, bool &B)
    {
        // Swap two boolean values.
        bool Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(char &A, char &B)
    {
        // Swap two character values.
        char Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(string &A, string &B)
    {
        // Swap two string values.
        string Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(clsDate &A, clsDate &B)
    {
        // Swap two date objects using clsDate's SwapDates method.
        clsDate::SwapDates(A, B);
    }

    static void ShuffleArray(int arr[100], int arrLength)
    {
        // Shuffle integer array using Fisher-Yates algorithm.
        for (int i = 0; i < arrLength; i++)
        {
            int idx1 = RandomNumber(0, arrLength - 1);
            int idx2 = RandomNumber(0, arrLength - 1);
            Swap(arr[idx1], arr[idx2]);
        }
    }

    static void ShuffleArray(string arr[100], int arrLength)
    {
        // Shuffle string array using Fisher-Yates algorithm.
        for (int i = 0; i < arrLength; i++)
        {
            int idx1 = RandomNumber(0, arrLength - 1);
            int idx2 = RandomNumber(0, arrLength - 1);
            Swap(arr[idx1], arr[idx2]);
        }
    }

    static string Tabs(short NumberOfTabs)
    {
        // Generate string containing specified number of tabs.
        string t = "";
        
        for (int i = 0; i < NumberOfTabs; i++)
        {
            t += "\t";
        }

        return t;
    }

    static string EncryptText(string Text, short EncryptionKey)
    {
        // Encrypt text by shifting each character by EncryptionKey positions.
        for (size_t i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);
        }

        return Text;
    }

    static string DecryptText(string Text, short EncryptionKey)
    {
        // Decrypt text by shifting each character back by EncryptionKey positions.
        for (size_t i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        
        return Text;
    }
};