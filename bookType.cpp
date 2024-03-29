#include "serendipity.h"
#include "bookType.h"


int bookType::bookCount = 0;

int bookType::sortType = 0;

void bookType::setSortType(int x) {
	sortType = x;
}

//Overloaders
bool bookType::operator<(bookType &otherBook) { 
	if (sortType == 0) {
		if (this->getQtyOnHand() < otherBook.getQtyOnHand())
			return true;
		else 
			return false;
	} else if (sortType == 1) {
		if (this->getWholesale() < otherBook.getWholesale())
			return true;
		else 
			return false;
	} else if (sortType == 2) {
				
		string date = this->getDateAdded();
		string month;
		string day;
		string year;
	
		month = date.substr(0, 2);
		day = date.substr(3, 2);
		year = date.substr(6, 4);
	
		int monthInt = stoi(month);
		int dayInt = stoi(day);
		int yearInt = stoi(year);
			
		string otherDate = otherBook.getDateAdded();
		
		month = otherDate.substr(0, 2);
		day = otherDate.substr(3, 2);
		year = otherDate.substr(6, 4);

		int otherMonthInt = stoi(month);
		int otherDayInt = stoi(day);
		int otherYearInt = stoi(year);
		
		bool result = false;
		
		int input = yearInt;
        int output = otherYearInt;

        if (input == output) {
            input = monthInt;
            output = otherMonthInt;
            if (input == output) {
                input = dayInt;
                output = otherDayInt;
                result = !(input < output);
            } else {
				result = !(input < output);
            }
        } else {
			result = !(input < output);
        }
	return result;
	}
}
bool bookType::operator<=(bookType *otherBook) { 
	if (this->getQtyOnHand() <= otherBook->getQtyOnHand())
		return true;
	else 
		return false;
}
bool bookType::operator>=(bookType *otherBook) { 
	if (this->getQtyOnHand() >= otherBook->getQtyOnHand())
		return true;
	else 
		return false;
}
bool bookType::operator==(bookType *otherBook) { 
	if (this->getQtyOnHand() == otherBook->getQtyOnHand())
		return true;
	else 
		return false;
}
bool bookType::operator!=(bookType *otherBook) { 
	if (this->getQtyOnHand() != otherBook->getQtyOnHand())
		return true;
	else 
		return false;
}





//Constructors
bookType::bookType() {
	title = "EMPTY";
	isbn = "EMPTY";
	author = "EMPTY"; 
	publisher = "EMPTY"; 
	dateAdded = getDate() + " (Auto)";
	qtyOnHand = 0;
	wholesale = 0.00;
	retail = 0.00;
}

bookType::bookType(string title1, string isbn1) { // Extra const?
	title = title1;
	isbn = isbn1;
	author = "EMPTY"; 
	publisher = "EMPTY"; 
	dateAdded = getDate() + " (Auto)";
	qtyOnHand = 0;
	wholesale = 0.00;
	retail = 0.00;
}

bookType::bookType(string title1, string isbn1, string author1, string publisher1, int qtyOnHand1, double wholesale1, double retail1) {
	title = title1;
	isbn = isbn1;
	author = author1; 
	publisher = publisher1; 
	dateAdded = getDate() + " (Auto)";
	qtyOnHand = qtyOnHand1;
	wholesale = wholesale1;
	retail = retail1;
}



//Setters

void bookType::setAll(string title1, string isbn1, string author1, string publisher1, int qtyOnHand1, double wholesale1, double retail1) {
	title = title1;
	isbn = isbn1;
	author = author1; 
	publisher = publisher1; 
	dateAdded = getDate() + " (Auto)";
	qtyOnHand = qtyOnHand1;
	wholesale = wholesale1;
	retail = retail1;
}
	
void bookType::setTitle(string title1) {
	title = title1;
}

void bookType::incBookCount() {
	bookCount++;
}
void bookType::decBookCount() {
	bookCount--;
}
	
void bookType::setIsbn(string isbn1) {
	isbn = isbn1;
}
	
void bookType::setAuthor(string author1) {
	author = author1;
}
	
void bookType::setPublisher(string publisher1) {
	publisher = publisher1;
}
	
void bookType::setDateAdded(string dateAdded1) {
	dateAdded = dateAdded1;
}
	
void bookType::setQtyOnHand(int qtyOnHand1) {
	qtyOnHand = qtyOnHand1;
}
	
void bookType::setWholesale(double wholesale1) {
	wholesale = wholesale1;
}
	
void bookType::setRetail(double retail1) {
	retail = retail1;
}
	

//Getters
string bookType::getTitle() {
	return title;
}
	
string bookType::getIsbn() {
	return isbn;
}
	
string bookType::getAuthor() {
	return author;
}
	
string bookType::getPublisher() {
	return publisher;
}
	
string bookType::getDateAdded() {
	return dateAdded;
}
	
int bookType::getQtyOnHand() {
	return qtyOnHand;
}
	
double bookType::getWholesale() {
	return wholesale;
}
	
double bookType::getRetail() {
	return retail;
}
int bookType::getBookCount() {
	return bookCount;
}

//Functs

bool bookType::equals(bookType *cmp) { // Can add more checks.
	if (getTitle() == cmp->getTitle() && getIsbn() == cmp->getIsbn() && getAuthor() == cmp->getAuthor()) { 
		return true;
	} else {
		return false;
	}
}

void bookType::print() {
	cout << "\n\t\t\t\t\tSerendipity Booksellers\n\t\t\t\t\tBook Information\n" << endl;
	cout << "Title: " << getTitle() << endl;
	cout << "ISBN: " << getIsbn() << endl;
	cout << "Author: " << getAuthor() << endl;
	cout << "Publisher: " << getPublisher() << endl;
	cout << "Date Added: " << getDateAdded() << endl;
	cout << "Quantity-On-Hand: " << getQtyOnHand() << endl;
	cout << "Wholesale Cost: " << getWholesale() << endl;
	cout << "Retail Cost: " << getRetail() << endl;
	pause();
	clears();
}


	