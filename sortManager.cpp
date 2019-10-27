#include "serendipity.h"
#include "bookType.h"

void sortByQty(bookType *book[]) {
	bookType temp;
	int i, j, index;  
    for (i = 0; i < book[0]->getBookCount()-1; i++) {
        index = i;  
        for (j = i+1; j < book[0]->getBookCount(); j++)  
			if (book[j]->getQtyOnHand() > book[index]->getQtyOnHand()) {
				index = j;  
			}
		
		temp.setAll(book[index]->getTitle(), book[index]->getIsbn(), book[index]->getAuthor(), book[index]->getPublisher(), book[index]->getQtyOnHand(), book[index]->getWholesale(), book[index]->getRetail());
		temp.setDateAdded(book[index]->getDateAdded());
					
		book[index]->setAll(book[i]->getTitle(), book[i]->getIsbn(), book[i]->getAuthor(), book[i]->getPublisher(), book[i]->getQtyOnHand(), book[i]->getWholesale(), book[i]->getRetail());
		book[index]->setDateAdded(book[i]->getDateAdded());
					
		book[i]->setAll(temp.getTitle(), temp.getIsbn(), temp.getAuthor(), temp.getPublisher(), temp.getQtyOnHand(), temp.getWholesale(), temp.getRetail());
		book[i]->setDateAdded(temp.getDateAdded());
		

    } 
}