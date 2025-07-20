#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBook.h"
#include <iomanip>
using namespace std;
class clsListBooks : protected clsScreen
{
private:
    static void PrintBookRecordLine(clsBook Book)
    {

        cout << setw(8) << left << "" << "| " << setw(45) << left << Book.Name;

        cout << "| " << setw(35) << left << Book.Author;
        cout << "| " << setw(10) << left << Book.SerialNumber;
        cout << "| " << setw(35) << left << Book.Category;
        cout << "| " << setw(15) << left << Book.Status;



    }

public:


    static void ShowBooksList()
    {

        vector <clsBook> vBooks = clsBook::GetBooksLibrary();
        string Title = "\t  Books List Screen";
        string SubTitle = "\t    (" + to_string(vBooks.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_____________________________________________________________________________________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(45) << " Book Name";

        cout << "| " << left << setw(35) << "Author";
        cout << "| " << left << setw(10) << "Serial Number";
        cout << "| " << left << setw(35) << "Category";
        cout << "| " << left << setw(15) << "Status";


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "__________________________________________________________________________________________________________________________\n" << endl;

        if (vBooks.size() == 0)
            cout << "\t\t\t\tNo Members Available In the System!";
        else

            for (clsBook Book : vBooks)
            {

                PrintBookRecordLine(Book);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "________________________________________________________________________________________________\n" << endl;

    }
};

