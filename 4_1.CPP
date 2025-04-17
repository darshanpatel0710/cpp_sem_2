#include <iostream>
#include <cmath>
using namespace std;

class Shape {
private:
    double radius;

public:
    Shape(double r = 0.0) : radius(r) {}

    void set_radius(double r) {
        radius = r;
    }

    double get_radius() {
        return radius;
    }
};

class Circle : public Shape {
public:
    Circle(double r = 0.0) : Shape(r) {}

    double calculate_area() {
        return M_PI * get_radius() * get_radius();
    }
};

int main() {
    const int size = 3;
    Circle circles[size] = { Circle(1.5), Circle(2.0), Circle(2.8) };

    for (int i = 0; i < size; ++i) {
        cout << "Circle " << i + 1 << " Area: " << circles[i].calculate_area() << endl;
    }

    cout << "\n24CE076_PatelDarshan\n";

    return 0;
}
