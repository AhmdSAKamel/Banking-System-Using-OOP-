#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsValidInput.h"



class clsDeleteUserScreen : protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

public:

    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("\tDelete User Screen");

        string UserName = "";

        UserName = clsInputValidate::ReadString("\nPlease Enter UserName: ");

        while (!clsUser::IsUserExist(UserName))
        {
            UserName = clsInputValidate::ReadString("\nUser is not found, choose another one: ");
        }

        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);

        cout << "\nAre you sure you want ot delete this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (tolower(Answer) == 'y')
        {

            if (User1.Delete())
            {
                cout << "\nUser Deleted Successfully :-)\n";
                _PrintUser(User1);
            }
            else
            {
                cout << "\nError, User was not deleted.";
            }
        }
    }
};

