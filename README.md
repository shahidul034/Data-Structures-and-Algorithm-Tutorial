# Data-Structures-and-Algorithm
## Datatypes
### 🎯Primitive Data Types
✔ Integer: Whole numbers without a fractional part (e.g., -3, 0, 42).

✔ Floating-point: Numbers with a fractional part (e.g., 3.14, -0.001, 2.0).

✔ Character: A single character (e.g., 'a', 'Z', '9').

✔ Boolean: Represents true or false values.

✔ Byte: Typically a small integer ranging from 0 to 255.
### 🎯Non-Primitive Data Types
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