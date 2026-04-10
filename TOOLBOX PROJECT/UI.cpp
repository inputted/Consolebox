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
	std::cout << Format::YELLOW << "Welcome to the Toolbox Project!\n\nMenu will appear shortly." << Format::RESET << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << Format::CLEAR;
	std::cout << Format::CYAN << "====== Main Menu ======\n" << Format::RESET;
	std::cout << Format::YELLOW << "+-----------------+\n" << Format::RESET;
	std::cout << Format::YELLOW << "| 1. Notes        |\n" << Format::RESET;
	std::cout << Format::YELLOW << "| 2. Calculator   |\n" << Format::RESET;
	std::cout << Format::YELLOW << "| 3. To-Do List   |\n" << Format::RESET;
	std::cout << Format::YELLOW << "| 4. Exit         |\n" << Format::RESET;
	std::cout << Format::YELLOW << "+-----------------+\n" << Format::RESET;
}

void displayCalculatorMenu() {
	std::cout << Format::CLEAR;
	std::cout << Format::CYAN << "====== Calculator ======\n" << Format::RESET;
	std::cout << "Type 'exit' to go back and 'c' to clear your history.\n";
}

std::string getCalcInput() {
	std::string final;
	std::cin >> final;
	return final;
}

int getMenuChoice() {
	int choice;
	std::cin >> choice;
	return choice;
}