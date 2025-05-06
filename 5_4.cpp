#include <iostream>
using namespace std;

class Fahrenheit;

class Celsius {
public:
    double value;

    Celsius(double val = 0.0) {
        value = val;
    }

    operator Fahrenheit();

    bool operator==(const Celsius& other) const {
        return value == other.value;
    }
};

class Fahrenheit {
public:
    double value;

    Fahrenheit(double val = 0.0) {
        value = val;
    }

    operator Celsius() {
        return Celsius((value - 32) * 5.0 / 9.0);
    }

    bool operator==(const Fahrenheit& other) const {
        return value == other.value;
    }
};

Celsius::operator Fahrenheit() {
    return Fahrenheit(value * 9.0 / 5.0 + 32);
}

int main() {
    const int size = 3;
    Celsius tempArray[size];

    for (int i = 0; i < size; i++) {
        double input;
        cout << "Enter temperature in Celsius #" << i + 1 << ": ";
        cin >> input;
        tempArray[i] = Celsius(input);
    }

    for (int i = 0; i < size; i++) {
        Fahrenheit f = tempArray[i];
        cout << "Celsius: " << tempArray[i].value << " -> Fahrenheit: " << f.value << " F" << endl;
    }

    cout<<"\nPatelDarshan_24CE076";


    return 0;
}
