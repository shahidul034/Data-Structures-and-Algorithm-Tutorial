#include <iostream>
using namespace std;

class Stack {
    int top;
    int arr[5]; // Stack size is 5

public:
    Stack() {
        top = -1; // Initialize stack as empty
    }

    bool isFull() {
        return top == 4; // Check if stack is full
    }

    bool isEmpty() {
        return top == -1; // Check if stack is empty
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow" << endl;
        } else {
            arr[++top] = value;
            cout << "Pushed: " << value << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
        } else {
            cout << "Popped: " << arr[top--] << endl;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        } else {
            return arr[top];
        }
    }

    int size() {
        return top + 1;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.peek() << endl;
    s.pop();
    cout << "Top element after pop: " << s.peek() << endl;
    cout << "Size of stack: " << s.size() << endl;
    return 0;
}
