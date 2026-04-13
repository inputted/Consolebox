#pragma once

void openCalculator();
double convertUnit(double value, const int& unitType, const std::string& fromUnit, const std::string& toUnit);
void inputUnits(double& value, std::string& fromUnit, std::string& toUnit);