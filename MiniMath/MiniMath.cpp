#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimum(vector<int> num_list) {
    /*int min = INT_MAX;
    for (int i = 0; i < num_list.size(); ++i) {
        if (num_list[i] < min) {
            min = num_list[i];
        }
    }
    return min;*/
    return num_list[0];
}

int maximum(vector<int> num_list) {
    /*int max = INT_MIN;
    for (int i = 0; i < num_list.size(); ++i) {
        if (num_list[i] > max) {
            max = num_list[i];
        }
    }
    return max;*/
    return num_list[num_list.size() - 1];
}


float mean(vector<int> num_list) {
    float sum = 0;
    for (int i = 0; i < num_list.size(); ++i) {
        sum += num_list[i];
    }
    return (sum / (float) num_list.size());
}

int median(vector<int> num_list) {
    /*sort(num_list.begin(), num_list.begin() + (num_list.size()));*/
    return num_list[(num_list.size() / 2)];
}

int mode(vector<int> num_list) {
    int mode_val = -1;
    int mode_num = 0;
    vector<int> num_count(1001, 0);
    for (int i = 0; i < num_list.size(); ++i) {
        num_count[num_list[i]] += 1;
    }
    for (int i = 0; i < num_count.size(); ++i) {
        if (num_count[i] > mode_val) {
            mode_val = num_count[i];
            mode_num = i;
        }
    }
    return mode_num;
}

int main()
{
    cout << "Raj Shah\tCIST004B Spring 2023\n\n";
    cout << "Minimum, Maximum, Mean, Median and Mode Calculator\n";
    
    int total_num;

    cout << "\nHow many numbers are in your list (1 to 100)? ";
    cin >> total_num;

    while (total_num < 1 or total_num > 100) {
        if (total_num < 1) {
            cout << "Hey come on!  The list must have at least 1 number!";
        }
        else {
            cout << "Really! You are prepared to enter " << total_num << " numbers? That's too many!";
        }
        cout << "\nHow many numbers are in your list (1 to 100)? ";
        cin >> total_num;
    }

    vector<int> num_list(total_num, 0);

    for (int i = 0; i < total_num; ++i) {
        int temp_val;
        cout << "For number " << (i+1) << ", enter an integer between 1 and 1000: ";
        cin >> temp_val;
        while (temp_val < 1 or temp_val > 1000) {
            cout << "Please try again!\n";
            cout << "For number " << (i+1) << ", enter an integer between 1 and 1000: ";
            cin >> temp_val;
        }
        num_list[i] = temp_val;
    }

    sort(num_list.begin(), num_list.begin() + total_num);

    cout << "The list of numbers has the following characteristics: \n";
    cout << "Minimum: " << minimum(num_list) << "\n";
    cout << "Maximum: " << maximum(num_list) << "\n";
    cout << "Mean: " << mean(num_list) << "\n";
    cout << "Median: " << median(num_list) << "\n";
    cout << "Mode: " << mode(num_list) << "\n";

}