// TOOLBOX PROJECT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Calculator.h"
#include "Notes.h"
#include "UI.h"


int main()
{
	displayMenu();
	bool running = true;

	while (running) {
		int choice = getMenuChoice();
		switch (choice) {
		case 1:
			openNotes();
			break;
		case 2:
			runCalculator();
			break;
		case 3:
			// Call to-do list function
			break;
		case 4:
			// Clock
			break;
		case 5:
			// Weather
			break;
		case 6:
			running = false;
			break;
		default:
			std::cout << "Invalid choice. Please try again." << std::endl;
			break;
		}
	}
}