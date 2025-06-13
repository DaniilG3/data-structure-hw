#include "ComplexNumber.h"

ComplexNumber::ComplexNumber() : real(0), imagine(0) {}

ComplexNumber::ComplexNumber(double realPart, double imaginePart) : real(realPart), imagine(imaginePart) {}

double ComplexNumber::getReal() const { return real; }

double ComplexNumber::getImagine() const { return imagine; }

void ComplexNumber::setReal(double realPart) {
    real = realPart;
}

void ComplexNumber::setImagine(double imagPart) {
    imagine = imagPart;
}

void ComplexNumber::print() const {
    if (imagine >= 0) {
        // Standard format when the imaginary part is non-negative
        std::cout << real << "+" << imagine << "i" << std::endl;
    } else {
        // Format when the imaginary part is negative
        std::cout << real << "+(" << imagine << ")i" << std::endl;
    }
}

void ComplexNumber::operator+(const ComplexNumber& other) {
    real += other.real;
    imagine += other.imagine;
}

void ComplexNumber::operator-(const ComplexNumber& other) {
    real -= other.real;
    imagine -= other.imagine;
}

void ComplexNumber::operator*(double scalar) {
    real *= scalar;
    imagine *= scalar;
}

void ComplexNumber::operator/(double scalar) {
    if (scalar != 0) {
        real /= scalar;
        imagine /= scalar;
    } else {
        std::cout << "Division by zero error!" << std::endl;
    }
}

bool ComplexNumber::operator==(const ComplexNumber& other) const {
    return (real == other.real) && (imagine == other.imagine);
}
