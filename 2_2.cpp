#include <iostream>
#include <string>
using namespace std;

class student {
private:
    int roll_number;
    string name;
    int marks_1, marks_2, marks_3;

public:
    student() {
        roll_number = -1;
        name = "Rahul";
        marks_1 = marks_2 = marks_3 = 0;
    }

    student(int r, string n, int m1, int m2, int m3) {
        roll_number = r;
        name = n;
        marks_1 = m1;
        marks_2 = m2;
        marks_3 = m3;
    }

    float calculate_average() {
        return (marks_1 + marks_2 + marks_3) / 3.0;
    }

    void display_details() {
        cout << "Roll Number: " << roll_number << endl;
        cout << "Name: " << name << endl;
        cout << "Marks in Subject 1: " << marks_1 << endl;
        cout << "Marks in Subject 2: " << marks_2 << endl;
        cout << "Marks in Subject 3: " << marks_3 << endl;
        cout << "Average Marks: " << calculate_average() << endl;
        cout << "-----------------------------" << endl;
    }
};

int main() {
    const int max_students = 10;
    student students[max_students];
    int student_count = 0;
    int choice;

menu:
    cout << "\n===== Student Record Menu =====\n";
    cout << "1. Add Default Students (Using Loop)\n";
    cout << "2. Add Student (With Input)\n";
    cout << "3. Display All Students\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int num;
            cout << "How many default students to add? ";
            cin >> num;

            if (num <= 0) {
                cout << "Please enter a valid positive number.\n";
            } else if (student_count + num <= max_students) {
                for (int i = 0; i < num; i++) {
                    students[student_count] = student();
                    student_count++;
                }
                cout << num << " default students added successfully.\n";
            } else {
                cout << "Not enough space to add " << num << " students.\n";
            }
            goto menu;
        }

        case 2: {
            if (student_count < max_students) {
                int roll, m1, m2, m3;
                string student_name;
                cout << "Enter Roll Number: ";
                cin >> roll;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, student_name);
                cout << "Enter Marks in Subject 1: ";
                cin >> m1;
                cout << "Enter Marks in Subject 2: ";
                cin >> m2;
                cout << "Enter Marks in Subject 3: ";
                cin >> m3;

                students[student_count] = student(roll, student_name, m1, m2, m3);
                student_count++;
                cout << "Student added successfully.\n";
            } else {
                cout << "Student limit reached.\n";
            }
            goto menu;
        }

        case 3: {
            if (student_count == 0) {
                cout << "No student records to display.\n";
            } else {
                cout << "\n--- All Student Records ---\n";
                for (int i = 0; i < student_count; i++) {
                    students[i].display_details();
                }
            }
            goto menu;
        }

        case 4:
            cout << "Exiting the program.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
            goto menu;
    }

    return 0;
}
