#include <iostream>
#include <string>
using namespace std;

string sentence;
string input;

bool matchWithWildcards(const string& pattern, int patternIndex, const string& text, int textIndex) {
    if (patternIndex == pattern.length() && textIndex == text.length())
        return true;
    if (patternIndex < pattern.length() && textIndex == text.length())
        return false;

    if (pattern[patternIndex] == '*') {
        for (int i = textIndex; i <= text.length(); ++i) {
            if (matchWithWildcards(pattern, patternIndex + 1, text, i))
                return true;
        }
        return false;
    } else if (pattern[patternIndex] == text[textIndex] || pattern[patternIndex] == '?') {
        return matchWithWildcards(pattern, patternIndex + 1, text, textIndex + 1);
    } else {
        return false;
    }
}

int findIndex(const string& input) {
    if (matchWithWildcards(input, 0, sentence, 0)) {
        cout << "The pattern was found in the sentence." << endl;
    } else {
        cout << "The pattern was not found in the sentence." << endl;
    }
    return 0;
}

int main() {
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    cout << "Enter a pattern with wildcard(s) (* or ?): ";
    getline(cin, input);

    findIndex(input);

    return 0;
}



