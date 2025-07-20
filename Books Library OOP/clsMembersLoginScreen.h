#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsLibraryMember.h"
#include "clsString.h"
#include "clsUtil.h"
#include <fstream>
#include "clsDate.h"
#include <iomanip>
#include "clsMembersMainMenuScreen.h"

using namespace std;
class clsMembersLoginScreen : protected clsScreen
{
private:
	static bool MembersLogin()
	{

		bool Login = true;
		short FailedLoginCount = 3;
		string MemberName;
		string Password;
		clsLibraryMember Member = clsLibraryMember::Find("");
		do
		{

			if (FailedLoginCount == 0)
			{
				cout << "Sorry You cant Login any further \n";
				return false;
			}
			MemberName = clsInputValidate::ReadString("Enter Member Name : ");
			Password = clsInputValidate::ReadString("Password : ");
			
			Login = clsLibraryMember::CheckLogin(MemberName, Password);
			if (Login == false)
			{
				FailedLoginCount--;
				cout << "Login Failed , you have " << FailedLoginCount << " Attempts left  \n";
				cout << "Press Any key to continue \n";
				system("pause>0");
			}

		} while (Login == false);
		Member = clsLibraryMember::Find(MemberName);
		
		if (clsDate::IsDate1AfterDate2(clsDate::GetSystemDate(), clsDate(Member.MembershipEndDate)))
		{
			system("cls");
			_DrawMembershipExpiredMessage();
			system("pause>0");
			return false;
		}

		clsMembersMainMenuScreen::ShowMainMembersChoicesMenu();
	}
public:
	static bool MembersLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t Members Login Screen ");
		return MembersLogin();
	}

};

