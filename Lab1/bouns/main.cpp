#include <iostream>
using namespace std;

// Abstract class representing a sorting algorithm
class Sorter {
public:
    virtual void sort(int* arr, size_t size) = 0;
    virtual bool compare(int a, int b) const = 0;
    virtual ~Sorter() {}

    // Common bubble sort implementation
    void bubbleSort(int* arr, size_t size) {
        for (size_t i = 0; i < size - 1; ++i) {
            for (size_t j = 0; j < size - i - 1; ++j) {
                if (compare(arr[j], arr[j + 1])) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};

class AscendingSorter : public Sorter {
public:
    void sort(int* arr, size_t size) override {
        bubbleSort(arr, size);
    }

    bool compare(int a, int b) const override {
        return a > b;
    }
};

class DescendingSorter : public Sorter {
public:
    void sort(int* arr, size_t size) override {
        bubbleSort(arr, size);
    }

    bool compare(int a, int b) const override {
        return a < b;
    }
};

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    // Using abstract class pointer for polymorphism
    Sorter* ascendingSorter = new AscendingSorter();
    Sorter* descendingSorter = new DescendingSorter();

    // Original Array
    cout << "Original Array: ";
    for (size_t i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Ascending Order
    ascendingSorter->sort(arr, n);
    cout << "Ascending Order: ";
    for (size_t i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Descending Order
    descendingSorter->sort(arr, n);
    cout << "Descending Order: ";
    for (size_t i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Cleanup
    delete ascendingSorter;
    delete descendingSorter;

    return 0;
}



