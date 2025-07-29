Banking System – C++ OOP Project

This is a console-based Banking System built using C++ and Object-Oriented Programming (OOP) principles. 
It simulates core banking functionalities and uses text files as the database backend to store clients, users, currencies, transfer and transaction logs.

The system provides the following functionalities:

Client Management
Add, update, delete, and search clients with ease.

User Management with Permissions
Each user has specific permissions that control access to features like editing clients, viewing data, or performing transactions.

Money Transfer & Balance Operations
Transfer money between clients, withdraw from balances, and view transaction history.

Currency Management
Add, update, or delete currencies used in transactions.

Data Logging
All money transfers and login activities are logged for tracking.

Role-based permissions (limit actions based on user privileges)

Financial Operations

Money transfer between clients

Withdraw from client balance

Currency management (Add / Update / Calculate / Delete currencies)

Search & Logs

Search clients

Log file for money transfers and user actions

💾 Data Storage
All data is stored in plain text files (no external database used). The following files are used

Clients.txt
Users.txt
Currencies.txt
TransferLog.txt
LoginRegister.txt

Technologies Used: C++ ,Object-Oriented Programming (OOP)

File I/O (fstream)

Folder Structure

/Classes         → All class definitions (Client, User, Currency, etc.)
/Database Files  → Text files used as a simple file-based database
BankingSystem.sln         → Entry point of the application

📌 Notes

The system is designed for learning and demonstration purposes.
I developed it during my journey in building a strong foundation in programming.
There is a simple encryption used for passwords – avoid using real credentials.
