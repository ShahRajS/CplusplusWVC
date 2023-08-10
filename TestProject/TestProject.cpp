#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //cout << setw(10);

    for (int i = 0; i <= 15; ++i) {
        if (i == 0){
            cout << setw(10) << "Number";
            cout << setw(10) << "Number*2";
            cout << setw(10) << "Number^2\n";
        }
        else {
            cout << setw(10) << i;
            cout << setw(10) << i*2;
            cout << setw(10) << i*i << "\n";
        }
    }

}
