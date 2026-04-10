
#include <string>
#include "Calculator.h"
#include "UI.h"


void runCalculator() {
	bool running = true;
	std::string userInput;
	displayCalculatorMenu();
	while (running) {
		userInput = getCalcInput();
		if (userInput == "exit") {
			running = false;
			displayMenu();
			break;
		}
	}
}