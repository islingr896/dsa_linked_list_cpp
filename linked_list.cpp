#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node (int val)
    {
        data = val;
        next = nullptr; // 1 newNode thì có luôn đuôi là nullptr
    }
};

// Đây là hàm insert vào đầu danh sách 
void insertHead (Node *& head, int val)  // truyền tham chiếu đến con trỏ của Head
{
    Node *newNode = new Node(val);
    newNode -> next = head;
    head = newNode;
}

void insertTail (Node *& head, int val)
{
    Node * newNode = new Node(val);

    // Nếu danh sách rỗng thì newNode được gán vào head luôn.
    if(head == nullptr)
    {
        head = newNode;
        return;
    }

    // Nếu danh sách chưa rỗng thì ta cần 1 biến để đi đến Node cuối.
    // Cần biến temp để không head vẫn trỏ ở đầu ds.
    Node *temp = head;
    
    while(temp-> next != nullptr)
    {
        temp = temp -> next;
    }
    temp -> next = newNode;
}

void deleteNode (Node *& head, int val)
{
    
    // Nếu ds rỗng thì return luôn.
    if(head == nullptr) return;

    // Kiểm tra xem head->data đầu tiên có phải cái cần xoá không
    // Nếu phải thì cần phải cập nhật lại Head cho ds.
    if(head-> data == val)
    {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return;
    }
    
    Node* temp = head;

    // Duyệt qua toàn ds, phát hiện và vòng while dừng ngay trước khi đến phần tử cần xoá, sẽ không trỏ đến phần tử đó nữa
    // Nếu không thấy thì thôi, temp-> next = nullptr
    while(temp->next != nullptr && temp->next->data != val)
    {
        temp = temp->next;
    }
    
    // vòng while dừng rồi thì giờ mình bắt đầu bỏ qua thằng cần xoá, trỏ đến thằng kia 1-2-3 thì bỏ qua 2
    if(temp -> next != nullptr)
    {
        Node* tmp = temp->next;
        temp->next = temp->next->next; // Nối thẳng temp đến node kia (bỏ qua node ở giữa là node cần xoá)
        delete tmp;
    }
}

void printList (Node* head)
{
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp -> data << " -> ";
        temp = temp->next;
    }
    cout << "Null\n";
}


int main()
{
    cout << "Start...\n";

    Node* head = nullptr;
    insertHead(head, 36);
    insertTail(head, 37);
    insertHead (head, 98);
    insertHead(head, 99999);

    printList(head);

    deleteNode(head, 36);

    printList(head);
    return 0;
}