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
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;

public:
    // constructor
    Queue() : front(NULL), rear(NULL) {}

    void Enqueue(T x) {
        Node<T>* newNode = new Node<T>(x);
        if (IsEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void Dequeue() {
        if (IsEmpty()) {
            cout << "Error: Queue Underflow" << endl;
            return;
        }
        Node<T>* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
    }

    T Front() {
        if (IsEmpty()) {
            cout << "Error: Queue is empty" << endl;
            return T();
        }
        return front->data;
    }

    bool IsEmpty() {
        return front == NULL;
    }

    void Print() {
        if (IsEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue: ";
        Node<T>* current = front;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue<int> Q;

    Q.Enqueue(5); Q.Print();
    Q.Enqueue(7); Q.Print();
    Q.Enqueue(10); Q.Print();
    Q.Dequeue(); Q.Print();
    Q.Dequeue(); Q.Print();
    Q.Enqueue(11); Q.Print();
    Q.Dequeue(); Q.Print();
    Q.Dequeue(); Q.Print();
    Q.Dequeue(); Q.Print();

    return 0;
}
