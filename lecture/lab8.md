<h2><i>👉Lab 8 - Tree: Tree Traversal - inorder, preorder and postorder</i></h2>

### ✅ Terminalogy
#### Root
It is the topmost node of a tree.

#### Height of a Node
The height of a node is the number of edges from the node to the deepest leaf (ie. the longest path from the node to a leaf node).

#### Depth of a Node
The depth of a node is the number of edges from the root to the node.

#### Height of a Tree
The height of a Tree is the height of the root node or the depth of the deepest node.
#### Types of Tree
- Binary Tree
- Binary Search Tree
- AVL Tree
- B-Tree

![Tree](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/images/tree01.png/?raw=true)

![Tree](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/images/tree02.png/?raw=true)

### ✅ `Inorder` traversal
- First, visit all the nodes in the left subtree
- Then the root node
- Visit all the nodes in the right subtree
```c
inorder(root->left)
display(root->data)
inorder(root->right)
```
### ✅ `Preorder` traversal
```
display(root->data)
preorder(root->left)
preorder(root->right)
```
### ✅ `Postorder` traversal
```
postorder(root->left)
postorder(root->right)
display(root->data)
```
### ✅ The `Node` class represents a single node in a binary tree
```c
class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
```
### ✅ Main function
```c
int main()
{
    Node* root=new Node(1);
    root->left = new Node(12);
    root->right = new Node(9);
    root->left->left = new Node(5);
    root->left->right = new Node(6);
    inorderTraversal(root);
    cout<<endl;
    preorderTraversal(root);
    cout<<endl;
    postorderTraversal(root);
}
```

[Full code](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/code/trees.cpp)

### Reference
https://www.programiz.com/dsa/tree-traversal





