#include "LinkedDeque.h"

int main(void)
{
    LinkedDeque A;
    A.insertFront("Hello");
    A.insertFront("World");
    A.insertFront("C++");
    A.insertBack("Hello");
    A.insertBack("World");
    A.insertBack("C++");
    while (!A.empty())
    {
        std::cout << A.front() << " " << A.back() << std::endl;
        A.removeFront();
    }
    return 0;
}