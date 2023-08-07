#include <iostream>
#include <limits>

int main() {
    std::cout << "maximum limit of unsigned  int: "  << std::numeric_limits<int>::max() << std::endl;
    std::cout << "maximum limit of unsigned  long int: "  << std::numeric_limits<long int>::max() << std::endl;
    std::cout << "maximum limit of unsigned  short int: "  << std::numeric_limits<short int>::max() << std::endl;
    std::cout << "maximum limit of unsigned  long: "  << std::numeric_limits<long>::max() << std::endl;
    std::cout << "maximum limit of unsigned  long long: "  << std::numeric_limits<long long>::max() << std::endl;
    std::cout << "maximum limit of unsigned  float: "  << std::numeric_limits<float>::max() << std::endl;
    std::cout << "maximum limit of unsigned  double: "  << std::numeric_limits<double>::max() << std::endl;
    std::cout << "maximum limit of unsigned  char: "  << static_cast<int>(std::numeric_limits<char>::max()) << std::endl;
    std::cout << "range limit of bool: " << std::boolalpha << false << " to " << true << std::endl;
    return 0;
}

