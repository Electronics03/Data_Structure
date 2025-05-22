#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include "DataError.h"

struct Elem
{
    std::string elt;
    int comp;
};

class Less
{
public:
    bool operator()(const Elem &p, const Elem &q) const
    {
        return p.comp < q.comp;
    }
};

template <typename E>
class VectorCompleteTree
{
private:
    std::vector<E> V;

protected:
    typedef typename std::vector<E>::iterator Position;
    Position pos(int i) { return V.begin() + i; }
    int idx(const Position &p) const { return p - V.begin(); }

public:
    VectorCompleteTree() : V(1) {}
    int size(void) const { return V.size() - 1; }
    Position left(const Position &p) { return pos(2 * idx(p)); }
    Position right(const Position &p) { return pos(2 * idx(p) + 1); }
    Position parent(const Position &p) { return pos(idx(p) / 2); }
    bool hasLeft(const Position &p) const { return 2 * idx(p) <= size(); }
    bool hasRight(const Position &p) const { return 2 * idx(p) + 1 <= size(); }
    bool isRoot(const Position &p) const { return idx(p) == 1; }
    Position root(void) { return pos(1); }
    Position last(void) { return pos(size()); }
    void addLast(const E &e) { V.push_back(e); }
    void removeLast(void) { V.pop_back(); }
    void swap(const Position &p, const Position &q)
    {
        E e = *q;
        *q = *p;
        *p = e;
    }
};
template <typename E, typename C>
class HeapPriorityQueue
{
public:
    typename std::vector<E>::iterator root(void) { return T.root(); }
    int size(void) const;
    bool empty(void) const;
    void insert(const E &e);
    const E &min(void);
    void removeMin(void);

private:
    VectorCompleteTree<E> T;
    C isLess;
    typedef typename VectorCompleteTree<E>::Position Position;
};
template <typename E, typename C>
int HeapPriorityQueue<E, C>::size(void) const { return T.size(); }
template <typename E, typename C>
bool HeapPriorityQueue<E, C>::empty(void) const { return T.size() == 0; }
template <typename E, typename C>
const E &HeapPriorityQueue<E, C>::min(void) { return *(T.root()); }
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
            if (isLess(*u, *v))
            {
                T.swap(u, v);
                u = v;
            }
        }
    }
}
int main()
{
    HeapPriorityQueue<Elem, Less> h;
    h.insert({"A", 4});
    h.insert({"B", 2});
    h.insert({"C", 5});
    h.insert({"E", 10});
    h.insert({"F", 8});
    h.insert({"G", 3});
    h.insert({"H", 6});
    while (!h.empty())
    {
        std::cout << (*(h.root())).comp << std::endl;
        h.removeMin();
    }
}