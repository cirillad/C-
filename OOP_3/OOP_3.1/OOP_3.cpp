#include <iostream>

using namespace std;

class Drib {
private:
    int numerator;
    int denominator;

public:
    Drib(int num, int den) : numerator(num), denominator(den) {};

    void setFraction(int num, int denom) {
        numerator = num;
        denominator = denom;
    }

    Drib operator +(const Drib& other) const {
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Drib(newNumerator, newDenominator);
    }

    Drib operator -(const Drib& other) const {
        int newNumerator = numerator * other.denominator - other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Drib(newNumerator, newDenominator);
    }

    Drib operator *(const Drib& other) const {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return Drib(newNumerator, newDenominator);
    }

    Drib operator /(const Drib& other) const {
        if (other.numerator == 0) {
            cerr << "Error: division by zero!" << endl;
            return Drib(0, 1);
        }
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        return Drib(newNumerator, newDenominator);
    }

    void print() const {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Drib fraction1(1, 2);
    Drib fraction2(1, 3);

    Drib result_add = fraction1 + fraction2;
    cout << "Adding: ";
    result_add.print();

    Drib result_subtract = fraction1 - fraction2;
    cout << "Subtracting: ";
    result_subtract.print();

    Drib result_multiply = fraction1 * fraction2;
    cout << "Multiplying: ";
    result_multiply.print();

    Drib result_divide = fraction1 / fraction2;
    cout << "Dividing: ";
    result_divide.print();
}
