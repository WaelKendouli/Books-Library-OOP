#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsLibraryMember.h"
#include "clsDate.h"
#include <iomanip>
using namespace std;
class clsUpdateMemberScreen : protected clsScreen
{
private :
	static string _ReadUsername()
	{
		string S;
		S = clsInputValidate::ReadString("Enter the Member that you want to Update :\n\n");
		return S;
	}
	static void _PrintFoundMember(clsLibraryMember Member)
	{
		cout << "\tMember is Found !\n";
		cout << "\n________________________________\n\n";
		cout << "Member Name : " << Member.Username << endl;
		cout << "Member ID : " << Member.ID << endl;
		cout << "Borrowed Books : " << Member.BorrowedBooks << endl;
		cout << "Membership end date : " << Member.MembershipEndDate << endl;
		cout << "Password : " << Member.Password << endl;


		cout << "\n________________________________\n";

	}
 static	void _UpdateMemberInfo(clsLibraryMember& Member)
	{
		
		cout << "Enter Number of borrowed Books : ";
		Member.BorrowedBooks = clsInputValidate::ReadShortNumber("try again");
		Member.MembershipEndDate = clsInputValidate::ReadString("Enter New end date :");
		while (!clsDate::IsValidDate(clsDate(Member.MembershipEndDate)))
		{
			cout << "Date is not valid , Try again !\n\n";
			Member.MembershipEndDate = clsInputValidate::ReadString("Enter New end date :");
		}
		Member.Password = clsInputValidate::ReadString("Enter New Password :");

	}
public :
	static void UpdateMemberInfo()
	{
		_DrawScreenHeader("\tUpdate Member Screen");
		string UserName = _ReadUsername();
		clsLibraryMember Member = clsLibraryMember::Find(UserName);
		while (Member.IsEmpty() == true)
		{
			cout << "Member not found try again \n\n";
			UserName = _ReadUsername();
			Member = clsLibraryMember::Find(UserName);
		}
		_PrintFoundMember(Member);
		if (clsInputValidate::AreYouSure() == true)
		{
			_UpdateMemberInfo(Member);
			Member.Update(UserName);
			cout << "\nUpdated Successfully\n";
		}
	}
};

