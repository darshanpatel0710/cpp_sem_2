#include <iostream>
using namespace std;

class BankAccount {
    char AccountHolder[20];
    long int AccountNumber;
    float Balance;

public:
    void AddDetail(int x) {
        cout << "Enter the Account holder Name: ";
        cin >> AccountHolder;
        cout << "Enter account number: ";
        AccountNumber=x;
        cout << "Enter your Balance: ";
        cin >> Balance;
    }

    void DepositMoney() {
        float Deposit;
        cout << "Enter the amount you want to deposit: ";
        cin >> Deposit;
        Balance += Deposit;
        cout << "Amount deposited successfully.\n";
    }

    long int GetAccNum() {
        return AccountNumber;
    }

    void WithdrawMoney() {
        float Withdraw;
        cout << "Enter the amount you want to withdraw: ";
        cin >> Withdraw;
        if (Withdraw > Balance) {
            cout << "Insufficient Balance\n";
        } else {
            Balance -= Withdraw;
            cout << "Withdrawal successful.\n";
        }
    }

    void DisplayDetails() {
        cout << "Account holder Name: " << AccountHolder << endl;
        cout << "Account Number: " << AccountNumber << endl;
        cout << "Balance is: " << Balance << endl;
    }
};

int main() {
    BankAccount B[2];
    int choice;
    long int AccNum;
    bool found;
    bool isDetailsAdded = false;

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
                    B[i].AddDetail(i+1);
                }
                isDetailsAdded = true;
                break;

            case 2:
                if (!isDetailsAdded) {
                    cout << "Please add account details first.\n";
                    break;
                }
                cout << "Enter Account number: ";
                cin >> AccNum;
                found = false;
                for (int i = 0; i < 2; i++) {
                    if (AccNum == B[i].GetAccNum()) {
                        B[i].DepositMoney();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found.\n";
                }
                break;

            case 3:
                if (!isDetailsAdded) {
                    cout << "Please add account details first.\n";
                    break;
                }
                cout << "Enter Account number: ";
                cin >> AccNum;
                found = false;
                for (int i = 0; i < 2; i++) {
                    if (AccNum == B[i].GetAccNum()) {
                        B[i].WithdrawMoney();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found.\n";
                }
                break;

            case 4:
                if (!isDetailsAdded) {
                    cout << "Please add account details first.\n";
                    break;
                }
                cout << "Enter Account number: ";
                cin >> AccNum;
                found = false;
                for (int i = 0; i < 2; i++) {
                    if (AccNum == B[i].GetAccNum()) {
                        B[i].DisplayDetails();
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
                cout<<"\n24CE076_PatelDarshan\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    }
}
