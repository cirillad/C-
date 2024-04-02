#include <iostream>

using namespace std;

//struct Complex {
//    double real;
//    double imag;
//};
//
//Complex add(Complex num1, Complex num2) {
//    Complex result;
//    result.real = num1.real + num2.real;
//    result.imag = num1.imag + num2.imag;
//    return result;
//}
//
//Complex subtract(Complex num1, Complex num2) {
//    Complex result;
//    result.real = num1.real - num2.real;
//    result.imag = num1.imag - num2.imag;
//    return result;
//}
//
//Complex multiply(Complex num1, Complex num2) {
//    Complex result;
//    result.real = num1.real * num2.real - num1.imag * num2.imag;
//    result.imag = num1.real * num2.imag + num1.imag * num2.real;
//    return result;
//}
//
//Complex divide(Complex num1, Complex num2) {
//    Complex result;
//    double denominator = num2.real * num2.real + num2.imag * num2.imag;
//    result.real = (num1.real * num2.real + num1.imag * num2.imag) / denominator;
//    result.imag = (num1.imag * num2.real - num1.real * num2.imag) / denominator;
//    return result;
//}
//
//void printComplex(Complex num) {
//    cout << num.real << " + " << num.imag << "i" << endl;
//}


//task2

const int MAX_CARS = 100;

struct Car {
    double length;
    double clearance;
    double engineVolume;
    double enginePower;
    double wheelDiameter;
    string color;
    string transmissionType;
};

Car cars[MAX_CARS];
int carsCount = 0;

void setCarValues(double length, double clearance, double engineVolume, double enginePower, double wheelDiameter, string color, string transmissionType) {
    if (carsCount < MAX_CARS) {
        cars[carsCount].length = length;
        cars[carsCount].clearance = clearance;
        cars[carsCount].engineVolume = engineVolume;
        cars[carsCount].enginePower = enginePower;
        cars[carsCount].wheelDiameter = wheelDiameter;
        cars[carsCount].color = color;
        cars[carsCount].transmissionType = transmissionType;
        carsCount++;
        cout << "Car added successfully.\n";
    }
    else {
        cout << "Cannot add more cars. Limit reached.\n";
    }
}

void displayCarValues(int carIndex) {
    if (carIndex >= 0 && carIndex < carsCount) {
        cout << "Length: " << cars[carIndex].length << " meters" << endl;
        cout << "Clearance: " << cars[carIndex].clearance << " meters" << endl;
        cout << "Engine volume: " << cars[carIndex].engineVolume << " liters" << endl;
        cout << "Engine power: " << cars[carIndex].enginePower << " horsepower" << endl;
        cout << "Wheel diameter: " << cars[carIndex].wheelDiameter << " inches" << endl;
        cout << "Color: " << cars[carIndex].color << endl;
        cout << "Transmission type: " << cars[carIndex].transmissionType << endl;
    }
    else {
        cout << "Invalid car index.\n";
    }
}

int searchCarByColor(const string& color) {
    for (int i = 0; i < carsCount; ++i) {
        if (cars[i].color == color) {
            return i;
        }
    }
    return -1; // Return -1 if car with specified color is not found
}

int main() {
    //Complex num1, num2;
    //cout << "Enter real and imaginary parts of the first complex number: ";
    //cin >> num1.real >> num1.imag;
    //cout << "Enter real and imaginary parts of the second complex number: ";
    //cin >> num2.real >> num2.imag;

    //cout << "Sum: ";
    //printComplex(add(num1, num2));

    //cout << "Difference: ";
    //printComplex(subtract(num1, num2));

    //cout << "Product: ";
    //printComplex(multiply(num1, num2));

    //cout << "Quotient: ";
    //printComplex(divide(num1, num2));

    //return 0;

    //task2

    char choice;
    do {
        cout << "Menu:\n";
        cout << "1. Add car\n";
        cout << "2. Display car details\n";
        cout << "3. Search car by color\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1': {
            double length, clearance, engineVolume, enginePower, wheelDiameter;
            string color, transmissionType;
            cout << "Enter car length: ";
            cin >> length;
            cout << "Enter car clearance: ";
            cin >> clearance;
            cout << "Enter engine volume: ";
            cin >> engineVolume;
            cout << "Enter engine power: ";
            cin >> enginePower;
            cout << "Enter wheel diameter: ";
            cin >> wheelDiameter;
            cout << "Enter color: ";
            cin >> color;
            cout << "Enter transmission type: ";
            cin >> transmissionType;
            setCarValues(length, clearance, engineVolume, enginePower, wheelDiameter, color, transmissionType);
            break;
        }
        case '2': {
            int carIndex;
            cout << "Enter car index to display details: ";
            cin >> carIndex;
            displayCarValues(carIndex);
            break;
        }
        case '3': {
            string colorToSearch;
            cout << "Enter color to search: ";
            cin >> colorToSearch;
            int foundIndex = searchCarByColor(colorToSearch);
            if (foundIndex != -1) {
                cout << "Car with color " << colorToSearch << " found at index " << foundIndex << endl;
            }
            else {
                cout << "Car with color " << colorToSearch << " not found.\n";
            }
            break;
        }
        case '4':
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '4');

    return 0;
}
