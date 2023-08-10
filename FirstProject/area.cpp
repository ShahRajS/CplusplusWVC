//Raj Shah
//CIST-004A-70357

#include <iostream>
#include <iomanip>
using namespace std;

int n_main(int argc, char* argv[])
{
	double radius;
	cout << "Enter the radius: ";
	cin >> radius;
	cout << "\nThe diameter is " << fixed << setprecision(12) << radius * 2 << ".\n";
	cout << "The area is " << radius * radius * 3.141592653 << ".\n";
	return 0;
}