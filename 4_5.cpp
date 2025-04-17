#include <iostream>
using namespace std;

class grade {
protected:
    string name;
    float m[3];

public:
    virtual char compute_grade() = 0;
    void input() {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter 3 marks: ";
        for (int i = 0; i < 3; ++i) {
            cin >> m[i];
        }
    }

    void display() {
        cout << "Student: " << name << "\nGrade: " << compute_grade() << endl;
    }

    virtual ~grade() {}
};

class undergraduate : public grade {
public:
    char compute_grade() override {
        float total = 0;
        for (int i = 0; i < 3; ++i) total += m[i];
        float avg = total / 3;

        if (avg >= 45) return 'P';
        else return 'F';
    }
};


class postgraduate : public grade {
public:
    char compute_grade() override {
        float total = 0;
        for (int i = 0; i < 3; ++i) total += m[i];
        float avg = total / 3;

        if (avg >= 50) return 'P';
        else return 'F';
    }
};


int main() {
     int choice;
    cout << "Enter student type:\n1. Undergraduate\n2. Postgraduate\nChoice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            undergraduate ug;
            ug.input();
            cout << "\n--- Grade Result ---\n";
            ug.display();
            break;
        }
        case 2: {
            postgraduate pg;
            pg.input();
            cout << "\n--- Grade Result ---\n";
            pg.display();
            break;
        }
        default:
            cout << "Invalid choice.\n";
            break;
    }
    cout<<endl<<"\n24CE076_PatelDarshan\n"<<endl;
    return 0;
}
