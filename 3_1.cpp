#include <iostream>
#include <string>

using namespace std;

class Employee {
    string name;
    double basic_salary;
    double bonus;

public:
    Employee() {}

    void initialize(string n, double b_salary, double b = 5000) {
        name = n;
        basic_salary = b_salary;
        bonus = b;
    }

    double total_salary() const {
        return basic_salary + bonus;
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Basic Salary: " << basic_salary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << total_salary() << endl << endl;
    }
};

void display_all(Employee employees[], int size, int index = 0) {
    if (index == size)
        return;
    employees[index].display();
    display_all(employees, size, index + 1);
}

int main() {
    const int num_employees = 4;
    Employee employees[num_employees];

    employees[0].initialize("Darshan", 55000);
    employees[1].initialize("Deep", 60000, 8000);
    employees[2].initialize("Krishiv", 52000);
    employees[3].initialize("Shaswat", 70000, 10000);

    display_all(employees, num_employees);

    cout << "\n24CE076_Pateldarshan\n";

    return 0;
}
