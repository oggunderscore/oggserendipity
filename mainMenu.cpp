#include "serendipity.h"
#include "bookType.h"
#include "resultsType.h"
//--------------------------------------------------------//
// File Name: mainMenu.cpp
// Project name: Serendipity Overloading Sorting
//--------------------------------------------------------
// Creators name and email: Kevin Nguyen, oggunderscore@gmail.com
// Creation Date: 11/21/19
// Date of Last Modification: 11/21/19
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
string day;
string month;
string year;

string getDate() {
	string date = month + "/" + day + "/" + year;
	return date;
}

void convertMonthToInt(string tMonth) {
	if (tMonth == "Jan") {
		month = "01";
	} else if (tMonth == "Feb") {
		month = "02";
	} else if (tMonth == "Mar") {
		month = "03";
	} else if (tMonth == "Apr") {
		month = "04";
	} else if (tMonth == "May") {
		month = "05";
	} else if (tMonth == "Jun") {
		month = "06";
	} else if (tMonth == "Jul") {
		month = "07";
	} else if (tMonth == "Aug") {
		month = "08";
	} else if (tMonth == "Sep") {
		month = "09";
	} else if (tMonth == "Oct") {
		month = "10";
	} else if (tMonth == "Nov") {
		month = "11";
	} else if (tMonth == "Dec") {
		month = "12";
	}
}

void mainMenu(bookType *book[]) {
	bool exitMenu = false;
	do {
		char selection;
		bool validInput;
		do {
			clears();
			cout << "\n\t\tSerendipity Book Sellers\n\t\t\tMain Menu\n\n";
			cout << "\t\t1. Cashier Module\n\t\t2. Inventory Database Module.\n\t\t3. Report Module.\n\t\t4. Exit\n\n\tPlease type in your input: ";
			cin.clear();
			cin >> selection;
			switch(selection) {
				case '1':
					validInput = true;
					clears();
					cashierModule(book);
					break;
				case '2':
					validInput = true;
					clears();
					inventoryDatabaseModule(book);
					break;
				case '3':
					validInput = true;
					clears();
					reportModule(book);
					break;
				case '4':
					validInput = true;
					cout << "Exiting Program..." << endl;
					exitMenu = true;
					pause();
					clears();
					return;
					break;
				default:
					validInput = false;
					cout << "\nPlease enter a valid selection!" << endl;;
					break;
			}
		} while (validInput != true);
	} while (exitMenu != true);
}
int main() {
	
	bookType *book[20];
	
	char tMonth[15], tDay[3], tYear[5];
	
	strftime(tMonth, sizeof(tMonth), "%b", timePointer);

	convertMonthToInt(tMonth);
	
	strftime(tDay, sizeof(tDay), "%d", timePointer);
	day = tDay;
	
	strftime(tYear, sizeof(tYear), "%Y", timePointer);
	year = tYear;
	
	mainMenu(book);
    return 0;
}