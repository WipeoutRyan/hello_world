#include <iostream>
#include <string>
using namespace std;

int askUser(int& value) {
    cout << "Please type a number: ";
    cin >> value;
    return value;
}

string askUser(string& value) {
    cout << "Please type a string: ";
    cin.ignore(); // Ignore previous newline character
    getline(cin, value);
    return value;
}

int main() {
    int intValue;
    string stringValue;

    askUser(intValue);
    cout << "The integer value chosen by the user is " << intValue << endl;

    askUser(stringValue);
    cout << "The string value chosen by the user is \"" << stringValue << "\"" << endl;

    return 0;
}

