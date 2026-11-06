// Runtime polymorphism: Shape (base) -> Circle, Rectangle, Triangle
#include <iostream>
using namespace std;

const double PI = 3.14159265;

// Parent class with virtual functions
class Shape {
public:
    virtual double area() const = 0;        // pure virtual: every shape must provide its own
    virtual void describe() const {         // virtual with a default version
        cout << "A shape";
    }
    virtual ~Shape() {}                     // virtual destructor for safe cleanup
};

// Derived class 1
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return PI * radius * radius; }
    void describe() const override { cout << "Circle with radius " << radius; }
};

// Derived class 2
class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
    void describe() const override { cout << "Rectangle " << width << " x " << height; }
};

// Derived class 3
class Triangle : public Shape {
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override { return 0.5 * base * height; }
    void describe() const override { cout << "Triangle with base " << base << " and height " << height; }
};

// Takes a reference to the BASE class. The version that runs depends on the real object.
void printInfo(const Shape& s) {
    s.describe();
    cout << " -> area = " << s.area() << endl;
}

int main() {
    // 1. Base-class pointers pointing to different derived objects
    Shape* shapes[3];
    shapes[0] = new Circle(3.0);
    shapes[1] = new Rectangle(4.0, 5.0);
    shapes[2] = new Triangle(6.0, 2.5);

    cout << "--- Through base-class pointers ---" << endl;
    for (int i = 0; i < 3; ++i) {
        shapes[i]->describe();                       // same call...
        cout << " -> area = " << shapes[i]->area()   // ...different behaviour
             << endl;
    }

    // 2. Through a base-class reference
    cout << "\n--- Through a base-class reference ---" << endl;
    Circle c(1.0);
    Rectangle r(2.0, 3.0);
    printInfo(c);
    printInfo(r);

    // Clean up (the virtual destructor makes this safe)
    for (int i = 0; i < 3; ++i) delete shapes[i];

    return 0;
}
