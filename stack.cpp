#include<iostream>
#include <stack>
#include <queue>

using namespace std;




int main()
{
    // stack<int> st;

    // st.push(10);    
    // st.push(36);

    // cout << "Top element: " << st.top() << endl;
    // st.pop();
    // cout << "updated top element: " << st.top()<< endl;
    // cout << "Empty ?" << (st.empty() ? "Yes" : "No") << endl;


    queue<int> q1;
    q1.push(100);
    q1.push(200);
    q1.push(98);

    cout << "Queue: " <<  q1.front() << endl;
    cout << q1.back();
    return 0;
}

