#include <iostream>
#include <string>
using namespace std;

int count_char(char*);
int count_vowels(char*);
void first_char_to_upper(char*);
void full_upper(char*);
void remove_extra_spaces(char*);

 

int main()
{
    char new_str[128];
    
    cout << "Raj Shah \t\tCIST 004A\n\n";
    cout << "Enter a string: ";
    cin.getline(new_str, 128);

    int total_char = count_char(new_str);
    cout << "\nThere are " << total_char << " characters in: \"" << new_str << "\".\n";

    int total_vowels = count_vowels(new_str);
    cout << "\nThere are " << total_vowels << " vowels in: \"" << new_str << "\".\n";

    first_char_to_upper(new_str);
    cout << "\nUpper Case First Characters: \"" << new_str << "\".\n";

    full_upper(new_str);
    cout << "\nSHOUTING: \"" << new_str << "\".\n";

    remove_extra_spaces(new_str);
    cout << "\nExtra spaces removed: \"" << new_str << "\".\n";
    return 0;
}

int count_char(char* input) {
    int count = 0; // <-- [Allocate Memory for 'count' as an integer, initalized with the value 0] PHRASING IMPORTANT FOR TESTS
    for (; *input != '\0'; ++input) {
        ++count;
    }
    return count;
}

int count_vowels(char* input) {
    int count = 0;
    for (; *input != '\0'; ++input) {
        char temp = tolower(*input);
        switch (temp) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            ++count;
        }
    }
    return count;
}

void first_char_to_upper(char* input) {
    *input = toupper(*input);
    for (; *input != '\0'; ++input) {
        if (*input == ' ') {
            *(input + 1) = toupper(*(input + 1));
        }
    }
    return;
}

void full_upper(char* input) {
    for (; *input != '\0'; ++input) {
        *input = toupper(*input);
    }
    return;
}

void remove_extra_spaces(char* input) {
    char* displace = input;
    for (; *input != '\0'; ) {
        if (*(input + 1) == ' ' and *input == ' ')
            ++input;
        else {
            if (*(input + 1) == '\0') {
                *(displace + 1) = '\0';
            }
            *displace = *input;
            ++displace;
            ++input;
        }
    }
    *displace = '\0';
    return;
}