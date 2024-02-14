/*
Implement the basic class shape and derive triangle, rectangle, circle and square classes from it. Implement functions to compute the area and parameters of polygon.
Use pure virtual functions
*/

#include<iostream>
#include<cmath>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

class Triangle : public Shape {
private:
    double side1, side2, side3;
public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}
    double area() const override {
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    double perimeter() const override {
        return side1 + side2 + side3;
    }
};

class Rectangle : public Shape {
private:
    double length, breadth;
public:
    Rectangle(double l, double b) : length(l), breadth(b) {}
    double area() const override {
        return length * breadth;
    }
    double perimeter() const override {
        return 2 * (length + breadth);
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
    double perimeter() const override {
        return 2 * M_PI * radius;
    }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}
};

int main() {
    Triangle triangle(3, 4, 5);
    Rectangle rectangle(4, 5);
    Circle circle(3);
    Square square(4);

    cout << "Triangle area: " << triangle.area() << ", perimeter: " << triangle.perimeter() << endl;
    cout << "Rectangle area: " << rectangle.area() << ", perimeter: " << rectangle.perimeter() << endl;
    cout << "Circle area: " << circle.area() << ", circumference: " << circle.perimeter() << endl;
    cout << "Square area: " << square.area() << ", perimeter: " << square.perimeter() << endl;

    return 0;
}
