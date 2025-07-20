
#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBook.h"
#include <iomanip>
using namespace std;
class clsFindByAuthorScreen : protected clsScreen
{
private:

	static string _ReadBookAuthor()
	{
		string S;
		S = clsInputValidate::ReadString("Enter Author name  :\n\n");
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
	static void ShowFindBookByAuthorScreen()
	{
		_DrawScreenHeader("\tFind a Book by Author Screen");
		string Author = _ReadBookAuthor();
	vector	<clsBook>  Books = clsBook::FindByAuthor(Author);
		while (Books.size() == 0)
		{
			cout << "Author was not found try again \n\n";
			Author = _ReadBookAuthor();
			Books = clsBook::FindByAuthor(Author);
		}
		for (clsBook& Book : Books)
		{
			_PrintBook(Book);
		}

		

	}
};

