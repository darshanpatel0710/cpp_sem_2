#include <iostream>
#include <cmath>
using namespace std;
class Loan {
private:
    double loanAmount;
    double annualInterestRate;
    int tenureMonths;

public:
    void getInput() {
        cout << "Enter Loan Amount: ";
        cin >> loanAmount;
        cout << "Enter Annual Interest Rate (in %): ";
        cin >> annualInterestRate;
        cout << "Enter Loan Tenure (in months): ";
        cin >> tenureMonths;
    }
    double calculateEMI() {
        double monthlyRate = annualInterestRate / (12 * 100);
        double emi = loanAmount * monthlyRate * pow(1 + monthlyRate, tenureMonths) / (pow(1 + monthlyRate, tenureMonths) - 1);
        return emi;
    }
    void displayDetails() {
        double emi = calculateEMI();
        cout << "Loan Amount: " << loanAmount << endl;
        cout << "Annual Interest Rate: " << annualInterestRate << "%" << endl;
        cout << "Loan Tenure: " << tenureMonths << " months" << endl;
        cout << "Calculated EMI: " << emi << endl;
    }
};

int main() {
    Loan loan;
    loan.getInput();
    loan.displayDetails();

    cout<<"\n24CE076_PatelDarshan\n";
    return 0;
}
