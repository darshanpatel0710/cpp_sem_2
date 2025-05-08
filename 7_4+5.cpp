#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

class student {
public:
    string name;
    int marks;
    char grade;
    double fees;  // New member for student fees

    student(string n, int m, char g, double f) : name(n), marks(m), grade(g), fees(f) {}
};

class report_generator {
public:
    static void generate_report_direct(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Error: Unable to open file!" << endl;
            return;
        }

        string name;
        int marks;
        char grade;
        double fees;

        cout << left << setw(20) << "Name" << setw(10) << "Marks" << setw(10) << "Grade" << setw(10) << "Fees" << endl;
        cout << "--------------------------------------------------------" << endl;

        while (file >> name >> marks >> grade >> fees) {
            cout << setw(20) << name << setw(10) << marks << setw(10) << grade << setw(10) << fixed << setprecision(2) << fees << endl;
        }

        file.close();
    }

    static void generate_report_stored(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Error: Unable to open file!" << endl;
            return;
        }

        vector<student> students;
        string name;
        int marks;
        char grade;
        double fees;

        while (file >> name >> marks >> grade >> fees) {
            students.push_back(student(name, marks, grade, fees));
        }

        file.close();

        cout << left << setw(20) << "Name" << setw(10) << "Marks" << setw(10) << "Grade" << setw(10) << "Fees" << endl;
        cout << "--------------------------------------------------------" << endl;

        for (const auto& stu : students) {
            cout << setw(20) << stu.name << setw(10) << stu.marks << setw(10) << stu.grade << setw(10) << fixed << setprecision(2) << stu.fees << endl;
        }
    }
};

int main() {
    string filename = "students.txt"; // Sample file path
    report_generator::generate_report_direct(filename);
    cout << endl;
    report_generator::generate_report_stored(filename);

    return 0;
}
