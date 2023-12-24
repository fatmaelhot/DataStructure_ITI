#include <iostream>
using namespace std;

void selectionSort(int array[], int length) {
    // Find the integer that should go in each cell of the array, from cell 0 to the end
    for (int j = 0; j < length - 1; j++) {
        // Find min: the index of the integer that should go into cell j.
        // Look through the unsorted integers (those at j or higher)
        int min = j;
        for (int k = j + 1; k < length; k++)
            if (array[k] < array[min])
                min = k;

        // Swap the int at j with the int at min
        int temp = array[j];
        array[j] = array[min];
        array[min] = temp;
    }
}

int main() {
    int arr[] = {78, 93, 32, 28, 110};
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
