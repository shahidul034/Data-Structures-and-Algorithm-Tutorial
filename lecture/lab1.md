<h2><i>👉Lab 1 - Installation and Introduction to Datatypes, Arrays, Pointers, Structures, and Class</i></h2>

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

### 🚩Questions
1) Create a Student class that holds information about a student, including their name, roll number, and an array of grades for different subjects. Write methods to calculate and display the student's average grade and their highest grade.

2) Create a BankAccount class that holds information about a bank account, such as account number, account holder name, and balance. Implement methods to deposit, withdraw, and display the account details. Use an array to manage multiple bank accounts.

3) Create a Book class that represents a book in a library. Each book has a title, author, ISBN, and availability status (whether the book is available or checked out). Create an array of books to represent the library and implement methods to check out a book, return a book, and display all available books.

4) Create an Employee class that holds information about an employee, such as name, employee ID, department, and salary. Create an array of employees and implement methods to add a new employee, search for an employee by ID, and display all employees in a specific department.