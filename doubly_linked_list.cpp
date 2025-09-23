#include<iostream>
using namepace std;

struct Node 
{
    int data;
    Node* prev;
    Node* next;

    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
}
void insertAtBeginning(Node *& head, int val)
{
    Node * newNode = new Node(val);
    
    // check if the doubly linked list is empty!
    if(head == nullptr)
    {
        head = newNode;
        return;
    }

    // nếu ko rỗng thì cập nhật prev, next pointers 
    // để insert new node ở đầu ds
    newNode -> next = head;
    head -> prev = newNode;
    head = newNode; // cập nhật newNode là Head
}

int main()
{
    
    


    return 0;
}

