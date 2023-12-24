#include <iostream>
#include <string>
using namespace std;

void selectionSort(string array[], int length) {
    for (int j = 0; j < length - 1; j++) {
        int min = j;
        for (int k = j + 1; k < length; k++) {
            if (array[k].compare(array[min]) < 0) {
                min = k;
            }
        }

        // Swap the found minimum element with the first element
        string temp = array[j];
        array[j] = array[min];
        array[min] = temp;
    }
}

int main() {
    string arr[] = {"fatma", "shimaa", "aya"};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is\n";
    for (int i = 0; i < n; i++) {
        cout << i << ": " << arr[i] << endl;
    }

    selectionSort(arr, n);

    cout << "\nSorted array is\n";
    for (int i = 0; i < n; i++) {
        cout << i << ": " << arr[i] << endl;
    }

    return 0;
}
