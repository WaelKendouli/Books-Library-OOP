
//class clsListMembersScreen
#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsLibraryMember.h"
#include <iomanip>
using namespace std;
class clsListMembersScreen :protected clsScreen
{

private:
    static void PrintMemberRecordLine(clsLibraryMember Member)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << Member.Username;
        
        cout << "| " << setw(12) << left << Member.ID;
        cout << "| " << setw(20) << left << Member.BorrowedBooks;
        cout << "| " << setw(20) << left << Member.MembershipEndDate;
        cout << "| " << setw(10) << left << Member.Password;


    }

public:


    static void ShowMembersList()
    {
      
        vector <clsLibraryMember> vMembers = clsLibraryMember::GetUsersLibrary();
        string Title = "\t  Client List Screen";
        string SubTitle = "\t    (" + to_string(vMembers.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << " Member Name";
    
        cout << "| " << left << setw(12) << "ID";
        cout << "| " << left << setw(20) << "Borrowed Books";
        cout << "| " << left << setw(20) << "Membership end date";
        cout << "| " << left << setw(10) << "Password";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vMembers.size() == 0)
            cout << "\t\t\t\tNo Members Available In the System!";
        else

            for (clsLibraryMember Member : vMembers)
            {

                PrintMemberRecordLine(Member);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

