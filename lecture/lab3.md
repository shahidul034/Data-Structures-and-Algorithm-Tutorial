<h2><i>👉Lab 3 - Stacks and Queues</i></h2>
 
## 🎯Stacks
A Stack follows the LIFO (Last In First Out) principle. This means that the last element inserted into the stack is the first one to be removed. Imagine a stack of plates; the last plate placed on top is the first to be removed.

### ✅Operations on Stack

`Push:` Add an element to the top of the stack.

`Pop:` Remove the top element from the stack.

`Peek (Top)`: Retrieve the top element without removing it.

`isEmpty`: Check if the stack is empty.

`Size`: Get the number of elements in the stack.

### ✅Stack Implementation using Array
```c
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

```
### ✅Stack Applications:

- Expression evaluation (infix to postfix)

- Backtracking algorithms (e.g., maze solving)

- Function call management in recursion


 
<h2><i>🚩Questions</i></h2>
 
1. **Reverse a String using Stack**
   - Write a program to reverse a string using a stack.
   
2. **Balanced Parentheses**
   - Given an expression string with parentheses `(` and `)`, check whether the parentheses are balanced or not using a stack.
   
3. **Evaluate Postfix Expression**
   - Write a program to evaluate a postfix expression (e.g., `231*+9-` equals `-4`).
   
4. **Sort a Stack**
   - Given a stack, write a program to sort its elements using recursion (you can only use stack operations like push, pop, etc.).
   
5. **Next Greater Element**
   - Given an array, for each element, find the next greater element. The next greater element is the first larger number to the right of the current element using a stack.

6. **Implement Two Stacks in an Array**
   - Implement two stacks in a single array without wasting space.

7. **Stock Span Problem**
   - Write a program to calculate the span of stock’s price for all days using a stack. The stock span on a given day is defined as the maximum number of consecutive days the stock price was less than or equal to the current price.

8. **Min Stack**
   - Design a stack that supports `push`, `pop`, `top`, and retrieving the minimum element in constant time.



## 🎯Queues
A Queue follows the FIFO (First In First Out) principle. The first element inserted into the queue is the first one to be removed. Think of a queue in a supermarket where the first customer in line is served first.

### ✅Operations on Queue

`Enqueue`: Add an element to the end of the queue.

`Dequeue`: Remove the element from the front of the queue.

`Front`: Retrieve the front element without removing it.

`isEmpty`: Check if the queue is empty.

`Size`: Get the number of elements in the queue.

### ✅Queue Implementation using Array
```c
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

```


### ✅Queue Applications:

- CPU scheduling

- Breadth-First Search (BFS) in graphs

- Printer task scheduling


 
<h2><i>🚩Questions</i></h2>
 

1. **Generate Binary Numbers**
   - Given a number `n`, generate and print binary numbers from 1 to `n` using a queue.
   
2. **Reverse a Queue**
   - Write a program to reverse the elements of a queue.
   
3. **Implement Stack using Queues**
   - Implement a stack using two queues.
   
4. **Circular Queue Implementation**
   - Implement a circular queue with fixed size using an array.
   
5. **Interleave First Half and Second Half of a Queue**
   - Given a queue of integers, interleave the first half of the queue with the second half.
   
6. **First Non-Repeating Character in a Stream**
   - Given a stream of characters, find the first non-repeating character at any point in the stream using a queue.
   
7. **Sliding Window Maximum**
   - Given an array and an integer `k`, find the maximum element in each sliding window of size `k` using a deque (double-ended queue).
   
8. **Implement Deque (Double-Ended Queue)**
   - Implement a deque with operations `insertFront`, `insertRear`, `deleteFront`, `deleteRear`, and checking if the deque is empty or full.

