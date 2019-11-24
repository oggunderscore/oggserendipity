#ifndef bookType_H
#define bookType_H



class bookType {
	private: 
		string title, isbn, author, publisher, dateAdded;
		int qtyOnHand;
		static int bookCount;
		double wholesale, retail;
	public: 
	
		//Constructors
		bookType();
		bookType(string, string); // Extra const?
		bookType(string, string, string, string, int, double, double);
		
		//COPY
		bookType(bookType *book) : 
			title(book->title),
			isbn(book->isbn),
			author(book->author),
			publisher(book->publisher),
			dateAdded(book->dateAdded),
			qtyOnHand(book->qtyOnHand),
			wholesale(book->wholesale),
			retail(book->retail) { }

		//Setters
		void setAll(string, string, string, string, int, double, double);
		void setTitle(string);
		void setIsbn(string);
		void setAuthor(string);
		void setPublisher(string);
		void setDateAdded(string);
		void setQtyOnHand(int);
		void setWholesale(double);
		void setRetail(double);
		static void incBookCount();
		static void decBookCount();
		
		//Getters
		string getTitle();
		string getIsbn();
		string getAuthor();
		string getPublisher();
		string getDateAdded();
		int getQtyOnHand();
		double getWholesale();
		double getRetail();
		int getBookCount();
		
		//Overloaders
		bool operator<(bookType &);
		bool operator<=(bookType &);
		bool operator>=(bookType &);
		bool operator==(bookType &);
		bool operator!=(bookType &);
		
		//Functs
		bool equals(bookType *);
		void print();

};

#endif