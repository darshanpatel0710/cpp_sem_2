#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout<<"Enter number of transaction IDs: ";
    cin>>n;

    vector<int> transactions(n);
    cout<<"Enter transaction IDs:\n";
    for (int i=0; i < n; ++i) {
        cin>>transactions[i];
    }

    // Sort the vector
    sort(transactions.begin(), transactions.end());

    // Remove duplicates manually
    vector<int> uniqueIDs;
    for (int i=0; i < n; ++i) {
        if (i == 0 || transactions[i] != transactions[i - 1]) {
            uniqueIDs.push_back(transactions[i]);
        }
    }

    // Display unique sorted transaction IDs
    cout<<"\nUnique Transaction IDs (sorted):\n";
    for (int id : uniqueIDs) {
        cout<<id<<" ";
    }
    cout<<endl;
    cout<<"24CE076_PatelDarshan";
    return 0;
}
