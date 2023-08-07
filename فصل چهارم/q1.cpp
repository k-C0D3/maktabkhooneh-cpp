#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <sstream>
#include <iomanip>

class Car {
public:
    std::string make;
    std::string owner;
    int year;
    std::string color;
    int mileage;
    std::string problem;
    std::chrono::system_clock::time_point entryTime;

    Car(const std::string& make, const std::string& owner, int year, const std::string& color, int mileage, const std::string& problem)
        : make(make), owner(owner), year(year), color(color), mileage(mileage), problem(problem) {
        entryTime = std::chrono::system_clock::now();
    }

    void displayInfo()  const {
        std::cout << "Make: " << make << std::endl;
        std::cout << "Owner: " << owner << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "Color: " << color << std::endl;
        std::cout << "Mileage: " << mileage << std::endl;
        std::cout << "Problem: " << problem << std::endl;
        std::cout << "Entry Time: " << formatTime(entryTime) << std::endl;
    }

private:
     std::string formatTime(const std::chrono::system_clock::time_point& timePoint) const {
        std::time_t time = std::chrono::system_clock::to_time_t(timePoint);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
        return ss.str();
    }
};

int main() {
    std::vector<Car> cars;

    while (true) {
        std::string make, owner, color, problem;
        int year, mileage;

        std::cout << "Enter car make (or 'q' to quit): ";
        std::getline(std::cin, make);

        if (make == "q") {
            break;
        }

        std::cout << "Enter car owner: ";
        std::getline(std::cin, owner);

        std::cout << "Enter car year: ";
        std::cin >> year;

        std::cout << "Enter car color: ";
        std::cin.ignore();
        std::getline(std::cin, color);

        std::cout << "Enter car mileage: ";
        std::cin >> mileage;

        std::cout << "Enter car problem: ";
        std::cin.ignore();
        std::getline(std::cin, problem);

        cars.emplace_back(make, owner, year, color, mileage, problem);
    }

    std::cout << "Car Information:\n";
    for (const Car& car : cars) {
        car.displayInfo();
        std::cout << std::endl;
    }

    return 0;
}