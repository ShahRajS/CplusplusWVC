#include <iostream>
#include <iomanip>

using namespace std;

//Raj Shah    CIST-004A-70357
int main() {
	cout << "Raj Shah\t\t\t CIST-004A-70357\n\n";
	float sum_credits = 0.0F;
	float weighted_total_gpa = 0.0F;
	float final_gpa = 0.0F;
	char temp_grade;
	char temp_sign;
	float gpa;

	do {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Enter your grade [ A B C D F ] for your next class, with [ + - ] modifiers if applicable, or an X if you are done: ";
		cin.get(temp_grade);
		temp_grade = toupper(temp_grade);
		cin.get(temp_sign);

		switch (temp_grade) {
		case 'X':
			continue;
		case 'A':
			gpa = 4.0F;
			break;
		case 'B':
			gpa = 3.0F;
			break;
		case 'C':
			gpa = 2.0F;
			break;
		case 'D':
			gpa = 1.0F;
			break;
		case 'F':
			gpa = 0.0F;
			break;
		default:
			cout << "You entered an invalid grade...\n";
			continue;
		}


		switch (temp_sign) {
		case '+':
			if (temp_grade == 'A') {
				cout << "Unfortunately, an A+ is just worth 4.0. \n";
			}
			else {
				gpa += 0.3F;
			}
			break;
		case '-':
			if (temp_grade == 'F') {
				cout << "Luckily, you cannot go below 0.0... \n";
			}
			else {
				gpa -= 0.3F;
			}
			break;
		case '\n':
			break;
		default:
			cout << "You entered an invalid sign\n";
			continue;
		}

		float temp_cred;
		cout << "\nEnter a valid number of credits [0.5 - 45.0] for this class: ";
		cin >> temp_cred;

		if (temp_cred > 45.0L or temp_cred < 0.5L) {
			cout << "You need to enter a valid number of credits!\n";
			continue;
		}

		sum_credits += temp_cred;
		weighted_total_gpa += (temp_cred * gpa);
	} while (temp_grade != 'X');
	final_gpa = weighted_total_gpa / sum_credits;
	cout << fixed << setprecision(3) << final_gpa << " is your overall gpa.";
}