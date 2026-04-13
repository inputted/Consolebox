// Was originally going to be a calculator, but now a unit converter
#include <iostream>
#include <string>
#include <unordered_map>
#include "Calculator.h"
#include "UI.h"

double convertUnit(double value, const int& unitType, const std::string& fromUnit, const std::string& toUnit);

void openCalculator() {
	bool running = true;
	std::string userInput;
	displayUnitConvertMenu();
	while (running) {
		int choice = getIntInput();
		switch (choice) {
			case 1:
				// Time
				break;
			case 2:
				// Distance
				break;
			case 3:
				// Computer Storage
				break;
			case 4:
				// Weight
				break;
			case 5:
				running = false;
				displayMenu();
				break;
		}
	}
}


double convertUnit(double value, const int & unitType, const std::string& fromUnit, const std::string& toUnit) {
	// Time conversion factors in seconds
	static const std::unordered_map<std::string, double> timeUnits = {
		{"seconds", 1},
		{"minutes", 60},
		{"hours", 3600},
		{"days", 86400},
		{"weeks", 604800},
		{"months", 2628000}, // Month and year are averaged
		{"years", 31536000} 
	};
	static const std::unordered_map<std::string, double> lengthUnits = {
		{"meters", 1},
		{"kilometers", 1000},
		{"miles", 1609.34},
		{"feet", 0.3048},
		{"inches", 0.0254},
		{"centimeters", 0.01}
	};
	static const std::unordered_map<std::string, double> weightUnits = {
		{"grams", 1},
		{"kilograms", 1000},
		{"pounds", 453.592},
		{"ounces", 28.3495},
		{"tons", 907184.74}
	};
	static const std::unordered_map<std::string, double> computerStorageUnits = {
		{"bytes", 1},
		{"kilobytes", 1024},
		{"megabytes", 1048576},
		{"megabits", 131072},
		{"gigabytes", 1073741824},
		{"gigabits", 134217728},
		{"terabytes", 1099511627776},
		{"terabits", 137438953472}
	};


	if (timeUnits.find(fromUnit) == timeUnits.end() || timeUnits.find(toUnit) == timeUnits.end()) {
		std::cout << "Invalid time units. Supported units: seconds, minutes, hours, days." << std::endl;
		return -1;
	}
	else {
		double valueInSeconds = value * timeUnits.at(fromUnit);
		return valueInSeconds / timeUnits.at(toUnit);
	}
}
