
#include <iostream>
#include "Clock.h"
#include "UI.h"

void openClock() {
	
	static bool running = true;
	while (running) {
		displayClockMenu();
		int choice = getIntInput();
		switch (choice) {
		case 1:
			std::cout << "Viewing clocks...\n";
			break;
		case 2:
			std::cout << "Adding clock...\n";
			break;
		case 3:
			std::cout << "Deleting clock...\n";
			break;
		case 4:
			running = false;
			displayMenu();
			break;
		default:
			std::cout << "Invalid choice. Please try again." << std::endl;
			break;
		}
	}
}