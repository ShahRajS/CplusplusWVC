#include <iostream>
#include <iomanip>
using namespace std;

//Raj Shah    CIST-004A-70357
//Simple Level: 13 pts

float gpa_val(char grade, char sign) {
	float gpa = 0;
	switch (grade) {
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
		cout << "Invalid grade. \n\n";
		return -1.0F;
	}
	switch (sign) {
	case '+':
		if (grade == 'A') {
			cout << "Unfortunately, an A+ is just worth 4.0. \n\n";
		}
		else {
			gpa += 0.3;
		}
		return gpa;
	case '-':
		if (grade == 'F') {
			cout << "Luckily, you cannot go below 0.0... \n\n";
		}
		else {
			gpa -= 0.3;
		}
		return gpa;
	default:
		return gpa;
	}
}

char get_grade() {
	char temp_grade = 'M';
	do {
		cout << "Enter your grade [ A B C D F ] for your next class, with [ + - ] modifiers if applicable, any other modifier will be ignored: ";
		cin.get(temp_grade);
		temp_grade = toupper(temp_grade);
		/*if (temp_grade != '\n') {
			cin.ignore(1000, '\n');
		}*/
	} while (temp_grade != 'A' and temp_grade != 'B' and temp_grade != 'C' and temp_grade != 'D' and temp_grade != 'F');
	return temp_grade;
}

char get_sign() {
	char grade_sign;
	cin.get(grade_sign);
	if (grade_sign != '\n') {
		cin.ignore(1000, '\n');
	}
	return grade_sign;
}

long double get_credit() {
	long double temp_cred;
	do {
		cout << "\nEnter a valid number of credits [0.5 - 45.0] for this class: ";
		cin >> temp_cred;
		cin.ignore();
		cin.clear();
	} while (temp_cred < 0.5L or temp_cred > 45);
	return temp_cred;
}

int main_t() {
	cout << "Raj Shah\t\t\t CIST-004A-70357\n\n";
	long double sum_credits = 0.0F;
	float weighted_total_gpa = 0.0F;
	float final_gpa;
	int isDone = 1;
	do {
		char grade = get_grade();
		char sign = get_sign();
		long double credits = get_credit();
		float gpa = gpa_val(grade, sign);

		sum_credits += credits;
		weighted_total_gpa += (gpa * credits);
		cout << "For this class, your weighted gpa is: " << (gpa * credits);
		cout << "\nEnter [ 1 ] if you want to add another class: ";
		cin >> isDone;
	} while (isDone == 1);
	final_gpa = weighted_total_gpa / sum_credits;
	cout << final_gpa << " is your overall gpa.";
	return -1;
}
