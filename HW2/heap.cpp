#include "heap.h"

template <typename E, typename C>
int HeapPriorityQueue<E, C>::size(void) const
{
    return T.size();
}
template <typename E, typename C>
bool HeapPriorityQueue<E, C>::empty(void) const
{
    return T.size() == 0;
}
template <typename E, typename C>
const E &HeapPriorityQueue<E, C>::min(void)
{
    return *(T.root());
}
template <typename E, typename C>
void HeapPriorityQueue<E, C>::insert(const E &e)
{
    T.addLast(e);
    Position v = T.last();
    while (!T.isRoot(v))
    {
        Position u = T.parent(v);
        if (!isLess(*v, *u))
            break;
        T.swap(v, u);
        v = u;
    }
}
template <typename E, typename C>
void HeapPriorityQueue<E, C>::removeMin(void)
{
    if (size() == 1)
        T.removeLast();
    else
    {
        Position u = T.root();
        T.swap(u, T.last());
        T.removeLast();
        while (T.hasLeft(u))
        {
            Position v = T.left(u);
            if (T.hasRight(u) && isLess(*(T.right(u)), *v))
                v = T.right(u);
            if (isLess(*v, *u))
            {
                T.swap(u, v);
                u = v;
            }
            else
                break;
        }
    }
}

template class HeapPriorityQueue<int, Comparator<int>>;
template class HeapPriorityQueue<char, Comparator<char>>;
