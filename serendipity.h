#ifndef serendipity_H
#define serendipity_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ios>
#include <limits>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <sstream>
#include <ctype.h>
#include <algorithm>
#include "windows.h"

//--------------------------------------------------------//
// File Name: serendipity.h
// Project name: Serendipity Overloading Sorting
//--------------------------------------------------------
// Creators name and email: Kevin Nguyen, oggunderscore@gmail.com
// Creation Date: 11/21/19
// Date of Last Modification: 11/21/19
//--------------------------------------------------------
// Purpose: Using a inputted key from a file, compare 
// and grade accordingly to the grading key, and 
// outputting results based on those inputs.
//--------------------------------------------------------
// Algorithm: 
// Using the first line of the text file provided, 
// input it as the grading key. Then gather the next 
// line of input. Split that into the students ID and 
// their answers. Then compare it to the key and grade it.
// And finally, output the score and data.
//--------------------------------------------------------
//                Data Dictionary
// Constants
// 
// Name           Data Type             Initial Value
// ----------     --------------        ------------------
// N/A 
// 
// Variables
// 
// Name           Data Type             Initial Value
// ----------     --------------        ------------------
// N/A 
//--------------------------------------------------------

using namespace std;

class bookType;
class resultsType;

size_t findCaseInsensitive(string data, string toSearch, size_t pos);
void cashierModule(bookType *[]);
void mainMenu(bookType *[]);
void inventoryDatabaseModule(bookType *[]);
void removeBook(bookType *[], int x);
void reportModule(bookType *[]);
void clears();
void pause();
int lookUpBook(bookType *[], resultsType []);

//Sorts
void sort(bookType *[], int);

string getDate();

const int DBSIZE = 20;


template <class U>
void selectionSort(U list[], const int length) {
	
	int index;
	int largestIndex;
	int location;
	U temp;

	unsigned long long int l = length;
	
	for (index = 0; index < length - 1; index++){
		//Step a
		largestIndex = index;
		
		for (location = index + 1; location < length; location++){
			
			if (*list[largestIndex] < *list[location])
				largestIndex = location;
		}
		//Step b

		temp = list[largestIndex];
		list[largestIndex] = list[index];
		list[index] = temp;
	}
}


#endif