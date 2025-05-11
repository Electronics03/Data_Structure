#include "CircularlyLinkedList.h"

int main(void)
{
    CLinkedList A;
    A.add("Hello");                      // Hello*
    A.add("World");                      // World->Hello*
    A.add("C++");                        // C++->World->Hello*
    A.advance();                         // World->Hello->C++*
    std::cout << A.back() << std::endl;  // C++
    std::cout << A.front() << std::endl; // World
    A.advance();                         // Hello->C++->World*
    A.remove();                          // C++->World*
    std::cout << A.back() << std::endl;  // World
    std::cout << A.front() << std::endl; // C++
    A.remove();
    A.remove();
    A.remove();
    A.remove();
    A.remove();
    return 0;
}