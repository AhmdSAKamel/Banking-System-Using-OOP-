
#pragma warning(disable: 4996) // When C++ douts in any code, it'll pop up a warning message, this line makes compiler disable the warning with the number 4996.
#pragma once


#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <cctype>
#include <fstream>
#include <ctime>
#include "Classes/clsString.h"      // Internal Libraries' syntax.




using namespace std;


namespace Course6Test
{
	int ReadNumberTest(string Message)
	{
		int Number = 0;
		
		cout << Message;
		cin >> Number;

		while (cin.fail())
		{

			cin.clear();	//Delete the error
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //Ignore rest of the line
			cout << "Invalid Number, Enter a valid one: " << endl;

			cin >> Number;
		}
		return Number;
	}

	string PositiveNegetiveTest(short Number)
	{
		string Status = "";

		Status = (Number == 0) ? "Zero" : ((Number > 0) ? "Positive" : "Negative");		//Nested Ternary Operator.

		return Status;
	}

	struct stName
	{
		string FirstName = "";
		string LastName = "";
		short Salary = 0;
	};

	struct stEmployee
	{
		string FirstName = "";
		string LastName = "";
		short Salary = 0;
	};

	//function decleration
	short Add(short, short);

	int MySum(int a, int b, int c = 0, int d = 0)
	{				//Optional Parameters/ Default Parameters

		return a + b + c + d;

	}

	void PrintNumbers(int N, int M)
	{
		if (N <= M)		//Recursive call 
		{
			cout << N << endl;
			PrintNumbers(N + 1, M); //Calling itslf.
		}

	}

	void RecursiveFromMToN(short M, short N = 0)
	{
		if (M >= 1)
		{
			cout << M << endl;
			RecursiveFromMToN(M - 1);
		}
	}

	short RecursivePowFunction(short N, short P)
	{

		if (P == 0)
			return 1; //Will not be executed untill the call stack is empty.
		else
		{
			short M = (N * RecursivePowFunction(N, P - 1));		//Will come back here for emptying the call stack.
			return M;
		}
	}

	void FillDimensionalArrayInMultTableTest(int arr10[10][10])
	{

		for (short i = 0; i < 10; i++)
		{
			for (short j = 0; j < 10; j++)
			{
				arr10[i][j] = (i + 1) * (j + 1);
			}
		}
	}

	void PrintDimensionalArray(int arr[10][10])
	{
		FillDimensionalArrayInMultTableTest(arr);

		for (short i = 0; i < 10; i++)
		{
			for (short j = 0; j < 10; j++)
			{
				printf("%0*d ", 2, arr[i][j]);
			}
			cout << endl;
		}
	}

	void FillVecotrsTest(vector <short>& vtor)
	{

		for (short& Number : vtor) //When we add the reference sign, it does not copy the item, it goes directly to its location at the memory.
		{
			cout << Number << " ";
		}
		cout << endl;
	}

	void VectorsTest()
	{
		vector <string> vNumbers = { "[]" , "{}" };

		vNumbers.push_back("8"); //Adding elements
		vNumbers.push_back("oop");
		vNumbers.push_back("oop");

		for (string& S : vNumbers)
		{
			cout << S << endl;
		}
	}

	void PushBackNumbersToVector(vector <short>& vNumbers)
	{
		short Number = 0;

		char Again = 'y';

		do
		{
			cout << "Please enter a number? ";
			cin >> Number;
			vNumbers.push_back(Number);

			cout << "\nDo you want to read more numbers? Y/N ? ";
			cin >> Again;


		} while (Again == 'y' || Again == 'Y');

	}

	void PrintVectorNumbers(vector <short>& vNumbers) //By refrence is prefered over making a copy then printing it.
	{
		for (short& Num : vNumbers)
		{
			cout << Num << "\n";
		}
		cout << endl;
	}

	void ReadEmployees(vector <stEmployee>& Employees)
	{
		char Again = 'y';

		stEmployee Employee;

		do
		{
			cout << "Enter First Name? ";
			cin >> Employee.FirstName;

			cout << "Enter Last Name? ";
			cin >> Employee.LastName;

			cout << "Enter Salary? ";
			cin >> Employee.Salary;

			Employees.push_back(Employee);

			cout << "\nDo you want to add more employees? Y/N ? ";
			cin >> Again;

		} while (Again == 'y' || Again == 'Y');
	}

	void PrinVectortEmployees(vector <stEmployee>& Employees)
	{

		cout << "\nEmployees vector:\n\n";

		for (stEmployee& Employee : Employees)
		{
			cout << Employee.FirstName << endl;
			cout << Employee.LastName << endl;
			cout << Employee.Salary << endl;

			cout << endl;
		}
	}

	void TestCreateReference()
	{

		int a = 10;
		int& x = a;

		cout << &a << endl;
		cout << x << endl;

		x = 19;		// Changing one will change the other. Because both have the same location at memory.

		cout << a << endl;
		cout << x << endl;
	}

	void TestPointer()
	{
		int a = 10;

		int* P = &a; // Here we defined a variable from pointer of integer kind, stored in P.

		cout << *P + 10;   //  Changing the value by pointer.

	}

	void SwapByPointersTest(int* n1, int* n2) // Sometimes within the function we need to make a variable points at another one at memory.
	{
		int Temp = 0;
		Temp = *n1;
		*n1 = *n2;
		*n2 = Temp;
	}

	void ArrayWithPointersTest(short arr[4])
	{
		arr[0] = 1;
		arr[1] = 2;
		arr[2] = 3;
		arr[3] = 4;


		short* prr;

		prr = arr; //Equivalent to the address of arr[0].

		cout << *(prr);		// Value of arr[0];

		cout << *(prr + 1);	// Value of arr[1];
	}

	void StructuresWithPointersTest()
	{
		stName Name, * pst; //Assigning a Pointer from the structure type.

		Name.FirstName = "Ahmed";
		Name.LastName = "Kamel";
		Name.Salary = 5000;

		cout << &Name.FirstName;

		pst = &Name;

		cout << pst->Salary; //Accessing the value of structure through a pointer.
	}

	void voidPointerTest()
	{
		//This makes us able to make a data pointer pointing at different data types in the run time.

		void* ppr;	//Generic Pointer, a typeless pointer that can point at any type of data at the memory.

		float f1 = 10.5;
		int x = 50;

		ppr = &f1;

		cout << ppr;	//Note: Void Pointers can't print the value of the variable, because it's Generic that does not know its type.

		cout << *(static_cast<float*>(ppr)); //By this, compiler will cast this generic pointer to a float pointer (Exciplicit Casting), so it could print its value.

		ppr = &x;	//This transfered the pointer from pointing at the float f1 to integer x.

		cout << *(static_cast<int*>(ppr));
	}

	void DynamicMemoryAllocationTest()
	{
		int* prrx; // Pointers do not preserve a space in memory.

		// Dynamically allocate memory in the run time.

		prrx = new int;	// A variable from integer type, then pointed at prrx.

		*prrx = 10;

		delete prrx; //Deallocate from the memory, for every "new" function, use "delete" in return.
	}

	void PointerNewArrayTest()
	{
		short NumberOfStudents = 4;

		float* prt;

		prt = new float[NumberOfStudents];

		delete[] prt;	// Deleting the array
	}

	void VectorsAccessElements()
	{
		vector <int> num{ 1,2,3,4,5 };

		cout << num.at(4);

		cout << num[4];
	}

	void VectorsIteratorTest()
	{
		vector <int>num{ 1, 2, 3, 4, 5 };


		//Declare iterator.
		vector <int>::iterator iter;	// Iterator must be the same type of vector.


		//Iterator with for loop.

						// First		/Last element in vector
		for (iter = num.begin(); iter != num.end(); iter++)
		{
			cout << *iter << "  ";  //Iter is pointing at element by element's pointer.
		}

	}

	void ExceptionHandlingTest()
	{
		vector<int>num{ 1,2,3,4,5 };

		try
		{
			cout << num.at(5);		// Any exception happens will not cause to crash the programme.
		}
		catch (...)
		{
			cout << "Out of bound\n";	// Any thing could cause an error put it in here.
		}


	}

	void StringObjectTest() // String Library should be used.
	{
		string s1 = "My Name is Ahmed, I like programming. ";

		cout << s1.length();		// Length

		cout << s1.at(3);			// Return the letter at position 3.

		s1.append("@It'sme.com");	//Add @It'sme.com to the end of string.

		s1.insert(7, " Test ");		// insert "test" at position 7.

		cout << s1.substr(16, 8);	// Print all the next 8 letters from position 16.

		s1.push_back('k');			// Add one character to the end of the string.

		s1.pop_back();				// Remove one character from the end of the string

		cout << s1.find("Test");	// Find "Test" at the string.

		cout << s1.find("test");	// Find "test" at the string.

		if (s1.find("test") == s1.npos) // No Position
		{
			cout << "\"test\" is not found";
		}

		s1.clear();					// Clear all string letters.
	}

	void cctypeFunctionsTest()
	{
		char x, w;

		x = toupper('a');	// From small to capital.

		w = tolower('A');	// From capital to small.

		cout << x << endl;
		cout << w << endl;

	    isupper('A');	// If it's uppercase, it'll return a positive number.

		islower('a');   // if it's not lowercase, it'll return a negative number.

		isdigit('9');   // Check if this chatacter is a digit or not, if not it'll return 0.

		ispunct(';');	// Check if this is a punctuation, if not it'll return 0.
	}

	void WriteDataToFileTest()
	{
		fstream MyFile;			//Assign a variable from file stream.

		// Open the file by write mode. When using this mode. whatever exists in the file. C++ will erase it, then rewrite on.
		MyFile.open("AFile.txt", ios::out);		// Set the name of the file that would store on the SSD by the end of execution.

		if (MyFile.is_open())		// It means that code above works without errors.
		{
			MyFile << "Ali\n";	// For adding to MyFile instead of screen.
			MyFile << "Maher\n";
			MyFile << "Fadi\n";
			MyFile << "Shadi\n";
			MyFile << "Ali\n";
			MyFile << "Mohammed\n";

			MyFile.close();	// To avoid errors
		}
		// To open the file. Go to View dropdown, press Solution explorer, then right mouse click on the project, then open folder in file explorer.
	}

	void AppendModeTest()
	{
		fstream MyFile;

		// MyFile2.open("MyFileInAppenMode.txt", ios::app); : append mode.

		MyFile.open("MyFileInAppenMode.txt", ios::out | ios::app); // Check the file, if it's not existed, open it for Write or append mode, and give priority to append.

		// Every time we make run, the programme will append the Data.

		if (MyFile.is_open())
		{
			MyFile << "Append Test\n";
		}
	}

	void PrintFilesReadModeTest(string FileName)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::in);		// Read Mode: this make us able to read from the file. (can't adjust into it)

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))	// Read first line from "MyFile", and add it to this variable (Line). 
			{
				if (Line == "")
				{
					Line = '\n';
				}
				cout << Line << endl;	// Print the read line.
			}
			MyFile.close();
		}
	}

	void LoadDataFromFiletoVectorTest(string FileName, vector <string>& FileContent)
	{
		fstream MyFile;

		MyFile.open(FileName, ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				FileContent.push_back(Line);
			}
			MyFile.close();
		}
	}

	void SaveVectorToFileTest(string FileName, vector <string>& FilledContent)
	{
		fstream VectorFile;

		VectorFile.open(FileName, ios::out);

		if (VectorFile.is_open())
		{
			for (string& C : FilledContent)
			{
				if (C != "")
				{
					VectorFile << C << endl;
				}
			}
			VectorFile.close();
		}
	}

	void DeleteRecordFromFile(string FileName, string Record)
	{
		vector <string> vFileContent;

		LoadDataFromFiletoVectorTest("AFile", vFileContent);

		for (string& Line : vFileContent)
		{
			if (Line == Record)
			{
				Line = "";
			}
		}
		SaveVectorToFileTest(FileName, vFileContent);
	}

	void UpdateRecordInFileTest(string FileName, string Record, string UpdateTo)
	{
		vector <string> vFileContent;
		LoadDataFromFiletoVectorTest(FileName, vFileContent);

		for (string& Line : vFileContent)
		{
			if (Line == Record)
			{
				Line = UpdateTo;
			}
		}
		SaveVectorToFileTest(FileName, vFileContent);

	}

	void DeleterecordFromFileTest()
	{
		WriteDataToFileTest();

		cout << "File Content Before Delete.\n";

		PrintFilesReadModeTest("AFile.txt");

		DeleteRecordFromFile("AFile.txt", "Ali");

		cout << "\n\nFile Content After Delete.\n\n";

		PrintFilesReadModeTest("AFile.txt");
	}

	void LocalGrinitchTimeTest()
	{
		// The library <ctime> is inherited from C language.

		time_t t = time(0);	  //Get time now.

		char* dt = ctime(&t);	// Convert in string form.

		cout << "Local date and time is: " << dt << '\n';

		tm* gmtm = gmtime(&t);		// Converting now to tm struct for UTC date/time. (Grinitch time/Universla time)

		dt = asctime(gmtm);			// Convert in string form.

		cout << "UTC date and time is: " << dt;
	}

	void  DatetiemStructureTest()
	{
		time_t t = time(0);	  //Get time now.

		tm* now = localtime(&t);  //tm is a structure from ctime library.

		cout << "Year: " << now->tm_year + 1900 << endl;	// tm_year is an element of the structure, it gives you how many years after 1900.
		cout << "Month: " << now->tm_mon + 1 << endl;
		cout << "Day: " << now->tm_mday << endl;
		cout << "Hour: " << now->tm_hour << endl;
		cout << "Min: " << now->tm_min << endl;
		cout << "Second: " << now->tm_sec << endl;
		cout << "Week Day (Days since sunday): " << now->tm_wday << endl;
		cout << "Year Day (Days since Jan 1st): " << now->tm_yday << endl;
		cout << "hours of daylight savings time: " << now->tm_isdst << endl;
	}

	int main()
	{
		srand((unsigned)time(NULL));

		return 0;
	}

	// function definition
	short Add(short a, short b)
	{
		return a + b;
	}
}


namespace Course7Test
{
	const string ClientsFileName = "Clients.txt";

	enum enWhatToCount { SmallLetter = 0, CapitalLetter = 1, All = 3 };

	struct stClient
	{
		string AccNumber;
		string PiCode;
		string CName;
		string CNumber;
		double AccBal = 0;
		bool MarkForDelete = false;
	};

	bool isVowl(char C);

	int RandomNumber(short From, short To)
	{
		int RandomNumber = rand() % (To - From + 1) + From;

		return RandomNumber;
	}

	void GenerateRanodmNumbersForMatrix(short arr[3][3])
	{
		for (short i = 0; i < 3; i++)
		{
			for (short C = 0; C < 3; C++)
			{
				arr[C][i] = RandomNumber(1, 10);
			}
		}
	}

	void PrintMatrix(short array[3][3])
	{
		for (short i = 0; i < 3; i++)
		{
			for (short C = 0; C < 3; C++)
			{
				printf(" %0*d ", 2, array[i][C]);
			}
			cout << endl;
		}
	}

	int RowSumTest(short arr[3][3], short RowNumber, short Cols)
	{
		short Sum = 0;

		for (short j = 0; j < Cols; j++)
		{
			Sum += arr[RowNumber][j];
		}
		return Sum;
	}

	void PrintEachRowSumTest(short arr[3][3], short Rows, short Cols)
	{
		cout << "\nThe following are the sum of each row in the matrix:\n";

		for (short i = 0; i < Rows; i++)
		{
			cout << " Row " << i + 1 << " Sum = " << RowSumTest(arr, i, Cols) << endl;
		}
	}

	void SumMatrixRowsInArray(short arr[3][3], short arrSum[3], short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			arrSum[i] = RowSumTest(arr, i, Cols);
		}
	}

	void PrintTargetSumArray(short arr[3], short Length, string target)
	{
		cout << "\nThe following are the sum of each " << target << " in the matrix : \n";

		for (short i = 0; i < Length; i++)
		{
			cout << target << i + 1 << " Sum = " << arr[i];

			cout << endl;
		}
	}

	short ColSumTest(short arr[3][3], short RowsNumber, short ColsNumber)
	{
		short ColsSum = 0;

		for (short j = 0; j < RowsNumber; j++)
		{
			ColsSum += arr[j][ColsNumber];
		}
		return ColsSum;
	}

	void PrintEachColSum(short arr[3][3], short Rows, short Cols)
	{
		cout << "\nThe following are the sum of each columns in the matrix:\n";

		for (short i = 0; i < Cols; i++)
		{
			cout << " Col " << i + 1 << " Sum = " << ColSumTest(arr, Rows, i) << endl;
		}
	}

	void SumMatrixColsInArray(short arr[3][3], short arrSum[3], short Rows, short Cols)
	{
		for (short i = 0; i < Cols; i++)
		{
			arrSum[i] = ColSumTest(arr, Rows, i);
		}
	}

	void FillArrayWithOrderedNumbs(short arr[3][3], short Rows, short Cols)
	{
		short Counter = 1;

		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				arr[i][j] = Counter;
				Counter++;
			}
		}
	}

	void PrintTransposedMatrix(short arr[3][3], short Rows, short Cols)
	{
		cout << "\n\nThe following is the transposed matrix:\n";

		for (short i = 0; i < Cols; i++)
		{
			for (short j = 0; j < Rows; j++)
			{
				cout << setw(3) << arr[j][i] << " ";
			}
			cout << endl;
		}
	}

	void MultiplyMatrix(short arr[3][3], short arrSecond[3][3], short arrSum[3][3], short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				arrSum[i][j] = arr[i][j] * arrSecond[i][j];
			}

		}
	}

	void PrintMiddleRowofMatrix(short arr[3][3], short Rows, short Cols)
	{
		short MiddleRow = round(Rows / 2);

		for (short i = 0; i < Cols; i++)
		{
			printf(" %0*d ", 2, arr[MiddleRow][i]);
		}
	}

	void PrintMiddleColsofMatrix(short arr[3][3], short Rows, short Cols)
	{
		short MiddleCols = round(Cols / 2);

		for (short i = 0; i < Rows; i++)
		{
			printf(" %0*d ", 2, arr[i][MiddleCols]);
		}
	}

	short SumOfMatrix(short arr[3][3], short Rows, short Cols)
	{
		short Sum = 0;

		for (short i = 0; i < Rows; i++)
		{
			for (short C = 0; C < Cols; C++)
			{
				Sum += arr[i][C];
			}
		}
		return Sum;
	}

	bool CheckTypicalMatrices(short arr[3][3], short arrSecond[3][3], short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short C = 0; C < Cols; C++)
			{
				if (arr[i][C] != arrSecond[i][C])
				{
					return false;
				}
			}
		}
		return true;
	}

	bool IsIdentityMatrix(short arr[3][3], short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (i == j && arr[i][j] != 1)
				{
					return false;
				}
				else if (i != j && arr[i][j] != 0)
				{
					return false;
				}
			}
		}
		return true;
	}

	bool IsScalarMatrix(short arr[3][3], short Rows, short Cols)
	{
		short Scalar = arr[0][0];

		for (short i = 0; i < Rows; i++)
		{
			for (short C = 0; C < Cols; C++)
			{
				if (i == C && arr[i][C] != Scalar)
				{
					return false;
				}
				else if (i != C && arr[i][C] != 0)
				{
					return false;
				}
			}
		}
		return true;
	}

	short HowManyInMatrix(short arr[3][3], short Rows, short Cols, short NumberToCheck)
	{
		short HowMany = 0;
		for (short i = 0; i < Cols; i++)
		{
			for (short j = 0; j < Rows; j++)
			{
				if (arr[j][i] == NumberToCheck)
				{
					HowMany++;
				}
			}
		}
		return HowMany;
	}

	bool IsSparseMatrix(short arr[3][3], short Rows, short Cols)
	{
		short MatrixSize = Rows * Cols;

		return (HowManyInMatrix(arr, Rows, Cols, 0) >= (MatrixSize / 2));
	}

	bool IsNumberInMatrix(short arr[3][3], short Rows, short Cols, short NumberToCheck)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (arr[i][j] == NumberToCheck)
				{
					return true;
				}
			}
		}
		return false;
	}

	void PrintIntersectedNumbersInMatrices(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (IsNumberInMatrix(Matrix1, Rows, Cols, Matrix2[i][j]))
				{
					cout << Matrix2[i][j] << "   ";
				}
			}
		}
	}

	short MinimumNumInMatrix(short arr[3][3], short Rows, short Cols)
	{
		short MinimumNumber = arr[0][0];

		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (arr[i][j] < MinimumNumber)
				{
					MinimumNumber = arr[i][j];
				}
			}
		}
		return MinimumNumber;
	}

	short MaxNumberInMatrix(short arr[3][3], short Rows, short Cols)
	{
		short MaxNumber = arr[0][0];

		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (arr[i][j] > MaxNumber)
				{
					MaxNumber = arr[i][j];
				}
			}
		}
		return MaxNumber;
	}

	bool IsPalindromeMatrix(short arr[3][3], short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols / 2; j++)
			{
				if (arr[i][j] != arr[i][Cols - 1 - j]);
				{
					return false;
				}
			}
		}
		return true;
	}

	void PrintFibonacciSeries(short To)
	{
		// I Wrote it on my own;

		short ToPrint = 0, FirstNumber = 1, PrevNumber = 1;

		cout << 1 << "  " << 1;

		for (short i = 2; i < To; i++)
		{
			ToPrint = PrevNumber + FirstNumber;

			cout << "  " << ToPrint;

			PrevNumber = FirstNumber;
			FirstNumber = ToPrint;
		}
	}

	void PrintFibonacciSeriesWithRecursion(short To)
	{
		// Wrote on my own.

		short static ToPrint = 0, FirstNumber = 1, PrevNumber = 0;

		ToPrint = FirstNumber + PrevNumber;

		PrevNumber = FirstNumber;
		FirstNumber = ToPrint;

		cout << ToPrint << "   ";

		if (To > 2)
		{
			PrintFibonacciSeriesWithRecursion(To - 1);
		}
	}

	string ReadString(string Message)
	{
		string String;

		cout << Message;
		getline(cin >> ws, String);	 // This makes ignore to the white spaces, that remains in buffer and cause issues.

		return String;
	}

	void PrintFirstLetterFromEachWord(string Whatever)
	{
		// Doctor's code

		bool isFirstLetter = true;

		cout << "\nFirst letter of this string: \n";

		for (short i = 0; i < Whatever.length(); i++)
		{
			if (Whatever[i] != ' ' && isFirstLetter)
			{
				cout << Whatever[i] << endl;
			}

			isFirstLetter = (Whatever[i] == ' ' ? true : false);
		}
	}

	string PrintFirstLetterInStringInCapital(string Whatever)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < Whatever.length(); i++)
		{
			if (Whatever[i] != ' ' && isFirstLetter)
			{
				Whatever[i] = toupper(Whatever[i]);
			}
			isFirstLetter = (Whatever[i] == ' ' ? true : false);
		}

		return Whatever;
	}

	string PrintFirstLetterInStringInLower(string ss)
	{
		bool isFirst = true;		// Doctor's code

		for (short i = 0; i < ss.length(); i++)
		{
			if (ss[i] != ' ' && isFirst)
			{
				ss[i] = tolower(ss[i]);
			}
			isFirst = (ss[i] == ' ' ? true : false);
		}
		return ss;
	}

	string UpperForString(string ss)
	{
		for (short k = 0; k < ss.length(); k++)
		{
			ss[k] = toupper(ss[k]);
		}
		return ss;
	}

	string LowerForString(string ss)
	{
		for (short i = 0; i < ss.length(); i++)
		{
			ss[i] = tolower(ss[i]);
		}
		return ss;
	}

	char ReadCharacter(string Message)
	{
		char Whatever = ' ';

		cout << Message;
		cin >> Whatever;

		return Whatever;
	}

	char InvertCharacter(char Whatever)
	{
		return isupper(Whatever) ? tolower(Whatever) : toupper(Whatever);
	}

	string InvertCharactersInString(string Whatever)
	{
		for (short i = 0; i < Whatever.length(); i++)
		{
			if (isupper(Whatever[i]) ? Whatever[i] = tolower(Whatever[i]) : Whatever[i] = toupper(Whatever[i]));
		}
		return Whatever;
	}

	short CountLetters(string ss, enWhatToCount WhatToCount = enWhatToCount::All)
	{
		if (WhatToCount == enWhatToCount::All)
		{
			return ss.length();
		}
		short Counter = 0;

		for (short i = 0; i < ss.length(); i++)
		{
			if (WhatToCount == enWhatToCount::CapitalLetter && isupper(ss[i]))
			{
				Counter++;
			}
			if (WhatToCount == enWhatToCount::SmallLetter && islower(ss[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}

	short CounterLetter(string ss, char LookingFor, bool MatchCase = true)
	{
		short Counter = 0;

		for (short i = 0; i < ss.length(); i++)
		{
			if (MatchCase)
			{
				if (ss[i] == LookingFor)
				{
					Counter++;
				}
			}
			else
			{
				if (tolower(ss[i]) == tolower(LookingFor))
				{
					Counter++;
				}
			}
		}
		return Counter;
	}

	short CounterVowels(string ss)
	{
		short Counter = 0;

		for (short i = 0; i < ss.length(); i++)
		{
			if (isVowl(ss[i]))
				Counter++;
		}
		return Counter;
	}

	void PrintAllVowls(string SS)
	{
		cout << "\nVowels in string are: ";

		for (short i = 0; i < SS.length(); i++)
		{
			if (isVowl(SS[i]))
			{
				cout << SS[i] << "  ";
			}
		}
	}

	void PrintEachWordInString(string SS, string Seperator = " ")
	{
		// Doctor's code

		string sWord;
		short pos = 0;

		cout << "\nYour string words are: \n\n";

		while ((pos = SS.find(Seperator)) != std::string::npos) // It stores in the variable "pos" the position of the first delimiter, npos() function is for if there is no delimiter, it could be only one word, so it'd exist of the loop.
		{
			sWord = SS.substr(0, pos);
			if (sWord != "")		// For checking if there are so much delimiters EX: "Ahmed     Sayed"
			{
				cout << sWord << endl;
			}

			SS.erase(0, pos + Seperator.length()); // Erase from starting position to start position + the length of the delimiter.
		}
		if (SS != "")
		{
			cout << SS << endl; //In case there is no delimiters in the string & to print last word of the string because there is no delimiter after last word..
		}
	}

	short CountsOfWordsInString(string sits)
	{
		string delimiter = " ", Copy;
		short Counter = 0, pos = 0;

		while ((pos = sits.find(delimiter)) != std::string::npos)
		{
			Copy = sits.substr(0, pos);

			if (Copy != "")
			{
				Counter++;
			}

			sits.erase(0, pos + delimiter.length());
		}
		if (sits != "")
		{
			Counter++;
		}
		return Counter;
	}

	vector <string> mySplit(string ss, string Delim = "")
	{
		vector <string> Splitted;

		string Copy;
		short pos = 0;

		while ((pos = ss.find(Delim)) != std::string::npos)
		{
			Copy = ss.substr(0, pos);

			if (Copy != "")
			{
				Splitted.push_back(Copy);
			}

			ss.erase(0, pos + Delim.length());
		}

		if (ss != "")
		{
			Splitted.push_back(ss);
		}

		return Splitted;
	}
	
	string myLeftTrim(string SS)
	{
		for (short i = 0; i < SS.length(); i++)
		{
			if (SS[i] != ' ')
			{
				return SS.substr(i, SS.length() - i);	// How!
			}
		}
		return "";
	}

	string myRightTrim(string SS)
	{
		for (short i = SS.length() - 1; i >= 0; i--)
		{
			if (SS[i] != ' ')
			{
				return SS.substr(0, i);
			}
		}
		return " ";
	}

	string myTrim(string SS)
	{
		return (myLeftTrim(myRightTrim(SS)));
	}

	string JoinString(vector<string>Ss, string Delim = " ")
	{
		string T;

		for (string& S : Ss)
		{
			T = T + S + Delim;
		}
		return T.substr(0, T.length() - Delim.length());
	}

	string JoinString(string arrString[3], short arrlength, string Delim = " ")
	{
		string WbW;

		for (short i = 0; i < arrlength; i++)
		{
			WbW = WbW + arrString[i] + Delim;
		}

		return WbW.substr(0, WbW.length() - Delim.length());
	}

	string ReverseWordsInString(string SS)
	{
		vector<string>vString;

		string Reversed = "";

		vString = mySplit(SS);

		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			--iter;

			Reversed += *iter + " ";
		}

		return myRightTrim(Reversed);	// We can also return Reversed.substr(0, SS.length()-1)
	}

	string ReplaceWordsWithBuiltInFunction(string SS, string sToReplace, string sReplaceTo)
	{
		short pos = SS.find(sToReplace);

		while (pos != std::string::npos)
		{
			SS = SS.replace(pos, sToReplace.length(), sReplaceTo);

			pos = SS.find(sToReplace);
		}

		return SS;
	}

	string myReplace(string SS, string ToReplace, string ReplaceTo, string Seperator = " ", bool IsSensitive = 1)
	{
		vector <string> MM = mySplit(SS, Seperator);

		for (string& S : MM)
		{
			if (IsSensitive)
			{
				if (S == ToReplace)
				{
					S = ReplaceTo;
				}
			}
			else
			{
				if (LowerForString(S) == LowerForString(ToReplace))
				{
					S = ReplaceTo;
				}
			}
		}

		SS = JoinString(MM);

		return SS;
	}

	string RemovePunctuations(string SS)
	{
		string Up;

		for (short i = 0; i < SS.length(); i++)
		{
			if (!ispunct(SS[i]))
			{
				Up += SS[i];
			}
		}
		return Up;
	}

	stClient ReadClientData(string AccountNumber = "000")
	{
		stClient Clinet;

		cout << "Please Enter Client Data:\n\n";

		if (AccountNumber == "000")
		{
			Clinet.AccNumber = ReadString("Enter Account Number? ");
		}
		else
			Clinet.AccNumber = AccountNumber;

			Clinet.PiCode = ReadString("Enter Pin Code? ");
			Clinet.CName = ReadString("Enter Name? ");
			Clinet.CNumber = ReadString("Enter Phone? ");
			Clinet.AccBal = Course6Test::ReadNumberTest("Enter Account Balance? ");

		return Clinet;
	}

	string ConvertRecordToLine(stClient Client, string Seperator)
	{
		string RecordClient;

		RecordClient += Client.AccNumber + Seperator;
		RecordClient += Client.PiCode + Seperator;
		RecordClient += Client.CName + Seperator;
		RecordClient += Client.CNumber + Seperator;
		RecordClient += to_string(Client.AccBal);


		return RecordClient;
	}

	stClient ConvertLineToRecord(string SS, string Seperator)
	{
		stClient Client;

		vector <string> vClients = mySplit(SS, Seperator);

		Client.AccNumber = vClients[0];
		Client.PiCode = vClients[1];
		Client.CName = vClients[2];
		Client.CNumber = vClients[3];
		Client.AccBal = stod(vClients[4]); // Cast to double

		return Client;
	}

	stClient MyConvertLineToRecord(string SS, string Seperator)
	{
		stClient Client;

		vector <string> vClients = mySplit(SS, Seperator);

		Client.AccNumber = vClients[0];
		Client.PiCode = vClients[1];

		return Client;
	}

	void AddDataLineToFile(string FileName, string stDataLine)
	{
		fstream myfile;

		myfile.open(FileName, ios::out | ios::app); 	// If there is already a file, compiler will excute last item.

		if (myfile.is_open())
		{
			myfile << stDataLine << endl;

			myfile.close();
		}
	}

	void AddNewClient()
	{
		stClient Client = ReadClientData();

		AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client, "/###/"));
	}

	void AddClients()
	{
		string Again;

		do
		{
			system("cls");
			cout << "Adding New Client:\n\n";

			AddNewClient();
			cout << "\nClient Added Successfully, do you want to add more clients? (Yes, No): ";
			cin >> Again;


		} while (Again == LowerForString("Yes"));
	}

	vector <stClient> AddClientsToVector(string FileName)
	{
		vector <stClient> vClients;

		fstream myfile;

		myfile.open(FileName, ios::in);

		if (myfile.is_open())
		{
			stClient Client;
			string Line;

			while (getline(myfile, Line))
			{
				Client = ConvertLineToRecord(Line, "/###/");

				vClients.push_back(Client);

			}
		}
		return vClients;
	}

	void PrintClientCard(stClient Client)
	{
		cout << setw(10) << "\nAccount Number  : " << Client.AccNumber;
		cout << setw(10) << "\nPin Code        : " << Client.PiCode;
		cout << setw(10) << "\nName            : " << Client.CName;
		cout << setw(10) << "\nPhone           : " << Client.CNumber;
		cout << setw(10) << "\nAccount Balance : " << Client.AccBal;
	}

	void PrintAllClientsData(vector <stClient> Clients)
	{
		cout << "\n\t\t\t\t\tClient List (" << Clients.size() << ") Client(s).";
		cout << "\n_________________________________________________________________________";
		cout << "____________________________________________________________\n" << endl;

		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_________________________________________________________________________";
		cout << "____________________________________________________________\n" << endl;

		for (stClient Client : Clients)
		{
			PrintClientCard(Client);
			cout << endl;
		}
		cout << "\n_________________________________________________________________________";
		cout << "____________________________________________________________\n" << endl;

	}

	string FirstWord(string SS, string Seperator)
	{
		short pos = SS.find(Seperator);

		while (pos != std::string::npos)
		{
			return SS.substr(0, pos);
		}

		return "Seperator is not found";
	}

	bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<stClient>& vClients)
	{
		for (stClient& Client : vClients)
		{
			if (Client.AccNumber == AccountNumber)
			{
				Client.MarkForDelete = true;
				return true;
			}
		}
		return false;
	}

	bool FindClientByAccountNumber(string AccNuToFind, vector <stClient> vClients, stClient& Client)
	{
		for (stClient C : vClients)
		{
			if (C.AccNumber == AccNuToFind)
			{
				Client = C;
				return true;
			}
		}
		return false;
	}

	vector <stClient> SaveClientsDataToFile(string FileName, vector <stClient>& vClients)
	{
		fstream myfile;
		myfile.open(FileName, ios::out);

		string DataLine;

		if (myfile.is_open())
		{
			for (stClient C : vClients)
			{
				if (C.MarkForDelete == false)
				{
					DataLine = ConvertRecordToLine(C, "/###/");
					myfile << DataLine << endl;
				}
			}
			myfile.close();
		}
		return vClients;
	}

	bool DeleteClientByAccountNumber(string AccountNumber, vector <stClient>& vClients, string Seperator)
	{
		stClient Client;
		char Answer = 'n';

		if (FindClientByAccountNumber(AccountNumber, vClients, Client))
		{
			PrintClientCard(Client);

			cout << "\n\nAre you sure you want to delete this client? y/n ? ";
			cin >> Answer;

			if (tolower(Answer) == 'y')
			{
				MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
				SaveClientsDataToFile(ClientsFileName, vClients);

				//refresh Clients
				vClients = AddClientsToVector(ClientsFileName);

				cout << "\n\nClient Deleted Successfully.";

				return true;
			}

		}
		cout << "\n\nClient With Account Number (" << AccountNumber << ") is not found";
	}

	stClient ChangeClientRecord(string AccountNumber)
	{
		stClient Client;

		Client = ReadClientData(AccountNumber);

		return Client;
	}

	bool UpdateClientByAccountNumber(string AccountNumber, vector <stClient>& vClients)
	{
		stClient Client;
		char Answer;

		if (FindClientByAccountNumber(AccountNumber, vClients, Client))
		{
			PrintClientCard(Client);

			cout << "\n\nAre you sure you want to update this client? y/n ? ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
			{
				for (stClient& C : vClients)	//As long as it's by refrence, the value inside the vector has ajusted.
				{
					if (C.AccNumber == AccountNumber)
					{
						C = ChangeClientRecord(AccountNumber);
						break;		//Break from the loop, not function.
					}
				}

				SaveClientsDataToFile(ClientsFileName, vClients);

				cout << "\n\nClients Updated Successfully.";
				return true;
			}
		}
		else
		{
			cout << "\nClient with Account Number (" << AccountNumber << ") is not found!";
			return 0;
		}


	}




	int main()
	{
		srand((unsigned)time(NULL));

		vector <stClient> vClients = AddClientsToVector(ClientsFileName);
		string AccountNumber = ReadString("Please enter Account Number ? ");

		UpdateClientByAccountNumber(AccountNumber, vClients);

		cout << endl << endl;

		return 0;
	}

	bool isVowl(char C)
	{
		C = tolower(C);

		return ((C == 'a') || (C == 'e') || (C == 'i') || (C == 'o') || (C == 'u'));
	}
}


namespace Coursse8Test
{
	// -------
	enum enLeapOrNOt { LeapYear = 1, NotLeapYear = 2 };

	enum enSeperatorOptions { BackSlash = 1, Dash = 2, Column = 3 };

	struct sDate
	{
		short Year = 0;
		short Month = 0;
		short Day = 0;
	};

	struct sStartEndDate
	{
		sDate StartDate[2];
		sDate EndDate[2];
	};

	sDate ReadDate()
	{
		sDate Date;

		Date.Day = Course6Test::ReadNumberTest(" Please enter a Day? ");
		Date.Month = Course6Test::ReadNumberTest(" Please enter a Month? ");
		Date.Year = Course6Test::ReadNumberTest(" Please enter a Year? ");

		return Date;
	}

	string NumberToText(int Number)
	{

		if (Number < 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
							"Eight","Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
							"Fifteen", "Sixteen", "Seventeen", "Eighteen", "Ninteen" };

			return arr[Number] + " ";
		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "", "" ,"Twenty","Thirty" ,"Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

			return arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 99999999)
		{
			return NumberToText(Number / 1000000) + "millions " + NumberToText(Number % 1000000);
		}
	}

	bool isLeapYear(short Year)
	{
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}

	int NumberOfHoursInaYear(double NumberOfDays)
	{
		return  NumberOfDays * 24;
	}

	int NumberOfMinutesInaYear(double NumberOfHours)
	{
		int MinutesNumber = NumberOfHours * 60;

		return MinutesNumber;
	}

	int NumberOfSecondsInaYear(double NumberOfMinutes)
	{
		int NubmerOfSeconds = NumberOfMinutes * 60;

		return NubmerOfSeconds;
	}

	void PrintYearDetails(enLeapOrNOt YearKind, short YearNumber)
	{
		if (YearKind == enLeapOrNOt::LeapYear)
		{

			int NumberOfDays = 366;
			int NumberOfHours = NumberOfHoursInaYear(NumberOfDays);
			int NumberOfMinutes = NumberOfMinutesInaYear(NumberOfHours);
			int NumberOfSEcondsInaYear = NumberOfSecondsInaYear(NumberOfMinutes);

			cout << "\nNumber of Days   " << setw(10) << "in Year [" << YearNumber << "] is " << NumberOfDays;
			cout << "\nNumber of Hours  " << setw(10) << "in Year [" << YearNumber << "] is " << NumberOfHours;
			cout << "\nNumber of Minutes" << setw(10) << "in Year [" << YearNumber << "] is " << NumberOfMinutes;
			cout << "\nNumber of Seconds" << setw(10) << "in Year [" << YearNumber << "] is " << NumberOfSEcondsInaYear;
		}
		else
		{
			int NumberOfDays = 365;
			int NumberOfHours = NumberOfHoursInaYear(NumberOfDays);
			int NumberOfMinutes = NumberOfMinutesInaYear(NumberOfHours);
			int NumberOfSEcondsInaYear = NumberOfSecondsInaYear(NumberOfMinutes);

			cout << "\nNumber of Days   " << setw(10) << "in Year [" << YearNumber << "] is " << NumberOfDays;
			cout << "\nNumber of Hours  " << setw(10) << "in Year [" << YearNumber << "] is " << NumberOfHours;
			cout << "\nNumber of Minutes" << setw(10) << "in Year [" << YearNumber << "] is " << NumberOfMinutes;
			cout << "\nNumber of Seconds" << setw(10) << "in Year [" << YearNumber << "] is " << NumberOfSEcondsInaYear;
		}
	}

	short NumberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month>12)
			return 0;

		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
	}

	short DayOfWeekOrder(short Day, short Month, short Year)
	{
		short a, y, m;

		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short DayOfWeekOrder(sDate Date)
	{
		return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
	}

	string DayShortName(short DayOfWeekOrder)
	{
		string arrDayName[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri","Sat" };

		return arrDayName[DayOfWeekOrder];
	}

	void PrintDateDetails(short Year, short Month, short Day)
	{
		cout << endl << endl;

		cout << "Data      : " << setw(10) << Day << "/" << Month << "/" << Year << endl;
		cout << "Day Order : " << setw(10) << DayOfWeekOrder(Day, Month, Year) << endl;
		cout << "Day Name  : " << setw(10) << DayShortName(DayOfWeekOrder(Day, Month, Year));
	}

	string MonthShortName(short Month)
	{
		string Months[12] = { "Jun", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

		return Months[Month - 1];
	}

	void PrintMonthCalander(short Year, short Month)
	{

		short NumberOfDays = NumberOfDaysInAMonth(Month, Year);
		short Current = DayOfWeekOrder(1, Month, Year);		//Index of the day from 0 to 6.

		printf("\n  ______________%s___________________\n\n", MonthShortName(Month).c_str());

		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		int i;
		for (i = 0; i < Current; i++)
			printf("     ");

		for (short j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);	//Five Spaces.


			if (++i == 7)	//Every time the 'i' increases by one.
			{
				i = 0;
				printf("\n");
			}
		}
		printf("\n  ___________________________________");
	}

	void PrintMonthsOfYearCalander(short Year)
	{
		system("cls");

		cout << "\n\n _________________________________________\n\n";
		printf("         Calendar  - %d ", Year);
		cout << "\n _________________________________________\n";

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalander(Year, i);

			cout << endl << endl;
		}
	}

	int NumberOfDaysFromTheBeginning(short Year, short Month, short Day)
	{
		int TotalDays = 0;

		for (short i = 1; i < Month; i++)
		{
			TotalDays += NumberOfDaysInAMonth(i, Year);
		}

		TotalDays += Day;

		return TotalDays;
	}

	int NumberOfDaysFromTheBeginning(sDate Date)
	{
		return NumberOfDaysFromTheBeginning(Date.Year, Date.Month, Date.Day);
	}

	void FromTotalNumberOfDaysToDate(short DateOrderInYear, short Year)
	{
		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;
		short DateMonth = 1;
		short DateDay = 0;


		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(DateMonth, Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				DateMonth++;
			}
			else
			{
				DateDay = RemainingDays;
				break;
			}
		}

		printf("\nDate for [%d] is: %d/%d/%d", DateOrderInYear, DateDay, DateMonth, Year);
	}

	sDate AddingDaysToDate(short Day, short Month, short Year, short Additional = 1)
	{
		sDate Date;

		short RemainingDays = Additional + NumberOfDaysFromTheBeginning(Year, Month, Day);
		short MonthDays = 0;

		Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Month, Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Month++;

				if (Month > 12)
				{
					Month = 1;
					Year++;
				}
			}
			else
			{
				Day = RemainingDays;
				Date.Day = Day, Date.Month = Month, Date.Year = Year;

				return Date;
			}
		}
	}

	bool isLastDay(short Day, short Month, short Year)
	{
		return Day == NumberOfDaysInAMonth(Month, Year);
	}

	bool isLastMonth(short Month)
	{
		return Month == 12;
	}

	sDate AddingWeeksToDate(sDate Date, short WeeksToAdd)
	{
		short DaysInWeeks = WeeksToAdd * 7;

		Date = AddingDaysToDate(Date.Day, Date.Month, Date.Year, DaysInWeeks);

		return Date;
	}

	sDate AddingMonthsToDate(sDate Date, short MonthsToAdd)
	{
		while (MonthsToAdd >= 1)
		{
			if (Date.Month == 12)
			{
				Date.Month = 1;
				MonthsToAdd--;
				Date.Year++;
			}
			else
			{
				Date.Month++;
				MonthsToAdd--;
			}
		}
		return Date;
	}

	sDate AddingYearsToDate(sDate Date, short YearsToAdd)
	{
		for (short i = 1; i <= YearsToAdd; i++)
		{
			Date.Year++;
		}
		return Date;
	}

	sDate AddingYearsToDateFaster(sDate Date, short YearsToAdd = 10)
	{
		if (YearsToAdd > 0)
		{
			Date.Year += YearsToAdd;
		}
		return Date;
	}

	sDate SubtractXDays(sDate Date, short DaysToSub = 1)
	{
		int NumberToSubstract = DaysToSub;
		short DaysInMonth = 0;


		while (NumberToSubstract > 0)
		{
			if (Date.Day == 1 && Date.Month == 1)
			{
				Date.Year--;
				Date.Month = 12;
				Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
				NumberToSubstract--;
			}

			else if (Date.Day == 1)
			{
				Date.Month--;
				Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
				NumberToSubstract--;
			}

			else
			{
				while (Date.Day > 1 && NumberToSubstract > 0)
				{
					Date.Day--;
					NumberToSubstract--;
				}
			}
		}

		return Date;
	}

	sDate SubstractXWeeks(sDate Date, short WeeksToSub = 1)
	{
		int Weeks = WeeksToSub * 7;

		Date = SubtractXDays(Date, Weeks);

		return Date;
	}

	sDate SubstractXMonths(sDate Date, short MonthsToSub = 1)
	{
		while (MonthsToSub >= 1)
		{
			if (Date.Month == 12)
			{
				Date.Month = 1;
				MonthsToSub--;
				Date.Year++;
			}
			else
			{
				Date.Month--;
				MonthsToSub--;
			}
		}
		return Date;
	}

	sDate SubstractXYears(sDate Date, short YearsToSub = 1)
	{
		Date.Year -= YearsToSub;

		return Date;
	}

	sDate SubstractXDecades(sDate Date, short DecadesToSub = 1)
	{
		Date = SubstractXYears(Date, DecadesToSub * 10);

		return Date;
	}

	string PrintDayName(short DayOrder)
	{
		DayOrder += 1;

		switch (DayOrder)
		{
		case 1:
		{
			return "Sun";
		}
		case 2:
		{
			return "Mon";
		}
		case 3:
		{
			return "Tue";
		}
		case 4:
		{
			return "Wed";
		}
		case 5:
		{
			return "Thur";
		}
		case 6:
		{
			return "Fri";
		}
		case 7:
		{
			return "Sut";
		}
		}
	}

	short IsEndOfWeek(sDate Date)
	{
		return DayOfWeekOrder(Date.Day, Date.Month, Date.Day) == 6;
	}

	bool IsWeekEnd(sDate Date)
	{
		short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);

		return (DayIndex == 5 || DayIndex == 6);
	}

	bool IsBusindessDay(sDate Date)
	{
		return !IsWeekEnd(Date);
	}

	short DaysUntilEndOfWeek(sDate Date)
	{
		return 6 - DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
	}

	bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
	{
		return (Date1.Year < Date2.Year) ? true : (Date1.Year > Date2.Year) ? false : (Date1.Month < Date2.Month) ? true : (Date1.Month > Date2.Month) ? false : (Date1.Day < Date2.Day) ? true : false;
	}

	short GetVacationDays(sDate From, sDate To)
	{
		short DaysCount = 0;

		while (IsDate1BeforeDate2(To, From))
		{
			if (IsBusindessDay(From))
			{
				DaysCount++;
			}
		}
		return DaysCount;
	}

	bool IsDate1AfterDate2(sDate Date1, sDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2));
	}

	bool IsDate1EqualDate2(sDate Date1, sDate Date2)
	{
		return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	enDateCompare CompareDateFunctionResult(sDate Date1, sDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		return enDateCompare::After;
	}

	void ReadPeriods(sStartEndDate& Period, short NumberOfPeriod)
	{
		for (short i = 1; i <= NumberOfPeriod; i++)
		{
			cout << "\n Enter Period " << i << ':' << endl;
			cout << " Enter Start Date:\n\n";

			Period.StartDate[i - 1] = ReadDate();

			cout << "\n Enter End Date;\n\n";
			Period.EndDate[i - 1] = ReadDate();

			while (IsDate1AfterDate2(Period.StartDate[i - 1], Period.EndDate[i - 1]))
			{
				cout << "\n\n Date 1 should be Before Date 2: \n\n";

				cout << " Enter Period " << i << ':' << endl;
				cout << " Enter Start Date:\n\n";

				Period.StartDate[i - 1] = ReadDate();

				cout << "\n Enter End Date;\n";
				Period.EndDate[i - 1] = ReadDate();

				system("cls");
			}

			system("cls");
		}
	}

	bool IsPeriodsOverlap(sStartEndDate Periods)
	{
		if (			//Period 2.End Date < Period 1.StartDate.
			CompareDateFunctionResult(Periods.EndDate[1], Periods.StartDate[0]) == enDateCompare::Before
			||			// Or period 2.StartDate > Period 1.End Date.
			CompareDateFunctionResult(Periods.StartDate[1], Periods.EndDate[0]) == enDateCompare::After)
		{
			return false;
		}

		else
			return true;
	}

	int CalculatePeriodLength(sStartEndDate Dates, short Index = 0)
	{
		int Days = 0;

		while (IsDate1BeforeDate2(Dates.StartDate[Index], Dates.EndDate[Index]))
		{
			Days++;
			Dates.StartDate[Index] = AddingDaysToDate(Dates.StartDate[Index].Day, Dates.StartDate[Index].Month, Dates.StartDate[Index].Year);
		}
		return Days;
	}

	bool IsDateWithinPeriod(sStartEndDate EndStartDate, sDate DateToCheck)
	{
		return !(IsDate1BeforeDate2(DateToCheck, EndStartDate.StartDate[0])
			||
			(IsDate1AfterDate2(DateToCheck, EndStartDate.EndDate[0])));
	}

	sDate WhichDateBefore(sDate StartDate1, sDate StartDate2)
	{
		if (IsDate1BeforeDate2(StartDate1, StartDate2))
			return StartDate1;
		else
			return StartDate2;
	}

	bool isValidDate(sDate Date)
	{
		return Date.Month > 12 || Date.Month < 1 ? false : Date.Day > NumberOfDaysInAMonth(Date.Month, Date.Year) || Date.Day < 1 ? false : Date.Year < 1800 || Date.Year > 2030 ? false : true;
	}

	string ReadString()
	{
		string Date;

		cout << "Please Enter Date dd/mm/yyyy? ";
		getline(cin >> ws, Date);

		return Date;
	}

	sDate StringToDate(string SDate, string Seperator = "/")
	{
		//On My Own

		sDate Date;

		short pos = SDate.find(Seperator);

		Date.Day = stoi(SDate.substr(0, pos));
		SDate.erase(0, pos + Seperator.length());

		pos = SDate.find(Seperator);

		Date.Month = stoi(SDate.substr(0, pos));

		SDate.erase(0, pos + Seperator.length());

		pos = SDate.find(Seperator);


		Date.Year = stoi(SDate.substr(0, pos));


		return Date;
	}

	string DateToString(sDate Date)
	{
		// On My Own

		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}

	string FormateDate(sDate Date, string DateFormat = "d/m/y", string Seperator = "/")
	{
		//  Not perfect!

		string FormattedDateString = "";

		FormattedDateString = Course7Test::ReplaceWordsWithBuiltInFunction(DateFormat, "d", to_string(Date.Day));
		FormattedDateString = Course7Test::ReplaceWordsWithBuiltInFunction(FormattedDateString, "m", to_string(Date.Month));
		FormattedDateString = Course7Test::ReplaceWordsWithBuiltInFunction(FormattedDateString, "y", to_string(Date.Year));

		return FormattedDateString;
	}



	int main()
	{
		srand((unsigned)time(NULL));



		return 0;
	}


























}


namespace Course10Test
{

// String is a class.
// Class Members: The contents inside class are called members, and there are two types of: Data Members: Any variable declared inside the class.
// Class Members: Second type is Member Methods, Any function or procedure declared inside the class.
// Access Specifiers: There are 3 kinds of Access Modifiers, Private, Protected, Public. When we assign a member inside Private Access Kind, the member will be accessable only inside the class, and it can't be inherited or used ouside.
// Access Specifiers: Protected Member Kind is accessable inside, The Member won't be accessable ouside the class, but it can be inherited.
// Access Specifiers: Public Member Kind is accessable to all directions, and it can be inhirted.
// Properties Get and Set Through '='.
// First Principle/Concept of OOP : Encapsulation. Grouping all methods and functions inside one certain class.
// Second Principle/Concept of OOP: Abstraction. Only expose important methods inside the class.
// Constructors: Compiler always use construction Defaultly, everytime we assign an object from a class, it initializes values to that object.
// Copy Constructors: We can make copies of the constructor by overloading.
// Destructors: Destructor is the opposite to constructor, Destructor is a method that destruct members inside classes, Destructor is the last called method inside class, inside it we can do whatever we want.
// There can be only one Destructor inside the class, we can't make overloading with it, we can't send parameters to it and recieve parameters from.
// Static Members: When the mission of any function done, Compiler destroys all the variables inside it, except for Static Variables. Same with Static Members inside classes.
// Third Principle/Concept of OOP: Inheritance. Inheriting complete code without copying it.
// Access Specifiers/Modifiers Review: Either from Derived Classes or Base Classes, what can be seen in main is the public members only.
// Inheritance Types: 1-Single Inheritance, 2-Multi Level Inheritance, 3-Hierarchal Inheritance, These three types are supported in most Programming Languages.
// 4-Multiple Inheritance: This type is in C++, Treating with is not easy. One class can inherit more than a class. Most Modern programming languages don't support this type cuz it causes issues.
// Up Casting vs Down Casting.
// Virtual Functions: When we make a virtual method inside a class, compiler treats with differently and create a virtual table for in memory to save the addresses of it to don't mix in coding.
// Static-Early Binding vs Dynamic-Late Binding, Early Binding is a little faster in run time.
// Fourth Principle/Concept of OOP: Polymorphism: It allows us to create consistent code, Same name can use it differently.
// Interfaces: Pure Virtual Functions and Abstract Classes.
// Friend Classes: Giving access to certain class to have full access to another class.
// Friend Function: Giving access to certain function to have full access to a certain class.
// "this" pointer in C++ : Compiler uses "this" by default to reach any member/method inside the class.
// Passing Objects to Functions (ByRef/ByVal): Objects can be treated like any data type such as int, bool, string etc; they can be passed to functions as parameters either by reference or by value.
// Objects with Parameterized Constructor and Array: 
// Class vs Structure: C++ is an extend to C, C++ supports OOP while C don't, structure exists when C do, so structure those days was limited, so when C++ comes, they built class on the existed structure in C.
// Not all languages support Structure, when you have a method, straightly use class, for grouping data use structure.





}
