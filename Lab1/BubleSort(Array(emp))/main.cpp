#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    int id;
    string name;
    double salary;

    // Constructor
    Employee(int empId, const string& empName, double empSalary)
        : id(empId), name(empName), salary(empSalary) {}

    // Function to display employee information
    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Salary: " << salary << endl;
    }
};

void bubbleSortEmployees(int n, Employee array[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Compare employees based on their names
            if (array[j].name > array[j + 1].name) {
                // Swap the employees
                swap(array[j], array[j + 1]);
            }
        }
    }
}

int main() {
    // Create an array of employees
    Employee employees[] = {
        {101, "John", 50000.0},
        {102, "Alice", 60000.0},
        {103, "Bob", 45000.0},
        {104, "Eve", 55000.0}
    };

    int n = sizeof(employees) / sizeof(employees[0]);

    cout << "Employees before sorting:" << endl;
    for (int i = 0; i < n; i++) {
        employees[i].display();
    }

    // Sort the array of employees using bubble sort
    bubbleSortEmployees(n, employees);

    cout << "\nEmployees after sorting by name:" << endl;
    for (int i = 0; i < n; i++) {
        employees[i].display();
    }

    return 0;
}


/*#include<iostream>
using namespace std;

void bubble_sort(int n, string array[]) {
    string temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    string arr[] = {"ahmed", "mahmoud", "ibrahem", "mohammed"};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(n, arr);

    cout << "Elements after sorting of the array:- " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
*/
