#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsValidInput.h"
#include <iomanip>
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"



using namespace std;

class clsManageUsersScreen : protected clsScreen
{

private:

    enum enManageUsersMenueOptions 
    {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };

    static short ReadManageUsersMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _GoBackToManageUsersMenue()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
        system("pause>0");
        ShowManageUsersMenue();
    }

    static void _ShowListUsersScreen()
    {
        clsUsersListScreen::ShowUsersList();
    }

    static void _ShowAddNewUserScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }

    static void _ShowDeleteUserScreen()
    {
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }

    static void _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }

    
    static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
    {
        system("cls");

        switch (ManageUsersMenueOption)
        {
        case enManageUsersMenueOptions::eListUsers:
        {
            _ShowListUsersScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eAddNewUser:
        {
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eDeleteUser:
        {
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eUpdateUser:
        {
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eFindUser:
        {
            _ShowFindUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eMainMenue:
        {
            // do nothing here the main screen will handle it :-) ;
        }
        }
    }



public:


    static void ShowManageUsersMenue()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("\t Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersMenueOption((enManageUsersMenueOptions)ReadManageUsersMenueOption());
    }

};

