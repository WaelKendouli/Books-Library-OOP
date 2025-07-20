#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBook.h"
#include <iomanip>
using namespace std;
class clsReturnBookScreen : protected clsScreen
{
private:

	static string _ReadBookName()
	{
		string S;
		S = clsInputValidate::ReadString("Enter Book name  :\n\n");
		return S;
	}
	static void _PrintBook(clsBook Book)
	{
		cout << "Book is Found :-)\n";
		cout << "\n________________________________\n";
		cout << "\nBook Name : " << Book.Name << endl;
		cout << "Author : " << Book.Author << endl;
		cout << "Serial Number  : " << Book.SerialNumber << endl;
		cout << "Category : " << Book.Category << endl;
		cout << "Status : " << Book.Status << endl;


		cout << "\n________________________________\n";

	}
public:
	static void ShowReturnBookScreen()
	{
		_DrawScreenHeader("\tReturn a Book Screen");
		string Name = _ReadBookName();
		clsBook  Book = clsBook::Find(Name);
		while (Book.IsEmpty() == true || Book.Status == "Available")
		{
			cout << "Book was not found or its already Available try again \n\n";
			Name = _ReadBookName();
			Book = clsBook::Find(Name);
		}


		_PrintBook(Book);

		if (clsInputValidate::AreYouSure() == true)
		{
			Book.ChangeStatusToAvailable();
			// DONT FORGET to Increase the current Member's Borrowed books number    
			cout << "Borrowing Process Succeeded ";
		}

	}
};

