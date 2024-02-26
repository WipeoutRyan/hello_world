#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

double find_median(const vector<int>& data) {
    int n = data.size();
    if (n % 2 == 0) {
        return (data[n/2 - 1] + data[n/2]) / 2.0;
    } else {
        return data[n/2];
    }
}

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "File not found." << endl;
        return 1;
    }

    vector<int> data;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string cell;
        while (getline(ss, cell, ',')) {
            data.push_back(stoi(cell));
        }
    }

    file.close();

    sort(data.begin(), data.end());

    double median = find_median(data);

    cout << "Median: " << median << endl;

    return 0;
}
