#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "clsScreen.h"
#include "clsUtil.h"
using namespace std;

class clsLibraryMember : protected clsScreen
{
private :
	enum enMode
	{
		eEmpty=0,eUpdate = 1
	};
	enMode _Mode;
	string _UserName;
	string _ID;
	
	short _BorrowedBooks;
	string _MembershipEndDate;
	bool _MarkForDelete = false;
	string _Password;

static	clsLibraryMember _ConvertLineToObject(string Line)
	{
	vector <string> vLibUsers;
	vLibUsers = clsString::Split(Line);

	return clsLibraryMember(enMode::eUpdate, vLibUsers[0],
		vLibUsers[1], stoi(vLibUsers[2]), vLibUsers[3], clsUtil::Decryption(vLibUsers[4]));
	}

 static	string _ConvertObjectToLine(clsLibraryMember Member,string Separator = "#//#")
	{
		string Line = "";
		Line += Member.Username + Separator;
		Line += Member.ID + Separator;
		Line += to_string( Member.BorrowedBooks) + Separator;
		Line += Member.MembershipEndDate + Separator;
		Line += clsUtil::Encryption(Member.Password);


		return Line;
	}
 static  vector <clsLibraryMember> _LoadUsersDataFromFile()
 {

	 vector <clsLibraryMember> vUsers;

	 fstream MyFile;
	 MyFile.open("LibraryUsers.txt", ios::in);//read Mode

	 if (MyFile.is_open())
	 {

		 string Line;


		 while (getline(MyFile, Line))
		 {

			 clsLibraryMember User = _ConvertLineToObject(Line);

			 vUsers.push_back(User);
		 }

		 MyFile.close();

	 }

	 return vUsers;

 }
	
static	void _SaveRecordsToFile(vector <clsLibraryMember> vLibUsers)
	{

		fstream File;
		
		File.open("LibraryUsers.txt", ios::out);
		if (File.is_open())
		{
			string Line;

			for (clsLibraryMember& U:vLibUsers)
			{
				if (U.MarkForDelete()==false)
				{
					Line = _ConvertObjectToLine(U);
					File << Line << endl;
				}
			}
			File.close();
			
		}
	}
	
static	clsLibraryMember _ReturnEmptyObject()
	{
		return clsLibraryMember(enMode::eEmpty, "", "", 0, "","");
	}
static void _AddNewLineToMemberFile(string Line)
{
	fstream MyFile;
	MyFile.open("LibraryUsers.txt", ios::out | ios::app);

	if (MyFile.is_open())
	{

		MyFile << Line << endl;

		MyFile.close();

	}
}

public :
	clsLibraryMember(enMode Mode,string UserName ,string ID,short BorrowedBooks,string Membership,string Password)
	{
		_Mode = Mode;
		_UserName = UserName;
		_ID = ID;
		_BorrowedBooks = BorrowedBooks;
		_MembershipEndDate = Membership;
		_Password = Password;
	}
	bool MarkForDelete()
	{
		return _MarkForDelete;
	}
	string GetUserName()
	{
		return _UserName;
	}
	string GetID()
	{
		return _ID;
	}
	short GetBorrowedBooks()
	{
		return _BorrowedBooks;
	}
	string GetMembershipEndDate()
	{
		return _MembershipEndDate;
	}
	void SetID(string ID)
	{
		_ID = ID;
	}
	void SetUserName(string UserName)
	{
		 _UserName = UserName;
	}
	void SetBorrowedBooks(int BorrowedBooks)
	{
		_BorrowedBooks = BorrowedBooks;
	}
	void SetMembership (string MembershipEnd)
	{
		_MembershipEndDate = MembershipEnd;
	}
	string GetPassword()
	{
		return _Password;
	}
	void SetPassword(string Password)
	{
		_Password = Password;
	}

	_declspec(property(get = GetUserName, put = SetUserName))string Username;
	_declspec(property(get = GetBorrowedBooks, put = SetBorrowedBooks))short BorrowedBooks;
	_declspec(property( get = GetID,put=SetID))string ID;
	_declspec(property(get = GetMembershipEndDate, put = SetMembership))string MembershipEndDate;
	_declspec(property(get = GetPassword, put = SetPassword))string Password;




	bool IsEmpty()
	{
		
		return (_Mode == enMode::eEmpty);
	}

	static bool IsMemberExist(string UserName)
	{

		clsLibraryMember Member = clsLibraryMember::Find(UserName);
		return (!Member.IsEmpty());
	}

	static vector <clsLibraryMember> GetUsersLibrary()
	{
		return _LoadUsersDataFromFile();
	}

	static	clsLibraryMember Find(string UserName)
	{
		fstream MyFile;
		MyFile.open("LibraryUsers.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsLibraryMember Member = _ConvertLineToObject(Line);
				if (Member.Username == UserName)
				{
					MyFile.close();
					return Member;
				}

			}

			MyFile.close();

		}
		
		return _ReturnEmptyObject();
	}

	static void Delete(string UserName)
	{
		vector <clsLibraryMember> vLibMembers = _LoadUsersDataFromFile();

		for (clsLibraryMember& Member : vLibMembers)
		{
			if (Member.Username==UserName)
			{
				Member._MarkForDelete = true;
			}
		}
		_SaveRecordsToFile(vLibMembers);
	}

	 clsLibraryMember Update(string UserName)
	{
		 vector <clsLibraryMember> vLibMembers = _LoadUsersDataFromFile();

		 for (clsLibraryMember& Member : vLibMembers)
		 {
			 if (Member.Username == UserName)
			 {
				 Member = *this;
				 _SaveRecordsToFile(vLibMembers);
				 return Member;
			 }
		 }
		 
		 
	}
	  void AddNew()
	 {
		  _AddNewLineToMemberFile(_ConvertObjectToLine(*this));
	 }
	 
	  void IncreaseBorrowedBooksNumber()
	  {
		  _BorrowedBooks++;
	  }

	  static	bool CheckLogin(string Name, string Password)
	  {
		  vector <clsLibraryMember> vMembers = _LoadUsersDataFromFile();

		  for (clsLibraryMember& Member : vMembers)
		  {
			  if (Member.Username == Name && Member.Password == Password)
			  {
				  return true;
			  }
		  }
		  return false;
	  }

};

