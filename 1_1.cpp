#include <iostream>
using namespace std;

class BankAccount {
private:
    char accountHolderName[100];
    int accountNumber;
    double balance;

public:
    void setAccountDetails(const char* name, int number, double initialBalance) {
        int i = 0;
        while (name[i] != '\0' && i < 99) {
            accountHolderName[i] = name[i];
            i++;
        }
        accountHolderName[i] = '\0';
        accountNumber = number;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. Current balance: $" << balance << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds" << endl;
        } else if ((balance - amount) < 500) {
            cout << "Cannot withdraw. Minimum balance of 500 must be maintained." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful. Current balance: $" << balance << endl;
        }
    }

    void checkBalance() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: $" << balance << endl;
    }
};

int main() {
    BankAccount account;
    account.setAccountDetails("John Doe", 12345, 1000.0);
    int choice;
    double amount;
    do {
        cout << "\n1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.checkBalance();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 4);
   cout<<"24CE076_PatelDarshan";
    return 0;
}
