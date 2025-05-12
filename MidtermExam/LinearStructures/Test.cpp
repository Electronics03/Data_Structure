#include "Iterator.h"

int main(void)
{
    Nodelist A;
    A.insertFront("97");
    A.insertFront("86");
    A.insertFront("75");
    A.insertFront("65");
    A.insertFront("54");
    A.insertFront("44");
    A.insertFront("3");
    A.insertFront("21");
    A.insertFront("10");
    A.insertFront("2");
    for (Nodelist::Iterator i = A.begin(); i != A.end(); ++i)
        std::cout << *i << " ";

    std::cout << std::endl;
    return 0;
}