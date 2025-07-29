#pragma once

#include <iostream>
#include "Classes/clsScreen.h"
#include "Classes/clsValidInput.h"
#include "Classes/clsClientListScreen.h"
#include <iomanip>
#include "Classes/clsAddNewClientScreen.h"
#include "Classes/clsDeleteClientScreen.h"
#include "Classes/clsUpdateClientScreen.h"
#include "Classes/ShowFindClientScreen.h"
#include "Classes/clsTransactionsScreen.h"
#include "Classes/clsManageUsers.h"
#include "Classes/Global.h"
#include "Classes/clsLoginRegisterScreen.h"
#include "Classes/clsCurrencyExchangeMainScreen.h"


using namespace std;

class clsMainScreen : protected clsScreen       //Every screen in the project should have a seperate class and inherit "clsScreen".
{

private:

    enum enMainMenueOptions
    {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister = 8,eCurrencies = 9,eExit
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 10, "Enter Number between 1 to 10? ");
        
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {   
        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();

    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _ShowManageUsersMenue()
    {
        clsManageUsersScreen::ShowManageUsersMenue();
    }

    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _ShowCurrenciesScreen()
    {
        clsCurrencyExchangeMainScreen::ShowCurrenciesMenue();
    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");


       // clsLoginScreen::ShowLoginScreen();        // Causing error because clsLoginScreen class called this class "clsMainScreen.h", when it did, it made something called "Circular Reference".
       // You can't include two classes calling each others.
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        system("cls");

        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:

            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:

            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:

            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:

            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:

            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eLoginRegister:

            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eCurrencies:

            _ShowCurrenciesScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eExit:

            _Logout();
            break;
        }
    }


public:

    static void ShowMainMenue()
    {

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";


        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }

};

