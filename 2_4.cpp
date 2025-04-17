#include <iostream>
#include <string>
using namespace std;

class item {
private:
    int id;
    string name;
    double price;
    int quantity;

public:
    item() : id(0), name("unknown"), price(0.0), quantity(0) {}

    item(int i, string n, double p, int q) : id(i), name(n), price(p), quantity(q) {}

    void set_details(int i, string n, double p, int q) {
        id = i;
        name = n;
        price = p;
        quantity = q;
    }

    void add_stock(int amount) {
        if (amount > 0)
            quantity += amount;
    }

    bool sell(int amount) {
        if (amount > 0 && amount <= quantity) {
            quantity -= amount;
            return true;
        }
        return false;
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name
             << ", Price: $" << price << ", Quantity: " << quantity << endl;
    }

    int get_id() const {
        return id;
    }
};

int main() {
    int size;
    cout << "Enter number of items to manage: ";
    cin >> size;

    item* inventory = new item[size];

    for (int i = 0; i < size; ++i) {
        int id, quantity;
        double price;
        string name;
        cout << "\nEnter details for item " << (i + 1) << ":\n";

        id = i + 1;
        cin.ignore();
        cout << "Name: ";
        getline(cin, name);
        cout << "Price: ";
        cin >> price;
        cout << "Quantity: ";
        cin >> quantity;
        inventory[i].set_details(id, name, price, quantity);
    }

    int choice, item_id, amount;
    bool running = true;

    while (running) {
        cout << "\n1. Add Stock\n2. Sell Item\n3. Display Inventory\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item ID to add stock: ";
                cin >> item_id;
                cout << "Enter amount to add: ";
                cin >> amount;
                for (int i = 0; i < size; ++i) {
                    if (inventory[i].get_id() == item_id) {
                        inventory[i].add_stock(amount);
                        break;
                    }
                }
                break;

            case 2:
                cout << "Enter item ID to sell: ";
                cin >> item_id;
                cout << "Enter amount to sell: ";
                cin >> amount;
                for (int i = 0; i < size; ++i) {
                    if (inventory[i].get_id() == item_id) {
                        if (!inventory[i].sell(amount)) {
                            cout << "Not enough stock.\n";
                        }
                        break;
                    }
                }
                break;

            case 3:
                for (int i = 0; i < size; ++i) {
                    inventory[i].display();
                }
                break;

            case 4:
                running = false;
                break;

            default:
                cout << "Invalid choice.\n";
        }
    }

    delete[] inventory;

    cout << "24CE076_patel_darshan\n";
    return 0;
}
