#include <iostream>
using namespace std;

class Queue {
    int front, rear;
    int arr[5]; // Queue size is 5

public:
    Queue() {
        front = rear = -1; // Initialize queue as empty
    }

    bool isFull() {
        return rear == 4; // Check if queue is full
    }

    bool isEmpty() {
        return front == -1; // Check if queue is empty
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue overflow" << endl;
        } else {
            if (front == -1) front = 0;
            arr[++rear] = value;
            cout << "Enqueued: " << value << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow" << endl;
        } else {
            cout << "Dequeued: " << arr[front++] << endl;
            if (front > rear) front = rear = -1; // Reset if queue becomes empty
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        } else {
            return arr[front];
        }
    }

    int size() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front element: " << q.peek() << endl;
    q.dequeue();
    cout << "Front element after dequeue: " << q.peek() << endl;
    cout << "Size of queue: " << q.size() << endl;
    return 0;
}
