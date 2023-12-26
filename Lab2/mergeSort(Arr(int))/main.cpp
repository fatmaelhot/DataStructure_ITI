#include <iostream>

using namespace std;

void Merge(int arr[], int start, int mid, int end, bool ascending) {
    int size1 = mid - start + 1;
    int size2 = end - mid;
    int* A1 = new int[size1];
    int* A2 = new int[size2];
    int i, j;

    for (int i = 0; i < size1; i++) {
        A1[i] = arr[start + i];
    }

    for (int j = 0; j < size2; j++) {
        A2[j] = arr[mid + 1 + j];
    }

    i = j = 0;
    int k = start;

    while ((i < size1) && (j < size2)) {
        if ((ascending && A1[i] < A2[j]) || (!ascending && A1[i] > A2[j])) {
            arr[k] = A1[i];
            i++;
        } else {
            arr[k] = A2[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        arr[k] = A1[i];
        k++;
        i++;
    }

    while (j < size2) {
        arr[k] = A2[j];
        k++;
        j++;
    }

    delete[] A1;
    delete[] A2;
}

void MergeSort(int arr[], int start, int end, bool ascending) {
    if (start < end) {
        int mid = (start + end) / 2;
        MergeSort(arr, start, mid, ascending);
        MergeSort(arr, mid + 1, end, ascending);
        Merge(arr, start, mid, end, ascending);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Ascending order
    MergeSort(arr, 0, size - 1, true);

    cout << "Sorted array (ascending):" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Descending order
    MergeSort(arr, 0, size - 1, false);

    cout << "Sorted array (descending):" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}




/*#include <iostream>

using namespace std;

void Merge(int arr[], int start, int mid, int end) {
    int size1 = mid - start + 1;
    int size2 = end - mid;
    int* A1 = new int[size1];
    int* A2 = new int[size2];
    int i, j;

    for (int i = 0; i < size1; i++) {
        A1[i] = arr[start + i];
    }

    for (int j = 0; j < size2; j++) {
        A2[j] = arr[mid + 1 + j];
    }

    i = j = 0;
    int k = start;

    while ((i < size1) && (j < size2)) {
        if (A1[i] < A2[j]) {
            arr[k] = A1[i];
            i++;
        } else {
            arr[k] = A2[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        arr[k] = A1[i];
        k++;
        i++;
    }

    while (j < size2) {
        arr[k] = A2[j];
        k++;
        j++;
    }

    delete[] A1;
    delete[] A2;
}

void MergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        MergeSort(arr, start, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, start, mid, end);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    MergeSort(arr, 0, size - 1);

    cout << "Sorted array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}*/



