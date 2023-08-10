#include <iostream>
#include <iomanip>
#include <ctime> //for Extra credit

using namespace std;

void primeFactor(unsigned int num, unsigned int div = 2) {
	if (num == div) { // It's Prime
		std::cout << div << " ";
		return;
	} 
	else if (num % div == 0) { // div is a factor
		std::cout << div << ", ";
		primeFactor(num / div, div);
	}
	else {
		primeFactor(num, div + 1);
	}
	return;
}


int main() {
	clock_t start_time; //for Extra credit
	clock_t end_time; //for Extra credit
	clock_t time_diff; //for Extra credit

	unsigned int number;
	cout << "Raj Shah \t\t CIST-004A-70357\n\n";
	std::cout << "Enter a number to factor: ";
	std::cin >> number;
	std::cout << "The prime factors are: ";

	start_time = clock(); //for Extra credit
	primeFactor(number);
	end_time = clock(); //for Extra credit
	time_diff = end_time - start_time; //for Extra credit
	cout << "\n\nThis took " << setprecision(4) << time_diff << " mSeconds.\n"; //for Extra credit
	std::cout << std::endl;
	return 0;
}
