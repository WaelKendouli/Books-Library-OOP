#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsAdminLogin.h"
#include "clsDate.h"
#include "clsInputValidate.h"
#include "clsLibUsersMainMenuScreen.h"
using namespace std;
class clsAdminLoginScreen : protected clsScreen
{
private :
	static bool AdminsLogin()
	{
		
		bool Login=true;
		short FailedLoginCount = 3;
		string AdminName;
		string Password;
		do
		{
		
			if (FailedLoginCount==0)
			{
				cout << "Sorry You cant Login any further \n";
				return false;
			}
			AdminName = clsInputValidate::ReadString("Enter Admin Name : ");
			Password = clsInputValidate::ReadString("Password : ");
			Login = clsAdminLogin::CheckLogin(AdminName, Password);
			if (Login == false)
			{
				FailedLoginCount--;
				cout << "Login Failed , you have " << FailedLoginCount << " Attempts left  \n";
				cout << "Press Any key to continue \n";
				system("pause>0");
			}

		} while (Login==false);
		clsLibUserMainMenuScreen::ShowMainMenue();
	}
public :
	static bool AdminsLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t Admin Login Screen ");
		return AdminsLogin();
	}
};

