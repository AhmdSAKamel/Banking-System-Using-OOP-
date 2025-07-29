#pragma once
#include <iostream>
#include <string>

using namespace std;

class InterfaceCommunication		// Abstract Class (Interface)
{


public:

	virtual void SendEmail(string Title, string Body) = 0;
	virtual void SendFAx(string Title, string Body) = 0;
	virtual void SendSMS(string Title, string Body) = 0;


};

