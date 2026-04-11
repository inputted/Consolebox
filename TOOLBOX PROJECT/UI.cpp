#include <iostream>
#include <thread>
#include <chrono>
#include "UI.h"

namespace Format {
	const std::string RED = "\033[31m";
	const std::string GREEN = "\033[32m";
	const std::string YELLOW = "\033[33m";
	const std::string BLUE = "\033[34m";
	const std::string MAGENTA = "\033[35m";
	const std::string CYAN = "\033[36m";
	const std::string RESET = "\033[0m";
	const std::string REDBG = "\033[41m";
	const std::string GREENBG = "\033[42m";
	const std::string YELLOWBG = "\033[43m";
	const std::string BLUEBG = "\033[44m";
	const std::string BOLD = "\033[1m";
	const std::string UNDERLINE = "\033[4m";
	const std::string CLEAR = "\033[2J\033[H";
	void printColored(const std::string& text, const std::string& color) {
		std::cout << color << text << RESET << std::endl;
	}
}


void displayMenu() {
	std::cout << Format::CLEAR;
	std::cout << Format::CYAN << "====== Main Menu ======\n\n" << Format::RESET;
	std::cout << "Type only the function number to select it.\n";
	std::cout << Format::YELLOW << "+-----------------+\n" << Format::RESET;
	std::cout << Format::YELLOW << "|" << Format::GREEN << " 1. Notes        "<<Format::YELLOW<<"|\n" << Format::RESET;
	std::cout << Format::YELLOW << "|" << Format::CYAN << " 2. Calculator   "<<Format::YELLOW<<"|\n" << Format::RESET;
	std::cout << Format::YELLOW << "|" << Format::MAGENTA << " 3. To-Do List   "<<Format::YELLOW<<"|\n" << Format::RESET;
	std::cout << Format::YELLOW << "|" << Format::RESET << " 4. Clock        "<<Format::YELLOW<<"|\n" << Format::RESET;
	std::cout << Format::YELLOW << "|" << Format::BLUE << " 5. Weather      "<<Format::YELLOW<<"|\n" << Format::RESET;
	std::cout << Format::YELLOW << "|" << Format::RED << " 6. Exit         "<<Format::YELLOW<<"|\n" << Format::RESET;
	std::cout << Format::YELLOW << "+-----------------+\n" << Format::RESET;
}

void displayNotesMenu() {
	std::cout << Format::CLEAR;
	std::cout << Format::CYAN << "====== Notes Menu ======\n" << Format::RESET;
	std::cout << Format::YELLOW << "+-----------------+\n" << Format::RESET;
	std::cout << Format::YELLOW << "| 1. Create Note  |\n" << Format::RESET;
	std::cout << Format::YELLOW << "| 2. View Notes   |\n" << Format::RESET;
	std::cout << Format::YELLOW << "| 3. Delete Note  |\n" << Format::RESET;
	std::cout << Format::YELLOW << "| 4. Import Note  |\n" << Format::RESET;
	std::cout << Format::YELLOW << "| 5. Back to Main |\n" << Format::RESET;
	std::cout << Format::YELLOW << "+-----------------+\n" << Format::RESET;
}

int getMenuChoice() {
	int choice;
	std::cin >> choice;
	return choice;
}