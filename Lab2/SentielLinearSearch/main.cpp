#include <iostream>

using namespace std;

int sentinelLinearSearch(int arr[], int n, int data) {
    int last = arr[n - 1];
    arr[n - 1] = data;

    int i = 0;
    while (arr[i] != data) {
        i++;
    }

    arr[n - 1] = last;

    if ((i < n - 1) || (data == arr[n - 1])) {
        cout << "Found at index " << i << endl;
        return i;
    } else {
        cout << "Not Found" << endl;
        return -1;
    }
}

int main() {
    const int n = 5;
    int arr[n] = {8, 2, 3, 9, 5};
    int data;

    cout << "Enter the value to search: ";
    cin >> data;

    int result = sentinelLinearSearch(arr, n, data);

    return 0;
}

