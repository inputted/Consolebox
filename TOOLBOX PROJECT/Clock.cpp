
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <ctime>
#include "Clock.h"
#include "UI.h"

void addClock();
void viewClocks();
void deleteClock();

void openClock() {
	viewClocks();
}

void viewClocks() {
	std::string line;
	std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::tm localTime;
	localtime_s(&localTime, &now);
	std::cout << "Local time :" << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S") << std::endl;
	std::cout << std::endl;
}

void addClock() {
	std::string name, timezone;
	std::cout << "Enter clock name: ";
	std::getline(std::cin, name);
	std::cout << "Enter time offset from UTC (e.g., +2, -5): ";
	std::getline(std::cin, timezone);
	if (timezone[0] != '+' && timezone[0] != '-') {
		std::cout << "Invalid timezone format. Please use + or - followed by the offset." << std::endl;
		return;
	}

	// Save clock to file
	std::ofstream outFile("Clocks.txt", std::ios::app);
	if (outFile.is_open()) {
		outFile << name << "|" << timezone << "\n";
		outFile.close();
		std::cout << "Clock added successfully!" << std::endl;
	}
	else {
		std::cout << "Error opening file!" << std::endl;
	}
}

void deleteClock() {
	// Read all lines into memory, remove the requested line, then overwrite the file.
	std::ifstream inFile("Clocks.txt");
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
		std::cout << "No clocks to delete." << std::endl;
		return;
	}
	// Show clocks with numbers
	for (size_t i = 0; i < lines.size(); ++i) {
		std::istringstream ss(lines[i]);
		std::string name, timezone;
		std::getline(ss, name, '|');
		std::getline(ss, timezone);
		std::cout << (i + 1) << ". " << name << " - UTC" << timezone << std::endl;
	}
	std::cout << "Enter clock number to delete: ";
	int clockNumber;
	if (!(std::cin >> clockNumber)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input." << std::endl;
		return;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (clockNumber < 1 || clockNumber > static_cast<int>(lines.size())) {
		std::cout << "Clock number out of range." << std::endl;
		return;
	}
	// Remove the selected line
	lines.erase(lines.begin() + (clockNumber - 1));
	// Overwrite the original file with remaining lines
	std::ofstream outFile("Clocks.txt", std::ios::trunc);
	if (!outFile.is_open()) {
		std::cout << "Error opening file!" << std::endl;
		return;
	}
	for (const auto& l : lines) {
		outFile << l << "\n";
	}
	outFile.close();
	std::cout << "Clock deleted successfully!" << std::endl;
}