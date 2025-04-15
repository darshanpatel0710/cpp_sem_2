#include <iostream>
using namespace std;

class bank_account 
{

    char account_holder_name[100];
    int account_number;
    double account_balance;

public:
    void set_account_details(const char* holder_name, int acc_number, double initial_balance) {
        int i = 0;
        while (holder_name[i] != '\0' && i < 99) {
            account_holder_name[i] = holder_name[i];
            i++;
        }
        account_holder_name[i] = '\0';
        account_number = acc_number;
        account_balance = initial_balance;
    }

    void deposit_amount(double deposit_amount) {
        if (deposit_amount > 0) {
            account_balance += deposit_amount;
            cout << "Deposit successful. Current balance: $" << account_balance << endl;
        }
    }

    void withdraw_amount(double withdraw_amount) {
        if (withdraw_amount > account_balance) {
            cout << "Insufficient funds" << endl;
        } else if ((account_balance - withdraw_amount) < 500) {
            cout << "Cannot withdraw. Minimum balance of 500 must be maintained." << endl;
        } else {
            account_balance -= withdraw_amount;
            cout << "Withdrawal successful. Current balance: $" << account_balance << endl;
        }
    }

    void check_account_balance() {
        cout << "Account Number: " << account_number << endl;
        cout << "Account Holder: " << account_holder_name << endl;
        cout << "Balance: $" << account_balance << endl;
    }
};

int main() {
    bank_account user_account;
    user_account.set_account_details("John Doe", 12345, 1000.0);
    
    int user_choice;
    double transaction_amount;
    
    do {
        cout << "\n1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> user_choice;

        switch (user_choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> transaction_amount;
                user_account.deposit_amount(transaction_amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> transaction_amount;
                user_account.withdraw_amount(transaction_amount);
                break;
            case 3:
                user_account.check_account_balance();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (user_choice != 4);

    cout << "24CE076_PatelDarshan";
    return 0;
}
