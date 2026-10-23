#include <iostream>

int main() {
    int firstNumber, secondNumber, temporary;

    std::cout << "Enter the first number: ";
    std::cin >> firstNumber;

    std::cout << "Enter the second number: ";
    std::cin >> secondNumber;

    std::cout << "Before swapping:\n";
    std::cout << "First number: " << firstNumber << "\n";
    std::cout << "Second number: " << secondNumber << "\n";

    temporary = firstNumber;
    firstNumber = secondNumber;
    secondNumber = temporary;

    std::cout << "After swapping:";
    std::cout << "First number: " << firstNumber << "\n";
    std::cout << "Second number: " << secondNumber << "\n";

    return 0;
}