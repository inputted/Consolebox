
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <Windows.h>
#include <shellapi.h>
#include "Notes.h"
#include "UI.h"

void createNote();
void fetchNotes();
void deleteNote();
void importNote();

void openNotes() {
	bool running = true;
	displayNotesMenu(); // Displays its menu from the UI file
	while (running) {
		int choice = getIntInput();
		switch (choice) {
		case 1:
			createNote();
			break;
		case 2:
			fetchNotes();
			break;
		case 3:
			deleteNote();
			break;
		case 4:
			importNote();
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
	std::cin.ignore();
	std::getline(std::cin, noteTitle);
	std::ofstream noteFile("StoredNotes\\" + noteTitle + ".txt"); // StoredNotes is the subfolder where each note is stored locally
	if (noteFile.is_open()) {
		noteFile.close();
		std::cout << "Note created successfully!" << std::endl;
		// Instead of making my own editor, the program uses the users default text editor
		ShellExecuteA(NULL, "open", ("StoredNotes\\" + noteTitle + ".txt").c_str(), NULL, NULL, SW_SHOWDEFAULT);
	} else {
		std::cout << "Error creating note." << std::endl;
	}
}

void fetchNotes() {
	std::string quickNotesArray[10]; // Only fetches the first 10 notes
	int index = 0;

	std::cout << "\nStored Notes:\n";
	// The program loops the subfolder for the first 10 notes, and adds them to the array for quick access
	for (const auto& entry : std::filesystem::directory_iterator("StoredNotes")) {
		std::cout << index+1 << ". " << entry.path().filename().string() << std::endl;
		if (index < 10) {
			quickNotesArray[index] = entry.path().filename().string();
			index++;
		}
		else {
			break;
		}
	}
	// If the desired file is not in the quick access, the user can instead manually type the file name
	std::cout << "\nEnter the note number, type 20 to manually enter file name, and 0 to go back: ";
	int choice = getIntInput();
	if (choice == 20) {
		std::string fileName;
		std::cout << "Enter file name (excluding the .txt): ";
		std::cin >> fileName;
		ShellExecuteA(NULL, "open", ("StoredNotes\\" + fileName + ".txt").c_str(), NULL, NULL, SW_SHOWDEFAULT);
	}
	else if (choice == 0) {
		displayNotesMenu();
	}
	else if (choice > 0 && choice <= index) {
		ShellExecuteA(NULL, "open", ("StoredNotes\\" + quickNotesArray[choice - 1]).c_str(), NULL, NULL, SW_SHOWDEFAULT);
	} else{
		std::cout << "Invalid choice.\n" << std::endl;
	}
}

// This function deletes a note, given its name. Pretty self explanatory
void deleteNote() {
	std::string noteTitle;
	std::cout << "Enter the title of the note to delete: ";
	std::cin.ignore();
	std::getline(std::cin, noteTitle);
	if (std::filesystem::exists("StoredNotes\\" + noteTitle + ".txt")) {
		std::filesystem::remove("StoredNotes\\" + noteTitle + ".txt");
		std::cout << "Note deleted successfully!" << std::endl;
	}
	else {
		std::cout << "Note does not exist. Did you type the name correct? (do not include .txt)" << std::endl;
	}
}

// This function lets the user copy a note from another location to access within the program
void importNote() {
	std::string filePath;
	std::cout << "Enter the full path of the note to import: ";
	std::cin.ignore();
	std::getline(std::cin, filePath);
	if (std::filesystem::exists(filePath)) {
		std::filesystem::copy(filePath, "StoredNotes\\" + std::filesystem::path(filePath).filename().string());
		std::cout << "Note imported successfully!" << std::endl;
	} else {
		std::cout << "File does not exist. Please check the path and try again." << std::endl;
	}
}