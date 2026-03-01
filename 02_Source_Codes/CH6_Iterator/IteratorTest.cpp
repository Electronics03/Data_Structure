#include <iostream>
#include "Iterator.h"

int main(void)
{
    Nodelist<int> A;
    A.insertFront(97);
    A.insertFront(86);
    A.insertFront(75);
    A.insertFront(65);
    A.insertFront(54);
    A.insertFront(44);
    A.insertFront(33);
    A.insertFront(21);
    A.insertFront(10);
    A.insertFront(2);
    for (Nodelist<int>::Iterator i = A.begin(); i != A.end(); ++i)
        std::cout << *i << " ";

    std::cout << std::endl;
    return 0;
}
/*
 * g++                                -> 컴파일러
 * -o CH6_Iterator/IteratorTest.exe   -> exe 파일 이름, 위치
 * CH6_Iterator/IteratorTest.cpp      -> 함께 하는 파일 이름, 위치
 * CH6_Iterator/Iterator.cpp          -> 함께 하는 파일 이름, 위치
 * CH6_Iterator/DataError.cpp         -> 함께 하는 파일 이름, 위치
 *
 * g++ -o CH6_Iterator/IteratorTest.exe CH6_Iterator/IteratorTest.cpp CH6_Iterator/Iterator.cpp CH6_Iterator/DataError.cpp
 */