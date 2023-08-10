#include <iostream>
#include <iomanip>
using namespace std;

void print_gpa(int total_students, float min_gpa, float max_gpa, float avg_gpa) {
	cout << fixed;
	cout << setprecision(3);
	cout << "\nThe total number of students in this class is: " << total_students;
	cout << ".\nThe minimum GPA entered for this class is: " << min_gpa;
	cout << ".\nThe maximum GPA entered for this class is: " << max_gpa;
	cout << ".\nThe average GPA for the students in this class is: " << avg_gpa << ".\n\n";
}

int get_num_students() {
	int total_students = -1;
	do {
		total_students = -1;
		cin.ignore();
		cin.clear();
		cout << "Enter total number of students in class: ";
		cin >> total_students;
	} while (total_students <= 0);
	return total_students;
}

int main_C()
{
	float min_gpa = 5.0F;
	float max_gpa = -1.0F;
	float avg_gpa;
	float combined_gpa = 0.0F;
	float temp_gpa = -1.0;

	cout << "Raj Shah\t\t\t CIST-004A-70357\n\n";

	//int total_students = get_num_students();
	int total_students = 0;

	do {
		if (temp_gpa <= 4.0F and temp_gpa >= 0 and temp_gpa != -1) {
			if (temp_gpa > max_gpa) {
				max_gpa = temp_gpa;
			}
			if (temp_gpa < min_gpa) {
				min_gpa = temp_gpa;
			}
			combined_gpa += temp_gpa;
			total_students += 1;
			cout << "This student's GPA is: " << temp_gpa << ".\n";
		}
		else if (temp_gpa == -1.0) {

		}
		else {
			cout << temp_gpa << " is an invalid GPA.\n";
		}
		cout << "Enter a valid GPA (0.0 - 4.0) for the next student, or -1 when you're done: ";
		cin >> temp_gpa;
	} while (temp_gpa != -1.0F);

	/*for (int i = 0; i < total_students; i++) {
		float temp_gpa;
		do {
			cout << "Enter a valid GPA (0.0 - 4.0) for Student #" << i + 1 << ": ";
			cin >> temp_gpa;
		} while (temp_gpa < 0.0F or temp_gpa > 4.0F);

		if (temp_gpa > max_gpa) {
			max_gpa = temp_gpa;
		}
		if (temp_gpa < min_gpa) {
			min_gpa = temp_gpa;
		}

		combined_gpa += temp_gpa;
	}*/

	avg_gpa = combined_gpa / total_students;

	print_gpa(total_students, min_gpa, max_gpa, avg_gpa);
	return -1;
}