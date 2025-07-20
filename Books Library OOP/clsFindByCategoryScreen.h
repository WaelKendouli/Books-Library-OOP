#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBook.h"
#include <iomanip>
using namespace std;
class clsFindByCategoryScreen : protected clsScreen
{

private:

	static string _ReadBookCategory()
	{
		string S;
		S = clsInputValidate::ReadString("Enter Category name  :\n\n");
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
	static void ShowFindBookByCategoryScreen()
	{
		_DrawScreenHeader("\tFind a Book by Category Screen");
		string Category = _ReadBookCategory();
		vector	<clsBook>  Books = clsBook::FindByCategory(Category);
		while (Books.size() == 0)
		{
			cout << "Category was not found try again \n\n";
			Category = _ReadBookCategory();
			Books = clsBook::FindByCategory(Category);
		}
		for (clsBook& Book : Books)
		{
			_PrintBook(Book);
		}



	}
};

