//Raj Shah
//CIST-004A-70357

#include <iostream>
#include <iomanip>
using namespace std;

/*float bmi_calc(float height, float weight) {
    float bmi = weight / (height * height);
    return bmi;
}*/

void print_bmi(float bmi) {
    cout << "Your BMI is " << bmi << ". ";
    if (bmi < 18.5F) {
        cout << "Quite low, innit?\n"; //underweight
    }
    else if (bmi < 25.0F) {
        cout << "Nice and normal weight... almost TOO average. Did you input those values correctly?\n"; //normal weight
    }
    else if (bmi < 30.0F) {
        cout << "The verdict: GO TO GYM!\n"; // overweight
    }
    else {
        cout << "This might be a medical problem...\n"; //obese+
    }
}
void print_height(float height) {
    cout << "\nYour height in meters is: " << height << ". ";
    if (height < 1.524F) {
        cout << "Did you dress up as a dwarf for halloween?\n";
    }
    else if (height < 1.7272F) {
        cout << "Standard height... almost TOO average. Did you input those values correctly?\n";
    }
    else {
        cout << "Watch where you're stepping!\n";
    }
}

void print_weight(float weight) {
    cout << "Your weight in kilograms is: " << weight << ". ";
    if (weight < 45) {
        cout << "Don't wear anything too large, can't have you floating away!\n";
    }
    else if (weight < 70) {
        cout << "Standard weight... almost TOO average. Did you input those values correctly?\n";
    }
    else {
        cout << "Did the concrete crack?!??!?\n";
    }
}

int f_main()
{
    float height;
    float weight;
    float bmi;
    float in_to_m = 2.54F / 100.0F; //conversion factor of inches to meters
    float lb_to_kg = 2.20462F; //conversion factor of pounds to kilograms
    cout << "Raj Shah\t\t\t CIST-004A-70357\n\n";
    cout << "Please enter your height in inches: ";
    cin >> height;
    cout << "Please enter your weight in pounds: ";
    cin >> weight;
    if (height <= 0 or weight <= 0) {
        cout << "You think you're funny huh... PUT POSITIVE NUMBERS IN!!";
    }
    else {
        height *= in_to_m; //height conversion to metric
        print_height(height);
        weight /= lb_to_kg; //weight conversion to metric
        print_weight(weight);
        //bmi = bmi_calc(height, weight);
        //print_bmi(bmi);
    }
    return 0;
}