#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void add_item(const string& filename) {
    ofstream file(filename, ios::app);
    string name;
    int quantity;
    double price;
    cout << "Enter item name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Enter quantity and price: ";
    cin >> quantity >> price;
    file << name << ',' << quantity << ',' << price << '\n';
}

void view_inventory(const string& filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
}

void search_item(const string& filename) {
    ifstream file(filename);
    string target, line, name;
    cout << "Enter item name to search: ";
    cin >> ws;
    getline(cin, target);
    bool found = false;
    while (getline(file, line)) {
        size_t pos1 = line.find(',');
        name = line.substr(0, pos1);
        if (name == target) {
            cout << line << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Item not found" << endl;
}

int main() {
    string filename = "inventory.txt";
    int choice;
    while (true) {
        cout << "Enter 1 to add, 2 to view, 3 to search, 0 to exit: ";
        cin >> choice;
        if (choice == 1) add_item(filename);
        else if (choice == 2) view_inventory(filename);
        else if (choice == 3) search_item(filename);
        else break;
    }
    return 0;
}
