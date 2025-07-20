#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsLibraryMember.h"
using namespace std;



class clsFindMemberScreen : protected clsScreen
{
private :
	static void _PrintFoundMember(clsLibraryMember Member)
	{
		cout << "\n\n________________________________\n";
		cout << "Member Name : " << Member.Username << endl;
		cout << "Member ID : " << Member.ID << endl;
		cout << "Borrowed Books : " << Member.BorrowedBooks << endl;
		cout << "Membership end date : " << Member.MembershipEndDate << endl;
		cout << "Password : " << Member.Password << endl;

		cout << "\n\n________________________________\n";

	}
	static string _ReadUserName()
	{
		string UserName = clsInputValidate::ReadString("Enter UserName : ");
		return UserName;
	}
public :
	static 	void FindMember()
	{
		_DrawScreenHeader("\tFind Member Screen");
		string UserName = _ReadUserName();
		clsLibraryMember Member = clsLibraryMember::Find(UserName);
		if (Member.IsEmpty()==false)
		{
			_PrintFoundMember(Member);
		}
		else
		{
			cout << "Member Not Found :-( \n";
		}
	}
};

