#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsLibraryMember.h"
#include "clsDate.h"
#include <iomanip>
using namespace std;
class clsAddNewMemberScreen : protected clsScreen
{
private :
	static string _ReadUsername()
	{
		string S;
		S = clsInputValidate::ReadString("Enter User name  :\n\n");
		return S;
	}

	static void _ReadNewMemberInfo(clsLibraryMember& Member)
	{
		Member.Username = clsInputValidate::ReadString("User Name :");
		Member.ID = clsInputValidate::ReadString("ID :");
		Member.BorrowedBooks = clsInputValidate::ReadShortNumber("Borrowed Books :");
		Member.MembershipEndDate = clsInputValidate::ReadString("Membership end date dd/mm/yyyy:");
		while (!clsDate::IsValidDate(Member.MembershipEndDate))
		{
			cout << "Date not Valid , Try again \n";
			Member.MembershipEndDate = clsInputValidate::ReadString("Membership end date dd/mm/yyyy:");
		}
		Member.Password = clsInputValidate::ReadString("Enter New Password :");

	}
	static void _PrintMember(clsLibraryMember Member)
	{
		cout << "\n________________________________\n";
		cout << "\nMember Name : " << Member.Username << endl;
		cout << "Member ID : " << Member.ID << endl;
		cout << "Borrowed Books : " << Member.BorrowedBooks << endl;
		cout << "Membership end date : " << Member.MembershipEndDate << endl;
		cout << "Password : " << Member.Password << endl;
		cout << "\n________________________________\n";

	}
public :
	static void AddNewMember()
	{
		_DrawScreenHeader("Add New Member ");
		clsLibraryMember NewMember = clsLibraryMember::Find("");
		bool isExist;
		do
		{
			_ReadNewMemberInfo(NewMember);
			isExist = clsLibraryMember::IsMemberExist(NewMember.Username);
			if (isExist ==true)
			{
				cout << "\nMember Already exist try new one \n";
			}
			
		} while (isExist ==true);
		_PrintMember(NewMember);
		if (clsInputValidate::AreYouSure()==true)
		{
			NewMember.AddNew();
		}
	}

};

