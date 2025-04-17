#include "Iterator.h"
#include <iostream>

template <typename Elem>
class SequenceBubbleSort : public Nodelist<Elem>
{
public:
    typename Nodelist<Elem>::Iterator atIndex(int i) const;
    int indexOf(const typename Nodelist<Elem>::Iterator &p) const;
};

template <typename Elem>
typename Nodelist<Elem>::Iterator SequenceBubbleSort<Elem>::atIndex(int i) const
{
    typename Nodelist<Elem>::Iterator p = this->begin();
    for (int j = 0; j < i; j++)
        ++p;
    return p;
}

template <typename Elem>
int SequenceBubbleSort<Elem>::indexOf(const typename Nodelist<Elem>::Iterator &p) const
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
void bubbleSort1(SequenceBubbleSort<int> &S)
{
    int n = S.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            SequenceBubbleSort<int>::Iterator prec = S.atIndex(j - 1);
            SequenceBubbleSort<int>::Iterator succ = S.atIndex(j);
            if (*prec > *succ)
            {
                int tmp = *succ;
                *succ = *prec;
                *prec = tmp;
            }
        }
    }
}
void bubbleSort2(SequenceBubbleSort<int> &S)
{
    int n = S.size();
    for (int i = 0; i < n; i++)
    {
        SequenceBubbleSort<int>::Iterator prec = S.begin();
        for (int j = 1; j < n - i; j++)
        {
            SequenceBubbleSort<int>::Iterator succ = prec;
            ++succ;
            if (*prec > *succ)
            {
                int tmp = *succ;
                *succ = *prec;
                *prec = tmp;
            }
            ++prec;
        }
    }
}
int main(void)
{
    SequenceBubbleSort<int> seq;
    seq.insertBack(5);
    seq.insertBack(1);
    seq.insertBack(4);
    seq.insertBack(2);
    seq.insertBack(6);

    for (auto it = seq.begin(); it != seq.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    bubbleSort2(seq);

    for (auto it = seq.begin(); it != seq.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    return 0;
}
/*
 * g++                                -> 컴파일러
 * -o CH6_Iterator/SequenceBubbleSort.exe   -> exe 파일 이름, 위치
 * CH6_Iterator/SequenceBubbleSort.cpp      -> 함께 하는 파일 이름, 위치
 * CH6_Iterator/Iterator.cpp          -> 함께 하는 파일 이름, 위치
 * CH6_Iterator/DataError.cpp         -> 함께 하는 파일 이름, 위치
 *
 * g++ -o CH6_Iterator/SequenceBubbleSort.exe CH6_Iterator/SequenceBubbleSort.cpp CH6_Iterator/Iterator.cpp CH6_Iterator/DataError.cpp
 */