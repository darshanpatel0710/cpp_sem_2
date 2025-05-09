#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

const int MAX_TRANSACTIONS = 100;

class bank_account {
private:
    string account_holder;
    double balance;
    string* transactions;
    int transaction_count;

    void log_transaction(const string& log) {
        if (transaction_count < MAX_TRANSACTIONS) {
            transactions[transaction_count++] = log;
        } else {
            cout << "Transaction log full. Unable to log further operations.\n";
        }
    }

public:
    bank_account(string name, double initial_balance) {
        account_holder = name;
        balance = initial_balance;
        transactions = new string[MAX_TRANSACTIONS];
        transaction_count = 0;
    }

    ~bank_account() {
        delete[] transactions;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Deposit amount must be positive.");
        }
        balance += amount;
        log_transaction("Deposited: ₹" + to_string(amount));
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Withdrawal amount must be positive.");
        }
        if (amount > balance) {
            throw runtime_error("Insufficient balance.");
        }
        balance -= amount;
        log_transaction("Withdrew: ₹" + to_string(amount));
    }

    void display_balance() const {
        cout << "Current Balance: ₹" << balance << endl;
    }

    void show_transaction_history() const {
        cout << "\nTransaction History for " << account_holder << ":\n";
        for (int i = 0; i < transaction_count; i++) {
            cout << i + 1 << ". " << transactions[i] << endl;
        }
    }
};

int main() {
    string name;
    double initial_balance;

    cout << "Enter account holder's name: ";
    getline(cin, name);
    cout << "Enter initial balance: ₹";
    cin >> initial_balance;

    bank_account account(name, initial_balance);

    int choice;
    double amount;

    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Show Balance\n4. Show Transaction History\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "Enter deposit amount: ₹";
                    cin >> amount;
                    account.deposit(amount);
                    break;
                case 2:
                    cout << "Enter withdrawal amount: ₹";
                    cin >> amount;
                    account.withdraw(amount);
                    break;
                case 3:
                    account.display_balance();
                    break;
                case 4:
                    account.show_transaction_history();
                    break;
                case 5:
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 5);

    cout << "24CE076_PatelDarshan" << endl;

    return 0;
}
