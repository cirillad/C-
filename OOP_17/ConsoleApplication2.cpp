#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

class Car {
    string name;
    int year;
    double engineVolume;
    double price;

public:
    Car(string n, int y, double ev, double p)
        : name(n), year(y), engineVolume(ev), price(p) {}

    string getName() const { return name; }
    int getYear() const { return year; }
    double getEngineVolume() const { return engineVolume; }
    double getPrice() const { return price; }

    void printInfo() const {
        cout << "Name: " << name << endl;
        cout << "Year: " << year << endl;
        cout << "Engine Volume: " << engineVolume << " L" << endl;
        cout << "Price: $" << price << endl;
    }

    void saveToFile(ofstream& outFile) const {
        outFile << name << endl;
        outFile << year << endl;
        outFile << engineVolume << endl;
        outFile << price << endl;
    }

    static Car loadFromFile(ifstream& inFile) {
        string name;
        int year;
        double engineVolume, price;
        getline(inFile, name);
        inFile >> year >> engineVolume >> price;
        inFile.ignore();
        return Car(name, year, engineVolume, price);
    }
};

class CarManager {
    vector<Car> cars;

public:
    void addCar(const Car& car) {
        cars.push_back(car);
    }

    void removeCar(const string& name) {
        auto it = remove_if(cars.begin(), cars.end(), [&name](const Car& car) {
            return car.getName() == name;
            });
        if (it != cars.end()) {
            cars.erase(it, cars.end());
            cout << "Car removed successfully." << endl;
        }
        else {
            cout << "Car not found." << endl;
        }
    }

    void printAll() const {
        for (const auto& car : cars) {
            car.printInfo();
            cout << "-----------------------" << endl;
        }
    }

    void searchByName(const string& name) const {
        for (const auto& car : cars) {
            if (car.getName() == name) {
                car.printInfo();
                return;
            }
        }
        cout << "No results found for car name: " << name << endl;
    }

    void searchByYear(int year) const {
        for (const auto& car : cars) {
            if (car.getYear() == year) {
                car.printInfo();
                return;
            }
        }
        cout << "No results found for car year: " << year << endl;
    }

    void sortByPrice() {
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.getPrice() < b.getPrice();
            });
        cout << "Cars sorted by price." << endl;
    }

    void sortByName() {
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.getName() < b.getName();
            });
        cout << "Cars sorted by name." << endl;
    }

    void saveAllToFile(const string& filename) const {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            for (const auto& car : cars) {
                car.saveToFile(outFile);
                outFile << "----" << endl;
            }
            outFile.close();
        }
        else {
            cout << "Unable to open file for writing." << endl;
        }
    }

    void loadAllFromFile(const string& filename) {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            cars.clear();
            while (inFile.peek() != EOF) {
                Car car = Car::loadFromFile(inFile);
                cars.push_back(car);
                inFile.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            inFile.close();
        }
        else {
            cout << "Unable to open file for reading." << endl;
        }
    }
};

void printMenu() {
    cout << "\nMenu:\n";
    cout << "1. Add Car\n";
    cout << "2. Remove Car\n";
    cout << "3. Print All Cars\n";
    cout << "4. Search Car by Name\n";
    cout << "5. Search Car by Year\n";
    cout << "6. Sort Cars by Price\n";
    cout << "7. Sort Cars by Name\n";
    cout << "8. Save Cars to File\n";
    cout << "9. Load Cars from File\n";
    cout << "10. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    CarManager manager;
    int choice;

    do {
        printMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int year;
            double engineVolume, price;

            cout << "Enter car name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter year of manufacture: ";
            cin >> year;
            cout << "Enter engine volume (L): ";
            cin >> engineVolume;
            cout << "Enter price: $";
            cin >> price;

            manager.addCar(Car(name, year, engineVolume, price));
            break;
        }
        case 2: {
            string name;
            cout << "Enter car name to remove: ";
            cin.ignore();
            getline(cin, name);
            manager.removeCar(name);
            break;
        }
        case 3:
            manager.printAll();
            break;
        case 4: {
            string name;
            cout << "Enter car name to search: ";
            cin.ignore();
            getline(cin, name);
            manager.searchByName(name);
            break;
        }
        case 5: {
            int year;
            cout << "Enter car year to search: ";
            cin >> year;
            manager.searchByYear(year);
            break;
        }
        case 6:
            manager.sortByPrice();
            manager.printAll();
            break;
        case 7:
            manager.sortByName();
            manager.printAll();
            break;
        case 8:
            manager.saveAllToFile("cars.txt");
            break;
        case 9:
            manager.loadAllFromFile("cars.txt");
            break;
        case 10:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 10);

}
