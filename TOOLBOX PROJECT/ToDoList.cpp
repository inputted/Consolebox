
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include "ToDoList.h"
#include "UI.h"

bool initialImport = false;

void createTask();
void viewTasks();
void deleteTask();

void openToDoList() {
	displayToDoListMenu();
	bool running = true;
	while (running) {
		int choice = getIntInput();
		switch (choice) {
		case 1:
			createTask();
			break;
		case 2:
			viewTasks();
			break;
		case 3:
			deleteTask();
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

void createTask() {
	std::string title, deadline;
	bool validDeadline = false;
	std::cout << "Enter task title: ";
	std::cin.ignore();
	std::getline(std::cin, title);
	std::cout << "Enter task deadline (YYYY-MM-DD) or type 0 for none: ";
	// Checks validity of the deadline input
	while (!validDeadline) {
		std::getline(std::cin, deadline);
		if (deadline == "0") {
			deadline = "No deadline";
			validDeadline = true;
		} else {
			std::tm tm = {};
			std::istringstream ss(deadline);
			ss >> std::get_time(&tm, "%Y-%m-%d");
			if (ss.fail()) {
				std::cout << "Invalid date format. Please enter in YYYY-MM-DD format or type 0 for none: ";
			} else {
				validDeadline = true;
			}
		}
	}
	std::ofstream outFile("ToDoList.txt", std::ios::app);
	if (outFile.is_open()) {
		outFile << title << "|" << deadline << "|0\n";
		outFile.close();
		std::cout << "Task created successfully!" << std::endl;
	} else {
		std::cout << "Error opening file!" << std::endl;
	}
}

void viewTasks() {
	std::ifstream inFile("ToDoList.txt");
	if (inFile.is_open()) {
		std::string line;
		int taskNumber = 1;
		// Check if file is empty
		if (!std::getline(inFile, line)) {
			std::cout << "No tasks to view." << std::endl;
			inFile.close();
			return;
		}
		// Grabs each bit of information to be formatted in the output
		while (std::getline(inFile, line)) {
			std::istringstream ss(line);
			std::string title, deadline, completedStr;
			std::getline(ss, title, '|');
			std::getline(ss, deadline, '|');
			std::getline(ss, completedStr);
			bool completed = (completedStr == "1");
			std::cout << taskNumber << ". " << title << " - Deadline: " << deadline << " - " << (completed ? "Completed" : "Not Completed") << std::endl;
			taskNumber++;
		}
		inFile.close();
		std::cout << std::endl;
	} else {
		std::cout << "Error opening file!" << std::endl;
	}
}

void deleteTask() {
	// Read all lines into memory, remove the requested line, then overwrite the file.
	std::ifstream inFile("ToDoList.txt");
	if (!inFile.is_open()) {
		std::cout << "Error opening file!" << std::endl;
		return;
	}

	std::vector<std::string> lines;
	std::string line;
	while (std::getline(inFile, line)) {
		lines.push_back(line);
	}
	inFile.close();

	if (lines.empty()) {
		std::cout << "No tasks to delete." << std::endl;
		return;
	}

	// Show tasks with numbers
	for (size_t i = 0; i < lines.size(); ++i) {
		std::istringstream ss(lines[i]);
		std::string title, deadline, completedStr;
		std::getline(ss, title, '|');
		std::getline(ss, deadline, '|');
		std::getline(ss, completedStr);
		bool completed = (completedStr == "1");
		std::cout << (i + 1) << ". " << title << " - Deadline: " << deadline << " - " << (completed ? "Completed" : "Not Completed") << std::endl;
	}

	std::cout << "Enter task number to delete: ";
	int taskNumber;
	if (!(std::cin >> taskNumber)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input." << std::endl;
		return;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (taskNumber < 1 || taskNumber > static_cast<int>(lines.size())) {
		std::cout << "Task number out of range." << std::endl;
		return;
	}

	// Remove the selected line
	lines.erase(lines.begin() + (taskNumber - 1));

	// Overwrite the original file with remaining lines
	std::ofstream outFile("ToDoList.txt", std::ios::trunc);
	if (!outFile.is_open()) {
		std::cout << "Error writing to file!" << std::endl;
		return;
	}
	for (const auto& l : lines) {
		outFile << l << '\n';
	}
	outFile.close();

	std::cout << "Task deleted successfully." << std::endl;
}