#include <vector>
#include <iostream>

using namespace std;

int main_2() {
	vector <int> myVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 7, 5, 3, 1};
	cout << "Raj Shah\t\tCIST004A\n";
	for (int i = 0; i < myVec.size(); ++i) {
		cout << "\nLine " << i + 1 << "\t";
		for (int j = 0; j < myVec[i]; ++j) {
			cout << "[]";
		}
	}
	cout << endl;
	return 0;
}