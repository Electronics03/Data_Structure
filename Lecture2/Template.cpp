#include <iostream>
#include <cstdlib>

template <typename T>

bool comp(T A, T B)
{
    return (A > B) ? true : false;
}

int main(void)
{
    double A, B;
    std::cin >> A >> B;
    std::cout << comp(A, B) << std::endl;
    return 0;
}