#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arrays;
    int n;
   cout<< "Enter how many elements you want to enter: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        arrays.push_back(element);
    }

   cout<< "The original array before reversing is:" << endl;
    for (int ele : arrays) {
       cout<< ele << " ";
    }


    reverse(arrays.begin(), arrays.end());
   cout<< endl << endl << "The array after reversing using dynamic inbuilt function is:" << endl;
    for (int ele : arrays) {
       cout<< ele << " ";
    }

    int start = 0;
    int size = arrays.size();
    int end = size - 1;

    while (start < end) {
        swap(arrays[start], arrays[end]);
        start++;
        end--;
    }

   cout<< endl << endl << "The array after reversing using iterator is:" << endl;
    for (int i = 0; i < arrays.size(); i++) {
       cout<< arrays[i] << " ";
    }

   cout<< endl << "24CE076_PatelDarshan" << endl;

    return 0;
}
