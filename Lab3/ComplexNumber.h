#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H
#include <iostream>

class ComplexNumber {
private:
    double real;
    double imagine;

public:
    ComplexNumber();

    ComplexNumber(double realPart, double imaginePart);

    double getReal() const;
    double getImagine() const;

    void setReal(double realPart);
    void setImagine(double imaginePart);

    void print() const;

    void operator+(const ComplexNumber& other);
    void operator-(const ComplexNumber& other);
    void operator*(double scalar);
    void operator/(double scalar);
    bool operator==(const ComplexNumber& other) const;
};

#endif // COMPLEXNUMBER_H
