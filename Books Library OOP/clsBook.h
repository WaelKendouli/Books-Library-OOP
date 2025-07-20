#pragma once
#include <iostream>
#include <fstream>
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;
class clsBook : protected clsScreen
{
private :
	enum  enMode
	{
		Empty=0,Exist=1
	};

	enMode _Mode;
	string _Name;
	string _Author;
	int _SerialNumber;
	string _Category;
	string _Status;
	bool _MarkForDelete = false;



	static	clsBook _ConvertLineToObject(string Line)
	{
		vector <string> vBooks;
		vBooks = clsString::Split(Line);

		return clsBook(enMode::Exist,vBooks[0], vBooks[1], stoi(vBooks[2]), vBooks[3], vBooks[4]);
	}
	static	string _ConvertObjectToLine(clsBook Book, string Separator = "#//#")
	{
		string Line = "";
		Line += Book.Name + Separator;
		Line += Book.Author + Separator;
		Line += to_string(Book.SerialNumber) + Separator;
		Line += Book.Category + Separator;

		Line += Book.Status;


		return Line;
	}
	static  vector <clsBook> _LoadBooksDataFromFile()
	{

		vector <clsBook> vBooks;

		fstream MyFile;
		MyFile.open("Books.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsBook Book = _ConvertLineToObject(Line);

				vBooks.push_back(Book);
			}

			MyFile.close();

		}

		return vBooks;

	}

	static	void _SaveRecordsToFile(vector <clsBook> Books)
	{

		fstream File;

		File.open("Books.txt", ios::out);
		if (File.is_open())
		{
			string Line;

			for (clsBook& U : Books)
			{
				if (U._MarkForDelete == false)
				{
					Line = _ConvertObjectToLine(U);
					File << Line << endl;
				}
			}
			File.close();

		}
	}

	static	clsBook _ReturnEmptyObject()
	{
		return clsBook(enMode::Empty,"", "", 0, "", "");
	}
	static void _AddNewLineToBooksFile(string Line)
	{
		fstream MyFile;
		MyFile.open("Books.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << Line << endl;

			MyFile.close();

		}
	}


public :

	clsBook(enMode Mode,string Name, string Author, int SerialNumber, string Category , string Status)
	{
		_Mode = Mode;
		_Name = Name;
		_Author = Author;
		_SerialNumber = SerialNumber;
		_Category = Category;
		_Status = Status;
	}
	string GetName()
	{
		return _Name;
	}
	string GetAuthor()
	{
		return _Author;
	}
	int GetSerialNumber()
	{
		return _SerialNumber;
	}
	string GetCategory()
	{
		return _Category;
	}
	string GetStatus()
	{
		return _Status;
	}

	


	void SetAuthor(string Author)
	{
		_Author = Author;
	}
	void SetName(string Name)
	{
		_Name = Name;
	}
	void SetSerialNumber(int SerialNumber)
	{
		_SerialNumber = SerialNumber;
	}
	void SetCategory(string Category)
	{
		_Category = Category;
	}

	void SetStatus(string Status)
	{
		_Status = Status;
	}

	_declspec(property(get = GetName, put = SetName))string Name;
	_declspec(property(get = GetSerialNumber, put = SetSerialNumber))int SerialNumber;
	_declspec(property(get = GetAuthor, put = SetAuthor))string Author;
	_declspec(property(get = GetCategory, put = SetCategory))string Category;
	_declspec(property(get = GetStatus, put = SetStatus))string Status;

	bool IsEmpty()
	{

		return (_Mode == enMode::Empty);
	}

	static bool IsBookExist(string Name)
	{

		clsBook Member = clsBook::Find(Name);
		return (!Member.IsEmpty());
	}

	static vector <clsBook> GetBooksLibrary()
	{
		return _LoadBooksDataFromFile();
	}

	static	clsBook Find(string Name)
	{
		fstream MyFile;
		MyFile.open("Books.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBook Book = _ConvertLineToObject(Line);
				if (Book.Name == Name)
				{
					MyFile.close();
					return Book;
				}

			}

			MyFile.close();

		}

		return _ReturnEmptyObject();
	}

	static void Delete(string Name)
	{
		vector <clsBook> vLibBooks = _LoadBooksDataFromFile();

		for (clsBook& Book : vLibBooks)
		{
			if (Book.Name == Name)
			{
				Book._MarkForDelete = true;
			}
		}
		_SaveRecordsToFile(vLibBooks);
	}

	void Update(string Name)
	{
		vector <clsBook> vLibBook = _LoadBooksDataFromFile();

		for (clsBook& Book : vLibBook)
		{
			if (Book.Name == Name)
			{
				Book = *this;
				_SaveRecordsToFile(vLibBook);
				break;
			}
		}


	}
	void AddNew()
	{
		_AddNewLineToBooksFile(_ConvertObjectToLine(*this));
	}

 void ChangeStatusToBorrowed()
	{
		 
		
	 if (_Status == "Available")
	 {

		 _Status = "Borrowed";
	 }
	 Update(_Name);
			
	}

 	void ChangeStatusToAvailable()
 {

	 if (_Status == "Borrowed")
	 {

		 _Status = "Available";
	 }
	 Update(_Name);
 }

  static vector <clsBook> GetAvailableOnlyList()
 {
	 vector <clsBook> vBooks = _LoadBooksDataFromFile();
	 vector <clsBook> vAvailableBooks;
	 for (clsBook& Book : vBooks)
	 {
		 if (Book.Status== "Available")
		 {
			 vAvailableBooks.push_back(Book);
		 }

	 }
	 return vAvailableBooks;
	}
  static vector	<clsBook> FindByAuthor(string Author)
  {
	  fstream MyFile;
	  vector <clsBook> vBooks;
	  MyFile.open("Books.txt", ios::in);//read Mode

	  if (MyFile.is_open())
	  {
		  
		  string Line;
		  while (getline(MyFile, Line))
		  {
			  clsBook Book = _ConvertLineToObject(Line);
			  if (Book.Author == Author)
			  {
				  vBooks.push_back(Book);
				  
			  }

		  }

		  MyFile.close();

	  }
	  return vBooks;
	  
  }

  static vector	<clsBook> FindByCategory(string Category)
  {
	  fstream MyFile;
	  vector <clsBook> vBooks;
	  MyFile.open("Books.txt", ios::in);//read Mode

	  if (MyFile.is_open())
	  {

		  string Line;
		  while (getline(MyFile, Line))
		  {
			  clsBook Book = _ConvertLineToObject(Line);
			  if (Book.Category == Category)
			  {
				  vBooks.push_back(Book);

			  }

		  }

		  MyFile.close();

	  }
	  return vBooks;

  }



};

