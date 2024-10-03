#include <iostream>
using namespace std;
// Node class
class node
{
public:
    int info;         // Data part
    node* link;       // Pointer to the next node
};
node *head = NULL, *temp;  // Global pointers to manage the list
int allocation(int item)
{
    node *ptr = new node();  // Allocate a new node
    ptr->info = item;        // Set the data
    ptr->link = NULL;        // Set the link to null

    if (head == NULL)
    {
        head = ptr;          // If list is empty, the new node becomes head
        temp = ptr;
    }
    else
    {
        temp->link = ptr;    // Otherwise, link the last node to the new node
        temp = ptr;
    }
}
int traverse()
{
    node *srt = head;        // Start from the head
    while (srt != NULL)
    {
        cout << srt->info << " ";  // Print data
        srt = srt->link;           // Move to the next node
    }
    cout << endl;
}
void insert_first(int data)
{
    node *ptr=new node();
    ptr->info=data;
    ptr->link=head;
    head=ptr;
}
void insert_last(int data)
{
    node *ptr=new node();
    ptr->info=data;
    node *srt=head;
    while(srt->link!=NULL)
    {
        srt=srt->link;
    }
    srt->link=ptr;
    ptr->link=NULL;
}
void insert_node_after_item(int search,int data)
{
    node *ptr=new node();
    ptr->info=data;
    node *srt=head;
    while(srt->info!=search)
    {
        srt=srt->link;
    }
    ptr->link=srt->link;
    srt->link=ptr;
}
void insert_node_before_item(int search, int data)
{
    node *ptr=new node();
    ptr->info=data;
    node *srt=head,*prev;

    while(srt->info!=search)
    {
        prev=srt;
        srt=srt->link;
    }
    prev->link=ptr;
    ptr->link=srt;
}

void delete_first_node()
{
    if (head==NULL)
    {
        cout<<"Linked list is empty!!!"<<endl;
    }
    else
        head=head->link;
}

void delete_last_node()
{
    if (head==NULL)
    {
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
    traverse();
    insert_first(9);
    traverse();
    insert_last(31);
    traverse();
    insert_node_after_item(20, 25);
    traverse();
    insert_node_before_item(30,27);
    traverse();
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
