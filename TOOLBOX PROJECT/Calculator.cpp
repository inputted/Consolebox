// Was originally going to be a calculator, but now a unit converter
#include <iostream>
#include <string>
#include <unordered_map>
#include "Calculator.h"
#include "UI.h"

double convertUnit(double value, const int& unitType, const std::string& fromUnit, const std::string& toUnit);
void inputUnits(double& value, std::string& fromUnit, std::string& toUnit);

void openCalculator() {
	bool running = true;
	std::string userInput;
	displayUnitConvertMenu();
	while (running) {
		int choice = getIntInput();
		double userValue;
		std::string fromUnit, toUnit;
		double convertedValue;
		switch (choice) {
			case 1:
				std::cout << "\n\n Convert from the following units: seconds, minutes, hours, days, weeks, months, years" << std::endl;
				inputUnits(userValue, fromUnit, toUnit);
				convertedValue = convertUnit(userValue, 1, fromUnit, toUnit);
				if (convertedValue != -1) {
					std::cout << userValue << " " << fromUnit << " is equal to " << convertedValue << " " << toUnit << std::endl;
				}
				break;
			case 2:
				std::cout << "\n\n Convert from the following units: meters, kilometers, miles, feet, inches, centimeters" << std::endl;
				inputUnits(userValue, fromUnit, toUnit);
				convertedValue = convertUnit(userValue, 2, fromUnit, toUnit);
				if (convertedValue != -1) {
					std::cout << userValue << " " << fromUnit << " is equal to " << convertedValue << " " << toUnit << std::endl;
				}
				break;
			case 3:
				std::cout << "\n\n Convert from the following units: bytes, kilobytes, megabytes, megabits, gigabytes, gigabits, terabytes, terabits" << std::endl;
				inputUnits(userValue, fromUnit, toUnit);
				convertedValue = convertUnit(userValue, 3, fromUnit, toUnit);
				if (convertedValue != -1) {
					std::cout << userValue << " " << fromUnit << " is equal to " << convertedValue << " " << toUnit << std::endl;
				}
				break;
			case 4:
				std::cout << "\n\n Convert from the following units: grams, kilograms, pounds, ounces, tons" << std::endl;
				inputUnits(userValue, fromUnit, toUnit);
				convertedValue = convertUnit(userValue, 4, fromUnit, toUnit);
				if (convertedValue != -1) {
					std::cout << userValue << " " << fromUnit << " is equal to " << convertedValue << " " << toUnit << std::endl;
				}
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

	switch (unitType) {
		double convertedValue;
		case 1: // Time
			if (timeUnits.find(fromUnit) == timeUnits.end() || timeUnits.find(toUnit) == timeUnits.end()) {
				std::cout << "Invalid time units. Supported units: seconds, minutes, hours, days." << std::endl;
				return -1;
			}
			convertedValue = value * timeUnits.at(fromUnit);
			return convertedValue / timeUnits.at(toUnit);
			break;
		case 2: // Distance
			if (lengthUnits.find(fromUnit) == lengthUnits.end() || lengthUnits.find(toUnit) == lengthUnits.end()) {
				std::cout << "Invalid distance units. Supported units: meters, kilometers, miles, feet, inches, centimeters." << std::endl;
				return -1;
			}
			convertedValue = value * lengthUnits.at(fromUnit);
			return convertedValue / lengthUnits.at(toUnit);
			break;
		case 3: // Computer Storage
			if (computerStorageUnits.find(fromUnit) == computerStorageUnits.end() || computerStorageUnits.find(toUnit) == computerStorageUnits.end()) {
				std::cout << "Invalid computer storage units. Supported units: bytes, kilobytes, megabytes, megabits, gigabytes, gigabits, terabytes, terabits." << std::endl;
				return -1;
			}
			convertedValue = value * computerStorageUnits.at(fromUnit);
			return convertedValue / computerStorageUnits.at(toUnit);
			break;
		case 4: // Weight
			if (weightUnits.find(fromUnit) == weightUnits.end() || weightUnits.find(toUnit) == weightUnits.end()) {
				std::cout << "Invalid weight units. Supported units: grams, kilograms, pounds, ounces, tons." << std::endl;
				return -1;
			}
			convertedValue = value * weightUnits.at(fromUnit);
			return convertedValue / weightUnits.at(toUnit);
			break;
		default:
			std::cout << "Invalid unit type." << std::endl;
			return -1;
			break;
	}
}

void inputUnits(double& value, std::string& fromUnit, std::string& toUnit) {
	static bool validInput = false;
	std::cout << "Enter the value to convert: ";
	std::cin >> value;
	std::cout << "Enter the unit to convert from: ";
	std::cin >> fromUnit;
	std::cout << "Enter the unit to convert to: ";
	std::cin >> toUnit;
}