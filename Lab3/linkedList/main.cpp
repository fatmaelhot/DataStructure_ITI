#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T value;
    Node* next;

    Node(T data) : value(data), next(NULL) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(NULL) {}

    // Function to insert a new node at the beginning of the linked list
    void insertAtBeginning(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    // Function to insert a new node at the end of the linked list
    void insertAtEnd(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == NULL) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to delete a node with a specific value from the linked list
    void remove(T data) {
        if (head == NULL) {
            return; // Empty list, nothing to delete
        }

        if (head->value == data) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T>* current = head;
        while (current->next != NULL && current->next->value != data) {
            current = current->next;
        }

        if (current->next == NULL) {
            return; // Value not found
        }

        Node<T>* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // Function to search for a value in the linked list
    bool search(T data) {
        Node<T>* current = head;
        while (current != NULL) {
            if (current->value == data) {
                return true; // Value found
            }
            current = current->next;
        }
        return false; // Value not found
    }

    // Function to print the linked list
    void print() {
        Node<T>* current = head;
        while (current != NULL) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Function to delete all nodes in the linked list
    void clear() {
        while (head != NULL) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Destructor to free memory when the linked list object is destroyed
    ~LinkedList() {
        clear();
    }
};

int main() {
    LinkedList<int> linkedList;

    // Insert nodes at the beginning
    linkedList.insertAtBeginning(3);
    linkedList.insertAtBeginning(2);
    linkedList.insertAtBeginning(1);

    // Print the linked list
    cout << "Linked List after inserting at the beginning: ";
    linkedList.print();

    // Insert nodes at the end
    linkedList.insertAtEnd(4);
    linkedList.insertAtEnd(5);

    // Print the linked list
    cout << "Linked List after inserting at the end: ";
    linkedList.print();

    // Search for a value
    int searchValue;
    cout << "enter search value ";
    cin>>searchValue;
    if (linkedList.search(searchValue)) {
        cout << searchValue << " found in the linked list." << endl;
    } else {
        cout << searchValue << " not found in the linked list." << endl;
    }

    // Remove a node
    int RemoveValue;
    cout<<"Enter RemoveValue ";
    cin>>RemoveValue;
    linkedList.remove(RemoveValue);

    // Print the modified linked list
    cout << "Linked List after removing "<<RemoveValue<<":";
    linkedList.print();

    // Clear the linked list
    linkedList.clear();

    // Print the empty linked list
    cout << "Linked List after clearing: ";
    linkedList.print();

    return 0;
}
