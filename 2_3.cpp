#include <iostream>
using namespace std;

class bank_account {
    char account_holder[20];
    long int account_number;
    float balance;

public:
    void add_detail(int x) {
        cout << "Enter the Account holder Name: ";
        cin >> account_holder;
        cout << "Enter account number: ";
        account_number = x;
        cout << "Enter your Balance: ";
        cin >> balance;
    }

    void deposit_money() {
        float deposit;
        cout << "Enter the amount you want to deposit: ";
        cin >> deposit;
        balance += deposit;
        cout << "Amount deposited successfully.\n";
    }

    long int get_acc_num() {
        return account_number;
    }

    void withdraw_money() {
        float withdraw;
        cout << "Enter the amount you want to withdraw: ";
        cin >> withdraw;
        if (withdraw > balance) {
            cout << "Insufficient Balance\n";
        } else {
            balance -= withdraw;
            cout << "Withdrawal successful.\n";
        }
    }

    void display_details() {
        cout << "Account holder Name: " << account_holder << endl;
        cout << "Account Number: " << account_number << endl;
        cout << "Balance is: " << balance << endl;
    }
};

int main() {
    bank_account b[2];
    int choice;
    long int acc_num;
    bool found;
    bool is_details_added = false;

    while (true) {
        cout << "--------------------------------\n";
        cout << "Enter 1 to add details\n";
        cout << "Enter 2 to deposit money\n";
        cout << "Enter 3 to withdraw money\n";
        cout << "Enter 4 to display details\n";
        cout << "Enter 5 to exit\n";
        cout << "--------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < 2; i++) {
                    cout << "\nEntering details for account " << i + 1 << ":\n";
                    b[i].add_detail(i + 1);
                }
                is_details_added = true;
                break;

            case 2:
                if (!is_details_added) {
                    cout << "Please add account details first.\n";
                    break;
                }
                cout << "Enter Account number: ";
                cin >> acc_num;
                found = false;
                for (int i = 0; i < 2; i++) {
                    if (acc_num == b[i].get_acc_num()) {
                        b[i].deposit_money();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found.\n";
                }
                break;

            case 3:
                if (!is_details_added) {
                    cout << "Please add account details first.\n";
                    break;
                }
                cout << "Enter Account number: ";
                cin >> acc_num;
                found = false;
                for (int i = 0; i < 2; i++) {
                    if (acc_num == b[i].get_acc_num()) {
                        b[i].withdraw_money();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found.\n";
                }
                break;

            case 4:
                if (!is_details_added) {
                    cout << "Please add account details first.\n";
                    break;
                }
                cout << "Enter Account number: ";
                cin >> acc_num;
                found = false;
                for (int i = 0; i < 2; i++) {
                    if (acc_num == b[i].get_acc_num()) {
                        b[i].display_details();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found.\n";
                }
                break;

            case 5:
                cout << "Exiting program. Goodbye!\n";
                cout << "\n24CE076_PatelDarshan\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    }
}
