#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

//class Equation {
//public:
//    virtual vector<double> findRoots() const = 0;
//    virtual ~Equation() {}
//};
//
//class LinearEquation : public Equation {
//private:
//    double a, b;
//
//public:
//    LinearEquation(double a, double b) : a(a), b(b) {}
//
//    vector<double> findRoots() const override {
//        if (a == 0) {
//            cerr << "Error: a cannot be zero in a linear equation" << endl;
//            return {};
//        }
//        return { -b / a };
//    }
//};
//
//class QuadraticEquation : public Equation {
//private:
//    double a, b, c;
//
//public:
//    QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}
//
//    vector<double> findRoots() const override {
//        if (a == 0) {
//            cerr << "Error: a cannot be zero in a quadratic equation" << endl;
//            return {};
//        }
//        double discriminant = b * b - 4 * a * c;
//        if (discriminant < 0) {
//            cerr << "Error: No real roots" << endl;
//            return {};
//        }
//        else if (discriminant == 0) {
//            return { -b / (2 * a) };
//        }
//        else {
//            double sqrt_discriminant = sqrt(discriminant);
//            return {
//                (-b + sqrt_discriminant) / (2 * a),
//                (-b - sqrt_discriminant) / (2 * a)
//            };
//        }
//    }
//};

//=================================================

//2

class Shape {
public:
    virtual void Show() const = 0;
    virtual void Save(ofstream& out) const = 0;
    virtual void Load(ifstream& in) = 0;
    virtual ~Shape() {}
};

class Square : public Shape {
private:
    int x, y;
    int side;
public:
    Square(int x = 0, int y = 0, int side = 0) : x(x), y(y), side(side) {}

    void Show() const override {
        cout << "Square: (" << x << ", " << y << "), side: " << side << endl;
    }

    void Save(ofstream& out) const override {
        out << "Square " << x << " " << y << " " << side << endl;
    }

    void Load(ifstream& in) override {
        in >> x >> y >> side;
    }
};

class Rectangle : public Shape {
private:
    int x, y;
    int width, height;
public:
    Rectangle(int x = 0, int y = 0, int width = 0, int height = 0) : x(x), y(y), width(width), height(height) {}

    void Show() const override {
        cout << "Rectangle: (" << x << ", " << y << "), width: " << width << ", height: " << height << endl;
    }

    void Save(ofstream& out) const override {
        out << "Rectangle " << x << " " << y << " " << width << " " << height << endl;
    }

    void Load(ifstream& in) override {
        in >> x >> y >> width >> height;
    }
};

class Circle : public Shape {
private:
    int x, y;
    int radius;
public:
    Circle(int x = 0, int y = 0, int radius = 0) : x(x), y(y), radius(radius) {}

    void Show() const override {
        cout << "Circle: center(" << x << ", " << y << "), radius: " << radius << endl;
    }

    void Save(ofstream& out) const override {
        out << "Circle " << x << " " << y << " " << radius << endl;
    }

    void Load(ifstream& in) override {
        in >> x >> y >> radius;
    }
};

class Ellipse : public Shape {
private:
    int x, y;
    int width, height;
public:
    Ellipse(int x = 0, int y = 0, int width = 0, int height = 0) : x(x), y(y), width(width), height(height) {}

    void Show() const override {
        cout << "Ellipse: top-left(" << x << ", " << y << "), width: " << width << ", height: " << height << endl;
    }

    void Save(ofstream& out) const override {
        out << "Ellipse " << x << " " << y << " " << width << " " << height << endl;
    }

    void Load(ifstream& in) override {
        in >> x >> y >> width >> height;
    }
};


int main()
{
    //1

    //LinearEquation linearEq(2, -4);
    //vector<double> linearRoots = linearEq.findRoots();
    //if (!linearRoots.empty()) {
    //    cout << "Linear equation root: " << linearRoots[0] << endl;
    //}

    //QuadraticEquation quadraticEq(1, -3, 2);
    //vector<double> quadraticRoots = quadraticEq.findRoots();
    //if (!quadraticRoots.empty()) {
    //    cout << "Quadratic equation roots: " << quadraticRoots[0] << ", " << quadraticRoots[1] << endl;
    //}

    //=================================================

    //2

    vector<Shape*> shapes;
    shapes.push_back(new Square(0, 0, 10));
    shapes.push_back(new Rectangle(5, 5, 15, 20));
    shapes.push_back(new Circle(10, 10, 5));
    shapes.push_back(new Ellipse(2, 2, 8, 4));

    ofstream outFile("shapes.txt");
    if (!outFile) {
        cerr << "Error opening file for writing" << endl;
        return 1;
    }

    for (const auto& shape : shapes) {
        shape->Show();
    }

    for (const auto& shape : shapes) {
        shape->Save(outFile);
    }
    outFile.close();

    for (auto& shape : shapes) {
        delete shape;
    }
}
