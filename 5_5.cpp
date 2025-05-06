#include <iostream>
#include <cmath>
using namespace std;

class shape {
public:
    virtual double area() = 0;
    virtual string name() = 0;
    virtual ~shape() {}
};

class rectangle : public shape {
private:
    double length, width;
public:
    rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double area() {
        return length * width;
    }

    string name() {
        return "rectangle";
    }
};

class circle : public shape {
private:
    double radius;
public:
    circle(double r) {
        radius = r;
    }

    double area() {
        return 3.14159 * radius * radius;
    }

    string name() {
        return "circle";
    }
};

int main() {
    const int size = 4;
    shape* shapes[size];

    shapes[0] = new rectangle(4, 5);
    shapes[1] = new circle(3);
    shapes[2] = new rectangle(2, 6);
    shapes[3] = new circle(2.5);

    for (int i = 0; i < size; i++) {
        cout << shapes[i]->name() << " Area: " << shapes[i]->area() << endl;
    }

    for (int i = 0; i < size; i++) {
        delete shapes[i];
    }

    cout<<"\nPatelDarshan_24CE076\n";

    return 0;
}
