#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string input;
    std::cout << "Input: ";
    std::cin >> input;

    std::reverse(input.begin(), input.end());

    std::string output;
    for (int i = 0; i < input.length(); i++) {
        if (i > 0 && i % 3 == 0) {
            output += ",";
        }
        output += input[i];
    }

    std::reverse(output.begin(), output.end());

    std::cout << "Output: " << output << std::endl;

    return 0;
}