//main.cpp
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main() {
    vector <int> n(5);
    vector <int> n1;
    vector <int> n2(5, 100);
    vector <int> n3{ 5 };
    vector <int> n4{ 0,7,0,3,8,2 };

    cout << n4.data() << "\n";
    return 0;
}