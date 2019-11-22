#include "serendipity.h"
#include "bookType.h"

void sort(bookType *book[], int x) {
	bookType temp;
	int i, j, index;  
	
	
    for (i = 0; i < book[0]->getBookCount()-1; i++) {
        index = i;  
        for (j = i+1; j < book[0]->getBookCount(); j++) {
			
			
			if (x == 0) { //SORT BY QTY
				if (book[j]->getQtyOnHand() > book[index]->getQtyOnHand()) {
					index = j;  
				}
			} else if (x == 1) { //SORT BY COST
				if (book[j]->getWholesale() > book[index]->getWholesale()) {
					index = j;  
				}
			} else if (x == 2) { // SORT BY AGE
				//STORED AS MONTH
				
				string aDate = book[j]->getDateAdded();
				int aMonth = stoi(aDate.substr(0, 1));
				int aDay = stoi(aDate.substr(3, 4));
				int aYear = stoi(aDate.substr(6, 9));
				string bDate = book[i]->getDateAdded();
				int bMonth = stoi(bDate.substr(0, 1));
				int bDay = stoi(bDate.substr(3, 4));
				int bYear = stoi(bDate.substr(6, 9));
				if (bYear > aYear) {
					if (bMonth > aMonth) {
						if (bDay > aDay) {
							index = j;  
						}
					}
					
				}
			}
			
			
		
		temp.setAll(book[index]->getTitle(), book[index]->getIsbn(), book[index]->getAuthor(), book[index]->getPublisher(), book[index]->getQtyOnHand(), book[index]->getWholesale(), book[index]->getRetail());
		temp.setDateAdded(book[index]->getDateAdded());
					
		book[index]->setAll(book[i]->getTitle(), book[i]->getIsbn(), book[i]->getAuthor(), book[i]->getPublisher(), book[i]->getQtyOnHand(), book[i]->getWholesale(), book[i]->getRetail());
		book[index]->setDateAdded(book[i]->getDateAdded());
					
		book[i]->setAll(temp.getTitle(), temp.getIsbn(), temp.getAuthor(), temp.getPublisher(), temp.getQtyOnHand(), temp.getWholesale(), temp.getRetail());
		book[i]->setDateAdded(temp.getDateAdded());
		
		}
    } 
}