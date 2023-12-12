#include <iostream>

using namespace std;

class GaussianInteger {
private:
    int real;
    int imag;

public:
    // Constructors
    GaussianInteger() : real(0), imag(0) {}
    GaussianInteger(int r, int i) : real(r), imag(i) {}

    // Getter methods
    int getReal() const { 
        
        return this->real; 
    }


    int getImag() const { 
        
        return this->imag; 
    }

    // Setter methods
    void setReal(int r) {
         this->real = r; 
         
    }
    void setImag(int i) { 
        
        this->imag = i; 
        
    }

    // Display method
    void display() const {
        cout << this->real << " + " << this->imag << "i" << endl;
    }

    // Addition method
    GaussianInteger add(const GaussianInteger& other) const {
        return GaussianInteger(this->real + other.real, this->imag + other.imag);
    }

    // Subtraction method
    GaussianInteger subtract(const GaussianInteger& other) const {
        return GaussianInteger(this->real - other.real, this->imag - other.imag);
    }

    // Conjugate method
    GaussianInteger conjugate() const {
        return GaussianInteger(this->real, -this->imag);
    }

    // Multiplication method
    GaussianInteger multiply(const GaussianInteger& other) const {
        int resultReal = (this->real * other.real) - (this->imag * other.imag);
        int resultImag = (this->real * other.imag) + (this->imag * other.real);
        return GaussianInteger(resultReal, resultImag);
    }

    // Scalar multiplication method
    GaussianInteger scalarMultiply(int scalar) const {
        return GaussianInteger(this->real * scalar, this->imag * scalar);
    }
};

int main() {
    // Test your GaussianInteger class here
    GaussianInteger A(3, 4);
    GaussianInteger B(5, -7);

    cout << "A: ";
    A.display();

    cout << "B: ";
    B.display();

    GaussianInteger sum = A.add(B);
    cout << "A + B: ";
    sum.display();

    GaussianInteger difference = A.subtract(B);
    cout << "A - B: ";
    difference.display();

    GaussianInteger product = A.multiply(B);
    cout << "A * B: ";
    product.display();

    GaussianInteger conjugateA = A.conjugate();
    cout << "Conjugate of A: ";
    conjugateA.display();

    GaussianInteger scalarProduct = A.scalarMultiply(2);
    cout << "2 * A: ";
    scalarProduct.display();

    return 0;
}
