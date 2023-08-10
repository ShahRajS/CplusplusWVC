//Raj Shah
//CIST-004A-70357

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

float bmi_calc(float height, float weight) {
    float in_to_m = 2.54F / 100.0F; //conversion factor of inches to meters
    float lb_to_kg = 2.20462F; //conversion factor of pounds to kilograms
    height = height * in_to_m;
    weight = weight / lb_to_kg;
    float bmi = weight / (height * height);
    return bmi;
}

void print_bmis(string name1, float height1, float weight1, float bmi1, string name2, float height2, float weight2, float bmi2) {

    cout << "\n" << name1 << "'s BMI is " << bmi1;
    cout << "\n" << name2 << "'s BMI is " << bmi2 << "\n";
    if (bmi2 > bmi1) {
        cout << name1 << " is \"healthier\" than " << name2;
    }
    else if (bmi1 > bmi2) {
        cout << name2 << " is \"healthier\" than " << name1;
    }
    else {
        cout << name1 << " and " << name2 << " have the same bmi!";
    }
}

int main() {
    string name1;
    float height1;
    float weight1;
    float bmi1;

    string name2;
    float height2;
    float weight2;
    float bmi2;

    cout << "Raj Shah\t\t\t CIST-004A-70357\n\n";
    cout << "Please enter the first person's full name: ";
    getline(cin, name1);
    cout << "Please enter the first person's height: ";
    cin >> height1;
    
    cout << "Please enter the first person's weight: ";
    cin >> weight1;
    
    cin.ignore();
    cout << "Please enter the second person's full name: ";
    getline(cin, name2);
    cout << "Please enter the second person's height: ";
    cin >> height2;
    cout << "Please enter the second person's weight: ";
    cin >> weight2;

    if (height1 <= 0 or weight1 <= 0 or height2 <= 0 or weight2 <= 0) {
        cout << "You think you're funny huh... PUT POSITIVE NUMBERS IN!!";
    }
    else {     
        bmi1 = bmi_calc(height1, weight1);
        bmi2 = bmi_calc(height2, weight2);
        print_bmis(name1, height1, weight1, bmi1, name2, height2, weight2, bmi2);
    }
    return 0;
}