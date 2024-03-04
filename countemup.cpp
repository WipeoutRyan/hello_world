#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class GroceryCounter {
private:
    int value;
    int overflow_count;

public:
    GroceryCounter() : value(0), overflow_count(0) {}

    void tens() {
        value = (value + 10) % 10000;
    }

    void ones() {
        value = (value + 1) % 10000;
    }

    void tenths() {
        value = (value + static_cast<int>(0.1 * 10000)) % 10000;
    }

    void hundredths() {
        value = (value + static_cast<int>(0.01 * 10000)) % 10000;
    }

    string total() {
        int dollars = value / 100;
        int cents = value % 100;
        ostringstream oss;
        oss << "$" << dollars << "." << setfill('0') << setw(2) << cents;
        return oss.str();
    }

    int number_of_overflows() {
        return overflow_count;
    }

    void clear() {
        value = 0;
        overflow_count = 0;
    }
};

int main() {
    GroceryCounter counter;
    cout << counter.total() << endl;  // Output: $0.00
    counter.ones();
    counter.ones();
    counter.tens();
    counter.tenths();
    counter.hundredths();
    cout << counter.total() << endl;  // Output: $12.34
    cout << counter.number_of_overflows() << endl;  // Output: 0
    counter.ones();
    counter.ones();
    counter.ones();
    counter.ones();  // Overflow
    cout << counter.total() << endl;  // Output: $0.04 (Counter wraps back to zero)
    cout << counter.number_of_overflows() << endl;  // Output: 1
    counter.clear();
    cout << counter.total() << endl;  // Output: $0.00
    return 0;
}
