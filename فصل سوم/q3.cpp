#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cout << "Enter Number of Students (n): ";
    std::cin >> n;

    std::vector<int> grades(n);
    std::cout << "Enter the grades:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> grades[i];
    }

    std::sort(grades.begin(), grades.end(), std::greater<int>());

    std::cout << "Output:\n";
    for (int grade : grades) {
        std::cout << grade << std::endl;
    }

    double sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    double average = sum / n;
    std::cout << "Average is: " << average << std::endl;

    return 0;
}