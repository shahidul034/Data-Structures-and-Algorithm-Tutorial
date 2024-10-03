<h2><i>👉Lab 5 - Linked Lists (Part 2)</i></h2>
	
### ✅Delete first node
```c
void delete_first_node()
{
    if (head==NULL)
    {
        cout<<"Linked list is empty!!!"<<endl;
    }
    else
        head=head->link;
}
```
### ✅Delete last node
```c
void delete_last_node()
{
    if (head==NULL){
        cout<<"Linked list is empty!!!"<<endl;
    }
    node *srt=head,*temp;
    while(srt->link!=NULL)
    {
        temp=srt;
        srt=srt->link;
    }
    temp->link=NULL;
}
```
### ✅Deleting a node with a given value 
```c
void delete_given_node(int search)
{
    if (head->info==search)
    {
        delete_first_node();
        return;
    }
    node *srt=head,*temp;
    while(srt->info!=search)
    {
        temp=srt;
        srt=srt->link;
    }
    temp->link=srt->link;

}
```
### ✅Deleting a node before a given value
```c
void delete_before_given_node(int search)
{
    if (head->info==search)
    {
        cout<<"It is the first node!!"<<endl;
        return;
    }
    node *srt=head,*temp;
    while(srt->info!=search)
    {
        temp=srt;
        srt=srt->link;
    }
    delete_given_node(temp->info);
}
```
### ✅Deleting a node after a given value
```c
void delete_after_given_node(int search)
{
    node *srt=head,*temp;
    while(srt->info!=search and srt->link!=NULL)
    {
        temp=srt;
        srt=srt->link;
    }
    if (srt->link==NULL)
    {
        cout<<"It is the last node!!!"<<endl;
        return;
    }
    delete_given_node(srt->link->info);
}
```
### ✅Main Function
```c
int main()
{

    allocation(10);
    allocation(20);
    allocation(30);
    allocation(40);
    allocation(50);
    allocation(60);
    allocation(70);
    allocation(80);
    delete_first_node();
    traverse();
    delete_last_node();
    traverse();
    delete_given_node(40);//delete 40
    traverse();
    delete_before_given_node(50);//delete 30
    traverse();
    delete_after_given_node(60);//delete 70
    delete_after_given_node(80);
    delete_before_given_node(20);
    traverse();

}
```

<h2><i>🚩Questions</i></h2>
	
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
