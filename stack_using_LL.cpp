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

class Stack
{
    // Khởi tạo Stack
    Node* top;

    public:

        Stack() 
        {
            top = nullptr;
        }

        //Hàm kiểm tra stack có rỗng?
        bool isEmpty()
        {
            return top == nullptr;
        }

        void push (int x)
        {
            Node* newNode = new Node(x);
            newNode-> next = top;
            top = newNode;
        }
        
        void pop()
        {
            if(isEmpty())
            {
                cout << "Stack is empty!\n";
                return;               
            }
            //sao chép stack
            Node *temp = top;
            //dịch chuyển stack xuống 1 bước
            top = top->next;
            // xoá stack cũ
            delete temp;
           
        }
        int peek()
        {
            if(isEmpty())
            {
                cout << "Stack is empty!\n";
                return -1;               
            }
            return top->data;
        }
};


int main()
{
    Stack s1;
    s1.push(5);
    s1.push(36);
    s1.pop();

    cout << s1.peek() << endl;
    cout <<"..........";
}