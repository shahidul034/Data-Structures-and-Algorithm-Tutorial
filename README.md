# Data-Structures-and-Algorithms
## Contents
| #Lab  | Topics name |
| ------------- | ------------- |
| 1 | ✔[Installation and Introduction to Datatypes, Arrays, Pointers, Structures, and Class](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/README.md#lab-1) |
| 2 | ✔[STL (Standard Template Library)](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/README.md#lab-2) |
| 3 | ✔[Stacks and Queues](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/README.md#lab-3) |
| 4 | ✔[Linked Lists (Part 1)](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial?tab=readme-ov-file#lab-4)|
| 5 | ✔[Linked Lists (Part 2)](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial?tab=readme-ov-file#lab-5) |
| 6 | ⏳Sorting |
| 7 | ⏳Graphs|
| 8 | ⏳Trees |
| 9 | ⏳Backtracking and Greedy |
| 10 | ⏳Hashing |
| 11 | ⏳Dynamic Programming |
> [!TIP]
> Click below to expand the sections.

<!--
- [x] [Lab1: Installation and Introduction to Datatypes, Arrays, Pointers, Structures and Class](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/README.md#lab1)
- [x] [Lab2: STL](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/README.md#lab2)
- [ ] Lab3: Stacks and Queues
- [ ] Lab4: Linked Lists (Part 1)
- [ ] Lab5: Linked Lists (Part 2)
- [ ] Lab6: Sorting
- [ ] Lab7: Graphs
- [ ] Lab8: Dynamic Programming
- [ ] Lab9: Trees
- [ ] Lab10: Backtracking and Greedy
- [ ] Lab11: Hashing
-->
<details>
 
<summary><h2><i>👉Lab 1 - Installation and Introduction to Datatypes, Arrays, Pointers, Structures, and Class</i></h2></summary>
 
## 🚀Installation
⬇️[Codeblocks](https://www.codeblocks.org/downloads/binaries/)

File: codeblocks-20.03mingw-setup.exe
## 🎯Introduction to Datatypes, Arrays, Pointers, Structures and Class
### ✅Primitive Data Types
 Data elements are arranged in a sequential manner.
 
`Integer`: Whole numbers without a fractional part (e.g., -3, 0, 42).

`Floating-point`: Numbers with a fractional part (e.g., 3.14, -0.001, 2.0).

`Character`: A single character (e.g., 'a', 'Z', '9').

`Boolean`: Represents true or false values.

`Byte`: Typically a small integer ranging from 0 to 255.
### ✅Non-Primitive Data Types
 Data elements are not arranged in a sequential manner.
 
`Arrays`: A collection of elements of the same type, stored in contiguous memory locations.

`Strings`: A sequence of characters, often implemented as an array of characters.

`Structures`: A collection of variables of different data types under a single name.

`Classes`: In object-oriented programming, a blueprint for creating objects (instances).
### ✅Linear Data Structures
`Arrays`: Elements are stored in contiguous memory locations.

`Linked Lists`: Elements (nodes) are connected by pointers.

`Stacks`: LIFO (Last In First Out) structure where elements are added/removed from the top.

`Queues`: FIFO (First In First Out) structure where elements are added at the rear and removed from the front.
### ✅Nonlinear Data Structures
`Trees`: Hierarchical structure with a root node and child nodes (e.g., binary trees, AVL trees).

`Graphs`: Consist of vertices (nodes) connected by edges. Graphs can be directed or undirected.

`Heaps`: A specialized tree-based structure that satisfies the heap property (e.g., max-heap, min-heap).
### ✅Abstract Data Types (ADTs)
An Abstract Data Type (ADT) is a type (or class) for objects whose behavior is defined by a set of values and a set of operations. ADTs specify what operations can be performed but not how these operations will be implemented. Examples of ADTs include:

`List`: An ordered collection of elements with operations like insertion, deletion, and traversal.

`Stack`: Operations include push, pop, and peek.

`Queue`: Operations include enqueue, dequeue, and peek.

`Map`: A collection of key-value pairs with operations like insertion, deletion, and lookup.

`Set`: A collection of unique elements with operations like insertion, deletion, and membership testing.

### ✅ Basic array example
 
```c
#include<iostream>
using namespace std;
int main()
{
    int arr[]={3,4,5,6,7};

    int arr2[5];
    for(int i=0;i<5;i++){
        cout<<"enter: ";
        cin>>arr2[i];
    }
    cout<<arr[0]<<endl;
    for(int i=0;i<5;i++){
        cout<<arr2[i]<<endl;
    }
}
```
### ✅ Multidimensional Arrays
```c
int test[2][3] = {{2, 4, 5}, {9, 0, 19}};
    for (int i = 0; i < 2; ++i)
    {

        // access columns of the array
        for (int j = 0; j < 3; ++j)
        {
            cout << "test[" << i << "][" << j << "] = " << test[i][j] << endl;
        }
    }
```
### ✅ Pointer
 A pointer is a variable that stores the memory address of another variable. Pointers are used to indirectly access and manipulate data in memory.
 
```c
    int *ptr;
    int arr[5];
    // store the address of the first
    // element of arr in ptr
    ptr = arr;
```
Same as before
```c
    int *ptr;
    int arr[5];
    ptr = &arr[0];
```
### ✅ Access element from array
```c
    for (int i = 0; i < 3; ++i)
    {
        cout << "&arr[" << i << "] = " << *(ptr+i) << endl;
    }
```
### ✅ Structure
```c
struct Person {
    char name[50];
    int age;
    char address[100];
};
struct Person person;
strcpy(p1.name,"shakib");// #include<cstring>
person.age = 35;
person.address = "123 Main St, Anytown USA";
```
### ✅ Class

Classes can have special member functions called constructors and destructors. Constructors are used to initialize object data, while destructors are called when an object is destroyed.
```c
class person {
public:
        string name;
        int age;
        person(string name, int age){
            this->name=name;
            this->age=age;
        }

        void update_name(string name){
            this->name=name;
        }
};
```
```c
person p1("Karim",25);
p1.update_name("Testing");
cout<<p1.name<<endl;
```
<details>

<summary><h2><i>🚩Questions</i></h2></summary>

1) Create a Student class that holds information about a student, including their name, roll number, and an array of grades for different subjects. Write methods to calculate and display the student's average grade and their highest grade.

2) Create a BankAccount class that holds information about a bank account, such as account number, account holder name, and balance. Implement methods to deposit, withdraw, and display the account details. Use an array to manage multiple bank accounts.

3) Create a Book class that represents a book in a library. Each book has a title, author, ISBN, and availability status (whether the book is available or checked out). Create an array of books to represent the library and implement methods to check out a book, return a book, and display all available books.

4) Create an Employee class that holds information about an employee, such as name, employee ID, department, and salary. Create an array of employees and implement methods to add a new employee, search for an employee by ID, and display all employees in a specific department.

</details>
</details>

<details>
<summary><h2><i>👉Lab 2 - STL (Standard Template Library)</i></h2></summary>
## 🎯C++ Standard Template Library (STL) Tutorial
The Standard Template Library (STL) in C++ is a powerful library that provides data structures and algorithms to help you efficiently store and manipulate data. Here's a basic introduction to some of the most commonly used components in the STL, focusing only on the most important and regularly used functions.

### ✅Vector
A vector is a dynamic array that can grow in size.
```c
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Declare a vector of integers
    vector<int> v;

    // Add elements using push_back
    v.push_back(10);   // {10}
    v.push_back(20);   // {10, 20}
    v.push_back(30);   // {10, 20, 30}

    // Access elements using []
    cout << "Element at index 1: " << v[1] << endl;  // 20

    // Access the size of the vector
    cout << "Size of vector: " << v.size() << endl;  // 3

    // Remove the last element
    v.pop_back();  // Now v = {10, 20}

    // Iterate using a loop
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;  // Output: 10 20

    return 0;
}

```

> #### Important Functions
> * `push_back(value)`: Adds an element to the end of the vector.
> * `pop_back()`: Removes the last element.
> * `size()`: Returns the number of elements in the vector.
> * `[]`: Accesses elements by index.

### ✅Stack 
A stack follows the LIFO (Last In, First Out) principle.
```c
#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> s,temp;

	// Push elements onto the stack
	s.push(10);
	s.push(20);
	s.push(30);
	while (!s.empty()) {
		int current = s.top();
		cout << current << " ";

		// Remove the top element from the original stack
		s.pop();

		// Push the element onto the temporary stack
		temp.push(current);
	}

	std::cout << std::endl;

	// Restore the original stack
	while (!temp.empty()) {
		s.push(temp.top());
		temp.pop();
	}
	// Access the top element
	cout << "Top element: " << s.top() << endl;  // 30

	// Remove the top element
	s.pop();  // Now top is 20

	cout << "New top element: " << s.top() << endl;  // 20

	return 0;
}

```
> #### Important Functions
> * `push(value)`: Pushes an element onto the stack.
> * `pop()`: Removes the top element.
> * `top()`: Returns the top element.
> * `empty()`: Checks if the stack is empty.
### ✅Queue
A queue follows the FIFO (First In, First Out) principle.
```c
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    
    // Add elements to the queue
    q.push(10);
    q.push(20);
    q.push(30);
    
    cout << "Method 1: Traversing while preserving the queue" << endl;
    {
        queue<int> temp = q; // Create a copy of the original queue
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
    
    cout << "Method 2: Traversing and restoring the queue" << endl;
    {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            int current = q.front();
            cout << current << " ";
            q.pop();
            q.push(current);
        }
        cout << endl;
    }
    
    return 0;
}
```
> #### Important Functions
> * `push(value)`: Adds an element to the queue.
> * `pop()`: Removes the front element.
> * `front()`: Returns the front element.
> * `back()`: Returns the last element.
### ✅Set
A set stores unique elements in sorted order.
```c
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;

    // Insert elements
    s.insert(10);
    s.insert(5);
    s.insert(10);  // Duplicate, will be ignored
    s.insert(15);

    // Check if element exists
    if (s.count(10)) {
        cout << "10 is present" << endl;
    }

    // Iterate through the set
    for (int x : s) {
        cout << x << " ";
    }
    cout << endl;  // Output: 5 10 15

    return 0;
}

```
> #### Important Functions
> * `insert(value)`: Inserts an element (if it’s not already present).
> * `count(value)`: Checks if an element exists (returns 0 or 1).
> * `erase(value)`: Removes an element.
> * `find(value)`: Finds an element.

### ✅Map 
A map stores key-value pairs in sorted order of keys.
```c
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> m;

    // Insert key-value pairs
    m["apple"] = 5;
    m["banana"] = 10;
    m["orange"] = 20;

    // Access value by key
    cout << "Apple count: " << m["apple"] << endl;  // 5

    // Iterate through the map
    for (auto p : m) {
        cout << p.first << ": " << p.second << endl;
    }
    // Output:
    // apple: 5
    // banana: 10
    // orange: 20

    return 0;
}

```
> #### Important Functions
> * `[]`: Access or insert elements by key.
> * `insert({key, value})`: Inserts a key-value pair.
> * `find(key)`: Finds an element by key.
> * `erase(key)`: Removes an element by key.

### ✅Algorithm 
STL also provides many useful algorithms. Here are some commonly used ones:
```c
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {3, 1, 4, 1, 5, 9};

    // Sort the vector
    sort(v.begin(), v.end());  // {1, 1, 3, 4, 5, 9}

    // Reverse the vector
    reverse(v.begin(), v.end());  // {9, 5, 4, 3, 1, 1}

    // Find an element
    if (binary_search(v.begin(), v.end(), 4)) {
        cout << "4 found" << endl;
    }

    // Display the vector
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;  // Output: 9 5 4 3 1 1

    return 0;
}

```
> #### Important Functions
> * `sort(start, end)`: Sorts the range [start, end).
> * `reverse(start, end)`: Reverses the range [start, end).
> * `binary_search(start, end, value)`: Checks if a value is present in a sorted range.


<details>

<summary><h2><i>🚩Questions</i></h2></summary>
### Question
1) **Problem Statement:** Given an array of integers, remove all the duplicate elements and return the unique elements in the same order as they first appeared.

2) **Problem Statement:** Given a list of words, count the frequency of each word and return the results in a dictionary (map).

3) **Problem Statement:** Given a list of integers, check if the list contains any duplicates.

4) **Problem Statement:** Given a string containing just the characters (, ), {, }, [ and ], determine if the input string is valid. The string is valid if: Open brackets must be closed by the same type of brackets. Open brackets must be closed in the correct order.

</details>
</details>

<details>
<summary><h2><i>👉Lab 3 - Stacks and Queues</i></h2></summary>
 
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

<details>
 
<summary><h2><i>🚩Questions</i></h2></summary>
 
### Stack Practice Questions

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

</details>

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

<details>
 
<summary><h2><i>🚩Questions</i></h2></summary>
 
### Queue Practice Questions

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

---
</details>

</details>

<details>
<summary><h2><i>👉Lab 4 - Linked Lists (Part 1)</i></h2></summary>

### ✅What is a Linked List?
A linked list is a dynamic data structure that consists of a sequence of nodes. Each node contains two parts:

- `Data`: Stores the value.
- `Link`: A pointer to the next node.

Unlike arrays, linked lists are dynamic and can grow or shrink in size without reallocating memory, making them more efficient for operations like insertion and deletion.

### ✅Types of Linked Lists

- `Singly Linked List`: Each node points to the next node in the sequence.
- `Doubly Linked List`: Each node points to both the next and previous nodes.
- `Circular Linked List`: The last node points back to the first node.

### ✅Basic Operations on a Linked List
- `Inserting a Node`: Add a new node to the list.
- `Deleting a Node`: Remove a node from the list.
- `Traversing the List`: Visit all nodes to access their values.
- `Searching a Node`: Find a node with a given value.

### ✅In this code
 
`Allocation`: Dynamically allocate memory for a new node and insert it at the end.

`Insertion`: Insert a new node at the beginning, end, or a specific position.

`Traversal`: Visit all nodes to access and print their values.

### ✅Basic pointers information
- `head` points to the first node.
- `temp` helps traverse the list or store temporary positions.

### ✅Structure of a Node
```c
#include <iostream>
using namespace std;
// Node class
class node {
public:
    int info;         // Data part
    node* link;       // Pointer to the next node
};
```
```
node *head = NULL, *temp;  // Global pointers to manage the list
```
### ✅Allocation Function
The `allocation` function creates a new node with a given value and inserts it at the end of the linked list. If the list is empty, the new node becomes the head.
```c
int allocation(int item) {
    node *ptr = new node();  // Allocate a new node
    ptr->info = item;        // Set the data
    ptr->link = NULL;        // Set the link to null

    if (head == NULL) {
        head = ptr;          // If list is empty, the new node becomes head
        temp = ptr;
    } else {
        temp->link = ptr;    // Otherwise, link the last node to the new node
        temp = ptr;
    }
}

```
### ✅Traversal Function

The `traverse` function iterates through the linked list and prints the value of each node.
```c
int traverse() {
    node *srt = head;        // Start from the head
    while (srt != NULL) {
        cout << srt->info << " ";  // Print data
        srt = srt->link;           // Move to the next node
    }
    cout << endl;
}

```
### ✅Main Function
The `main()` function demonstrates how to use the `allocation` and `traverse` functions to build and display the linked list.
```c
int main() {
    int n;
    cin >> n;  // Read the number of nodes

    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;            // Input the node value
        allocation(b);       // Insert the node
    }

    traverse();  // Display the list
    return 0;
}

```
<details>
<summary><h2><i>🚩Questions</i></h2></summary>
	
- Write a function to insert a node at the beginning of a linked list.
	- Input: LinkedList = `10 -> 20 -> 30`, Inserting `5` at the beginning.
	- Expected Output: `5 -> 10 -> 20 -> 30`
- Implement a function to insert a node at the end of the linked list.
    - Input: LinkedList = `10 -> 20 -> 30`, Inserting `40` at the end.
    - Expected Output: `10 -> 20 -> 30 -> 40`
- Write a function to traverse and print all elements of a linked list.
    - Input: LinkedList = `10 -> 20 -> 30`
    - Expected Output: `10 20 30`
- Write a function to create a linked list from an array of values.
    - Input: Array = `[5, 10, 15, 20]`
    - Expected Output: LinkedList = `5 -> 10 -> 15 -> 20`
</details>

</details>

<details>
<summary><h2><i>👉Lab 5 - Linked Lists (Part 2)</i></h2></summary>
	
### ✅Inserting a Node at the Beginning
To insert a node at the beginning of the list, we simply adjust the pointer of the new node to point to the current head, and then update the head to point to the new node.

```c
int insert_first(int data) {
    node *ptr = new node();  // Allocate a new node
    ptr->info = data;        // Set the data
    ptr->link = head;        // Link the new node to the current head
    head = ptr;              // Update head to the new node
}

```
###  ✅Inserting a Node at the End
To insert a node at the end of the list, we traverse to the last node and then link the new node to it.
```c
int insert_last(int data) {
    node *ptr = new node();  // Allocate a new node
    ptr->info = data;
    ptr->link = NULL;        // The new node will be the last node

    if (head == NULL) {
        head = ptr;          // If the list is empty, make this the first node
    } else {
        node *srt = head;
        while (srt->link != NULL) srt = srt->link;  // Traverse to the last node
        srt->link = ptr;                            // Link the last node to the new node
    }
}

```
### ✅Inserting a Node After a Given Node
To insert a node after a given node, we traverse the list until we find the node with the desired value, and then adjust the pointers to insert the new node.
```c
int after_insert_item(int data, int item) {
    node *ptr = new node();  // Allocate a new node
    ptr->info = item;

    node *srt = head;
    while (srt != NULL) {
        if (srt->info == data) {
            ptr->link = srt->link;  // Link the new node to the next node
            srt->link = ptr;        // Link the current node to the new node
            break;
        }
        srt = srt->link;
    }
}

```
### ✅Deleting a Node with a Given Value
To delete a node with a given value, we traverse the list until we find the node. We then unlink it from the list and free the memory.

```c
int deletion_given_item(int data) {
    node *srt = head, *prev = NULL;

    while (srt != NULL) {
        if (srt->info == data) {
            if (prev == NULL) {
                head = srt->link;  // If it's the head node, update the head
            } else {
                prev->link = srt->link;  // Unlink the node
            }
            delete srt;  // Free the memory
            break;
        }
        prev = srt;
        srt = srt->link;
    }
}

```
### ✅Main Function
```c
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        allocation(b);       // Insert nodes at the end
    }

    traverse();

    int data;
    cin >> data;
    insert_first(data);      // Insert node at the beginning
    traverse();

    cin >> data;
    insert_last(data);       // Insert node at the end
    traverse();

    int item;
    cin >> data >> item;
    after_insert_item(data, item);  // Insert node after a given node
    traverse();

    cin >> data;
    deletion_given_item(data);  // Delete a node
    traverse();

    return 0;
}

```

<details>
<summary><h2><i>🚩Questions</i></h2></summary>
- Write a function to insert a node after a given value in the linked list.

    - Input: LinkedList = `10 -> 20 -> 30`, Insert `25` after `20`.

    - Expected Output: `10 -> 20 -> 25 -> 30`

- Implement a function to insert a node before a given value in the linked list.

    - Input: LinkedList = `10 -> 20 -> 30`, Insert `15` before `20`.

    - Expected Output: `10 -> 15 -> 20 -> 30`

-   Write a function to delete a node with a specific value from the linked list.

    - Input: LinkedList = `10 -> 20 -> 30 -> 40`, Delete node `20`.

    - Expected Output: `10 -> 30 -> 40`

- Implement a function to delete the node after a given value.

    - Input: LinkedList = `10 -> 20 -> 30 -> 40`, Delete node after `20`.

    - Expected Output: `10 -> 20 -> 40`

- Write a function to reverse the linked list.

    - Input: LinkedList = `10 -> 20 -> 30`

    - Expected Output: `30 -> 20 -> 10`

- Write a function to search for a value in the linked list.

    - Input: LinkedList = `10 -> 20 -> 30`, Search for `20`.

    - Expected Output: True (`20` found in the list)

- Write a function to delete the first node of a linked list.

    - Input: LinkedList = `10 -> 20 -> 30`


    - Expected Output: `20 -> 30`
</details>

</details>



