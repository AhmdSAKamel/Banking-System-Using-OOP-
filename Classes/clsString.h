#pragma once

#include <iostream>
#include <vector>

using namespace std;

class clsString
{

private:
    string _Value;

public:

    clsString()
    {
        _Value = "";
    }

    clsString(string Value)
    {
        _Value = Value;
    }

    void SetValue(string Value) {
        _Value = Value;
    }

    string GetValue() {
        return _Value;
    }

    __declspec(property(get = GetValue, put = SetValue)) string Value;


    static size_t Length(string S1)
    {
        return S1.length();
    };

    size_t Length()
    {
        return _Value.length();
    };

    static int CountWords(string S1)
    {

        string delim = " "; // delimiter  
        int Counter = 0;
        size_t pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            if (sWord != "")
            {
                Counter++;
            }

            //erase() until positon and move to next word.
            S1.erase(0, pos + delim.length());
        }

        if (S1 != "")
        {
            Counter++; // it counts the last word of the string.
        }

        return Counter;

    }

    short CountWords()
    {
        return CountWords(_Value);
    };

    static string  UpperFirstLetterOfEachWord(string S1)
    {

        bool isFirstLetter = true;

        for (short i = 0; i < S1.length(); i++)
        {

            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = toupper(S1[i]);

            }

            isFirstLetter = (S1[i] == ' ' ? true : false);

        }

        return S1;
    }

    void  UpperFirstLetterOfEachWord()
    {
        // no need to return value , this function will directly update the object value  
        _Value = UpperFirstLetterOfEachWord(_Value);
    }

    static string  LowerFirstLetterOfEachWord(string S1)
    {

        bool isFirstLetter = true;

        for (short i = 0; i < S1.length(); i++)
        {

            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = tolower(S1[i]);

            }

            isFirstLetter = (S1[i] == ' ' ? true : false);

        }

        return S1;
    }

    void  LowerFirstLetterOfEachWord()
    {


        // no need to return value , this function will directly update the object value  
        _Value = LowerFirstLetterOfEachWord(_Value);
    }

    static string  UpperAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = toupper(S1[i]);
        }
        return S1;
    }

    void  UpperAllString()
    {
        _Value = UpperAllString(_Value);
    }

    static string  LowerAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = tolower(S1[i]);
        }
        return S1;
    }

    void  LowerAllString()
    {
        _Value = LowerAllString(_Value);
    }

    static char  InvertLetterCase(char char1)
    {
        return isupper(char1) ? tolower(char1) : toupper(char1);
    }

    static string  InvertAllLettersCase(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = InvertLetterCase(S1[i]);
        }
        return S1;
    }

    void  InvertAllLettersCase()
    {
        _Value = InvertAllLettersCase(_Value);
    }

    enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

    static size_t CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
    {


        if (WhatToCount == enWhatToCount::All)
        {
            return S1.length();
        }

        int Counter = 0;

        for (int i = 0; i < S1.length(); i++)
        {

            if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
                Counter++;


            if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
                Counter++;


        }

        return Counter;

    }

    static short  CountCapitalLetters(string S1)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (isupper(S1[i]))
                Counter++;

        }

        return Counter;
    }

    short  CountCapitalLetters()
    {
        return CountCapitalLetters(_Value);
    }

    static short  CountSmallLetters(string S1)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (islower(S1[i]))
                Counter++;

        }

        return Counter;
    }

    short  CountSmallLetters()
    {
        return CountSmallLetters(_Value);
    }

    static short  CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (MatchCase)
            {
                if (S1[i] == Letter)
                    Counter++;
            }
            else
            {
                if (tolower(S1[i]) == tolower(Letter))
                    Counter++;
            }

        }

        return Counter;
    }

    short  CountSpecificLetter(char Letter, bool MatchCase = true)
    {
        return CountSpecificLetter(_Value, Letter, MatchCase);
    }

    static bool IsVowel(char Ch1)
    {
        Ch1 = tolower(Ch1);

        return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

    }

    static short  CountVowels(string S1)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (IsVowel(S1[i]))
                Counter++;

        }

        return Counter;
    }

    short  CountVowels()
    {
        return CountVowels(_Value);
    }

    static vector<string> Split(string S1, string Delim)
    {

        vector<string> vString;

        size_t pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            // if (sWord != "")
            // {
            vString.push_back(sWord);
            //}

            S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
        }

        if (S1 != "")
        {
            vString.push_back(S1); // it adds last word of the string.
        }

        return vString;

    }

    vector<string> Split(string Delim)
    {
        return Split(_Value, Delim);
    }

    static string TrimLeft(string S1)
    {


        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(i, S1.length() - i);
            }
        }
        return "";
    }

    void TrimLeft()
    {
        _Value = TrimLeft(_Value);
    }

    static string TrimRight(string S1)
    {


        for (size_t i = S1.length() - 1; i >= 0; i--)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(0, i + 1);
            }
        }
        return "";
    }

    void TrimRight()
    {
        _Value = TrimRight(_Value);
    }

    static string Trim(string S1)
    {
        return (TrimLeft(TrimRight(S1)));

    }

    void Trim()
    {
        _Value = Trim(_Value);
    }

    static string JoinString(vector<string> vString, string Delim)
    {

        string S1 = "";

        for (string& s : vString)
        {
            S1 = S1 + s + Delim;
        }

        return S1.substr(0, S1.length() - Delim.length());


    }

    static string JoinString(string arrString[], short Length, string Delim)
    {

        string S1 = "";

        for (short i = 0; i < Length; i++)
        {
            S1 = S1 + arrString[i] + Delim;
        }

        return S1.substr(0, S1.length() - Delim.length());

    }

    static string ReverseWordsInString(string S1)
    {

        vector<string> vString;
        string S2 = "";

        vString = Split(S1, " ");

        // declare iterator
        vector<string>::iterator iter = vString.end();

        while (iter != vString.begin())
        {

            --iter;

            S2 += *iter + " ";

        }

        S2 = S2.substr(0, S2.length() - 1); //remove last space.

        return S2;
    }

    void ReverseWordsInString()
    {
        _Value = ReverseWordsInString(_Value);
    }

    static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
    {

        vector<string> vString = Split(S1, " ");

        for (string& s : vString)
        {

            if (MatchCase)
            {
                if (s == StringToReplace)
                {
                    s = sRepalceTo;
                }

            }
            else
            {
                if (LowerAllString(s) == LowerAllString(StringToReplace))
                {
                    s = sRepalceTo;
                }

            }

        }

        return JoinString(vString, " ");
    }

    string ReplaceWord(string StringToReplace, string sRepalceTo)
    {
        return ReplaceWord(_Value, StringToReplace, sRepalceTo);
    }

    static string RemovePunctuations(string S1)
    {

        string S2 = "";

        for (short i = 0; i < S1.length(); i++)
        {
            if (!ispunct(S1[i]))
            {
                S2 += S1[i];
            }
        }

        return S2;

    }

    void RemovePunctuations()
    {
        _Value = RemovePunctuations(_Value);
    }


};




































/*
#include "MyFirstLibrary.h" 	
#include <iostream>


class clsPerson		// Any futuristic assignment to a variable of this class, the variable will be called object.
{
private:		// It's private by default.
	// Internal use only.

	int _ID = 10;
	string _FirstName;
	string _LastName;


protected:   // Only accessable inside this class and all classes inhirets this class.


public: 	// Anything inside the class is private by default, so we need to use this for making it public.

	// Any function or procedure inside the class, we call it method.


	int ID()	//	When we don't make "Set" properity, we make it read only properity.
	{
		return _ID;	//	Accessable but not adjustable.
	}


	//Property Set
	void setFirstName(string FirstName)
	{
		_FirstName = FirstName;		// Here we adjusted the private variable by a function outside the class.
	}
	// When we make "Set" and "Get" to variables inside the class, we call it properties.

//Property Get
	string FirstName()
	{
		return _FirstName;
	}

	void setLastName(string FirstName)
	{
		_FirstName = FirstName;
	}

	string GetFirstName()
	{
		return _LastName;
	}

	// This is the name we call outside.
	__declspec(property(get = GetFirstName, put = setFirstName)) string _FirstName; 	// This line of code calls for a class in C++ to add property "get" and "put" (set), with the same type of.
};


class clsCalculator
{
	// Private Members.

	float _Result = 0;
	float _LastNumber = 0;
	string _LastOperation = "Clear";
	float _PreviousResult = 0;

	bool IsZero(float Number)
	{
		return (Number == 0);
	}

public:

	void Add(float Number)
	{
		_LastNumber = Number;
		_PreviousResult = _Result;
		_LastOperation = "Adding";
		_Result += Number;
	}

	void Subtract(float Number)
	{
		_LastNumber = Number;
		_PreviousResult = _Result;
		_LastOperation = "Subtracting";
		_Result -= Number;
	}

	void Divide(float Number)
	{
		_LastNumber = Number;

		if (IsZero(_Result))
		{
			Number = 1;
		}

		_PreviousResult = _Result;
		_LastOperation = "Dividing";
		_Result /= Number;
	}

	void Multiply(float Number)
	{
		_LastNumber = Number;
		_PreviousResult = _Result;
		_LastOperation = "Multiplying";
		_Result *= Number;
	}

	float GetFinalResults()
	{
		return _Result;
	}

	void Clear()
	{
		_LastNumber = 0;
		_PreviousResult = 0;
		_LastOperation = "Clear";
		_Result = 0;
	}

	void CancelLastOperation()
	{
		_LastNumber = 0;
		_LastOperation = "Cancelling Last Operation";
		_Result = _PreviousResult;
	}

	void PrintResult()
	{
		cout << "Result After " << _LastOperation << " " << _LastNumber << " is: " << _Result;

		cout << endl;
	}

};


class clsAddress
{


public:
	//This will be called when object is built.
	clsAddress(string Name)	// When there is a typless function with the smae name as it's the class inside, this is called constructor.
	{
		// This constructor will be called in anyway, and if devoloper did not write, compilter will write it instead of.
		// If you write any code, it'll execute it even if you didn't use it.

		cout << "Hi I'm the constractor.";
	}


	// Copy Constructor
	clsAddress(clsAddress& OO)	// Same name but different uses, "Function Overloading."
	{
		cout << "Hi I'm the Copy Constractor.";
	}


	~clsAddress()	// Will be called when object is destroyed, Syntax of is (Delta + Class's name).
	{
		cout << "\nHi, I'm The Destructor";
	}
};


void Fun2()
{
	clsAddress* Address = new clsAddress("Test");


	delete new clsAddress("Test");


	// Here we made dynamic allocation at memory during run time, we have called a contructor, but once the method did its job, compiler will destruct all members and methods but pointer and object will be remained in memory.
	// When we use pointer and object at memory, we should delete it autumatically in C++, Once we delete, the destructor will be called.
}

class clsA
{
public:
	int var;	// Per each object assigned to this class, we will have one variable (var), but have only one "counter" (because it's static).
	static int counter;		// We can consider static as a global/shared variable over the object, we can say that "counter" is a variable independent to the class itself, not the object.
	// Any assigned object can ajust its value.


	clsA()	// When it calls the constructor, we add one to "counter".
	{
		counter++;
	}

	void print()
	{
		cout << "\nvar		= " << var << endl;
		cout << "counter	= " << counter << endl;
	}

	static int Function1()			// We can call any static method without having an object of the class. It also can be called of any object.
	{
		return 20;
	}

	int Function2()
	{
		return 20;
	}
};

int clsA::counter = 0; // We must redefine the static member before any call of this class in the program. 


class clsPersonn
{
	int _ID;
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:


	clsPersonn()	// To be able ot make empty object of.
	{

	}

	clsPersonn(int ID, string FirstName, string LastName, string Email, string Phone)  // This is named "Parameterized Constructor".
	{
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	int ID()
	{
		return _ID;
	}

	void Print()
	{
		cout << "\nInfo:\n" << "------------------------------------\n";
		cout << "ID       : " << _ID << endl;
		cout << "FirstName: " << _FirstName << endl;
		cout << "LastName : " << _LastName << endl;
		cout << "Full Name: " << _FirstName + " " + _LastName << endl;
		cout << "Email    : " << _Email << endl;
		cout << "Phone    : " << _Phone << endl;
		cout << "\n------------------------------------\n";
	}

	void SendEmail(string Subject, string Budy)
	{
		cout << "The following message sent successfully to email: " << _Email << endl;

		cout << "Subject: " << Subject << endl;
		cout << "Budy: " << Budy;
	}

	void SendSMS(string SMS)
	{
		cout << "The following SMS sent successfully to Phone: " << _Phone << endl;

		cout << SMS;
	}

};


class clsEmployee : public clsPersonn  // In Public Access Modifier.
{
	// We can inherit the public members and protected members only.

	string _Title;
	string _Department;
	float _Salary;

protected:

	int _var2Test;

public:

	clsEmployee(int ID, string FirstName, string LastName, string Email, string Phone, string Title, string Department, float Salary)
		: clsPersonn(ID, FirstName, LastName, Email, Phone)	// Using the Column, I'm telling it to take these parameters to the base class. (Base Class accepted it because we made a contructor taking these parameters there.
	{
		_Title = Title;
		_Department = Department;
		_Salary = Salary;
	}


	void setTitle(string Title)
	{
		_Title = Title;
	}

	string Title()
	{
		return _Title;
	}

	void Print()		//As long as it's the same name as the Method in the base class, it took the same signiture, so it'd overrid the old "print" Procedure.
	{
		// We can do any function inside the deraived class.
		Print(); // So here we reached the print in the base class.

		cout << Title;
	}
};


class clsDeveloper : public clsEmployee
{
	string _MainProgrammingLanguage;

public:

	clsDeveloper(int ID, string FirstName, string LastName, string Email, string Phone, string Title, string Department, float Salary, string MainProgrammingLanguage)
		: clsEmployee(ID, FirstName, LastName, Email, Phone, Title, Department, Salary)

	{
		_MainProgrammingLanguage = MainProgrammingLanguage;
	}

	void Print()	// Overriding.
	{
		clsEmployee::Print();

		cout << "Main Programming Language: " << _MainProgrammingLanguage;
	}

	int ProtectedTest()
	{
		return clsEmployee::_var2Test;		// Protected Variable in Base Class, Derived classes can reach and outsiders can't.
		return _var2Test;		// Both Ways work;
	}
};


class Perso		//Smaller
{

public:
	string FullName = "Ahmed Sayed";

};

class clsEmploy : public Perso	//Bigger
{

public:
	string Title = "CEO Poors";
};


void TestT()
{
	clsEmploy Bigger;
	Perso Smaller;

	// Upcasting.			We can make a pointer from base class pointing at derived class, but the opposite is not possible.
	Perso* Pers1 = &Bigger;		// Bigger to Smaller

	Perso P2;

	// Downcasting.
//	clsEmploy* Employee = &P2;
}


void VirtualFunctionTest()
{
	clsEmploy Employ1;

	Perso* Person1 = &Employ1;
}


class clsMobile
{
	// As soon as the class has one pure virtual function, it turned into Abstract Class. (or Contract Class)
	// We can't make an object from any Abstract Class.

	virtual void Dial(string PhoneNumber) = 0;		// This syntax made it pure virtual function, This is the interface of.

	virtual void SendSMS(string Text) = 0;			// The face /header exists, but the implementation is not.
	virtual void TakePicture() = 0;

	friend class clsIphone;		// Here we allowed class "clsIphone" to access everything inside class "clsMobile", even members under Private Modifiers.
};


class clsIphone : public clsMobile		// We here made a contract to make an implementation for all the interface headers existed in the base class.
{

	int _Momo;

public:
	// The implementation:
	void Dial(string PhoneNumber)
	{

	}

	void SendSMS(string Text)
	{


	}

	void TakePicture()
	{


	}

	friend int Sum(clsIphone Iphone);	// That defined function "Sum" as a friend function, so it could access even private members within the funciton.

};


int Sum(clsIphone Iphone)
{
	return Iphone._Momo;
}


class clsThisTest
{

public:
	int ID;
	string Name;
	float Salary;

	clsThisTest(int ID, string Name, float Salary)
	{
		this->ID = ID;
		this->Name = Name;
		this->Salary = Salary;		// So compiler does not confuse between parameters and members.
	}


	static void Func1(clsThisTest Test)
	{
		Test.Print();
	}

	void Func2()
	{
		Func1(*this);	// Here we called "Func1" and send the current object to it, so compiler will send the entire class as a parameter with its data to "Func1" then execute the code inside.
	}

	void Print()
	{
		cout << ID << " Done Successfully";
	}

};


void ObjectsWithDynamicArrays()
{
	class ClsA
	{

	public:

		ClsA(int val)
		{
			x = val;
		}

		ClsA()
		{

		}

		int x;

		void Print()
		{
			cout << "The value of x = " << x << endl;
		}


	};

	short NumberOfObjects = 5;

	// Allocating dynamic array.
	// Of Size "NumberOfObjects" using new keyword.

	ClsA* arrtest = new ClsA[NumberOfObjects];

	// Calling Constructor
	// For each index of array

	for (int i = 0; i < NumberOfObjects; i++)
	{
		arrtest[i].Print();
	}
}


void ObjectsWithArray()
{
	class clsWithArray
	{
	public:
		clsWithArray(int value)
		{
			x = value;
		}
		int x;

		void print()
		{
			cout << "The value of x = " << x << endl;
		}
	};


	clsWithArray obj[] = { clsWithArray{10}, clsWithArray{20} };

	// using for loop to print each of two elements.

	for (int i = 0; i < 3; i++)
	{
		obj[i].print();
	}
}


int main()
{
	cout << 99;

	return 0;
}*/


