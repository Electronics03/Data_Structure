#include <iostream>
#include <string>
#include <vector>
#include "DataError.h"

using namespace std;

struct Elem
{
    string elt;
    int comp;
};

class Comp
{
public:
    bool operator()(const Elem &a, const Elem &b) { return a.comp < b.comp; }
};

template <typename E>
class VectorCompleteTree
{
private:
    vector<E> V;

protected:
    typedef typename vector<E>::iterator Position;
    Position pos(int i) { return (V.begin() + i); }
    int idx(const Position &p) const { return (p - V.begin()); }

public:
    VectorCompleteTree() : V(1) {}
    int size(void) const { return V.size() - 1; }
    Position left(const Position &p) { return pos(2 * idx(p)); }
    Position right(const Position &p) { return pos(2 * idx(p) + 1); }
    Position parent(const Position &p) { return pos(idx(p) / 2); }
    bool hasLeft(const Position &p) const { return (2 * idx(p)) <= size(); }
    bool hasRight(const Position &p) const { return (2 * idx(p) + 1) <= size(); }
    bool isRoot(const Position &p) const { return idx(p) == 1; }
    Position root(void) { return pos(1); }
    Position last(void) { return pos(size()); }
    void addLast(const E &e) { V.push_back(e); }
    void removeLast(void) { V.pop_back(); }
    void swap(const Position &p, const Position &q)
    {
        E tmp = *p;
        *p = *q;
        *q = tmp;
    }
};

template <typename E, typename C>
class HeapPriorityQueue
{
private:
    using Position = typename vector<E>::iterator;
    C isLess;
    VectorCompleteTree<E> T;

public:
    Position root(void) { return T.root(); }
    int size(void) const { return T.size(); }
    bool empty(void) const { return T.size() == 0; }
    const E &min(void) const { return *(T.root()); }
    void insert(const E &e);
    void removeMin(void);
};
template <typename E, typename C>
void HeapPriorityQueue<E, C>::insert(const E &e)
{
    T.addLast(e);
    Position v = T.last();
    while (!T.isRoot(v))
    {
        Position par = T.parent(v);
        if (!isLess(*v, *par))
            break;
        T.swap(v, par);
        v = par;
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
            Position chil = T.left(u);
            if (T.hasRight(u) && (isLess(*T.right(u), *chil)))
                chil = T.right(u);
            if (isLess(*u, *chil))
                break;
            T.swap(u, chil);
            u = chil;
        }
    }
}
int main()
{
    HeapPriorityQueue<Elem, Comp> h;
    h.insert({"A", 4});
    h.insert({"B", 2});
    h.insert({"C", 5});
    h.insert({"E", 10});
    h.insert({"F", 8});
    h.insert({"G", 3});
    h.insert({"H", 6});
    while (!h.empty())
    {
        std::cout << (*(h.root())).comp << ":" << (*(h.root())).elt << std::endl;
        h.removeMin();
    }
}