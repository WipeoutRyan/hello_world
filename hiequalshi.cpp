//edit to change commit message to 3 credit not 4 credits
#include <iostream>
#include <string>
#include <cctype>

bool isNumeric(char c) {
    return c >= '0' && c <= '9';
}

int compareNumericSubstrings(const std::string& string1, const std::string& string2, size_t& index1, size_t& index2) {
    std::string numStr1 = "", numStr2 = "";

    while (index1 < string1.length() && isNumeric(string1[index1]))
        numStr1 += string1[index1++];
    while (index2 < string2.length() && isNumeric(string2[index2]))
        numStr2 += string2[index2++];

    // Convert numeric substrings to integers for comparison
    int num1 = std::stoi(numStr1);
    int num2 = std::stoi(numStr2);

    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

int strcmp_case_insensitive(const std::string& string1, const std::string& string2) {
    size_t index1 = 0, index2 = 0;
    size_t len1 = string1.length();
    size_t len2 = string2.length();

    while (index1 < len1 && index2 < len2) {
        if (isNumeric(string1[index1]) && isNumeric(string2[index2])) {
            int numCompare = compareNumericSubstrings(string1, string2, index1, index2);
            if (numCompare != 0) return numCompare;
        } else {
            char c1 = std::tolower(string1[index1]);
            char c2 = std::tolower(string2[index2]);

            if (c1 < c2) return -1;
            if (c1 > c2) return 1;
            ++index1;
            ++index2;
        }
    }

    if (len1 < len2) return -1;
    if (len1 > len2) return 1;
    return 0;
}

int main() {
    std::string string1, string2;
    std::cout << "Enter a string: ";
    std::getline(std::cin, string1);
    std::cout << "Enter another string: ";
    std::getline(std::cin, string2);

    int result = strcmp_case_insensitive(string1, string2);

    if (result < 0)
        std::cout << "The comparison of string1 and string2 returns something less than zero" << std::endl;
    else if (result > 0)
        std::cout << "The comparison of string1 and string2 returns something greater than zero" << std::endl;
    else
        std::cout << "The comparison of string1 and string2 returns zero" << std::endl;

    return 0;
}




