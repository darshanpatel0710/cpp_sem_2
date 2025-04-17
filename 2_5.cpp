#include <iostream>
#include <cmath>
using namespace std;

class loan {
private:
    double loan_amount;
    double annual_interest_rate;
    int tenure_months;

public:
    void get_input() {
        cout << "Enter Loan Amount: ";
        cin >> loan_amount;
        cout << "Enter Annual Interest Rate (in %): ";
        cin >> annual_interest_rate;
        cout << "Enter Loan Tenure (in months): ";
        cin >> tenure_months;
    }

    double calculate_emi() {
        double monthly_rate = annual_interest_rate / (12 * 100);
        double emi = loan_amount * monthly_rate * pow(1 + monthly_rate, tenure_months) /
                     (pow(1 + monthly_rate, tenure_months) - 1);
        return emi;
    }

    void display_details() {
        double emi = calculate_emi();
        cout << "Loan Amount: " << loan_amount << endl;
        cout << "Annual Interest Rate: " << annual_interest_rate << "%" << endl;
        cout << "Loan Tenure: " << tenure_months << " months" << endl;
        cout << "Calculated EMI: " << emi << endl;
    }
};

int main() {
    loan l;
    l.get_input();
    l.display_details();

    cout << "\n24CE076_patel_darshan\n";
    return 0;
}
