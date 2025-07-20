#pragma once
#include <iostream>

#include "clsDate.h"

using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n";
       
        cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate())
            << "\n\n";
        

    }
    static void _DrawMembershipExpiredMessage()
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << "Membership expired Please contact the Liberiran";
        cout << "\n\t\t\t\t\t______________________________________\n";
    }


};


