#include <iostream>
#include <string>

using namespace std;

class Account {
public:
    string accountNumber;
    string holderName;
    double balance;
    Account* next;

    Account(const string& accNum, const string& name, double initialBalance)
        : accountNumber(accNum), holderName(name), balance(initialBalance), next(nullptr) {}

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

    bool transferTo(Account& recipient, double amount) {
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

    bool createAccountRecursive(Account* current, const string& accNum, const string& name, double initialBalance) {
        if (current == nullptr) {
            return false;
        }
        if (current->accountNumber == accNum) {
            return true;
        }
        if (current->next == nullptr) {
            current->next = new Account(accNum, name, initialBalance);
            return true;
        }
        return createAccountRecursive(current->next, accNum, name, initialBalance);
    }

    Account* findAccountRecursive(Account* current, const string& accNum) {
        if (current == nullptr) {
            return nullptr;
        }
        if (current->accountNumber == accNum) {
            return current;
        }
        return findAccountRecursive(current->next, accNum);
    }

    int countAccountsRecursive(Account* current) {
        if (current == nullptr) {
            return 0;
        }
        return 1 + countAccountsRecursive(current->next);
    }

public:
    Bank() : head(nullptr) {}

    bool createAccount(const string& accNum, const string& name, double initialBalance) {
        if (head == nullptr) {
            head = new Account(accNum, name, initialBalance);
            return true;
        }
        return createAccountRecursive(head, accNum, name, initialBalance);
    }

    bool transfer(const string& fromAcc, const string& toAcc, double amount) {
        Account* sender = findAccountRecursive(head, fromAcc);
        Account* receiver = findAccountRecursive(head, toAcc);
        if (sender && receiver) {
            return sender->transferTo(*receiver, amount);
        }
        return false;
    }

    Account* getAccount(const string& accNum) {
        return findAccountRecursive(head, accNum);
    }

    int getTotalAccounts() {
        return countAccountsRecursive(head);
    }
};

int main() {
    Bank bank;
    bank.createAccount("123", "Darshan", 1000.0);
    bank.createAccount("456", "Krishiv", 500.0);
    bank.transfer("123", "456", 200.0);

    Account* acc = bank.getAccount("123");
    if (acc) {
        cout << acc->holderName << " Balance: " << acc->balance << endl;
    }

    acc = bank.getAccount("456");
    if (acc) {
        cout << acc->holderName << " Balance: " << acc->balance << endl;
    }

    cout << "Total Accounts: " << bank.getTotalAccounts() << endl;

    cout<<"\n24CE076_PatelDarshan\n";

    return 0;
}

