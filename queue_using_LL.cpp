#include<iostream>
using namespace std;


struct Node
{
    int data;
    Node* next;
    Node (int x)
    {
        data = x;
        next = nullptr;
    }
};

class Queue
{
    private:
    // Khởi tạo Stack
    Node* front;
    Node* rear;

    public:

        Queue() 
        {
            front = nullptr;
            rear = nullptr;
            
        }

        //Hàm kiểm tra Queue có rỗng?
        bool isEmpty()
        {
            return front == nullptr;
        }

        void enqueue (int x)
        {
            Node* newNode = new Node(x);
            if(isEmpty())
            {
                front = rear = newNode;
            }
            else
            {
                rear->next = newNode;
                rear = newNode;
            }
        }
        
        int dequeue()
        {
            if(isEmpty())
            {
                cout << "Queue is empty!\n";
                return -1;               
            }
            //sao chép stack
            Node *temp = front;
            //dịch chuyển queue xuống 1 bước
            front = front->next;
            if (front == nullptr) rear = nullptr;
            // xoá queue cũ
            delete temp;
           
        }
        int getFront()
        {
            if(isEmpty())
            {
                cout << "Queue is empty!\n";
                return -1;               
            }
            return front->data;
        }
};


int main()
{
    Queue q1;

    q1.enqueue(1000);
    q1.enqueue(36);

    cout << "Front: " << q1.getFront() << endl; 

    q1.dequeue();

    cout << "After delete => Front: " << q1.getFront() << endl; 

}