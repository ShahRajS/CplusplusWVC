#include <iostream>
#include <vector>
using namespace std;

int roll_dice(int sides) {
    return 1 + (rand() % sides);
}

int get_num_rolls(int dice, int sides) {
    int num_rolls;
    do {
        cout << "How many times do you want to roll the dice (between " << (dice * sides * 40) << " and 10,000,000)? ";
        cin >> num_rolls;
    } while (num_rolls > 10'000'000 or num_rolls < (dice * sides * 40));
    return num_rolls;
}

int get_num_dice() {
    int num_dice;
    do {
        cout << "How many dice (between 1 and 20) are you rolling? ";
        cin >> num_dice;
    } while (num_dice > 20 or num_dice < 1);
    return num_dice;
}

int get_num_sides() {
    int num_sides;
    do {
        cout << "How many sides (between 2 and 20) does each dice have? ";
        cin >> num_sides;
    } while (num_sides > 20 or num_sides < 2);
    return num_sides;
}

/*void scale_results(vector <int>& results) {
    int max = -1;
    for (auto i : results) {
        if (i > max)
            max = i;
    } 
    for (int i = 0; i < results.size(); ++i) {
        float temp = (results[i] * 40.0f) / static_cast <float> (max);
        results[i] = temp;
    }
}*/

void print_graph(vector <int> rolls) {
    int max = -1;
    for (auto i : rolls) {
        if (i > max)
            max = i;
    }



    for (int i = 0; i < rolls.size(); ++i) {
        cout << "\nRoll " << i << "\t";
        for (int j = 0; j < (rolls.at(i) * 40.0f / static_cast <float> (max)); ++j) {
            cout << "*";
        }
    }
    cout << endl;
}

int main()
{
    cout << "Hello World!\n";
    int temp_roll;
    const int num_dice = get_num_dice();
    const int num_sides = get_num_sides();
    const int num_rolls = get_num_rolls(num_dice, num_sides);
    const int total_possible = num_sides * num_dice + 1;

    vector <int> results{};
    results.resize(total_possible);

    for (int i = 0; i < num_rolls; ++i) {
        temp_roll = 0;
        for (int j = 0; j < num_dice; ++j) {
            temp_roll += roll_dice(num_sides);
        }
        results.at(temp_roll) += 1;
    }

    //scale_results(results);
    print_graph(results);

    return 0;
}