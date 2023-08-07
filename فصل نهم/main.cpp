#include <iostream>
#include "BigNum.cpp"


template <typename T>
void bubbleSort(T arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    // Bubble Sort for integers
    int intArr[] = {5, 2, 8, 1, 9};
    bubbleSort(intArr, 5);
    std::cout << "Sorted integer array: ";
    for (const auto& num : intArr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    // Bubble Sort for floating-point numbers
    float floatArr[] = {3.14, 1.1, 2.2, 0.5};
    bubbleSort(floatArr, 4);
    std::cout << "Sorted double array: ";
    for (const auto& num : floatArr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Bubble Sort for BigNum
    BigNum bigNumArr[] = {BigNum("123456789987456321"), BigNum("44545454545454545455"), BigNum("70000000000000000000089")};
    bubbleSort(bigNumArr, 3);
    std::cout << "Sorted BigNum array: ";
    for (const auto& num : bigNumArr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}