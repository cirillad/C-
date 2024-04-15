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

    Drib add(const Drib& other) const {
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Drib(newNumerator, newDenominator);
    }

    Drib subtract(const Drib& other) const {
        int newNumerator = numerator * other.denominator - other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Drib(newNumerator, newDenominator);
    }

    Drib multiply(const Drib& other) const {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return Drib(newNumerator, newDenominator);
    }

    Drib divide(const Drib& other) const {
        if (other.numerator == 0) {
            cerr << "Error: division by zero!" << endl;
            return Drib(0, 1);
        }
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        return Drib(newNumerator, newDenominator);
    }

    bool isEqual(const Drib& other) const {
        return numerator * other.denominator == other.numerator * denominator;
    }

    void print() const {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Drib fraction1(1, 2);
    Drib fraction2(1, 3);

    Drib result = fraction1.add(fraction2);
    cout << "Adding: ";
    result.print();

    result = fraction1.subtract(fraction2);
    cout << "Subtracting: ";
    result.print();

    result = fraction1.multiply(fraction2);
    cout << "Multiplying: ";
    result.print();

    result = fraction1.divide(fraction2);
    cout << "Dividing: ";
    result.print();

    if (fraction1.isEqual(fraction2)) {
        cout << "Fractions are equal" << endl;
    }
    else {
        cout << "Fractions are not equal" << endl;
    }

    return 0;
}
