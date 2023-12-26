#include <iostream>
#include <string>

using namespace std;

struct Employee {
    int id;
    string name;
    double salary;
};

int linearSearch(Employee arr[], int n, const string& data) {
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i].name == data) {
            cout << "Found at index " << i << endl;
            index = i;
        }
    }
    return index;
}

int main() {
    const int n = 5;
    Employee arr[n] = {
        {1, "ahmed", 50000},
        {2, "mohammed", 60000},
        {3, "fatma", 55000},
        {4, "shimaa", 70000},
        {5, "islam", 45000}
    };

    string data;
    cout << "Please enter employee name: ";
    cin >> data;

    int result = linearSearch(arr, n, data);

    if (result == -1) {
        cout << "Not Found" << endl;
    }

    return 0;
}




/*#include <iostream>

using namespace std;

int linearSearch(int arr[], int n, int data) {
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == data) {
            cout << "Found at index " << i << endl;
            index = i; }
    }
    return index;
}

int main() {
    const int n = 5;
    int arr[n] = {1, 2, 3, 2, 4};
    int data;
    cout<<"please enter data ";
    cin>>data;

    int result = linearSearch(arr, n, data);

    if (result == -1) {
        cout << "Not Found" << endl;
    }

    return 0;
}*/


