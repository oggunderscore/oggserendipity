#include "serendipity.h"
#include "bookType.h"
#include "resultsType.h"
//--------------------------------------------------------//
// File Name: mainMenu.cpp
// Project name: Serendipity Ch 9-11
//--------------------------------------------------------
// Creators name and email: Kevin Nguyen, oggunderscore@gmail.com
// Creation Date: 9/14/19
// Date of Last Modification: 9/14/19
//--------------------------------------------------------//
// Purpose: This class serves the purpose of the main
// source and compilation for the rest of the program.
// The program is for the Serendipity Project.
// This class displays the mainMenu and redirects.
//--------------------------------------------------------//
// Algorithm: 
// While gathering input from the user upon prompt of the
// main menu, execute the redirection to the correct 
// module within the program.
//--------------------------------------------------------//
//                Data Dictionary
// Constants
// 
// Name           Data Type             Initial Value
// ----------     --------------        ------------------//
// exitCode       bool                  false
// 
// Variables
// 
// Name           Data Type             Initial Value
// ----------     --------------        ------------------//
// selection      int                   null
// validInput     boolean               null
// buffer         char array            null
// timePointer    time array            localtime
// t              time                  N/A 
// exitcode       boolean               false
// selection      int                   null
// validInput     boolean               null
//--------------------------------------------------------//


time_t t = time(NULL);
tm* timePointer = localtime(&t);
char buffer[26];

string getDate() {
	return buffer;
}

void mainMenu(bookType *book[]) {
	bool exitMenu = false;
	do {
		char selection;
		bool validInput;
		do {
			clear();
			cout << "\n\t\tSerendipity Book Sellers\n\t\t\tMain Menu\n\n";
			cout << "\t\t1. Cashier Module\n\t\t2. Inventory Database Module.\n\t\t3. Report Module.\n\t\t4. Exit\n\n\tPlease type in your input: ";
			cin >> selection;
			switch(selection) {
				case '1':
					validInput = true;
					clear();
					cashierModule(book);
					break;
				case '2':
					validInput = true;
					clear();
					inventoryDatabaseModule(book);
					break;
				case '3':
					validInput = true;
					clear();
					reportModule(book);
					break;
				case '4':
					validInput = true;
					cout << "Exiting Program..." << endl;
					exitMenu = true;
					pause();
					clear();
					return;
					break;
				default:
					validInput = false;
					cout << "\nPlease enter a valid selection!";
					break;
			}
		} while (validInput != true);
	} while (exitMenu != true);
}
int main() {
	
	bookType *book[20];
	
	strftime(buffer, sizeof(buffer), "%b %d, %Y", timePointer);
	mainMenu(book);
    return 0;
}