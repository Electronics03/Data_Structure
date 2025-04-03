#include <iostream>

using namespace std;

int main(void)
{
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    // int 자료형의 크기
    int a = 0;
    cout << "Size of variable a: " << sizeof(a) << " bytes" << endl;
    // 변수 a의 크기
    return 0;
}