#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(NULL) {}
};

template <typename T>
class Stack {
private:
    Node<T>* top;

public:
    // constructor
    Stack() : top(NULL) {}

    // copy constructor
    Stack(const Stack& other) {
        if (other.top == NULL) {
            top = NULL;
            return;
        }

        // Copy the first node
        top = new Node<T>(other.top->data);

        // Copy the rest of the nodes
        Node<T>* current = top;
        Node<T>* otherCurrent = other.top->next;
        while (otherCurrent != NULL) {
            current->next = new Node<T>(otherCurrent->data);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
    }

    // destructor
    ~Stack() {
        while (!IsEmpty()) {
            Pop();
        }
    }

    // assignment operator
    Stack& operator=(const Stack& other) {
        if (this != &other) {
            // Clear the current content
            while (!IsEmpty()) {
                Pop();
            }

            // Copy the content from the other stack
            if (other.top != NULL) {
                top = new Node<T>(other.top->data);
                Node<T>* current = top;
                Node<T>* otherCurrent = other.top->next;
                while (otherCurrent != NULL) {
                    current->next = new Node<T>(otherCurrent->data);
                    current = current->next;
                    otherCurrent = otherCurrent->next;
                }
            }
        }
        return *this;
    }

    void Push(T x) {
        Node<T>* newNode = new Node<T>(x);
        newNode->next = top;
        top = newNode;
    }

    void Pop() {
        if (IsEmpty()) {
            cout << "Error: Stack Underflow" << endl;
            return;
        }
        Node<T>* temp = top;
        top = top->next;
        delete temp;
    }

    T Top() {
        if (IsEmpty()) {
            cout << "Error: Stack is empty" << endl;
            return T();
        }
        return top->data;
    }

    bool IsEmpty() {
        return top == NULL;
    }

    void Print() {
        cout << "Stack: ";
        Node<T>* current = top;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack<int> S;

    S.Pop();
    S.Print(); // Empty
    S.Push(1);
    S.Print();
    S.Push(5);
    S.Print();
    S.Push(6);
    S.Print();
    S.Pop();
    S.Print(); // 1
    S.Pop();
    S.Print(); // 5
    S.Push(7);
    S.Print();
    S.Pop();
    S.Print(); // 6
    S.Pop();
    S.Print(); // 7
    S.Pop();
    S.Print(); // Empty
    S.Push(7);
    S.Print(); // 7
    // S1.Pop();S1.Print();
   // S.Pop();
    //S.Print(); // 7

    // Test copy constructor and assignment operator
    Stack<int> S2 = S;
    Stack<int> S3;
    S3 = S;

    cout << "S2: ";
    S2.Print();

    cout << "S3: ";
    S3.Print();

    return 0;
}
