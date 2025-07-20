

#include <iostream>
#include "clsAdminLoginScreen.h"
#include "clsMembersLoginScreen.h"
#include "clsInputValidate.h"
using namespace std;

int main()
{
	int Choice;
	cout << "Choose Login Mode \n [1]: Employee Login \n [2]: Member Login : \n";
	Choice = clsInputValidate::ReadIntNumberBetween(1, 2, "\nTry Again");

	if (Choice==1)
	{
		while (true)
		{
			if (!clsAdminLoginScreen::AdminsLoginScreen())
			{
				break;
			}

		}
	}
	else
	{
		while (true)
		{
			if (!clsMembersLoginScreen::MembersLoginScreen())
			{
				break;
			}

		}
	}

	
	
	
	system("pause>0");
}

