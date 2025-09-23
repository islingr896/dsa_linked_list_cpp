#include <iostream>
#include <set>

using namespace std;

int main()
{
    // Tạo 1 set có kiểu integer
    set<int> s1;

    // Thêm phần tử vào set
    s1.insert(100);
    s1.insert(36);
    s1.insert(38);
    s1.insert(36); // cái này sẽ bị bỏ qua, vì trong set ko trùng lặp phần tử

    cout << "Set: ";

    for(int x : s1)
    {
        cout << x << " ";
    }
    cout << endl;

    // Hàm xoá phần tử
    s1.erase(38);

    cout << "After erase: ";
    for(int x : s1)
    {
        cout << x << " ";
    }
    cout << endl;


    // Ngoài ra, có thể in ra size của s1
    cout << "Size s1: " << s1.size();


    return 0;


}