#include <iostream>

class GaussianInteger {
private:
    int real;
    int imag;

public:
    // Constructors
    GaussianInteger() : real(0), imag(0) {}
    GaussianInteger(int r, int i) : real(r), imag(i) {}

    // Getter methods
    int getReal() const { return real; }
    int getImag() const { return imag; }

    // Setter methods
    void setReal(int r) { real = r; }
    void setImag(int i) { imag = i; }

    // Display method
    void display() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }

    // Addition method
    GaussianInteger add(const GaussianInteger& other) const {
        return GaussianInteger(real + other.real, imag + other.imag);
    }

    // Subtraction method
    GaussianInteger subtract(const GaussianInteger& other) const {
        return GaussianInteger(real - other.real, imag - other.imag);
    }

    // Conjugate method
    GaussianInteger conjugate() const {
        return GaussianInteger(real, -imag);
    }

    // Multiplication method
    GaussianInteger multiply(const GaussianInteger& other) const {
        int resultReal = (real * other.real) - (imag * other.imag);
        int resultImag = (real * other.imag) + (imag * other.real);
        return GaussianInteger(resultReal, resultImag);
    }

    // Scalar multiplication method
    GaussianInteger scalarMultiply(int scalar) const {
        return GaussianInteger(real * scalar, imag * scalar);
    }
};

int main() {
    // Test your GaussianInteger class here
    GaussianInteger A(3, 4);
    GaussianInteger B(5, -7);

    std::cout << "A: ";
    A.display();

    std::cout << "B: ";
    B.display();

    GaussianInteger sum = A.add(B);
    std::cout << "A + B: ";
    sum.display();

    GaussianInteger difference = A.subtract(B);
    std::cout << "A - B: ";
    difference.display();

    GaussianInteger product = A.multiply(B);
    std::cout << "A * B: ";
    product.display();

    GaussianInteger conjugateA = A.conjugate();
    std::cout << "Conjugate of A: ";
    conjugateA.display();

    GaussianInteger scalarProduct = A.scalarMultiply(2);
    std::cout << "2 * A: ";
    scalarProduct.display();

    return 0;
}
