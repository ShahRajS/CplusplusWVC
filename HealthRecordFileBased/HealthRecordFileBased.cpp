#include "HealthRecord.hpp"
#include <vector>

using namespace std;

int main()
{
    string fileName = "HealthTest.csv";
    ifstream checkfile;
    ofstream newfile;
    bool checker = true;
    cout << "Raj Shah\t\tCIST004A\n\n";

    do {
        cout << "Enter an unused file name (example instead of example.csv): ";
        cin >> fileName;

        checkfile.open(fileName + ".csv", ios::in);
        if (checkfile) {
            cout << "This file already exists, please enter another file name.\n";
        }
        else {
            cout << "This file doesnt exist.... making a new one.\n";
            checkfile.close();
            newfile.open(fileName + ".csv", ios::binary | ios::app);
            checker = false;
            
        }
    } while (checker);

    
    cout << "--Enter 10 Health Records--\n";

    vector <HealthRecord*> records;

    string temp_name;
    int temp_height;
    int temp_weight;

    cin.ignore();
    for (int i = 1; i <= 10; ++i) {
        cout << "\nHealth Record #" << i << "\n";
        cout << "Enter the name: ";
        getline(cin, temp_name);
        cout << "Enter " << temp_name << "'s height in inches: ";
        cin >> temp_height;
        cout << "Enter " << temp_name << "'s weight in pounds: ";
        cin >> temp_weight;

        records.emplace_back(new HealthRecord{temp_name, temp_height, temp_weight});
        
        cin.ignore();
    }

    for (int i = 0; i < records.size(); ++i) {
        records[i]->outputCSV(newfile);
    }

    newfile.close();

    ifstream myfile(fileName + ".csv", ios::binary | ios::in);
    streampos begin, end;
    begin = myfile.tellg();
    myfile.seekg(0, ios::end);
    end = myfile.tellg();
    myfile.close();
    cout << "The size is: " << (end - begin) << " bytes.\n\n";

    cout << "Enter the 11th name: ";
    getline(cin, temp_name);
    cout << "Enter " << temp_name << "'s height in inches: ";
    cin >> temp_height;
    cout << "Enter " << temp_name << "'s weight in pounds: ";
    cin >> temp_weight;

    records.emplace_back(new HealthRecord{ temp_name, temp_height, temp_weight });

    newfile.open(fileName + ".csv", ios::app);

    records[records.size() - 1]->outputCSV(newfile);
    newfile.close();

    myfile.open(fileName + ".csv", ios::binary | ios::in);
    begin = myfile.tellg();
    myfile.seekg(0, ios::end);
    end = myfile.tellg();
    myfile.close();
    cout << "The size is: " << (end - begin) << " bytes.\n";

    return 0;
}
