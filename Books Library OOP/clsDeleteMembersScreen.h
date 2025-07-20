#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsLibraryMember.h"
#include <iomanip>
using namespace std;
class clsDeleteMembersScreen : protected clsScreen
{
private :

	static string _ReadUsername()
	{
		string S;
		S = clsInputValidate::ReadString("Enter the Member that you want to delete :\n\n");
		return S;
	}
	static void _PrintFoundMember(clsLibraryMember Member)
	{
		cout << "\n\n________________________________\n";
		cout << "Member Name : " << Member.Username << endl;
		cout << "Member ID : " << Member.ID << endl;
		cout << "Borrowed Books : " << Member.BorrowedBooks << endl;
		cout << "Membership end date : " << Member.MembershipEndDate << endl;
		cout << "Membership end date : " << Member.Password << endl;

		cout << "\n\n________________________________\n";

	}
public:
	static void DeleteMembers()
	{
		_DrawScreenHeader("\tDelete Members Screen");
		string UserName = _ReadUsername();
		clsLibraryMember Member = clsLibraryMember::Find(UserName);
		while (Member.IsEmpty()==true)
		{
			cout << "Member not found try again \n\n";
			UserName = _ReadUsername();
			Member = clsLibraryMember::Find(UserName);
		}
		_PrintFoundMember(Member);
		if (clsInputValidate::AreYouSure()==true)
		{
			clsLibraryMember::Delete(UserName);
		}

		
	}
};

