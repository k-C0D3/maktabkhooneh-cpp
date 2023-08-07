#include <iostream>
#include <cmath>

int main() {
    double radius;
    std::cout << "Enter the radius of the sphere: ";
    std::cin >> radius;

    double area = 4  *M_PI*  pow(radius, 2);

    std::cout << "The area of the sphere is: " << area << std::endl;

    return 0;
}