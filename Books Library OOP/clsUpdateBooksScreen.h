#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBook.h"
#include "clsDate.h"
#include <iomanip>
using namespace std;

class clsUpdateBooksScreen : protected clsScreen
{
private :

	static string _ReadBookName()
	{
		string S;
		S = clsInputValidate::ReadString("Enter Book name  :\n\n");
		return S;
	}

	static void _ReadUpdatedBookInfo(clsBook& Book)
	{
		Book.Name = clsInputValidate::ReadString("Book Name :");
		Book.Author = clsInputValidate::ReadString("Author :");
		Book.SerialNumber = clsInputValidate::ReadShortNumber("Serial Number :");
		Book.Category = clsInputValidate::ReadString("Category :");
		Book.Status = clsInputValidate::ReadString("Status :");


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
public :
	static void UpdateMemberInfo()
	{
		_DrawScreenHeader("\tUpdate Book Screen");
		string Name = _ReadBookName();
		clsBook  Book = clsBook::Find(Name);
		while (Book.IsEmpty() == true)
		{
			cout << "Book not found try again \n\n";
			Name = _ReadBookName();
			Book = clsBook::Find(Name);
		}
		_PrintBook(Book);
		if (clsInputValidate::AreYouSure() == true)
		{
			_ReadUpdatedBookInfo(Book);
			Book.Update(Name);
			cout << "\nUpdated Successfully\n";
		}
	}
};

