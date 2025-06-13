#include "ComplexNumber.h"
#include <iostream>

int main() {
    double real1, imagine1, real2, imagine2, scalar;
    char operation;
    bool repeat = true;

    std::cout << "Enter the real and imaginary part of the first complex number: ";
    std::cin >> real1 >> imagine1;
    ComplexNumber num1(real1, imagine1);

    while (repeat) {
        std::cout << "Enter one of the operations +, -, *, /, =: ";
        std::cin >> operation;

        if (operation == '+' || operation == '-' || operation == '=') {
            std::cout << "Enter the real and imaginary part of the second complex number: ";
            std::cin >> real2 >> imagine2;
            ComplexNumber num2(real2, imagine2);

            if (operation == '+') {
                num1 + num2;
            } else if (operation == '-') {
                num1 - num2;
            } else if (operation == '=') {
                if (num1 == num2) {
                    std::cout << "The complex numbers are equal." << std::endl;
                } else {
                    std::cout << "The complex numbers are not equal." << std::endl;
                }
            }
        } else if (operation == '*' || operation == '/') {
            std::cout << "Enter the scalar value: ";
            std::cin >> scalar;

            if (operation == '*') {
                num1 * scalar;
            } else if (operation == '/') {
                num1 / scalar;
            }
        }

        std::cout << "Result: ";
        num1.print();

        char letter;
        std::cout << "Do you want to continue y/n? ";
        std::cin >> letter;
        repeat = (letter == 'y');
    }

    return 0;
}
