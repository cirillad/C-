#include <iostream>

using namespace std;

class Overcoat {
private:
    int size = 0;
    int price = 0;
    string type = "None";
public:
    Overcoat(string type, int size, int price): type(type), size(size), price(price) {}

    Overcoat& operator=(const Overcoat& other) {
        if (this != &other)
        {
            size = other.size;
            price = other.price;
            type = other.type;
        }

        return *this;
    }

    bool operator==(const Overcoat& other) {
        return type == other.type;
    }

    bool operator>(const Overcoat& other) {
        return price > other.price;
    }
};


//=================================================================================================

class Flat {
private:
    int area;
    int price;

public:
    Flat(int area, int price) : area(area), price(price) {}

    Flat& operator=(const Flat& other) {
        if (this != &other) {
            area = other.area;
            price = other.price;
        }
        return *this;
    }

    bool operator==(const Flat& other) const {
        return area == other.area;
    }

    bool operator>(const Flat& other) const {
        return price > other.price;
    }
};

int main()
{
    Overcoat coat1("Winter", 40, 200);
    Overcoat coat2("Winter", 40, 250);
    Overcoat coat3("Spring", 30, 150);

    if (coat1 == coat2) {
        cout << "Coats are of the same type." << endl;
    }
    else {
        cout << "Coats are of different types." << endl;
    }

    if (coat1 > coat3) {
        cout << "Coat 1 is more expensive than Coat 3." << endl;
    }
    else {
        cout << "Coat 1 is not more expensive than Coat 3." << endl;
    }


//=================================================================================================

    Flat flat1(100, 200000);
    Flat flat2(120, 250000);
    Flat flat3(100, 180000);

    if (flat1 == flat3) {
        cout << "Flats have the same area." << endl;
    }
    else {
        cout << "Flats have different areas." << endl;
    }

    if (flat2 > flat1) {
        cout << "Flat 2 is more expensive than Flat 1." << endl;
    }
    else {
        cout << "Flat 2 is not more expensive than Flat 1." << endl;
    }
}
