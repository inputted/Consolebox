// TOOLBOX PROJECT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Calculator.h"
#include "Notes.h"
#include "ToDoList.h"
#include "Clock.h"
#include "UI.h"


int main()
{
	displayMenu();
	bool running = true;
	while (running) { // Switch statement used for navigation, persistent across all menus
		int choice = getIntInput();
		switch (choice) {
		case 1:
			openNotes();
			break;
		case 2:
			openCalculator();
			break;
		case 3:
			openToDoList();
			break;
		case 4:
			openClock();
			break;
		case 5:
			running = false;
			break;
		default:
			std::cout << "Invalid choice. Please try again." << std::endl;
			break;
		}
	}
	return 0;
}