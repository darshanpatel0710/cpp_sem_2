#include <iostream>
#include <string>

using namespace std;

class Employee {
    string name;
    double basicSalary;
    double bonus;

public:
    Employee() {}

    void initialize(string n, double bSalary, double b = 5000) {
        name = n;
        basicSalary = bSalary;
        bonus = b;
    }

    double totalSalary() const {
        return basicSalary + bonus;
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << totalSalary() << endl << endl;
    }
};

void displayAll(Employee employees[], int size, int index = 0) {
    if (index == size)
        return;
    employees[index].display();
    displayAll(employees, size, index + 1);
}

int main() {
    const int numEmployees = 4;
    Employee employees[numEmployees];

    employees[0].initialize("Darshan", 55000);
    employees[1].initialize("Deep", 60000, 8000);
    employees[2].initialize("Krishiv", 52000);
    employees[3].initialize("Shaswat", 70000, 10000);

    displayAll(employees, numEmployees);

    cout<<"\n24CE076_Pateldarshan\n";

    return 0;
}
