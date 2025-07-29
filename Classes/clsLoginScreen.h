#pragma once

#include <iostream>
#include "Classes/clsScreen.h"
#include "Classes/clsUser.h"
#include <iomanip>
#include "Classes/clsMainScreen.h"
#include "Classes/Global.h"
#include "Classes/clsDate.h"



class clsLoginScreen : protected clsScreen
{

private:

    static bool _Login()
    {
        bool LoginFaild = false;
        short Tries = 0;

        string Username, Password;

        do
        {
            if (LoginFaild)
            {
                Tries++;

                cout << "\nInvlaid Username/Password!";
                cout << "\nYou have " << (3 - Tries) << " trial(s) login.\n\n";
            }

            if (Tries == 3)
            {
                cout << "\n\nYou are locked after 3 failed trails.";
                return false;
            }

            cout << "Enter Username? ";
            cin >> Username;
            
            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);


        CurrentUser.RegisterLogin();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:

    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");

        return _Login();
    }

};

