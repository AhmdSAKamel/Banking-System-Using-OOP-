
#include "Classes/MyFirstLibrary.h"
#include "Classes/clsMainScreen.h"
#include "Classes/clsLoginScreen.h"
#include "Classes/clsCurrency.h"





void main()
{

	while (true)	//After choosing logout, It will come back here again.
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
	}

	system("pause>0");
}