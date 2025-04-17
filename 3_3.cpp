#include <iostream>
#include <string>

using namespace std;

class Account {
public:
    string account_number;
    string holder_name;
    double balance;
    Account* next;

    Account(const string& acc_num, const string& name, double initial_balance)
        : account_number(acc_num), holder_name(name), balance(initial_balance), next(nullptr) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    bool transfer_to(Account& recipient, double amount) {
        if (withdraw(amount)) {
            recipient.deposit(amount);
            return true;
        }
        return false;
    }
};

class Bank {
private:
    Account* head;

    bool create_account_recursive(Account* current, const string& acc_num, const string& name, double initial_balance) {
        if (current == nullptr) {
            return false;
        }
        if (current->account_number == acc_num) {
            return true;
        }
        if (current->next == nullptr) {
            current->next = new Account(acc_num, name, initial_balance);
            return true;
        }
        return create_account_recursive(current->next, acc_num, name, initial_balance);
    }

    Account* find_account_recursive(Account* current, const string& acc_num) {
        if (current == nullptr) {
            return nullptr;
        }
        if (current->account_number == acc_num) {
            return current;
        }
        return find_account_recursive(current->next, acc_num);
    }

    int count_accounts_recursive(Account* current) {
        if (current == nullptr) {
            return 0;
        }
        return 1 + count_accounts_recursive(current->next);
    }

public:
    Bank() : head(nullptr) {}

    bool create_account(const string& acc_num, const string& name, double initial_balance) {
        if (head == nullptr) {
            head = new Account(acc_num, name, initial_balance);
            return true;
        }
        return create_account_recursive(head, acc_num, name, initial_balance);
    }

    bool transfer(const string& from_acc, const string& to_acc, double amount) {
        Account* sender = find_account_recursive(head, from_acc);
        Account* receiver = find_account_recursive(head, to_acc);
        if (sender && receiver) {
            return sender->transfer_to(*receiver, amount);
        }
        return false;
    }

    Account* get_account(const string& acc_num) {
        return find_account_recursive(head, acc_num);
    }

    int get_total_accounts() {
        return count_accounts_recursive(head);
    }
};

int main() {
    Bank bank;
    bank.create_account("123", "Darshan", 1000.0);
    bank.create_account("456", "Krishiv", 500.0);
    bank.transfer("123", "456", 200.0);

    Account* acc = bank.get_account("123");
    if (acc) {
        cout << acc->holder_name << " Balance: " << acc->balance << endl;
    }

    acc = bank.get_account("456");
    if (acc) {
        cout << acc->holder_name << " Balance: " << acc->balance << endl;
    }

    cout << "Total Accounts: " << bank.get_total_accounts() << endl;

    cout << "\n24CE076_PatelDarshan\n";

    return 0;
}
