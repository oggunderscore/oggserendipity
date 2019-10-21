#include "serendipity.h"
#include "bookType.h"
#include "resultsType.h"

//--------------------------------------------------------//
// File Name: reportModule.cpp
// Project name: Serendipity Ch 9-11
//--------------------------------------------------------
// Creators name and email: Kevin Nguyen, oggunderscore@gmail.com
// Creation Date: 9/14/19
// Date of Last Modification: 9/14/19
//--------------------------------------------------------//
// Purpose: This class displays the reportModule.
//
//--------------------------------------------------------//
// Algorithm: 
// Prompt user for an input then execute module functions.
//------------------- -------------------------------------//
//                Data Dictionary
// Constants
// 
// Name           Data Type             Initial Value
// ----------     --------------        ------------------//
// N/A
// 
// Variables
// 
// Name           Data Type             Initial Value
// ----------     --------------        ------------------//
// selection      int                   null
// validInput     boolean               null
//--------------------------------------------------------//

void repListing(bookType *book[]) {
	clear();
	bool exitListing = false;
	int page = 1, maxPages;
	if (book[0]->getBookCount() >= 10) {
		maxPages = (book[0]->getBookCount()+9) / 10;
	} else {
		maxPages = 1;
	}
	cout << "###################################################################################################################################################################\n#\n#\t\t\tPLEASE RESIZE YOUR BOX TO BE THE SIZE DESIGNATED BY THE BARS.\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#";
	cout << endl;
	pause();
	
	
	
	while (exitListing != true) {
		int numOnPage = 0;
		bool skip = false;
		clear();
		cout << "\t\t\t\t\t\t\t\t----------- Serendipity BookSellers Report Listing -----------\n" << endl;
		cout << "\tDate: " << getDate() << "\tPAGE: " << page << " of " << maxPages << "\t\tDatabase Info (Books / Max): " << book[0]->getBookCount() << "/" << DBSIZE << "\n" << endl;
		cout << "Title                                             " << " " << "ISBN      " << " " << "Author              " << " " << "Publisher           " << " " << "Date Added          " << " " << "  QTY" << " " << "         Wholesale " << " " << "       Retail    " << endl;
		cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		for (int x = (page*10)-10; x < book[0]->getBookCount(); x++) {
			
			if (numOnPage == 10)
				skip = true;
			numOnPage++;
			if (skip != true) {
				string aTitle = book[x]->getTitle().substr(0,49);
				string aAuthor = book[x]->getAuthor().substr(0,19);
				string aPublisher = book[x]->getPublisher().substr(0,19);
				cout << left << setw(50) << aTitle << " " << setw(10) << book[x]->getIsbn() << " " << setw(20) << aAuthor << " " << setw(20) << aPublisher << " " << setw(20) << book[x]->getDateAdded() << " " << right << setw(5) << book[x]->getQtyOnHand() << " " << "        $" << setw(9) << right << book[x]->getWholesale() << "      " << left << "$  " << right << setw(6) << book[x]->getRetail() << "\n" << endl;

			}
		}
		
		
		

		
		cout << "\tPress UP_ARROW to go up a page. Press DOWN_ARROW to go down a page. Press ESC to quit." << endl;
		
		char c;
		cin >> c;
		if (c == '1') {
			if (page == maxPages)
				page = 1;
			else
				page++;
		} else if (c == '2') {
			if (page == 1)
						page = maxPages;
					else
						page--;
		} else if (c == '3') {
			exitListing = true;
		}
		
		/*
		char c;
		while (1) {
			c = getchar();
			switch(c) {
				case KEY_UP: 
					if (page == maxPages)
						page = 1;
					else
						page++;
					break;
				case KEY_DOWN:
					if (page == 1)
						page = maxPages;
					else
						page--;
					break;
				case KEY_ESC:
					exitListing = true;
					break;
			}
		}
		*/
	}
}
void repWholesale(bookType *book[]) {
	clear();
	bool exitWholesale = false;
	int page = 1, maxPages;
	if (book[0]->getBookCount() >= 10) {
		maxPages = (book[0]->getBookCount()+9) / 10;
	} else {
		maxPages = 1;
	}
	cout << "################################################################################################\n#\n#\t\t\tPLEASE RESIZE YOUR BOX TO BE THE SIZE DESIGNATED BY THE BARS.\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#";
	pause();
	
	double totalWholesaleValue = 0;
	
	for (int x = 0; x < book[0]->getBookCount(); x++) {
		totalWholesaleValue += (book[x]->getQtyOnHand()*book[x]->getWholesale());
	}
	
	
	
	while (exitWholesale != true) {
		int numOnPage = 0;
		bool skip = false;
		clear();
		cout << "\t\t----------- Serendipity BookSellers Report Listing -----------\n" << endl;
		cout << "\tDate: " << getDate() << "\tPAGE: " << page << " of " << maxPages << "\t\tDatabase Info (Books / Max): " << book[0]->getBookCount() << "/" << DBSIZE << "\n" << endl;
		cout << "Title                                             " << " " << "ISBN      " << " " << "  QTY" << " " << "          Wholesale " << endl;
		cout << "----------------------------------------------------------------------------------------------" << endl;
		for (int x = (page*10)-10; x < book[0]->getBookCount(); x++) {
			
			if (numOnPage == 10)
				skip = true;
			numOnPage++;
			if (skip != true) {
				string aTitle = book[x]->getTitle().substr(0,49);
				string aAuthor = book[x]->getAuthor().substr(0,19);
				string aPublisher = book[x]->getPublisher().substr(0,19);
				cout << left << setw(50) << aTitle << " " << setw(10) << book[x]->getIsbn() << " " << right << setw(5) << book[x]->getQtyOnHand() << " "<< "          $ " << setw(7) << right << book[x]->getWholesale() << "\n" << endl;

			}
		}
		
		if (page == maxPages) {
			cout << "Total Wholesale Value: $" << totalWholesaleValue << "\n" << endl;
		}
		
		cout << "\tPress UP_ARROW to go up a page. Press DOWN_ARROW to go down a page. Press ESC to quit." << endl;
		
		char c;
		cin >> c;
		if (c == '1') {
			if (page == maxPages)
				page = 1;
			else
				page++;
		} else if (c == '2') {
			if (page == 1)
						page = maxPages;
					else
						page--;
		} else if (c == '3') {
			exitWholesale = true;
		}
		
		/*
		char c;
		while (1) {
			c = getchar();
			switch(c) {
				case KEY_UP: 
					if (page == maxPages)
						page = 1;
					else
						page++;
					break;
				case KEY_DOWN:
					if (page == 1)
						page = maxPages;
					else
						page--;
					break;
				case KEY_ESC:
					exitListing = true;
					break;
			}
		}
		*/
	}
}
void repRetail(bookType *book[]) {
	clear();
	bool exitRetail = false;
	int page = 1, maxPages;
	if (book[0]->getBookCount() >= 10) {
		maxPages = (book[0]->getBookCount()+9) / 10;
	} else {
		maxPages = 1;
	}
	cout << "################################################################################################\n#\n#\t\t\tPLEASE RESIZE YOUR BOX TO BE THE SIZE DESIGNATED BY THE BARS.\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#\n#";
	pause();
	
	
	while (exitRetail != true) {
		int numOnPage = 0;
		bool skip = false;
		clear();
		cout << "\t\t----------- Serendipity BookSellers Report Listing -----------\n" << endl;
		cout << "\tDate: " << getDate() << "\tPAGE: " << page << " of " << maxPages << "\t\tDatabase Info (Books / Max): " << book[0]->getBookCount() << "/" << DBSIZE << "\n" << endl;
		cout << "Title                                             " << " " << "ISBN      " << " " << "  QTY" << " " << "               Retail " << endl;
		cout << "----------------------------------------------------------------------------------------------" << endl;
		
		
		double totalRetailValue = 0;
	
		for (int x = 0; x < book[0]->getBookCount(); x++) {
			totalRetailValue += (book[x]->getQtyOnHand()*book[x]->getRetail());
		}
		
		for (int x = (page*10)-10; x < book[0]->getBookCount(); x++) {
			
			if (numOnPage == 10)
				skip = true;
			numOnPage++;
			if (skip != true) {
				string aTitle = book[x]->getTitle().substr(0,49);
				string aAuthor = book[x]->getAuthor().substr(0,19);
				string aPublisher = book[x]->getPublisher().substr(0,19);
				cout << left << setw(50) << aTitle << " " << setw(10) << book[x]->getIsbn() << " " << right << setw(5) << book[x]->getQtyOnHand() << " " << setw(10) << "$ " << setw(9) << right << book[x]->getRetail() << "\n" << endl;

			}
		}
		
		if (page == maxPages) {
			cout << "Total Retail Value: $" << totalRetailValue << "\n" << endl;
		}
		
		cout << "\tPress UP_ARROW to go up a page. Press DOWN_ARROW to go down a page. Press ESC to quit." << endl;
		
		char c;
		cin >> c;
		if (c == '1') {
			if (page == maxPages)
				page = 1;
			else
				page++;
		} else if (c == '2') {
			if (page == 1)
						page = maxPages;
					else
						page--;
		} else if (c == '3') {
			exitRetail = true;
		}
		
		/*
		char c;
		while (1) {
			c = getchar();
			switch(c) {
				case KEY_UP: 
					if (page == maxPages)
						page = 1;
					else
						page++;
					break;
				case KEY_DOWN:
					if (page == 1)
						page = maxPages;
					else
						page--;
					break;
				case KEY_ESC:
					exitListing = true;
					break;
			}
		}
		*/
	}
}
void repQty() {
	cout << "You selected Listing by Quantity." << endl;
	pause();
	clear();
}
void repCost() {
	cout << "You selected Listing by Cost." << endl;
	pause();
	clear();
}
void repAge() {
	cout << "You selected Listing by Age." << endl;
	pause();
	clear();
}

void reportModule(bookType *book[]) {
	int selection;
	bool validInput;
	bool exitReports = false;
	do {
		if (validInput != true) {
			cout << "\t\tSerendipity Booksellers\n\t\t\tReports\n\n\t\t1. Inventory Listing\n\t\t2. Inventory Wholesale Value\n\t\t3. Inventory Retail Value\n\t\t4. Listing by Quantity\n\t\t5. Listing by Cost\n\t\t6. Listing by Age\n\t\t7. Return to Main Menu\n\n\t\tPlease enter your input: ";
			cin >> selection;
			switch(selection) {
				case 1:
					validInput = true;
					repListing(book);
					break;
				case 2:
					validInput = true;
					repWholesale(book);
					break;
				case 3:
					validInput = true;
					repRetail(book);
					break;
				case 4:
					validInput = true;
					repQty();
					break;
				case 5:
					validInput = true;
					repCost();
					break;
				case 6:
					validInput = true;
					repAge();
					break;
				case 7:
					validInput = true;
					exitReports = true;
					break;
				default:
					validInput = false;
					cout << "\nPlease enter a valid selection!";
					clear();
					break;
			}
		} else {
			break;
		}
	} while (exitReports != true);
}