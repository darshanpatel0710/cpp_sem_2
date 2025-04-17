#include<iostream>
using namespace std;

int recursive_sum(int* arr, int n) {
    if (n == 0) {
        return 0;
    }
    return arr[n - 1] + recursive_sum(arr, n - 1);
}

int iterative_sum(int* arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int size;
    cout << "Enter the size of array you want to create: ";
    cin >> size;
    cout << endl;

    int* array = new int[size];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }

    int recursive_result = recursive_sum(array, size);
    cout << "Recursive sum: " << recursive_result << endl;

    int iterative_result = iterative_sum(array, size);
    cout << "Iterative sum: " << iterative_result << endl;

    delete[] array;
    cout << "\n24CE076_PatelDarshan\n" << endl;
    return 0;
}

