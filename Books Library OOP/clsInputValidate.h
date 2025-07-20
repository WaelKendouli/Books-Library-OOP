#pragma once
#include <iostream>
#include "clsPeriod.h"
using namespace std;
class clsInputValidate
{
public:
	static string ReadString(string Message)
	{
		string S;
		cout << Message << endl;
		getline(cin >> ws, S);
		return S;
	}
	static	bool IsNumberBetween(int Number, int from, int to)
	{
		return (Number >= from && Number <= to);
	}

	static	bool IsNumberBetween(double Number, double from, double to)
	{
		return (Number >= from && Number <= to);
	}

	static	bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
	{
		if (clsDate::IsValidDate(Date) == false || clsDate::IsValidDate(DateFrom) == false || clsDate::IsValidDate(DateTo) == false)
		{
			cout << "One Of Dates isn't Valid \n";
			return false;
		}
		if (clsDate::IsDate1AfterDate2(DateFrom, DateTo))
		{
			clsDate::SwapDates(DateFrom, DateTo);
		}
		clsPeriod Period(DateFrom, DateTo);

		return  clsPeriod::IsDateWithinPeriod(Date, Period);
	}
	static short ReadShortNumber(string Text)
	{
		short Number = 0;
		cout << Text << endl;
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid please try again" << endl;
			cin >> Number;

		}
		return Number;
	}
	static int ReadIntNumber(string Text)
	{
		int Number = 0;
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Text << endl;
			cin >> Number;

		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string Text)
	{
		int Number = 0;
		cin >> Number;
		while (cin.fail() || !IsNumberBetween(Number, From, To))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Text << endl;
			cin >> Number;

		}
		return Number;
	}
	static double ReadDblNumber(string Text)
	{
		double Number = 0;
		cout << Text << endl;
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Not valid Try again :" << endl;
			cin >> Number;

		}
		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string Text)
	{
		double Number = 0;
		cout << Text << endl;
		cin >> Number;
		while (cin.fail() || !IsNumberBetween(Number, From, To))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Try again \n";
			cin >> Number;

		}
		return Number;
	}
	static bool IsValideDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static bool AreYouSure()
	{
		char Answer = 'n';
		cout << "\nAre you sure you want to perform this action y/n ?\n";
		cin >> Answer;
		return (tolower(Answer) == 'y');
	}
};

