#include <iostream>
#include <cmath>

class ComplexNumber {
private:
    double real;
    double imag;

public:
    // constructors
    ComplexNumber() : real(0.0), imag(0.0) {}
    ComplexNumber(double realPart, double imagPart) : real(realPart), imag(imagPart) {}

    // getters
    double getReal() const { return real; }
    double getImaginary() const { return imag; }

    // operations
    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    ComplexNumber operator-(const ComplexNumber& other) const {
        return ComplexNumber(real - other.real, imag - other.imag);
    }

    ComplexNumber operator*(const ComplexNumber& other) const {
        double resultReal = real * other.real - imag * other.imag;
        double resultImag = real * other.imag + imag * other.real;
        return ComplexNumber(resultReal, resultImag);
    }

    ComplexNumber operator/(const ComplexNumber& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        double resultReal = (real * other.real + imag * other.imag) / denominator;
        double resultImag = (imag * other.real - real * other.imag) / denominator;
        return ComplexNumber(resultReal, resultImag);
    }

    ComplexNumber conjugate() const {
        return ComplexNumber(real, -imag);
    }

    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    double realPart() const {
        return real;
    }

    double imaginaryPart() const {
        return imag;
    }
};

// the function to print a complex number
void printComplexNumber(const ComplexNumber& num) {
    std::cout << num.getReal() << " + " << num.getImaginary() << "i";
}

int main() {
    // testing the ComplexNumber class
    ComplexNumber num1(3.0, 4.0);
    ComplexNumber num2(1.5, -2.5);

    std::cout << "Number 1: ";
    printComplexNumber(num1);
    std::cout << std::endl;

    std::cout << "Number 2: ";
    printComplexNumber(num2);
    std::cout << std::endl;

    // test operations
    ComplexNumber sum = num1 + num2;
    std::cout << "Sum: ";
    printComplexNumber(sum);
    std::cout << std::endl;

    ComplexNumber diff = num1 - num2;
    std::cout << "Difference: ";
    printComplexNumber(diff);
    std::cout << std::endl;

    ComplexNumber prod = num1 * num2;
    std::cout << "Product: ";
    printComplexNumber(prod);
    std::cout << std::endl;

    ComplexNumber quotient = num1 / num2;
    std::cout << "Quotient: ";
    printComplexNumber(quotient);
    std::cout << std::endl;

    // testing other methods
    ComplexNumber conjugateNum = num1.conjugate();
    std::cout << "Conjugate of Number 1: ";
    printComplexNumber(conjugateNum);
    std::cout << std::endl;

    std::cout << "Magnitude of Number 1: " << num1.magnitude() << std::endl;
    std::cout << "Real Part of Number 1: " << num1.realPart() << std::endl;
    std::cout << "Imaginary Part of Number 1: " << num1.imaginaryPart() << std::endl;

    return 0;
}
