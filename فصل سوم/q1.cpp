#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::string result;
    for (char c : input) {
        if (std::islower(c)) {
            result += std::toupper(c);
        } else if (std::isupper(c)) {
            result += c;
        }
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}