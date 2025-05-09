#include <iostream>
#include <limits>
using namespace std;

bool get_valid_input(double &value, const string &prompt) {
    while (true) {
        cout << prompt;
        cin >> value;
        
        // Check if input is valid
        if (cin.fail()) {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the bad input
            cout << "Invalid input. Please enter a numeric value.\n";
        } else {
            return true; // Input is valid
        }
    }
}

int main() {
    double loan_amount = 0, income = 0;

    // Get valid loan amount input
    get_valid_input(loan_amount, "Enter loan amount: ");

    // Get valid income input (with validation for zero income)
    do {
        get_valid_input(income, "Enter annual income: ");
        if (income == 0) {
            cout << "Annual income cannot be zero. Please re-enter.\n";
        }
    } while (income == 0);

    // Calculate loan-to-income ratio
    double ratio = loan_amount / income;

    // Output the ratio with precision
    cout.precision(2);
    cout << fixed;
    cout << "Loan-to-Income Ratio: " << ratio << endl;

    cout << "24CE076_PatelDarshan" << endl;

    return 0;
}
