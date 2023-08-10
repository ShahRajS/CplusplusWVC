#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

class HealthRecord
{
private:
	std::string name;
	int height;
	int weight;
public:
	HealthRecord(std::string personName, int height, int weight);

	void setName(std::string personName);
	std::string getName();

	void setHeight(int height);
	int getHeight();

	void setWeight(int weight);
	int getWeight();

	float computeBMI();

	void outputCSV(std::ofstream& outputFile);
	void inputCSV(std::ifstream& inputFile);
};

