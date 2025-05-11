#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int A[] = {17, 12, 33, 15, 62, 45};
    vector<int> v(A, A + 6);
    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    cout << endl;
    v.pop_back();
    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    cout << endl;
    v.push_back(19);
    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    cout << endl;
    sort(v.begin(), v.begin() + 4);
    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    cout << endl;
    v.erase(v.end() - 4, v.end() - 2);
    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    cout << endl;
    return 0;
}