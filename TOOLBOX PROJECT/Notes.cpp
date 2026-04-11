
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Notes.h"
#include "UI.h"



void openNotes() {
	bool running = true;
	displayNotesMenu();
	while (running) {
		int choice = getIntInput();
		switch (choice) {
		case 1:
			// Create note
			break;
		case 2:
			// View notes
			break;
		case 3:
			// Delete note
			break;
		case 4:
			// Import note
			break;
		case 5:
			running = false;
			displayMenu();
			break;
		default:
			std::cout << "Invalid choice. Please try again." << std::endl;
			break;
		}
	}
}