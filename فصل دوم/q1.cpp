#include <iostream>
#include <iomanip>

int main() {
    int rows;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= rows - i; j++) {
            std::cout << " ";
        }
        for (int k = 1; k <= i; k++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }

    for (int i = rows; i >= 1; i--) {
        for (int j = 1; j <= rows - i; j++) {
            std::cout << " ";
        }
        for (int k = 1; k <= i; k++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }

    return 0;
}