#include "SinglyLinkedList.h"

int main(void)
{
    SLinkedList A;
    A.addFront("Chung-Ang Univ");
    A.addFront("CAU");
    A.addFront("EEE");
    A.addFront("Chung-Ang Univ");
    A.addFront("CAU");
    A.addFront("EEE");
    while (!A.empty())
    {
        std::cout << A.front() << std::endl;
        A.removeFront();
    }
    A.removeFront();
    return 0;
}