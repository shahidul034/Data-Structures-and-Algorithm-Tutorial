**Question:**  
You are given a singly linked list and a series of operations to perform on it. The linked list initially contains integers in **sorted ascending order**. Implement the following functions:

1. **`insertNode(value)`**: This function should insert a new node with the given value into the linked list, maintaining the ascending order of elements.
   
2. **`deleteInRange(start, end)`**: This function should delete all nodes with values within the range `[start, end]` (inclusive). If no nodes fall within this range, the list should remain unchanged.

Write a program that performs a series of insert and delete operations on the linked list. At the end of all operations, return the final state of the linked list as an array.

**Example:**

Input:  
Initial List: `1 -> 3 -> 5 -> 7 -> 9 -> 11`  
Operations:  
- `insertNode(4)`
- `insertNode(8)`

After insertion output: `1 -> 3 -> 4 -> 5 -> 7 -> 8 -> 9 -> 11`
- `deleteInRange(4, 8)`

Expected Output: `[1, 3, 9, 11]`

**Constraints:**
- Assume the values are integers.
- You may use a singly linked list structure for the implementation.