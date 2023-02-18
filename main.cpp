// Attempted to optimize and organize the code so the main program will look as clean as possible.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <sstream>
using namespace std;

#include "GroceryStore.h"


int main() {
	// Created grocery object of GroceryStore class
	GroceryStore grocery;
	string userInput;
	int menuInput = 0;
	stringstream ss;
	int i = 1;

	ss.exceptions(ios::failbit);
	
	grocery.printMenu();
	cout << endl;
	getline(cin, userInput);


	// While statement that is true until user inputs 4 then function will be executed and will break from loop
	while (menuInput != 4) {
		// Attempt at input validation. I tried to write a try-catch statement that will throw error to a catch all handler (...) just for simplification. 
		// If user enters a integer that is not within the options then it'll throw the error the the catch all handler
		// If user enters anything other than integer (ex. letters) then it'll throw the error to the catch all handler.
		try {
			ss.str("");
			ss.clear();
			ss << userInput;
			ss >> menuInput;

			if (menuInput < 1 || menuInput > 4) {
				throw runtime_error("Invalid option. Please try again");
			}
			cout << "You chose menu option: " << menuInput << endl;
			cout << endl;

			// Menu option 1
			if (menuInput == 1) {
				grocery.menuOption1();
			}
			// Menu option 2
			else if (menuInput == 2) {
				grocery.menuOption2();
			}
			// Menu option 3
			else if (menuInput == 3) {
				grocery.menuOption3();
			}
			// Menu option 4
			else if (menuInput == 4) {
				grocery.menuOption4();
				break;
			}
		}
		// Catch-all handler that'll execute if one of two errors are thrown.
		catch (...) {
			cout << "Not a valid option. Try again" << endl;
		}
		grocery.printMenu();
		cout << endl;
		getline(cin, userInput);
		ss.clear();
	}
	return 0;
}