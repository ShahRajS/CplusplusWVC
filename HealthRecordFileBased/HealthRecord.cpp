#include "HealthRecord.hpp"

HealthRecord::HealthRecord(std::string personName = "", int got_height = 1, int got_weight = 0) {
	HealthRecord::name = personName;
	HealthRecord::height = got_height;
	HealthRecord::weight = got_weight;
}

void HealthRecord::setName(std::string personName) {
	name = personName;
}

std::string HealthRecord::getName() {
	return name;
}

void HealthRecord::setHeight(int height) {
	HealthRecord::height = height;
}

int HealthRecord::getHeight() {
	return height;
}

void HealthRecord::setWeight(int weight) {
	HealthRecord::weight = weight;
}

int HealthRecord::getWeight() {
	return weight;
}

float HealthRecord::computeBMI() {
	float temp_h = (static_cast <float> (getHeight()) * (2.54F / 100.0F));
	float temp_w = (static_cast <float> (getWeight()) / 2.20462F);
	return (temp_w / (temp_h * temp_h));
}

void HealthRecord::outputCSV(std::ofstream& outFile) {
	outFile << std::fixed << std::setprecision(2);
	outFile << getName() << ',';
	outFile << getHeight() << ',';
	outFile << getWeight() << ',';
	outFile << computeBMI() << '\r' << '\n';
}

void HealthRecord::inputCSV(std::ifstream& inFile) {

}