#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsUtil.h"
#include <fstream>
#include "clsDate.h"
#include <iomanip>
using namespace std;
class clsAdminLogin
{
private :
enum enMode
	{
		eEmpty = 0 , eExist=1
	};
	enMode _Mode;
	string _Name;
	string _Password;
	string _AccNumber;

	static	clsAdminLogin _ConvertLineToObject(string Line)
	{
		vector <string> vLibAdmins;
		vLibAdmins = clsString::Split(Line);

		return clsAdminLogin(enMode::eExist, vLibAdmins[0],
			clsUtil::Decryption(vLibAdmins[1]), vLibAdmins[2]);
	}

	static  vector <clsAdminLogin> _LoadAdminsDataFromFile()
	{

		vector <clsAdminLogin> vAdmins;

		fstream MyFile;
		MyFile.open("Admins.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsAdminLogin Admin = _ConvertLineToObject(Line);

				vAdmins.push_back(Admin);
			}

			MyFile.close();

		}

		return vAdmins;

	}

	static	clsAdminLogin _ReturnEmptyObject()
	{
		return clsAdminLogin(enMode::eEmpty, "", "", "");
	}

public :
	clsAdminLogin(enMode Mode,string Name ,string Password,string AccNumber)
	{
		_Mode = Mode;
		_Name = Name;
		_Password = Password;
		_AccNumber = AccNumber;
	}
	string GetPassword()
	{
		return _Password;
	}
	void SetPassword(string Password)
	{
		_Password = Password;
	}
	_declspec(property(get = GetPassword, put = SetPassword))string Password;

	string GetName()
	{
		return _Name;
	}
	void SetName(string Name)
	{
		_Name = Name;
	}
	_declspec(property(get = GetName, put = SetName))string Name;
	string GetAccountNumber()
	{
		return _AccNumber;
	}
	void SetAccountNumber(string AccountNumber)
	{
		_AccNumber = AccountNumber;
	}
	_declspec(property(get = GetAccountNumber, put = SetAccountNumber))string AccountNumber;

	static	clsAdminLogin Find(string AdminName)
	{
		fstream MyFile;
		MyFile.open("Admins.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsAdminLogin Member = _ConvertLineToObject(Line);
				if (Member.Name == AdminName)
				{
					MyFile.close();
					return Member;
				}

			}

			MyFile.close();

		}

		return _ReturnEmptyObject();
	}

	static	bool CheckLogin(string AdminName,string Password)
	{
		vector <clsAdminLogin> vAdmins = _LoadAdminsDataFromFile();

		for (clsAdminLogin& Admin : vAdmins)
		{
			if (Admin.Name == AdminName && Admin.Password == Password)
			{
				return true;
			}
		}
		return false;
	}
};

