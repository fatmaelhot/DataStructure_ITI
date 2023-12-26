#include <iostream>

using namespace std;

int BinarySearch(int x, int a[], int size) {
    int start = 0;
    int end = size - 1;
    int midIndex;

    while (start <= end) {
        midIndex = (start + end) / 2;

        if (a[midIndex] == x)
            return midIndex;

        if (x < a[midIndex])
            end = midIndex - 1;

        else
            start = midIndex + 1;
    }

    // If the target is not found, return -1
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;

    cout << "Enter the target value: ";
    cin >> target;

    int index = BinarySearch(target, arr, size);

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}


