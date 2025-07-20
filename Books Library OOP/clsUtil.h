#pragma once
#include<iostream>
#include<string>
#include<cstdlib>
#include"clsDate.h"
using namespace std;
class clsUtil
{

public:
    static void Srand()
    {
        srand((unsigned)time(NULL));
    }
    static int ReadPositiveNumber(string Text)
    {
        int Number = 0;
        do
        {
            cout << Text << endl;
            cin >> Number;
        } while (Number <= 0);
        return Number;
    }

    static void Swap(int& a, int& b)
    {
        int c;
        c = a;
        a = b;
        b = c;
    }
    static void Swap(string& a, string& b)
    {
        string c;
        c = a;
        a = b;
        b = c;
    }
    static void Swap(clsDate& a, clsDate& b)
    {
        clsDate c;
        c = a;
        a = b;
        b = c;
    }
    static  int NumberInReversed(int Number)
    {
        int remainder = 0;
        int Number2 = 0;
        do
        {
            remainder = Number % 10;
            Number /= 10;
            Number2 = Number2 * 10 + remainder;

        } while (Number > 0);
        return Number2;
    }
    static  void PrintReversedResult(int Number)
    {
        cout << NumberInReversed(Number);
    }

    static string NumberToText(int Number)
    {
        if (Number == 0)
        {
            return "";
        }
        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "",
            "One","Two","Three","Four","Five","Six","Seven",
            "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
            "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
            return arr[Number] + " ";
        }
        if (Number >= 20 && Number <= 99)
        {
            string arr[] = {
            "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty"
            ,"Ninety" };
            return arr[Number / 10] + " " + NumberToText(Number % 10);
        }
        if (Number >= 100 && Number <= 199)
        {
            return "One Hundred " + NumberToText(Number % 100);
        }
        if (Number >= 200 && Number <= 999)
        {
            return NumberToText(Number / 100) + "Hundreds " +
                NumberToText(Number % 100);
        }
        if (Number >= 1000 && Number <= 1999)
        {
            return "One Thousand " + NumberToText(Number % 1000);
        }
        if (Number >= 2000 && Number <= 999999)
        {
            return NumberToText(Number / 1000) + "Thousands " +
                NumberToText(Number % 1000);
        }
        if (Number >= 1000000 && Number <= 1999999)
        {
            return "One Million " + NumberToText(Number % 1000000);
        }
        if (Number >= 2000000 && Number <= 999999999)
        {
            return NumberToText(Number / 1000000) + "Millions " +
                NumberToText(Number % 1000000);
        }
        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return "One Billion " + NumberToText(Number %
                1000000000);
        }
        else
        {
            return NumberToText(Number / 1000000000) + "Billions " +
                NumberToText(Number % 1000000000);
        }
    }

    static  int CountDigitFrequency(int Number, short int Digit)
    {
        int remainder = 0;
        short int sum = 0;
        do
        {
            remainder = Number % 10;
            Number /= 10;
            if (remainder == Digit)
            {
                sum++;
            }

        } while (Number > 0);
        return sum;
    }
    static  void PrintResultOfDigitFrequency(int Number)
    {
        for (int i = 1; i <= 9; i++)
        {
            short int DigitFrequency = CountDigitFrequency(Number, i);
            if (DigitFrequency >= 1)
                cout << "Digit " << i << " Frequency is " << DigitFrequency << " Time(s)\n";
        }
    }





    static  bool isPalindromeNumber(int Number)
    {
        return NumberInReversed(Number) == Number;
    }
    static void PrintResult(int Number)
    {
        if (isPalindromeNumber(Number))
        {
            cout << "Yes, it's Palindrome Number\n";
        }
        else
            cout << "No, it's not Palindrome Number\n";
    }

    static  void InvertedNumberPattern(int Number)
    {
        for (int i = Number; i >= 1; i--)
        {
            for (int a = 1; a <= i; a++)
            {
                cout << i;
            }
            cout << endl;
        }
    }
    static void NumberPattern(int Number)
    {
        for (int i = 1; i <= Number; i++)
        {
            for (int a = 1; a <= i; a++)
            {
                cout << i;
            }
            cout << endl;
        }
    }
    static  void InvertedLetterPattern(int Number)
    {
        int Letter = 65;
        for (int i = (Letter + Number) - 1; i >= Letter; i--)
        {
            for (int a = 65; a <= i; a++)
            {
                cout << char(i);
            }
            cout << endl;
        }
    }
    static void LetterPattern(int Number)
    {
        int Letter = 65;
        for (int i = 65; i <= (Letter + Number - 1); i++)
        {
            for (int a = 65; a <= i; a++)
            {
                cout << char(i);
            }
            cout << endl;
        }
    }
    static  void WordFromAAAtoZZZ()
    {
        string word = " ";
        for (int i = 65; i <= 90; i++)
        {
            for (int a = 65; a <= 90; a++)
            {
                for (int b = 65; b <= 90; b++)
                {
                    word = word + char(i);
                    word = word + char(a);
                    word = word + char(b);

                    cout << word << endl;
                    word = " ";

                }
            }
            cout << endl;
        }
    }
    static  string ReadPassword(string Text)
    {
        string Password = "";
        cout << Text << endl;
        cin >> Password;
        return Password;
    }
    static  bool GuessPassword(string Pass)
    {
        string word = "";
        int count = 0;
        for (int i = 65; i <= 90; i++)
        {
            for (int a = 65; a <= 90; a++)
            {
                for (int b = 65; b <= 90; b++)
                {

                    word = word + char(i);
                    word = word + char(a);
                    word = word + char(b);
                    count++;
                    cout << "trial [" << count << "] : ";
                    cout << word << endl;
                    if (word == Pass)
                    {
                        cout << "Password is: " << word << endl;
                        cout << "found after " << count << " Trial(s)\n";

                        return true;
                    }
                    word = "";


                }
            }

        }
        return false;
    }

    static  string Encryption(string Text, short int KeyEncryption = 2)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + KeyEncryption);
        }
        return Text;
    }
    static string Decryption(string Text, short int KeyEncryption = 2)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - KeyEncryption);
        }
        return Text;
    }

    static  int RandomNumber(int from, int to)
    {
        int Number = rand() % (to - from + 1) + from;
        return Number;
    }

};
