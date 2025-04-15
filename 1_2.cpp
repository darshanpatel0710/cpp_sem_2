#include <iostream>
#include <cstring>

using namespace std;

class product
{
public:
    int product_id;
    char name[50];
    int quantity;
    double price;

    void add_product(int id, const char* product_name, int qty, double cost) {
        product_id = id;
        strcpy(name, product_name);
        quantity = qty;
        price = cost;
    }

    void update_quantity(int qty) {
        quantity += qty;
    }

    double total_value() {
        return quantity * price;
    }
};

int main() {
    product inventory[10];
    int product_count = 0;

    int choice, id, qty, found;
    double cost;
    char name[50];
    double total_inventory_value = 0;

start:
    cout << "\nInventory Management System\n";
    cout << "1. Add a new product\n";
    cout << "2. Update product quantity\n";
    cout << "3. Calculate total inventory value\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            if (product_count < 10) {
                cout << "Enter product ID: ";
                cin >> id;
                cout << "Enter product name: ";
                cin >> name;
                cout << "Enter product quantity: ";
                cin >> qty;
                cout << "Enter product price: ";
                cin >> cost;

                inventory[product_count].add_product(id, name, qty, cost);
                product_count++;
                cout << "Product added successfully!\n";
            } else {
                cout << "Inventory full! Cannot add more products.\n";
            }
            break;

        case 2:
            cout << "Enter product ID to update quantity: ";
            cin >> id;
            found = 0;

            for (int i = 0; i < product_count; i++) {
                if (inventory[i].product_id == id) {
                    cout << "Enter quantity change (positive for restock, negative for sale): ";
                    cin >> qty;
                    inventory[i].update_quantity(qty);
                    found = 1;
                    cout << "Product quantity updated!\n";
                    break;
                }
            }
            if (found == 0) {
                cout << "Product with ID " << id << " not found.\n";
            }
            break;

        case 3:
            total_inventory_value = 0;
            for (int i = 0; i < product_count; i++) {
                total_inventory_value += inventory[i].total_value();
            }
            cout << "Total value of inventory: $" << total_inventory_value << endl;
            break;

        case 4:
            cout << "Exiting the system. Goodbye!\n";
            return 0;

        default:
            cout << "Invalid choice, please try again.\n";
    }
    goto start;

    cout<<"24CE076_PatelDarshan";
    return 0;
}
