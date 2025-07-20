#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsFindMemberScreen.h"
#include "clsListMembersScreen.h"
#include "clsDeleteMembersScreen.h"
#include "clsUpdateMemberScreen.h"
#include "clsAddNewMemberScreen.h"
#include "clsListBooks.h"
#include "clsAddNewBooksScreen.h"
#include "clsRemoveBooksScreen.h"
#include "clsUpdateBooksScreen.h"


using namespace std;
class clsLibUserMainMenuScreen :protected clsScreen
{
private :
    enum eUserMainScreen
    {
        eFindMembers = 1, eListMembers = 2, 
        eUpdateMembers = 3, eDeleteMembers = 4, eAddNewMembers = 5
        ,eListBooks, eAddBooks = 7, eRemoveBooks = 8 , eLogOut = 10 , eUpdateBooks=9 
	};

    static int _ReadMainMenuChoice()
    {
        short Option = clsInputValidate::ReadIntNumberBetween(1, 10, "Invalid Try Again");
        return Option;
    }
    static void _FindMembers()
    {
        clsFindMemberScreen::FindMember();
    }
    static void _ListMembers()
    {
        clsListMembersScreen::ShowMembersList();
    }
    static void _UpdateMembers()
    {
        clsUpdateMemberScreen::UpdateMemberInfo();
    }
    static void _DeleteMembers()
    {
         clsDeleteMembersScreen::DeleteMembers();
    }
    static void _AddNewMembers()
    {
        clsAddNewMemberScreen::AddNewMember();
    }
    static void _ListBooks()
    {
        clsListBooks::ShowBooksList();
    }
    static void _AddBooks()
    {
        clsAddNewBooksScreen::AddNewBook();
    }
    static void _RemoveBooks()
    {
        clsRemoveBooksScreen::RemoveBooks();
    }
    static void _UpdateBooks()
    {
        clsUpdateBooksScreen::UpdateMemberInfo();
    }
    static void _Logout()
    {

    }
    static void _BackToMain()
    {
        ShowMainMenue();
    }
    static void _PerformLibraryMainMenuScreen(eUserMainScreen Choice)
    {
        switch (Choice)
        {
        case clsLibUserMainMenuScreen::eFindMembers:
            system("cls");
            _FindMembers();
            system("pause>0");
            _BackToMain();

            break;
        case clsLibUserMainMenuScreen::eListMembers:
            system("cls");
            _ListMembers();
            system("pause>0");
            _BackToMain();

            break;
        case clsLibUserMainMenuScreen::eUpdateMembers:
            system("cls");
            _UpdateMembers();
            system("pause>0");
            _BackToMain();

            break;
        case clsLibUserMainMenuScreen::eDeleteMembers:
            system("cls");
            _DeleteMembers();
            system("pause>0");
            _BackToMain();

            break;
        case clsLibUserMainMenuScreen::eAddNewMembers:
            system("cls");
            _AddNewMembers();
            system("pause>0");
            _BackToMain();

            break;
        case clsLibUserMainMenuScreen::eUpdateBooks:
            system("cls");
            _UpdateBooks();
            system("pause>0");
            _BackToMain();

            break;
        case clsLibUserMainMenuScreen::eListBooks:
            system("cls");
            _ListBooks();
            system("pause>0");
            _BackToMain();

            break;
        case clsLibUserMainMenuScreen::eAddBooks:
            system("cls");
            _AddBooks();
            system("pause>0");
            _BackToMain();

            break;
        case clsLibUserMainMenuScreen::eRemoveBooks:
            system("cls");
            _RemoveBooks();
            system("pause>0");
            _BackToMain();

            break;
        case clsLibUserMainMenuScreen::eLogOut:
            _Logout();
            break;
        default:
            break;
        }
    }

public :
    static void ShowMainMenue()
    {

        system("cls");
        _DrawScreenHeader("\t\tLibrary Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tLibrary Main Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Find a Member.\n";
        cout << setw(37) << left << "" << "\t[2] Show Members List.\n";
        cout << setw(37) << left << "" << "\t[3] Update Member info.\n";
        cout << setw(37) << left << "" << "\t[4] Delete Member.\n";
        cout << setw(37) << left << "" << "\t[5] Add new Member.\n";
        cout << setw(37) << left << "" << "\t[6] List Books.\n";
        cout << setw(37) << left << "" << "\t[7] Add Books.\n";
        cout << setw(37) << left << "" << "\t[8] Remove Books.\n";
        cout << setw(37) << left << "" << "\t[9] Update Books.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";

        cout << setw(37) << left << "" << "===========================================\n";
        
        cout << setw(37) << left << "" << "Enter a choice from [1] to [10]\n";

        _PerformLibraryMainMenuScreen((eUserMainScreen)_ReadMainMenuChoice());
    }
};

