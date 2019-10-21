#ifndef serendipity_H
#define serendipity_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ios>
#include <limits>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <sstream>
#include <ctype.h>
#include <algorithm>

//--------------------------------------------------------//
// File Name: serendipity.h
// Project name: Serendipity Ch 9-11
//--------------------------------------------------------
// Creators name and email: Kevin Nguyen, oggunderscore@gmail.com
// Creation Date: 9/14/19
// Date of Last Modification: 9/14/19
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

//short GetAsyncKeyState(int vKey);

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
string getDate();

const int DBSIZE = 20;


#endif