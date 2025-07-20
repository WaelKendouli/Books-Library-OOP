#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBook.h"
#include "clsDate.h"
#include <iomanip>
using namespace std;

class clsRemoveBooksScreen : protected clsScreen
{
	static string _ReadUsername()
	{
		string S;
		S = clsInputValidate::ReadString("Enter the Book that you want to delete :\n\n");
		return S;
	}
	static void _PrintBook(clsBook Book)
	{
		cout << "\n________________________________\n";
		cout << "\nBook Name : " << Book.Name << endl;
		cout << "Author : " << Book.Author << endl;
		cout << "Serial Number  : " << Book.SerialNumber << endl;
		cout << "Category : " << Book.Category << endl;
		cout << "Status : " << Book.Status << endl;


		cout << "\n________________________________\n";

	}
public:
	static void RemoveBooks()
	{
		_DrawScreenHeader("\tDelete Members Screen");
		string Name = _ReadUsername();
		clsBook Book = clsBook::Find(Name);
		while (Book.IsEmpty() == true)
		{
			cout << "Member not found try again \n\n";
			Name = _ReadUsername();
			Book = clsBook::Find(Name);
		}
		_PrintBook(Book);
		if (clsInputValidate::AreYouSure() == true)
		{
			clsBook::Delete(Name);
		}


	}
};

