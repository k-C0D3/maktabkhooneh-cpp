#include <iostream>

int main() {
    double celsius;
    std::cout << "Enter the temperature in Celsius: ";
    std::cin >> celsius;

    double fahrenheit = (celsius * 9/5) + 32;

    std::cout << "The temperature in Fahrenheit is: " << fahrenheit << std::endl;

    return 0;
}