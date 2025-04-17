#include "Iterator.h"
#include <iostream>

template <typename Elem>
class NodeSequence : public Nodelist<Elem>
{
public:
    typename Nodelist<Elem>::Iterator atIndex(int i) const;
    int indexOf(const typename Nodelist<Elem>::Iterator &p) const;
};

template <typename Elem>
typename Nodelist<Elem>::Iterator NodeSequence<Elem>::atIndex(int i) const
{
    typename Nodelist<Elem>::Iterator p = this->begin();
    for (int j = 0; j < i; j++)
        ++p;
    return p;
}

template <typename Elem>
int NodeSequence<Elem>::indexOf(const typename Nodelist<Elem>::Iterator &p) const
{
    typename Nodelist<Elem>::Iterator q = this->begin();
    int j = 0;
    while (p != q)
    {
        ++q;
        ++j;
    }
    return j;
}
int main(void)
{
    NodeSequence<int> seq;
    seq.insertBack(10);
    seq.insertBack(20);
    seq.insertBack(30);
    seq.insertBack(40);
    seq.insertBack(50);

    for (auto it = seq.begin(); it != seq.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    int idx = 2;
    auto it = seq.atIndex(idx);
    std::cout << idx << "|" << *it << std::endl;

    int backIndex = seq.indexOf(it);
    std::cout << "|" << backIndex << std::endl;

    auto last = seq.end();
    --last;
    std::cout << *last << std::endl;
    std::cout << seq.indexOf(last) << std::endl;

    return 0;
}
/*
 * g++                                -> 컴파일러
 * -o CH6_Iterator/NodeSequence.exe   -> exe 파일 이름, 위치
 * CH6_Iterator/NodeSequence.cpp      -> 함께 하는 파일 이름, 위치
 * CH6_Iterator/Iterator.cpp          -> 함께 하는 파일 이름, 위치
 * CH6_Iterator/DataError.cpp         -> 함께 하는 파일 이름, 위치
 *
 * g++ -o CH6_Iterator/NodeSequence.exe CH6_Iterator/NodeSequence.cpp CH6_Iterator/Iterator.cpp CH6_Iterator/DataError.cpp
 */