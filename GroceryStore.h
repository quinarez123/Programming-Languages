#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstring>
using namespace std;
#ifndef GROCERYSTORE_H
#define GROCERYSTORE_H

class GroceryStore {
	// Set a these data members to private since we are only working with one class.
private:
	ifstream groceryFS;
	ofstream outFS;
	int frequencyValue = 0;
	string searchItem;
	string groceryItem;
	vector<string> inventory;
	int i = 0;
	string tempItem;
	int j = 0;
	vector<char> specialChar;
	// Member functions are usually set to public.
public:
	void printMenu() const;
	void menuOption1();
	void menuOption2();
	void menuOption3();
	int menuOption4();
};

#endif