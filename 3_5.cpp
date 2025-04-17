#include <iostream>
using namespace std;

long long calculate_super_digit(string n, int k) {
    long long digit_sum = 0;
    for (char digit : n) {
        digit_sum += digit - '0';
    }

    digit_sum *= k;

    while (digit_sum >= 10) {
        long long temp_sum = 0;
        while (digit_sum > 0) {
            temp_sum += digit_sum % 10;
            digit_sum /= 10;
        }
        digit_sum = temp_sum;
    }

    return digit_sum;
}

int main() {
    string n;
    int k;
    cout << "Enter the number as a string: ";
    cin >> n;
    cout << "Enter the how many times you want to concate the number: ";
    cin >> k;

    cout << "Super Digit: " << calculate_super_digit(n, k) << endl;

    cout<<"\n24CE076_PatelDarshan\n";
    return 0;
}
