#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBook.h"
#include "clsListBooks.h"
#include "clsDate.h"
#include "clsAvailableBooksScreen.h"
#include "clsFindByBookNameScreen.h"
#include "clsFindByAuthorScreen.h"
#include "clsFindByCategoryScreen.h"
#include "clsBorrowBookScreen.h"
#include "clsReturnBookScreen.h"

#include <iomanip>
using namespace std;
class clsMembersMainMenuScreen : protected clsScreen
{
private :
    enum enMainMembersMenu
    {
        eAllBooks = 1 ,eOnlyAvailable=2 , eSearchByName =3
        , eSearchByAuthor=4 , eSearchByCat=5,eBorrowBooks=6,eReturnBook=7,eLogout=8

    };
    static int _ReadMainMenuChoice()
    {
        short Option = clsInputValidate::ReadIntNumberBetween(1, 8, "Invalid Try Again");
        return Option;

    }
    static void _AllBooks()
    {
        clsListBooks::ShowBooksList();
    }
    static void _OnlyAvailable()
    {
        clsAvailableBooksScreen::ShowAvailableBooksList();
    }
    static void _SearchByName()
    {
        clsFindByBookNameScreen::ShowFindBookByNameScreen();
    }
    static void _SearchByAuthor()
    {
        clsFindByAuthorScreen::ShowFindBookByAuthorScreen();
    }
    static void _SearchByCategory()
    {
        clsFindByCategoryScreen::ShowFindBookByCategoryScreen();
    }
    static void _BorrowBooks()
    {
        clsBorrowBookScreen::ShowBorrowBookScreen();
    }
    static void _LogOut()
    {

    }
    static void _ReturnBook()
    {
        clsReturnBookScreen::ShowReturnBookScreen();
    }
    static void BackToMainMenu()
    {
        system("pause");
        ShowMainMembersChoicesMenu();
    }
    static void _PerformMemberMainMenuScreen(enMainMembersMenu Choice)
    {
        switch (Choice)
        {
        case clsMembersMainMenuScreen::eAllBooks:
            system("cls");
            _AllBooks();
            
            BackToMainMenu();
            break;
        case clsMembersMainMenuScreen::eOnlyAvailable:
            system("cls");
            _OnlyAvailable();
            
            BackToMainMenu();

            break;
        case clsMembersMainMenuScreen::eSearchByName:
            system("cls");
            _SearchByName();
            
            BackToMainMenu();

            break;
        case clsMembersMainMenuScreen::eSearchByAuthor:
            system("cls");
            _SearchByAuthor();
            BackToMainMenu();

            break;
        case clsMembersMainMenuScreen::eSearchByCat:
            system("cls");
            _SearchByCategory();
            BackToMainMenu();

            break;
        case clsMembersMainMenuScreen::eBorrowBooks:
            system("cls");
            _BorrowBooks(); //check the note in this class 
            BackToMainMenu();

            break;
        case clsMembersMainMenuScreen::eReturnBook:
            system("cls");
            _ReturnBook();
            BackToMainMenu();

            break;
        case clsMembersMainMenuScreen::eLogout:
            system("cls");
            _LogOut();
            

            break;
      
        }
    }
public :
    static void ShowMainMembersChoicesMenu()
    {

        system("cls");
        _DrawScreenHeader("\t\tLibrary Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tLibrary Main Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show all books.\n";
        cout << setw(37) << left << "" << "\t[2] Show only Available book List.\n";
        cout << setw(37) << left << "" << "\t[3] Search a book by Name.\n";
        cout << setw(37) << left << "" << "\t[4] Search a book by author.\n";
        cout << setw(37) << left << "" << "\t[5] Search a book by Category .\n";
        cout << setw(37) << left << "" << "\t[6] Borrow a book .\n";
        cout << setw(37) << left << "" << "\t[7] Return a Book.\n";
        cout << setw(37) << left << "" << "\t[8] Log out.\n";


        cout << setw(37) << left << "" << "===========================================\n";

        cout << setw(37) << left << "" << "Enter a choice from [1] to [8]\n";

        _PerformMemberMainMenuScreen((enMainMembersMenu)_ReadMainMenuChoice());
    }
};

