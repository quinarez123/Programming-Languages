#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstring>
#include <string.h>
using namespace std;

#include "GroceryStore.h"

// This function will display the menu options that are available to the user.
void GroceryStore::printMenu() const {
	cout << "PLEASE ENTER A MENU OPTION TO CONTINUE" << endl;
	cout << endl;
	cout << "Option 1: Enter a word that you are looking for" << endl;
	cout << endl;
	cout << "Option 2: Print list along with frequency" << endl;
	cout << endl;
	cout << "Option 3: Print list along with frequency in histogram format" << endl;
	cout << endl;
	cout << "Option 4: Exit Program" << endl;
}



// Menu option 1 will prompt the user to input an item that they are looking for and display the item name and the frequency next to it.
void GroceryStore::menuOption1() {
	// Opens the input file.
	groceryFS.open("groceryInput.txt");
	cout << "Please enter name of item that you are looking for" << endl;
	// Validated user by always changing first letter to uppercase to match input file's case.
	cin >> searchItem;
	searchItem[0] = toupper(searchItem[0]);
	
	
	// WHILE loop will read through all of the input file and if and item equals the user's inputted item then the frequency value will be incremented.
	while (!groceryFS.eof()) {
		groceryFS >> groceryItem;
		if (searchItem == groceryItem) {
			++frequencyValue;
		}
	}
	// Once file is fully read the item and frequency value will be displayed if it is more than 0 else it will print a message saying that item was not sold today.
	if (frequencyValue == 0) {
		cout << "***That item was not sold today***" << endl;
		cout << endl;
	}
	
	else {
		cout << searchItem << " " << frequencyValue << endl;
	}
	// Closes the input file
	cin.ignore();
	groceryFS.close();
}


// Menu option 2 will compare elements from vector(inventory) to duplicate items in the input file
void GroceryStore::menuOption2() {
	groceryFS.open("groceryInput.txt");
	// Opens output file "frequency.dat" in order to write to that file.
	outFS.open("frequency.dat");
	cout << "Here is the list of all items and frequency" << endl;
	// will store item to groceryItem(temporary value) then if item is not already in inventory vector then it will be pushed back unless it's already in vector then it will be ignored for now.(no duplicate vector)
	while (!groceryFS.eof()) {
		groceryFS >> groceryItem;
		if (find(inventory.begin(), inventory.end(), groceryItem) != inventory.end()) {
			groceryItem.clear();
		}
		else {
			inventory.push_back(groceryItem);
		}
	}
	// Close and open input file. Not sure if this is necessary but since I'm reading through input file again I wanted to make sure it went smoothly.
	groceryFS.close();
	groceryFS.open("groceryInput.txt");

	// This for loop will iterate through each item in the non duplicate vector(inventory) and each element will be compared against all the items in the input file and if it matches then the frequency value will be incremented.
	for (i = 0; i < inventory.size(); i++) {
		while (!groceryFS.eof()) {
			groceryFS >> tempItem;
			if (inventory.at(i) == tempItem) {
				++frequencyValue;
				tempItem.clear();
			}
			else {
				tempItem.clear();
			}
		}
		// Once it reached the end of the input file then the item and frequency value will be displayed on screen and will be written to an output file "frequency.dat"
		// frequency value will be reset to 0 in order to be used in the next iteration.
		cout << inventory.at(i) << " " << frequencyValue << endl;
		outFS << inventory.at(i) << " " << frequencyValue << endl;
		groceryFS.close();
		groceryFS.open("groceryInput.txt");
		frequencyValue = 0;
		
		// This concludes the full element iteration.
	}
	groceryFS.close();
	outFS.close();
	cout << endl;
	cout << endl;
}



// Menu option 3 is the same as menu option 2 except instead of an integer value being displayed. Several special characters will be displayed depending on the frequency value.
void GroceryStore::menuOption3() {
	groceryFS.open("groceryInput.txt");
	outFS.open("frequency.dat");
	cout << "Here is the list of all items and frequency" << endl;
	while (!groceryFS.fail()) {
		groceryFS >> groceryItem;
		if (find(inventory.begin(), inventory.end(), groceryItem) != inventory.end()) {
			groceryItem.clear();
		}
		else {
			inventory.push_back(groceryItem);
		}
	}

	groceryFS.close();
	groceryFS.open("groceryInput.txt");

	for (i = 0; i < inventory.size(); i++) {
		while (!groceryFS.eof()) {
			groceryFS >> tempItem;
			if (inventory.at(i) == tempItem) {
				++frequencyValue;
				tempItem.clear();
			}
			else {
				tempItem.clear();
			}
		}
		
		cout << inventory.at(i) << " ";
		outFS << inventory.at(i) << " ";
		// FOR loop that will output the number of characters that will be displayed next to the item name to show the frequency
		for (j = 0; j < frequencyValue; ++j) {
			specialChar.push_back('*');
		}
		//FOR loop that will write the output from the previous for loop into "frequency.dat"
		for (j = 0; j < specialChar.size(); ++j) {
			outFS << specialChar.at(j);
			cout << specialChar.at(j);
		}
		outFS << endl;
		cout << endl;
		groceryFS.close();
		groceryFS.open("groceryInput.txt");
		frequencyValue = 0;
		specialChar.clear();
	}
	groceryFS.close();
	outFS.close();
	cout << endl;
	cout << endl;
}




// Menu option 4 just displays a message and terminates the program
int GroceryStore::menuOption4() {
	cout << "Program will now be terminated" << endl;
	return 0;
}
