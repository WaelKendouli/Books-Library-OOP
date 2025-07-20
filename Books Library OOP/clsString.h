#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class clsString
{
private:
    string _Value;
public:
    clsString()
    {
        _Value = " ";
    }
    clsString(string S)
    {
        _Value = S;
    }
    void SetValue(string S)
    {
        _Value = S;
    }
    string GetValue()
    {
        return _Value;
    }
    __declspec(property(get = GetValue, put = SetValue))string Value;

    static short Length(string S)
    {
        return S.length();
    }

    short Length()
    {
        return _Value.length();
    }

    static short CountWords(string S1)
    {

        string delim = " ";
        short Count = 0;
        short Pos = 0;
        string sWord;

        while ((Pos = S1.find(delim)) != string::npos)
        {
            sWord = S1.substr(0, Pos);

            if (sWord != "")
            {
                Count++;
            }
            S1.erase(0, Pos + delim.length());
        }

        if (S1 != "")
        {
            Count++;
        }
        return Count;
    }
    void CountWords()
    {
        _Value = CountWords(_Value);
    }

    static vector<string> Split(string S1, string Delim = "#//#")
    {
        vector<string> vString;

        string sWord;
        short Pos = 0;

        while ((Pos = S1.find(Delim)) != string::npos)
        {
            sWord = S1.substr(0, Pos);

            if (sWord != "")
            {
                vString.push_back(sWord);
            }
            S1.erase(0, Pos + Delim.length());
        }

        if (S1 != "")
        {
            vString.push_back(S1);
        }

        return vString;
    }

    

    static string TrimLeft(string S1)
    {
        while (S1[0] == ' ')
        {
            S1.erase(0, 1);
        }
        return S1;
    }
    void TrimLeft()
    {
        _Value = TrimLeft(_Value);
    }

    static string TrimRight(string S1)
    {
        while (S1[S1.length() - 1] == ' ')
        {
            S1.pop_back();
        }
        return S1;
    }
    void TrimRight()
    {
        _Value = TrimRight(_Value);
    }

    static string TrimAll(string S1)
    {
        return TrimLeft(TrimRight(S1));
    }
    void TrimAll()
    {
        _Value = TrimAll(_Value);
    }
    static string JoinString(vector<string> VString, string Delim)
    {
        string S1 = "";

        for (string word : VString)
        {
            S1 += Delim + word;
        }
        S1.erase(0, Delim.length());

        return S1;
    }
    void JoinString()
    {
        vector <string> Vstring;
        _Value = JoinString(Vstring, " ");
    }
    static string RemovePunctuationsFromString(string S1)
    {
        string S2 = "";

        for (int i = 0; i < S1.length(); i++)
        {
            if (!ispunct(S1[i]))
            {
                S2 += S1[i];
            }
        }
        return S2;
    }
    void RemovePunctuationsFromString()
    {
        _Value = RemovePunctuationsFromString(_Value);
    }

    static string ReadText()
    {
        string Text;

        cout << "\nPlease, Enter Your String? \n";
        getline(cin, Text);

        return Text;
    }

    static string UpperAllString(string Text)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char(toupper(Text[i]));
        }
        return Text;
    }
    void UpperAllString()
    {
        _Value = UpperAllString(_Value);
    }
    static string LowerAllString(string Text)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char(tolower(Text[i]));
        }
        return Text;
    }

    void LowerAllString()
    {
        _Value = LowerAllString(_Value);
    }

    static string LowerFirstLetterOfEachWord(string Text)
    {
        bool isFirstLetter = true;

        for (int i = 0; i < Text.length(); i++)
        {
            if (Text[i] != ' ' && isFirstLetter)
            {
                Text[i] = char(tolower(Text[i]));
            }

            isFirstLetter = (Text[i] == ' ' ? true : false);
        }
        return Text;
    }

    void LowerFirstLetterOfEachWord()
    {
        _Value = LowerFirstLetterOfEachWord(_Value);
    }

    static string UpperFirstLetterOfEachWord(string Text)
    {
        bool isFirstLetter = true;

        for (int i = 0; i < Text.length(); i++)
        {
            if (Text[i] != ' ' && isFirstLetter)
            {
                Text[i] = char(toupper(Text[i]));
            }

            isFirstLetter = (Text[i] == ' ' ? true : false);
        }
        return Text;
    }
    void UpperFirstLetterOfEachWord()
    {
        _Value = UpperFirstLetterOfEachWord(_Value);
    }
    static string InvertAllLettersString(string Text)
    {
        bool isFirstLetter = true;

        for (int i = 0; i < Text.length(); i++)
        {
            if (Text[i] != ' ' && isFirstLetter)
            {
                Text[i] = (isupper(Text[i]) ? tolower(Text[i]) : toupper(Text[i]));
            }

            isFirstLetter = (Text[i] == ' ' ? true : false);
        }
        return Text;
    }
    void InvertAllLettersString()
    {
        _Value = InvertAllLettersString(_Value);
    }

    enum enWhatToCount
    {
        SmallLetters = 0,
        CapitalLetters = 1,
        All = 3
    };

    static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
    {
        if (WhatToCount == enWhatToCount::All)
        {
            return S1.length();
        }

        short Count = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
                Count++;

            if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
                Count++;
        }

        return Count;
    }
    static short CountSmallLetter(string Text)
    {
        short Count = 0;

        for (short i = 0; i < Text.length(); i++)
        {
            if (islower(Text[i]))
                Count++;
        }
        return Count;
    }

    void CountSmallLetter()
    {
        _Value = CountSmallLetter(_Value);
    }

    static short CountCapitalLetter(string Text)
    {
        short Count = 0;

        for (short i = 0; i < Text.length(); i++)
        {
            if (isupper(Text[i]))
                Count++;
        }
        return Count;
    }

    void CountCapitalLetter()
    {
        _Value = CountCapitalLetter(_Value);
    }

    static short CountSpecificLetter(string S1, char Letter)
    {
        short Count = 0;

        for (int i = 0; i < S1.length(); i++)
        {
            if (S1[i] == Letter)
                Count++;
        }

        return Count;
    }
    void CountSpecificLetter()
    {
        char letter;
        cout << "\n Type a Letter to search for :\n";
        cin >> letter;
        _Value = CountSpecificLetter(_Value, letter);
    }
    static bool IsVowel(char Letter)
    {
        Letter = tolower(Letter);
        return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u'));
    }

    static short CountVowels(string S1)
    {
        short Count = 0;

        for (int i = 0; i < S1.length(); i++)
        {
            if (IsVowel(S1[i]))
                Count++;
        }
        return Count;
    }
    void CountVowels()
    {
        _Value = CountVowels(_Value);
    }
    static void PrintVowels(string S1)
    {
        cout << "\nVowels in string are: \n";

        for (int i = 0; i < S1.length(); i++)
        {
            if (IsVowel(S1[i]))
                cout << S1[i] << "\t";
        }
    }
    void PrintVowels()
    {
        PrintVowels(_Value);
    }
    static void PrintEachWordInString(string S1)
    {
        cout << "\nYour string Words are: \n\n";

        string delim = " ";
        string sWord;
        short Pos = 0;

        while ((Pos = S1.find(delim)) != string::npos)
        {
            sWord = S1.substr(0, Pos);

            if (sWord != "")
            {
                cout << sWord << endl;
            }
            S1.erase(0, Pos + delim.length());
        }

        if (S1 != "")
        {
            cout << sWord << endl;
        }
    }
    void PrintEachWordInString()
    {
        PrintEachWordInString(_Value);
    }

};

