# Data-Structures-and-Algorithm
## Installation
[Codeblocks](https://www.codeblocks.org/downloads/binaries/)

File: codeblocks-20.03mingw-setup.exe
## Datatypes
### 🎯Primitive Data Types
 Data elements are arranged in a sequential manner.
 
✔ Integer: Whole numbers without a fractional part (e.g., -3, 0, 42).

✔ Floating-point: Numbers with a fractional part (e.g., 3.14, -0.001, 2.0).

✔ Character: A single character (e.g., 'a', 'Z', '9').

✔ Boolean: Represents true or false values.

✔ Byte: Typically a small integer ranging from 0 to 255.
### 🎯Non-Primitive Data Types
 Data elements are not arranged in a sequential manner.
 
✔ Arrays: A collection of elements of the same type, stored in contiguous memory locations.

✔ Strings: A sequence of characters, often implemented as an array of characters.

✔ Structures: A collection of variables of different data types under a single name.

✔ Classes: In object-oriented programming, a blueprint for creating objects (instances).
## Data Structures
### 🎯Linear Data Structures
✔ Arrays: Elements are stored in contiguous memory locations.

✔ Linked Lists: Elements (nodes) are connected by pointers.

✔ Stacks: LIFO (Last In First Out) structure where elements are added/removed from the top.

✔ Queues: FIFO (First In First Out) structure where elements are added at the rear and removed from the front.
### 🎯Nonlinear Data Structures
✔ Trees: Hierarchical structure with a root node and child nodes (e.g., binary trees, AVL trees).

✔ Graphs: Consist of vertices (nodes) connected by edges. Graphs can be directed or undirected.

✔ Heaps: A specialized tree-based structure that satisfies the heap property (e.g., max-heap, min-heap).
### 🎯Abstract Data Types (ADTs)
An Abstract Data Type (ADT) is a type (or class) for objects whose behavior is defined by a set of values and a set of operations. ADTs specify what operations can be performed but not how these operations will be implemented. Examples of ADTs include:

✔ List: An ordered collection of elements with operations like insertion, deletion, and traversal.

✔ Stack: Operations include push, pop, and peek.

✔ Queue: Operations include enqueue, dequeue, and peek.

✔ Map: A collection of key-value pairs with operations like insertion, deletion, and lookup.

✔ Set: A collection of unique elements with operations like insertion, deletion, and membership testing.

## 🎯Array
✅ Basic array example
 
```
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
✅ Multidimensional Arrays
```
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
✅ Pointer
 A pointer is a variable that stores the memory address of another variable. Pointers are used to indirectly access and manipulate data in memory.
 
```
    int *ptr;
    int arr[5];
    // store the address of the first
    // element of arr in ptr
    ptr = arr;
```
✅ Same as before
```
    int *ptr;
    int arr[5];
    ptr = &arr[0];
```
✅ Access element from array
```
    for (int i = 0; i < 3; ++i)
    {
        cout << "&arr[" << i << "] = " << *(ptr+i) << endl;
    }
```
✅ Structure
```
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
✅ Class

Classes can have special member functions called constructors and destructors. Constructors are used to initialize object data, while destructors are called when an object is destroyed.
```
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
```
person p1("Karim",25);
p1.update_name("Testing");
cout<<p1.name<<endl;
```
🚩Question
1) Create a Student class that holds information about a student, including their name, roll number, and an array of grades for different subjects. Write methods to calculate and display the student's average grade and their highest grade.

2) Create a BankAccount class that holds information about a bank account, such as account number, account holder name, and balance. Implement methods to deposit, withdraw, and display the account details. Use an array to manage multiple bank accounts.

📝 Home works

1) Create a Book class that represents a book in a library. Each book has a title, author, ISBN, and availability status (whether the book is available or checked out). Create an array of books to represent the library and implement methods to check out a book, return a book, and display all available books.

2) Create an Employee class that holds information about an employee, such as name, employee ID, department, and salary. Create an array of employees and implement methods to add a new employee, search for an employee by ID, and display all employees in a specific department.

## 🎯C++ Standard Template Library (STL) Tutorial 
The Standard Template Library (STL) in C++ is a powerful library that provides data structures and algorithms to help you efficiently store and manipulate data. Here's a basic introduction to some of the most commonly used components in the STL, focusing only on the most important and regularly used functions.

### ✅Vector
A vector is a dynamic array that can grow in size.
```
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
#### Important Functions: 

push_back(value): Adds an element to the end of the vector.

pop_back(): Removes the last element.

size(): Returns the number of elements in the vector.

[]: Accesses elements by index.

### ✅Stack 
A stack follows the LIFO (Last In, First Out) principle.
```
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    // Push elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);

    // Access the top element
    cout << "Top element: " << s.top() << endl;  // 30

    // Remove the top element
    s.pop();  // Now top is 20

    cout << "New top element: " << s.top() << endl;  // 20

    return 0;
}

```
#### Important Functions:
push(value): Pushes an element onto the stack.

pop(): Removes the top element.

top(): Returns the top element.

empty(): Checks if the stack is empty.
### ✅Queue
A queue follows the FIFO (First In, First Out) principle.
```
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // Add elements to the queue
    q.push(10);
    q.push(20);
    q.push(30);

    // Access the front and back
    cout << "Front: " << q.front() << endl;  // 10
    cout << "Back: " << q.back() << endl;    // 30

    // Remove the front element
    q.pop();  // Now front is 20

    cout << "New front: " << q.front() << endl;  // 20

    return 0;
}
```
#### Important Functions:
push(value): Adds an element to the queue.

pop(): Removes the front element.

front(): Returns the front element.

back(): Returns the last element.
### ✅Set
A set stores unique elements in sorted order.
```
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
#### Important Functions:
insert(value): Inserts an element (if it’s not already present).

count(value): Checks if an element exists (returns 0 or 1).

erase(value): Removes an element.

find(value): Finds an element.

### ✅Map 
A map stores key-value pairs in sorted order of keys.
```
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
#### Important Functions:
[]: Access or insert elements by key.

insert({key, value}): Inserts a key-value pair.

find(key): Finds an element by key.

erase(key): Removes an element by key.

### ✅Algorithm 
STL also provides many useful algorithms. Here are some commonly used ones:
```
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
#### Important Functions:
sort(start, end): Sorts the range [start, end).

reverse(start, end): Reverses the range [start, end).

binary_search(start, end, value): Checks if a value is present in a sorted range.

🚩Question

1) **Problem Statement:** Given an array of integers, remove all the duplicate elements and return the unique elements in the same order as they first appeared.

2) **Problem Statement:** Given a list of words, count the frequency of each word and return the results in a dictionary (map).

3) **Problem Statement:** Given a list of integers, check if the list contains any duplicates.

4) **Problem Statement:** Given a string containing just the characters (, ), {, }, [ and ], determine if the input string is valid. The string is valid if: Open brackets must be closed by the same type of brackets. Open brackets must be closed in the correct order.
