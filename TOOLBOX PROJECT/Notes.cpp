
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <shellapi.h>
#include "Notes.h"
#include "UI.h"

void createNote();

void openNotes() {
	bool running = true;
	displayNotesMenu();
	while (running) {
		int choice = getIntInput();
		switch (choice) {
		case 1:
			createNote();
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

void createNote() {
	std::string noteTitle;
	std::cout << "Enter note title: ";
	std::cin.ignore(); // Clear the input buffer
	std::getline(std::cin, noteTitle);
	std::ofstream noteFile("StoredNotes\\" + noteTitle + ".txt");
	if (noteFile.is_open()) {
		noteFile.close();
		std::cout << "Note created successfully!" << std::endl;
		ShellExecuteA(NULL, "open", ("StoredNotes\\" + noteTitle + ".txt").c_str(), NULL, NULL, SW_SHOWDEFAULT);
	} else {
		std::cout << "Error creating note." << std::endl;
	}
}