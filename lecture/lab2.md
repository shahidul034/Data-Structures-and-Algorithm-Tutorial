<h2><i>👉Lab 2 - C++ Standard Template Library (STL) Tutorial</i></h2>
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




### 🚩Questions

1) **Problem Statement:** Given an array of integers, remove all the duplicate elements and return the unique elements in the same order as they first appeared.

2) **Problem Statement:** Given a list of words, count the frequency of each word and return the results in a dictionary (map).

3) **Problem Statement:** Given a list of integers, check if the list contains any duplicates.

4) **Problem Statement:** Given a string containing just the characters (, ), {, }, [ and ], determine if the input string is valid. The string is valid if: Open brackets must be closed by the same type of brackets. Open brackets must be closed in the correct order.
