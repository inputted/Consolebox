
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include "ToDoList.h"
#include "UI.h"

bool initialImport = false;

struct Task {
	std::string title;
	std::string deadline;
	bool completed;
};

void createTask();
void viewTasks();
void deleteTask();

void openToDoList() {
	std::string upcomingTasks[3] = { "Task 1: ", "Task 2: ", "Task 3: " };
	displayToDoListMenu(upcomingTasks);
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
	std::getline(std::cin, title);
	std::cout << "Enter task deadline (YYYY-MM-DD) or type 0 for none: ";
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
		std::cout << "Enter a task number to toggle completion status, or 0 to return: ";

	} else {
		std::cout << "Error opening file!" << std::endl;
	}
}

void deleteTask() {
	std::cout << std::endl;
}