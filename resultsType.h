#ifndef resultsType_H
#define resultsType_H


class resultsType {
	public: 
		bookType book;
		int index;
		static int amount;
		
		void setBook(bookType book1) {
			book = book1;
		}
		
};

#endif