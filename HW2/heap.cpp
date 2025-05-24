#include "heap.h"

template <typename E, typename C>
int HeapPriorityQueue<E, C>::size() const {
    return T.size();
}

.....

template class HeapPriorityQueue<int, Comparator<int>>;
template class HeapPriorityQueue<char, Comparator<char>>;

