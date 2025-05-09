#include <iostream>
using namespace std;

class sorted_merger {
private:
    int* arr1;
    int* arr2;
    int size1;
    int size2;
    int* merged;
    int merged_size;

public:
    sorted_merger(int s1, int s2) {
        size1 = s1;
        size2 = s2;
        arr1 = new int[size1];
        arr2 = new int[size2];
        merged_size = size1 + size2;
        merged = new int[merged_size];
    }

    void read_arrays() {
        cout << "Enter " << size1 << " sorted elements for first array:\n";
        for (int i = 0; i < size1; ++i) {
            cin >> arr1[i];
        }

        cout << "Enter " << size2 << " sorted elements for second array:\n";
        for (int i = 0; i < size2; ++i) {
            cin >> arr2[i];
        }
    }

    void merge_arrays() {
        int i = 0, j = 0, k = 0;

        while (i < size1 && j < size2) {
            if (arr1[i] < arr2[j]) {
                merged[k++] = arr1[i++];
            } else {
                merged[k++] = arr2[j++];
            }
        }

        while (i < size1) {
            merged[k++] = arr1[i++];
        }

        while (j < size2) {
            merged[k++] = arr2[j++];
        }
    }

    void display_merged_array() const {
        cout << "Merged sorted array:\n";
        for (int i = 0; i < merged_size; ++i) {
            cout << merged[i] << " ";
        }
        cout << "\n";
    }

    ~sorted_merger() {
        delete[] arr1;
        delete[] arr2;
        delete[] merged;
    }
};

int main() {
    int size1, size2;

    cout << "Enter size of first sorted array: ";
    cin >> size1;
    cout << "Enter size of second sorted array: ";
    cin >> size2;

    sorted_merger merger(size1, size2);

    merger.read_arrays();
    merger.merge_arrays();
    merger.display_merged_array();

    cout << "24CE076_PatelDarshan";

    return 0;
}
