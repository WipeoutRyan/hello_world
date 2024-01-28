#include <iostream>
#include <cmath>
using namespace std; 

class ComplexNumber {
private:
    double real;
    double imag;

public:
    ComplexNumber() : real(0.0), imag(0.0) {}
    ComplexNumber(double realPart, double imagPart) : real(realPart), imag(imagPart) {}

    double getReal() const { return real; }
    double getImaginary() const { return imag; }

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




void pretty_print(const ComplexNumber& num) {
    cout << num.getReal() << " + " << num.getImaginary() << "i";
}

int main(){
    ComplexNumber num1(3.0, 4.0);
    ComplexNumber num2(1.5, -2.5);

    cout << "Number 1: ";
    pretty_print(num1);
    cout << endl;

    cout << "Number 2: ";
    pretty_print(num2);
    cout << endl;

    
    ComplexNumber sum = num1 + num2;
    cout << "Sum: ";
    pretty_print(sum);
    cout << endl;

    ComplexNumber diff = num1 - num2;
    cout << "Difference: ";
    pretty_print(diff);
    cout << endl;

    ComplexNumber prod = num1 * num2;
    cout << "Product: ";
    pretty_print(prod);
    cout << endl;

    ComplexNumber quotient = num1 / num2;
    cout << "Quotient: ";
    pretty_print(quotient);
    cout << endl;


    ComplexNumber conjugateNum = num1.conjugate();
    cout << "Conjugate of Number 1: ";
    pretty_print(conjugateNum);
    cout << endl;

    cout << "Magnitude of Number 1: " << num1.magnitude() << endl;
    cout << "Real Part of Number 1: " << num1.realPart() << endl;
    cout << "Imaginary Part of Number 1: " << num1.imaginaryPart() << endl;

    return 0;
}