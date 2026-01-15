#pragma once

#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

class clsString
{
private:
    string _Value;

public:
    // ==================== Constructors ====================
    clsString() : _Value("") {}

    clsString(string Value) : _Value(Value) {}

    // ==================== Getters & Setters (Clear & Portable) ====================
    void SetValue(string Value) { _Value = Value; }
    string GetValue() const { return _Value; }
    // =============================================================================

    // ==================== Length ====================
    static short Length(string S1) { return short(S1.length()); }
    short Length() const { return Length(_Value); }

    // ==================== Word Count ====================
    static short CountWords(string S1)
    {
        string delim = " ";
        short Counter = 0;
        size_t pos = 0;
        string sWord;

        while ((pos = S1.find(delim)) != string::npos)
        {
            sWord = S1.substr(0, pos);
            if (!sWord.empty())
                Counter++;
            S1.erase(0, pos + delim.length());
        }
        if (!S1.empty())
            Counter++;

        return Counter;
    }

    short CountWords() const { return CountWords(_Value); }

    // ==================== Case Conversion ====================
    static string UpperFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;
        for (size_t i = 0; i < S1.length(); ++i)
        {
            if (S1[i] != ' ' && isFirstLetter)
                S1[i] = toupper(S1[i]);
            isFirstLetter = (S1[i] == ' ');
        }
        return S1;
    }

    void UpperFirstLetterOfEachWord() { _Value = UpperFirstLetterOfEachWord(_Value); }

    static string LowerFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;
        for (size_t i = 0; i < S1.length(); ++i)
        {
            if (S1[i] != ' ' && isFirstLetter)
                S1[i] = tolower(S1[i]);
            isFirstLetter = (S1[i] == ' ');
        }
        return S1;
    }

    void LowerFirstLetterOfEachWord() { _Value = LowerFirstLetterOfEachWord(_Value); }

    static string UpperAllString(string S1)
    {
        for (size_t i = 0; i < S1.length(); ++i)
            S1[i] = toupper(S1[i]);
        return S1;
    }

    void UpperAllString() { _Value = UpperAllString(_Value); }

    static string LowerAllString(string S1)
    {
        for (size_t i = 0; i < S1.length(); ++i)
            S1[i] = tolower(S1[i]);
        return S1;
    }

    void LowerAllString() { _Value = LowerAllString(_Value); }

    static char InvertLetterCase(char c)
    {
        return isupper(c) ? tolower(c) : toupper(c);
    }

    static string InvertAllLettersCase(string S1)
    {
        for (size_t i = 0; i < S1.length(); ++i)
            S1[i] = InvertLetterCase(S1[i]);
        return S1;
    }

    void InvertAllLettersCase() { _Value = InvertAllLettersCase(_Value); }

    // ==================== Letter Counting ====================
    enum enWhatToCount
    {
        SmallLetters = 0,
        CapitalLetters = 1,
        All = 3
    };

    static short CountLetters(string S1, enWhatToCount WhatToCount = All)
    {
        if (WhatToCount == All)
            return short(S1.length());

        short Counter = 0;
        for (char c : S1)
        {
            if (WhatToCount == CapitalLetters && isupper(c))
                Counter++;
            if (WhatToCount == SmallLetters && islower(c))
                Counter++;
        }
        return Counter;
    }

    static short CountCapitalLetters(string S1)
    {
        short Counter = 0;
        for (char c : S1)
            if (isupper(c))
                Counter++;
        return Counter;
    }

    short CountCapitalLetters() const { return CountCapitalLetters(_Value); }

    static short CountSmallLetters(string S1)
    {
        short Counter = 0;
        for (char c : S1)
            if (islower(c))
                Counter++;
        return Counter;
    }

    short CountSmallLetters() const { return CountSmallLetters(_Value); }

    static short CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
    {
        short Counter = 0;
        char target = MatchCase ? Letter : tolower(Letter);

        for (char c : S1)
        {
            if (MatchCase)
            {
                if (c == Letter)
                    Counter++;
            }
            else
            {
                if (tolower(c) == target)
                    Counter++;
            }
        }
        return Counter;
    }

    short CountSpecificLetter(char Letter, bool MatchCase = true) const
    {
        return CountSpecificLetter(_Value, Letter, MatchCase);
    }

    // ==================== Vowels ====================
    static bool IsVowel(char Ch1)
    {
        Ch1 = tolower(Ch1);
        return (Ch1 == 'a' || Ch1 == 'e' || Ch1 == 'i' || Ch1 == 'o' || Ch1 == 'u');
    }

    static short CountVowels(string S1)
    {
        short Counter = 0;
        for (char c : S1)
            if (IsVowel(c))
                Counter++;
        return Counter;
    }

    short CountVowels() const { return CountVowels(_Value); }

    // ==================== Split & Join ====================
    static vector<string> Split(string S1, string Delim)
    {
        vector<string> vString;
        size_t pos = 0;
        string sWord;

        while ((pos = S1.find(Delim)) != string::npos)
        {
            sWord = S1.substr(0, pos);
            if (!sWord.empty())
                vString.push_back(sWord);
            S1.erase(0, pos + Delim.length());
        }
        if (!S1.empty())
            vString.push_back(S1);

        return vString;
    }

    vector<string> Split(string Delim) const
    {
        return Split(_Value, Delim);
    }

    // ==================== Trim ====================
    static string TrimLeft(string S1)
    {
        size_t start = S1.find_first_not_of(" ");
        return (start == string::npos) ? "" : S1.substr(start);
    }

    void TrimLeft() { _Value = TrimLeft(_Value); }

    static string TrimRight(string S1)
    {
        size_t end = S1.find_last_not_of(" ");
        return (end == string::npos) ? "" : S1.substr(0, end + 1);
    }

    void TrimRight() { _Value = TrimRight(_Value); }

    static string Trim(string S1) { return TrimLeft(TrimRight(S1)); }
    void Trim() { _Value = Trim(_Value); }

    // ==================== Join ====================
    static string JoinString(const vector<string> &vString, string Delim)
    {
        if (vString.empty())
            return "";
        string result = vString[0];
        for (size_t i = 1; i < vString.size(); ++i)
            result += Delim + vString[i];
        return result;
    }

    static string JoinString(const string arrString[], short Length, string Delim)
    {
        if (Length <= 0)
            return "";
        string result = arrString[0];
        for (short i = 1; i < Length; ++i)
            result += Delim + arrString[i];
        return result;
    }

    // ==================== Reverse Words ====================
    static string ReverseWordsInString(string S1)
    {
        vector<string> vWords = Split(S1, " ");
        string result;
        for (auto it = vWords.rbegin(); it != vWords.rend(); ++it)
            result += *it + " ";
        if (!result.empty())
            result.pop_back(); // remove last space
        return result;
    }

    void ReverseWordsInString() { _Value = ReverseWordsInString(_Value); }

    // ==================== Replace Word ====================
    static string ReplaceWord(string S1, string StringToReplace, string ReplaceTo, bool MatchCase = true)
    {
        vector<string> vWords = Split(S1, " ");
        for (string &word : vWords)
        {
            if (MatchCase)
            {
                if (word == StringToReplace)
                    word = ReplaceTo;
            }
            else
            {
                if (LowerAllString(word) == LowerAllString(StringToReplace))
                    word = ReplaceTo;
            }
        }
        return JoinString(vWords, " ");
    }

    string ReplaceWord(string StringToReplace, string ReplaceTo, bool MatchCase = true) const
    {
        return ReplaceWord(_Value, StringToReplace, ReplaceTo, MatchCase);
    }

    // ==================== Remove Punctuation ====================
    static string RemovePunctuations(string S1)
    {
        string result;
        for (char c : S1)
            if (!ispunct(c))
                result += c;
        return result;
    }

    void RemovePunctuations() { _Value = RemovePunctuations(_Value); }
};