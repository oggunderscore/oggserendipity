#include "serendipity.h"
#include "bookType.h"
#include "resultsType.h"
//--------------------------------------------------------//
// File Name: cashierModule.cpp
// Project name: Serendipity Ch 9-11
//--------------------------------------------------------
// Creators name and email: Kevin Nguyen, oggunderscore@gmail.com
// Creation Date: 9/14/19
// Date of Last Modification: 9/14/19
//--------------------------------------------------------//
// Purpose: This class displays the cashierModule.
// It also functions as intended to gather information from
// the user to store information and run calculations.
//--------------------------------------------------------//
// Algorithm: 
// Prompt user for an input then execute module functions.
//--------------------------------------------------------//
//                Data Dictionary
// Constants
// 
// Name           Data Type             Initial Value
// ----------     --------------        ------------------//
// taxRate        float                 0.06
// 
// Variables
// 
// Name           Data Type             Initial Value
// ----------     --------------        ------------------//
// date           string                null
// ISBN           string                null
// title          string                null
// quantity       int                   null
// rounding       int                   null
// width          int                   null
// price          float                 null
// subtotal       float                 null
// total          float                 null
// tax            float                 null
// selection      int                   null
// validInput     boolean               null
// spacer         string                null
//--------------------------------------------------------//

struct receiptType {
	bookType book;
	int amount, id;
};

int cashierSearch(bookType *book[], int &amount) {
	string search, temp, tempInt;	
	bool foundNeg = true;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	do {
		cout << "\nPurchase Request (exact title/isbn): ";
		//cin.ignore(numeric_limits<streamsize>::max(),'\n');
		getline(cin, temp);
		tempInt = temp.substr(0, 3);
		if (tempInt.find("-") != string::npos) {	
			cout << "ERROR: Cannot enter negative numbers!" << endl;
			foundNeg = true;
		} else {
			foundNeg = false;
			amount = stoi(tempInt);
			search = temp.substr(4, temp.length()); //50 x Title
		}
	} while (foundNeg == true);
	
	if (amount != 0) {
		for (int x = 0; x < DBSIZE; x++) {
			size_t found = findCaseInsensitive(book[x]->getTitle(), search, 0);
			if (found != string::npos) {
				if (book[x]->getQtyOnHand() < amount) {
					return (-2);
				} else {
					return x;
				}
			} else { 
				for (int x = 0; x < DBSIZE; x++) {
					found = book[x]->getIsbn().find(search);
					if (found != string::npos) {
						if (book[x]->getQtyOnHand() < amount) {
							return (-2);
						} else {
							return x;
						}
					}
				}
			}
		}
	} else {
		return (-3);
	}
	return (-1);
}

void addToReceipt(bookType *book1, int index1, int amount1, receiptType  *receipts[], int &items) {
	if (items == 0) {
		receipts[0]->book = new bookType(book1);
		receipts[0]->amount = amount1;
		receipts[0]->id = index1;
		items++;
	} else {
		bool dupe = false;
		for (int x = 0; x < items; x++) {
			if (receipts[x]->book.equals(book1)) {
				receipts[x]->amount += amount1;
				dupe = true;
			}
		}
		if (dupe == false) {
			receipts[items]->book = new bookType(book1);
			receipts[items]->amount = amount1;
			receipts[items]->id = index1;
			items++;
		}
	}
}

//removed prototype for gatherReq
void gatherRequests(bookType *book[], receiptType *receipts[], int &items) {
	bool exitRequests = false;
	do {
		int amount = 0;
		int index = cashierSearch(book, amount);
		bool validInput;
		char selection;
		
		if (index >= 0) {
				do {
					//Add?
					addToReceipt(book[index], index, amount, receipts, items);
					cout << endl;
					cout << "\"" << book[index]->getTitle()
							<< "\" added to cart. Add another book? (Y/N): ";
					cin >> selection;
					switch (selection) {
						case 'Y':
						case 'y':
							validInput = true;
							break;
						case 'N':
						case 'n':
							validInput = true;
							exitRequests = true;
							amount = 0;
							cout << endl;
							break;
						default:
							cout << "Please enter a valid response! ";
							validInput = false;
							break;
					}
				} while (validInput != true);
			} else if (index == (-1)) {
				do {
					cout << "\nError: Could not find Book. Try again? (Y/N): ";
					cin >> selection;
					switch (selection) {
						case 'Y':
						case 'y':
							validInput = true;
							break;
						case 'N':
						case 'n':
							validInput = true;
							exitRequests = true;
							break;
						default:
							cout << "Please enter a valid response! ";
							validInput = false;
							break;
					}
				} while (validInput != true);
			} else if (index == (-2)) {
				do {
					cout << "\nError: Cannot buy amount over inventory amount. Try again? (Y/N): ";
					cin >> selection;
					switch (selection) {
						case 'Y':
						case 'y':
							validInput = true;
							break;
						case 'N':
						case 'n':
							validInput = true;
							exitRequests = true;
							break;
						default:
							cout << "Please enter a valid response! ";
							validInput = false;
							break;
					}
				} while (validInput != true);
			} else if (index == (-3)) {
				do {
					cout << "\nError: Why buy 0 books.. Try again? (Y/N): ";
					cin >> selection;
					switch (selection) {
						case 'Y':
						case 'y':
							validInput = true;
							break;
						case 'N':
						case 'n':
							validInput = true;
							exitRequests = true;
							break;
						default:
							cout << "Please enter a valid response! ";
							validInput = false;
							break;
					}
				} while (validInput != true);
			}
	} while (exitRequests != true);
}


void cashierModule(bookType *book[]) {
	receiptType *receipts[DBSIZE];
	int items = 0;
	bool exitCashier = false;
	bool validInput;
	char selection;
	cout << fixed;
	cout.precision(2);
	do {
		exitCashier = false;
		clear();
		cout << "\t\tSerendipity Booksellers\n\t\tCashier Module Setup\n\tFORMAT: # x TITLE";
		
		gatherRequests(book, receipts, items);
		
		
		
		

		if (exitCashier != true) {
			if (items > 0) {
				int rounding;
				float price, subtotal, total = 0, totalSubTotal = 0, totalTax = 0, tax, taxRate = 0.06, quantity;
				
				clear();
				cout << "Serendipity Booksellers\n\nDate: " << getDate() << "\n\nQty\tISBN\t\tTitle\t\t\t\t\t\t\t\tPrice\tTotal\n-----------------------------------------------------------------------------------------------------------------\n";
				
				for (int x = 0; x < items; x++) {
					//Calculate
					subtotal = receipts[x]->book.getRetail() * receipts[x]->amount * 1.0;
					tax = (float) (subtotal * taxRate) * 100.0;
					rounding = (int) tax;
					tax = rounding / 100.0;
					totalSubTotal += subtotal;
					totalTax += tax;
					total += subtotal + tax;
					
					book[receipts[x]->id]->setQtyOnHand(book[receipts[x]->id]->getQtyOnHand() - receipts[x]->amount); //subtract amount from book.
					
					cout << receipts[x]->amount << "\t" << receipts[x]->book.getIsbn() << "\t" << setw(48) << left << receipts[x]->book.getTitle() << "\t\t" << right << setw(6) << receipts[x]->book.getRetail() << "\t" << right << setw(6) << subtotal << endl;
					
				}

				
				
				
				cout << "\n\n\t\t\t\t\t\t\t   Subtotal: " << "\t\t\t\t" << right << setw(6) << totalSubTotal << left << "\n\t\t\t\t\t\t\t   Tax: " << "\t\t\t\t" << right << setw(6) << totalTax << left << "\n\t\t\t\t\t\t\t   Total: " << "\t\t\t\t" << right << setw(6) << total << left << "\n\nThank you for Shopping at Serendipity!" << endl;
				cout << endl;
				
				if (items > 0) {
			
			
			
			//Print Receipt & Confirm
			
				validInput = false;
				do {
					cout << "Confirm Purchase? (Y/N): ";
					cin >> selection;
					switch (selection) {
						case 'Y':
						case 'y':
							validInput = true;
							cout << "Purchase successful." << endl;
							break;
						case 'N':
						case 'n':
							validInput = true;
							clear();
							exitCashier = true;
							break;
						default:
							cout << "Please enter a valid response! ";
							validInput = false;
							break;
					}
				} while (validInput != true);

				
				for (int x = 0; x < items; x++) {
					if (receipts[x]->book.getQtyOnHand() < receipts[x]->amount) {
						cout << "NOTE: User requested " << receipts[x]->amount << " out of " <<  receipts[x]->book.getQtyOnHand() << " books available for book: \"" << receipts[x]->book.getTitle() << "\".\nSetting desired amount to Qty in Inventory.\n" << endl;
						receipts[x]->amount = receipts[x]->book.getQtyOnHand();
						cout << endl;
					}
				}
			} else if (items == 0) {
				exitCashier = true;
			}
				


				validInput = false;

				do {
					if (validInput != true) {
						cout << "Would you like to enter another receipt? (Y/N) : ";
						cin >> selection;
						switch (selection) {
							case 'Y':
							case 'y':
								validInput = true;
								clear();
								break;
							case 'N':
							case 'n':
								validInput = true;
								clear();
								exitCashier = true;
								break;
							default:
								cout << "Please enter a valid response! ";
								validInput = false;
								break;
						}
					} else {
						break;
					}
				} while (validInput != true);
			}
		}
	} while (exitCashier != true);
}