#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high, bool ascending) {
    int pivot = arr[high];  // Pivot
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        if ((ascending && arr[j] <= pivot) || (!ascending && arr[j] >= pivot)) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high, bool ascending) {
    if (low < high) {

        int pivot = partition(arr, low, high, ascending);
        quickSort(arr, low, pivot - 1, ascending);
        quickSort(arr, pivot + 1, high, ascending);
    }
}

void displayArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << "\t";
}

int main() {
    int arr[] = {12, 23, 3, 43, 51, 35, 19, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Input array" << endl;
    displayArray(arr, n);
    cout << endl;

    // Ascending order
    quickSort(arr, 0, n - 1, true);
    cout << "Array sorted in ascending order with quick sort" << endl;
    displayArray(arr, n);
    cout << endl;

    // Descending order
    quickSort(arr, 0, n - 1, false);
    cout << "Array sorted in descending order with quick sort" << endl;
    displayArray(arr, n);

    return 0;
}


/*#include <iostream>
using namespace std;
// Swap two elements - Utility function
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// partition the array using last element as pivot
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        //if current element is smaller than pivot, increment the low element
        //swap elements at i and j
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

//quicksort algorithm
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        //partition the array
        int pivot = partition(arr, low, high);

        //sort the sub arrays independently
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void displayArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<<arr[i]<<"\t";

}

int main()
{
    int arr[] = {12,23,3,43,51,35,19,45};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Input array"<<endl;
    displayArray(arr,n);
    cout<<endl;
    quickSort(arr, 0, n-1);
    cout<<"Array sorted with quick sort"<<endl;
    displayArray(arr,n);
    return 0;
}*/
