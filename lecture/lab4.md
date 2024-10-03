<h2><i>👉Lab 4 - Linked Lists (Part 1)</i></h2>

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
### ✅Inserting a Node at the Beginning
To insert a node at the beginning of the list, we simply adjust the pointer of the new node to point to the current head, and then update the head to point to the new node.

```c
void insert_first(int data){
    node *ptr=new node();
    ptr->info=data;
    ptr->link=head;
    head=ptr;
}

```
###  ✅Inserting a Node at the End
To insert a node at the end of the list, we traverse to the last node and then link the new node to it.
```c
void insert_last(int data){
    node *ptr=new node();
    ptr->info=data;
    node *srt=head;
    while(srt->link!=NULL){
        srt=srt->link;
    }
    srt->link=ptr;
    ptr->link=NULL;
}

```
### ✅Inserting a Node After a Given Node
To insert a node after a given node, we traverse the list until we find the node with the desired value, and then adjust the pointers to insert the new node.
```c
void insert_node_after_item(int search,int data){
    node *ptr=new node();
    ptr->info=data;
    node *srt=head;
    while(srt->info!=search){
        srt=srt->link;
    }
    ptr->link=srt->link;
    srt->link=ptr;
}

```
### ✅Inserting a Node before a Given Node
To insert a node before a given node, we traverse the list until we find the node with the desired value, and then adjust the pointers to insert the new node.
```c
void insert_node_before_item(int search, int data){
    node *ptr=new node();
    ptr->info=data;
    node *srt=head,*prev;
    
    while(srt->info!=search){
        prev=srt;
        srt=srt->link;
    }
    prev->link=ptr;
    ptr->link=srt;
}

```
### ✅Main Function
The `main()` function demonstrates how to use the `allocation` and `traverse` functions to build and display the linked list.
```c
int main() {

	allocation(10);
	allocation(20);
	allocation(30);
	traverse(); //10 20 30 
	insert_first(9);
	traverse();//9 10 20 30 
	insert_last(31);
	traverse();//9 10 20 30 31 
	insert_node_after_item(20, 25);
	traverse();//9 10 20 25 30 31 
	insert_node_before_item(30,27);
	traverse();//9 10 20 25 27 30 31 
	return 0;
}

```
<h2><i>🚩Questions</i></h2>
	
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
