#include "serendipity.h"
#include "bookType.h"
#include "resultsType.h"
//--------------------------------------------------------//
// File Name: inventoryDatabaseModule.cpp
// Project name: Serendipity Ch 9-11
//--------------------------------------------------------
// Creators name and email: Kevin Nguyen, oggunderscore@gmail.com
// Creation Date: 9/14/19
// Date of Last Modification: 9/14/19
//--------------------------------------------------------//
// Purpose: This class displays the inventoryDatabaseModule.
//--------------------------------------------------------//
// Algorithm: 
// Prompt user for an input then execute module functions.
//--------------------------------------------------------//
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
// book           array of structs      null
// tbook          struct                null
//--------------------------------------------------------//


void editor(bookType *[], int x);


void resetTemps(bookType &tBook) {
	tBook.setTitle("EMPTY");
	tBook.setIsbn("EMPTY");
	tBook.setAuthor("EMPTY"); 
	tBook.setPublisher("EMPTY"); 
	tBook.setDateAdded(getDate());
	tBook.setQtyOnHand(0);
	tBook.setWholesale(0.0);
	tBook.setRetail(0.0);
}

void bookInfo(bookType *book[], int bookID) {
	cout << "\n\t\t\t\t\tSerendipity Booksellers\n\t\t\t\t\tBook Information\n" << endl;
	cout << "Title: " << book[bookID]->getTitle() << endl;
	cout << "ISBN: " << book[bookID]->getIsbn() << endl;
	cout << "Author: " << book[bookID]->getAuthor() << endl;
	cout << "Publisher: " << book[bookID]->getPublisher() << endl;
	cout << "Date Added: " << book[bookID]->getDateAdded() << endl;
	cout << "Quantity-On-Hand: " << book[bookID]->getQtyOnHand() << endl;
	cout << "Wholesale Cost: " << book[bookID]->getWholesale() << endl;
	cout << "Retail Cost: " << book[bookID]->getRetail() << endl;
	pause();
	clear();
}
size_t findCaseInsensitive(string data, string toSearch, size_t pos) {
	// Convert complete given String to lower case
	transform(data.begin(), data.end(), data.begin(), ::tolower);
	// Convert complete given Sub String to lower case
	transform(toSearch.begin(), toSearch.end(), toSearch.begin(), ::tolower);
	// Find sub string in given string
	return data.find(toSearch, pos);
}

int resultsType::amount = 0;


void executeFind(bookType *book[]) {
	bool exitExecuteFind = false;
	bool validInput;
	char selection;
	
	resultsType results[DBSIZE];//create table of results possible of 20 searches
	results[0].amount = 0;
	
	while (exitExecuteFind != true) {
		clear();
		validInput = false;
		cout << "\t\tSerendipity Booksellers\n\t\tInventory Database\n\n\t\t1. Look up a Book\n\t\t2. Add a Book\n\t\t3. Edit a Book's Record\n\t\t4. Delete a Book\n\t\t5. Return to Main Menu\n\n\t\tPlease type in your input: 1\n";
		int index = lookUpBook(book, results);
		if (index >= 0) {
			for (int x = 0; x < results[0].amount; x++) {
				if (exitExecuteFind != true) {
					validInput = false;
					do {
						if (validInput != true) {
							
							///////////
							/*
							resultsType results[DBSIZE]; //create table of results possible of 20 searches
							results[0].amount = 0;
							
							*/
							
							
							clear();
							cout << endl;
							for (int y = 0; y < results[0].amount; y++) {
								string selected = "   ";
								if (x == y) {
									selected = " > ";
								}
								cout << selected << "\"" << results[y].bookTitle << "\"" << endl;
							}
							
							
							cout << "\n\nWould you like to view the selected book? \nN = Next Selection\n\n\t(Y/N): ";
							
							
							
							cin >> selection;
							switch (selection) {
								case 'Y':
								case 'y':
									validInput = true;
									clear();
									bookInfo(book, results[x].index);
									exitExecuteFind = true;
									break;
								case 'N':
								case 'n':
									validInput = true;
									if (x == results[0].amount - 1)
										exitExecuteFind = true;
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
		} else {
			do {
				if (validInput != true) {
					cout << "Error: Could not find Book by Title / ISBN. Try again? (Y/N): ";
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
							exitExecuteFind = true;
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
}


int lookUpBook(bookType *book[], resultsType results[]) { 
	results[0].amount = 0;
	string search;
	cout << "\nSearch: ";
	cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
	getline(cin, search);
	
	
	for (int x = 0; x < book[0]->getBookCount(); x++) {
		size_t found = findCaseInsensitive(book[x]->getTitle(), search, 0);
		if (found != string::npos) {
			string title = book[x]->getTitle();
			results[results[0].amount].bookTitle = title; // CRASH
			cout << "OOF!" << endl;
			results[results[0].amount].index = x;
			results[0].amount += 1;
		} else { 
			for (int x = 0; x < book[0]->getBookCount(); x++) {
				found = book[x]->getIsbn().find(search);
				if (found != string::npos) {
					results[results[0].amount].bookTitle = book[x]->getTitle();
					results[results[0].amount].index = x;
					results[0].amount += 1;
				}
			}
		}
	}
	if (results[0].amount == 0) {
		return (-1);
	} else {
		return 0;
	}
}

void addBook(bookType *book[]) {
	bookType tBook;
	resetTemps(tBook);
	bool exitAddBook = false;
	while (exitAddBook != true) {
		clear();
		
		if (book[0]->getBookCount() >= DBSIZE) {
			cout << "Database is full! Please delete some books to proceed! (" << book[0]->getBookCount() << "/" << DBSIZE << ")\n";
			pause();
			clear();
			exitAddBook = true;
		} else {
			bool validInput;
			char selection;
			string temp;
			int tempInt;
			double tempDouble;
			do {
				cout << fixed;
				cout.precision(2);
				cout << "*************************************************************\n\t\tSerendipity Booksellers\n\t\t\tAdd Book Menu\n\n\tCurrent Database Size: " << book[0]->getBookCount() << "/" << DBSIZE << "\n" << endl;
				cout << "\t\t\t\t\t+ Pending Values +" << endl;
				cout << "(1) Enter Book Title\t\t\t >   --" << tBook.getTitle() << endl;
				cout << "(2) Enter ISBN\t\t\t\t >   --" << tBook.getIsbn() << endl;
				cout << "(3) Enter Author\t\t\t >   --" << tBook.getAuthor() << endl;
				cout << "(4) Enter Publisher\t\t\t >   --" << tBook.getPublisher() << endl;
				cout << "(5) Enter Date Added\t\t\t >   --" << tBook.getDateAdded() << endl;
				cout << "(6) Enter Quantity on Hand\t\t >   --" << tBook.getQtyOnHand() << endl;
				cout << "(7) Enter Wholesale Cost\t\t >   --$" << tBook.getWholesale() << endl;
				cout << "(8) Enter Retail Price\t\t\t >   --$" << tBook.getRetail() << endl;
				cout << "(9) Save Book to Database\t" << endl;
				cout << "(0) Return to Inventory Menu" << endl;
				cout << "\n*************************************************************\n\tChoice (0-9): ";
				cin >> selection;
				validInput = true;
				switch(selection) {
					case '1':
						validInput = true;
						clear();
						cout << "*************************************************************\n\tInput Book Title: ";
						cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
						getline(cin, temp);
						tBook.setTitle(temp);
						break;
					case '2':
						validInput = true;
						clear();
						cout << "*************************************************************\n\tInput ISBN: ";
						cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
						getline(cin, temp);
						tBook.setIsbn(temp);
						break;
					case '3':
						validInput = true;
						clear();
						cout << "*************************************************************\n\tInput Author: ";
						cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
						getline(cin, temp);
						tBook.setAuthor(temp);
						break;
					case '4':
						validInput = true;
						clear();
						cout << "*************************************************************\n\tInput Publisher: ";
						cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
						getline(cin, temp);
						tBook.setPublisher(temp);
						break;
					case '5':
						validInput = true;
						clear();
						cout << "*************************************************************\n\tInput Date: ";
						cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
						getline(cin, temp);
						tBook.setDateAdded(temp);
						break;
					case '6':
						validInput = true;
						clear();
						cout << "*************************************************************\n\tInput Quantity on Hand: ";
						cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
						cin >> tempInt;
						tBook.setQtyOnHand(tempInt);
						break;
					case '7':
						validInput = true;
						clear();
						cout << "*************************************************************\n\tInput Wholesale Cost: ";
						cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
						cin >> tempDouble;
						tBook.setWholesale(tempDouble);
						break;
					case '8':
						validInput = true;
						clear();
						cout << "*************************************************************\n\tInput Retail Price: ";
						cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
						cin >> tempDouble;
						tBook.setRetail(tempDouble);
						break;
					case '9':
						validInput = true;
						clear();
						
						//SAVING CODE
						
						book[book[0]->getBookCount()] = new bookType();
						book[book[0]->getBookCount()]->setAll(tBook.getTitle(), tBook.getIsbn(), tBook.getAuthor(), tBook.getPublisher(), tBook.getQtyOnHand(), tBook.getWholesale(), tBook.getRetail());
						book[book[0]->getBookCount()]->setDateAdded(tBook.getDateAdded());
						/*
						book[book[0].getBookCount()].setTitle(tBook.getTitle());
						book[book[0].getBookCount()].setIsbn(tBook.getIsbn());
						book[book[0].getBookCount()].setAuthor(tBook.getAuthor());
						book[book[0].getBookCount()].setPublisher(tBook.getPublisher());
						book[book[0].getBookCount()].setDateAdded(tBook.getDateAdded());
						book[book[0].getBookCount()].setQtyOnHand(tBook.getQtyOnHand());
						book[book[0].getBookCount()].setWholesale(tBook.getWholesale());
						book[book[0].getBookCount()].setRetail(tBook.getRetail());
						*/
						
						book[0]->incBookCount();
						cout << "Save was successful. Database: (" << book[0]->getBookCount() << "/" << DBSIZE << ")";
						cout << endl;
						resetTemps(tBook);
						clear();
						cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
						break;
					case '0':
						validInput = true;
						clear();
						resetTemps(tBook);
						exitAddBook = true;
						break;
					default:
						validInput = false;
						clear(); 
						cout << "\nPlease enter a valid selection!\n";
						break;
				}	
			} while (validInput == false);
		}
		clear();
	}
}

void editBook(bookType *book[]) {
	bool exitEditBook = false;
	bool validInput;
	char selection;
	
	
	
	resultsType results[DBSIZE]; //create table of results possible of 20 searches
	results[0].amount = 0;
	
	
	
	while (exitEditBook != true) {
		clear();
		validInput = false;
		cout << "\t\tSerendipity Booksellers\n\t\tInventory Database\n\n\t\t1. Look up a Book\n\t\t2. Add a Book\n\t\t3. Edit a Book's Record\n\t\t4. Delete a Book\n\t\t5. Return to Main Menu\n\n\t\tPlease type in your input: 3\n"; 
		int index = lookUpBook(book, results);
		
		if (index >= 0) {
			for (int x = 0; x < results[0].amount; x++) {
				if (exitEditBook != true) {
					validInput = false;
					do {
						if (validInput != true) {
							clear();
							cout << endl;
							for (int y = 0; y < results[0].amount; y++) {
								string selected = "   ";
								if (x == y) {
									selected = " > ";
								}
								cout << selected << "\"" << results[y].bookTitle << "\"" << endl;
							}
							
							
							cout << "\n\nWould you like to edit the selected book? \nN = Next Selection\n\n\t(Y/N): ";
							
							
							
							cin >> selection;
							switch (selection) {
								case 'Y':
								case 'y':
									validInput = true;
									editor(book, results[x].index);
									exitEditBook = true;
									break;
								case 'N':
								case 'n':
									validInput = true;
									if (x == results[0].amount - 1)
										exitEditBook = true;
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
		} else {
			do {
				if (validInput != true) {
					cout << "Error: Could not find Book by Title / ISBN. Try again? (Y/N): ";
					cin >> selection;
					switch (selection) {
						case 'Y':
						case 'y':
							validInput = true;
							break;
						case 'N':
						case 'n':
							validInput = true;
							exitEditBook = true;
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
}



void deleteBook(bookType *book[]) {
	bool exitDeleteBook = false;
	bool validInput = false;
	char selection;
	
	resultsType results[DBSIZE]; //create table of results possible of 20 searches
	results[0].amount = 0;
	
	
	while (exitDeleteBook != true) {
		clear();
		validInput = false;
		cout << "\t\tSerendipity Booksellers\n\t\tInventory Database\n\n\t\t1. Look up a Book\n\t\t2. Add a Book\n\t\t3. Edit a Book's Record\n\t\t4. Delete a Book\n\t\t5. Return to Main Menu\n\n\t\tPlease type in your input: 4\n"; 
		int index = lookUpBook(book, results);
		
		if (index >= 0) {
			for (int x = 0; x < results[0].amount; x++) {
				if (exitDeleteBook != true) {
					validInput = false;
					do {
						if (validInput != true) {
							clear();
							cout << endl;
							for (int y = 0; y < results[0].amount; y++) {
								string selected = "   ";
								if (x == y) {
									selected = " > ";
								}
								cout << selected << "\"" << results[y].bookTitle << "\"" << endl;
							}
							cout << "\n\nWould you like to delete the selected book? \nN = Next Selection\n\n\t(Y/N): ";
							cin >> selection;
							switch (selection) {
								case 'Y':
								case 'y':
									validInput = true;
									removeBook(book, results[x].index);
									cout << "Database: (" << book[0]->getBookCount() << "/" << DBSIZE << ")" << endl;
									cout << endl;
									pause();
									exitDeleteBook = true;
									break;
								case 'N':
								case 'n':
									validInput = true;
									if (x == results[0].amount - 1)
										exitDeleteBook = true;
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
		} else {
			do {
				if (validInput != true) {
					cout << "Error: Could not find Book by Title / ISBN. Try again? (Y/N): ";
					cin >> selection;
					switch (selection) {
						case 'Y':
						case 'y':
							validInput = true;
							break;
						case 'N':
						case 'n':
							validInput = true;
							exitDeleteBook = true;
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
}

void printDatabase(bookType *book[]) {
	clear();
	cout << "\t\t\t\t\t\t\t\t----------- Database Table -----------\n" << endl;
	cout << "ID\t\t\t\t\t\t\t\t\t\t\t\t\tTitle\t\t\tISBN\t\tAuthor\t\tPublisher\tDate\tQty\tWholesale Retail\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int x = 0; x < book[0]->getBookCount(); x++) {
		cout << x << "\t" << setw(76) << book[x]->getTitle() << "\t" << setw(12) << book[x]->getIsbn() << "\t" << setw(12) << book[x]->getAuthor() << "\t" << setw(12) << book[x]->getPublisher() << "\t" << setw(12) << book[x]->getDateAdded() << "\t" << book[x]->getQtyOnHand() << "\t" << book[x]->getWholesale() << "\t" << book[x]->getRetail() << endl;
	}
	cout << endl;
	pause();
}



void inventoryDatabaseModule(bookType *book[]) {
	bool exitInventoryModule = false;
	do {
		char selection;
		bool validInput;
		clear();
		do {
			cout << "\t\tSerendipity Booksellers\n\t\tInventory Database\n\n\t\t1. Look up a Book\n\t\t2. Add a Book\n\t\t3. Edit a Book's Record\n\t\t4. Delete a Book\n\t\t5. Return to Main Menu\n\n\t\tPlease type in your input: "; 
			cin >> selection;
				validInput = true;
				switch(selection) {
					case '1':
						validInput = true;
						executeFind(book);
						break;
					case '2':
						validInput = true;
						addBook(book);
						break;
					case '3':
						validInput = true;
						editBook(book);
						break;
					case '4':
						validInput = true;
						deleteBook(book);
						break;
					case '5':
						validInput = true;
						exitInventoryModule = true;
						break;
					case '6':
						validInput = true;
						printDatabase(book);
						break;
					default:
						validInput = false;
						clear(); 
						cout << "\nPlease enter a valid selection!\n";
						break;
			}			
		} while (validInput == false);
	} while (exitInventoryModule != true); 
}

void removeBook(bookType *book[], int x) {
	clear();
	int finalBook = x;
	cout << "Book \"" << book[x]->getTitle() << "\" has been deleted." << endl;
	for (int y = x; y < DBSIZE-1; y++){
		book[y]->setTitle(book[y+1]->getTitle());
		book[y]->setIsbn(book[y+1]->getIsbn());
		book[y]->setAuthor(book[y+1]->getAuthor());
		book[y]->setPublisher(book[y+1]->getPublisher());
		book[y]->setDateAdded(book[y+1]->getDateAdded());
		book[y]->setQtyOnHand(book[y+1]->getQtyOnHand());
		book[y]->setWholesale(book[y+1]->getWholesale());
		book[y]->setRetail(book[y+1]->getRetail());
		finalBook++;
	}
	delete book[finalBook];
	book[0]->decBookCount();
}

void editor(bookType *book[], int x) {
	bool exitEditor = false;
	bookType tBook;
	tBook.setTitle(book[x]->getTitle());
	tBook.setIsbn(book[x]->getIsbn());
	tBook.setAuthor(book[x]->getAuthor());
	tBook.setPublisher(book[x]->getPublisher());
	tBook.setDateAdded(book[x]->getDateAdded());
	tBook.setQtyOnHand(book[x]->getQtyOnHand());
	tBook.setWholesale(book[x]->getWholesale());
	tBook.setRetail(book[x]->getRetail());
	while (exitEditor != true) {
		clear();
		bool validInput;
		char selection;
		string temp;
		int tempInt;
		double tempDouble;
		do {
			cout << fixed;
			cout.precision(2);
			cout << "*************************************************************\n\t\tSerendipity Booksellers\n\t\t\tBook Editor Menu\n\n\tCurrent Database Size: " << book[0]->getBookCount() << "/" << DBSIZE << "\n" << endl;
			cout << "\t\t\t\t\t+ Pending Values +" << endl;
			cout << "(1) Enter Book Title\t\t\t >   --" << tBook.getTitle() << endl;
			cout << "(2) Enter ISBN\t\t\t\t >   --" << tBook.getIsbn() << endl;
			cout << "(3) Enter Author\t\t\t >   --" << tBook.getAuthor() << endl;
			cout << "(4) Enter Publisher\t\t\t >   --" << tBook.getPublisher() << endl;
			cout << "(5) Enter Date Added\t\t\t >   --" << tBook.getDateAdded() << endl;
			cout << "(6) Enter Quantity on Hand\t\t >   --" << tBook.getQtyOnHand() << endl;
			cout << "(7) Enter Wholesale Cost\t\t >   --$" << tBook.getWholesale() << endl;
			cout << "(8) Enter Retail Price\t\t\t >   --$" << tBook.getRetail() << endl;
			cout << "(9) Save Book to Database\t" << endl;
			cout << "(0) Return to Inventory Menu" << endl;
			cout << "\n*************************************************************\n\tChoice (0-9): ";
			cin >> selection;
			validInput = true;
			switch(selection) {
				case '1':
					validInput = true;
					clear();
					cout << "*************************************************************\n\tInput Book Title: ";
					cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
					getline(cin, temp);
					tBook.setTitle(temp);
					break;
				case '2':
					validInput = true;
					clear();
					cout << "*************************************************************\n\tInput ISBN: ";
					cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
					getline(cin, temp);
					tBook.setIsbn(temp);
					break;
				case '3':
					validInput = true;
					clear();
					cout << "*************************************************************\n\tInput Author: ";
					cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
					getline(cin, temp);
					tBook.setAuthor(temp);
					break;
				case '4':
					validInput = true;
					clear();
					cout << "*************************************************************\n\tInput Publisher: ";
					cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
					getline(cin, temp);
					tBook.setPublisher(temp);
					break;
				case '5':
					validInput = true;
					clear();
					cout << "*************************************************************\n\tInput Date: ";
					cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
					getline(cin, temp);
					tBook.setDateAdded(temp);
					break;
				case '6':
					validInput = true;
					clear();
					cout << "*************************************************************\n\tInput Quantity on Hand: ";
					cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
					cin >> tempInt;
					tBook.setQtyOnHand(tempInt);
					break;
				case '7':
					validInput = true;
					clear();
					cout << "*************************************************************\n\tInput Wholesale Cost: ";
					cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
					cin >> tempDouble;
					tBook.setWholesale(tempDouble);
					break;
				case '8':
					validInput = true;
					clear();
					cout << "*************************************************************\n\tInput Retail Price: ";
					cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear input buffer from previous text.
					cin >> tempDouble;
					tBook.setRetail(tempDouble);
					break;
				case '9':
					validInput = true;
					clear();
					
					//SAVING CODE
					book[book[0]->getBookCount()] = new bookType();
					book[book[0]->getBookCount()]->setAll(tBook.getTitle(), tBook.getIsbn(), tBook.getAuthor(), tBook.getPublisher(), tBook.getQtyOnHand(), tBook.getWholesale(), tBook.getRetail());
					book[book[0]->getBookCount()]->setDateAdded(tBook.getDateAdded());

					
					/*
					book[x]->setTitle(tBook.getTitle());
					book[x]->setIsbn(tBook.getIsbn());
					book[x]->setAuthor(tBook.getAuthor());
					book[x]->setPublisher(tBook.getPublisher());
					book[x]->setDateAdded(tBook.getDateAdded());
					book[x]->setQtyOnHand(tBook.getQtyOnHand());
					book[x]->setWholesale(tBook.getWholesale());
					book[x]->setRetail(tBook.getRetail());
					*/
					
					cout << "Edit was successful. Database: (" << book[0]->getBookCount() << "/" << DBSIZE << ")";
					cout << endl;
					resetTemps(tBook);
					pause();
					clear();
					break;
				case '0':
					validInput = true;
					clear();
					resetTemps(tBook);
					exitEditor = true;
					break;
				default:
					validInput = false;
					clear(); 
					cout << "\nPlease enter a valid selection!\n";
					break;
			}	
		} while (validInput == false);
	}
}