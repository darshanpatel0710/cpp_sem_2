#include <iostream>
using namespace std;

class base {
public:
    base() {
        cout << "Base constructor\n";
    }

    virtual ~base() {
        cout << "Base destructor\n";
    }
};

class derived : public base {
private:
    int* data;

public:
    derived() {
        data = new int[5];
        cout << "Derived constructor: memory allocated\n";
    }

    ~derived() {
        delete[] data;
        cout << "Derived destructor: memory released\n";
    }
};

int main() {
    base* obj = new derived();
    delete obj;
    cout << "24CE076_PatelDarshan";
    return 0;
}
