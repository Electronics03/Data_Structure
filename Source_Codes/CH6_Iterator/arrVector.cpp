#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

typedef int Elem;

class arrVector
{
private:
    int capacity;
    int n;
    Elem ERROR = 0;
    Elem *A;

public:
    arrVector();
    ~arrVector();

    int size(void) const;
    bool empty(void) const;

    Elem &operator[](int i);
    Elem &at(int i);

    void erase(int i);
    void insert(int i, const Elem &data);

    void reserve(int N);
};

arrVector::arrVector() : capacity(0), n(0), A(NULL) {}
arrVector::~arrVector() {}

int arrVector::size(void) const { return n; }
bool arrVector::empty(void) const { return (n == 0); }
Elem &arrVector::operator[](int i) { return A[i]; }
Elem &arrVector::at(int i) { return A[i]; }
void arrVector::erase(int i)
{
    if (empty())
    {
        std::cout << "ERROR: Vector is Empty." << std::endl;
        return;
    }
    for (int j = i + 1; j < n; j++)
        A[j - 1] = A[j];
    n--;
}
void arrVector::insert(int i, const Elem &data)
{
    if (n >= capacity)
        reserve(std::max(1, 2 * capacity));
    for (int j = n - 1; j >= i; j--)
        A[j + 1] = A[j];
    A[i] = data;
    n++;
}
void arrVector::reserve(int N)
{
    if (capacity >= N)
        return;
    Elem *B = new Elem[N];
    for (int i = 0; i < n; i++)
        B[i] = A[i];
    if (A != NULL)
        delete[] A;
    A = B;
    capacity = N;
    return;
}

int main(void)
{
    arrVector A;
    A.insert(0, 1);
    A.insert(0, 2);
    A.insert(0, 5);
    A.insert(0, 3);
    A.insert(0, 6);
    A.insert(0, 8);
    A.insert(0, 4);
    for (int i = 0; i < A.size(); i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
    return 0;
}